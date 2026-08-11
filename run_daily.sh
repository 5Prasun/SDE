#!/usr/bin/env bash
# Runs one daily publish + push. Point cron at this file.
set -euo pipefail

# Move to the repo root (this script's own folder), regardless of where cron runs it.
cd "$(dirname "$0")"

# If git/python aren't found when run by cron, uncomment and set full paths:
# export PATH="/usr/local/bin:/usr/bin:/bin:$PATH"

# One-per-day guard: skip if the last commit is already dated today.
LAST_DATE=$(git log -1 --format=%cd --date=format:'%Y-%m-%d' 2>/dev/null || echo "none")
TODAY=$(date +'%Y-%m-%d')
if [ "$LAST_DATE" = "$TODAY" ]; then
  echo "$(date '+%F %T'): already pushed today; skipping."
  exit 0
fi

python3 scripts/publish_next.py

git add -A
if git diff --cached --quiet; then
  echo "$(date '+%F %T'): nothing new to publish (all 50 done)."
  exit 0
fi

DAY=$(ls solutions/*.cpp | wc -l | tr -d ' ')
NAME=$(ls solutions/*.cpp | sort | tail -n1 | sed 's#solutions/##; s#^[0-9]*_##; s#\.cpp$##; s#-# #g')
git commit -m "Day ${DAY}/50: ${NAME}"
git push
echo "$(date '+%F %T'): pushed Day ${DAY}/50 - ${NAME}"
