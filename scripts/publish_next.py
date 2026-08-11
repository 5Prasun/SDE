#!/usr/bin/env python3
"""
Publish the next solution.

Run daily by the GitHub Actions workflow. It:
  1. counts how many solutions are already in solutions/
  2. copies the next one from vault/ into solutions/
  3. rebuilds the progress section of README.md

Idempotent by state: the number of published files decides what comes next,
so a re-run without a new day simply republishes nothing new beyond the count.
When every problem is published it prints DONE and changes nothing.
"""
import json
import pathlib
import datetime

ROOT = pathlib.Path(__file__).resolve().parents[1]
VAULT = ROOT / "vault"
SOLUTIONS = ROOT / "solutions"
DATA = ROOT / "data" / "problems.json"
README = ROOT / "README.md"

START = "<!-- PROGRESS:START -->"
END = "<!-- PROGRESS:END -->"


def load_problems():
    return json.loads(DATA.read_text(encoding="utf-8"))


def published_count():
    return len(list(SOLUTIONS.glob("*.cpp")))


def build_progress(problems, done):
    total = len(problems)
    today = datetime.date.today().isoformat()
    lines = [
        START,
        f"### Progress: {done} / {total}  ({done * 100 // total}%)",
        "",
        f"_Last updated: {today}_",
        "",
        "| Day | Problem | Difficulty | Topic | Status |",
        "|----:|---------|:----------:|-------|:------:|",
    ]
    for p in problems:
        n = p["num"]
        if n <= done:
            name = f"[{p['name']}](solutions/{p['file']})"
            status = "✅"
        else:
            name = p["name"]
            status = "⬜"
        lines.append(f"| {n:02d} | {name} | {p['difficulty']} | {p['topic']} | {status} |")
    lines.append(END)
    return "\n".join(lines)


def update_readme(problems, done):
    text = README.read_text(encoding="utf-8")
    block = build_progress(problems, done)
    pre, _, rest = text.partition(START)
    _, _, post = rest.partition(END)
    README.write_text(pre + block + post, encoding="utf-8")


def main():
    SOLUTIONS.mkdir(exist_ok=True)
    problems = load_problems()
    done = published_count()

    if done >= len(problems):
        print(f"DONE: all {len(problems)} solutions already published.")
        return

    nxt = problems[done]  # done files -> next is index `done`
    src = VAULT / nxt["file"]
    dst = SOLUTIONS / nxt["file"]
    dst.write_text(src.read_text(encoding="utf-8"), encoding="utf-8")

    new_done = done + 1
    update_readme(problems, new_done)
    print(f"PUBLISHED day {new_done:02d}: {nxt['name']} -> solutions/{nxt['file']}")


if __name__ == "__main__":
    main()
