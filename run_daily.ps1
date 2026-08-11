# Runs one daily publish + push. Point Windows Task Scheduler at this file.
$ErrorActionPreference = "Stop"
Set-Location -Path $PSScriptRoot

# One-per-day guard: skip if the last commit is already dated today.
$today = (Get-Date).ToString("yyyy-MM-dd")
$lastDate = ""
try { $lastDate = (git log -1 --format=%cd --date=format:'%Y-%m-%d') } catch {}
if ($lastDate -eq $today) {
    Write-Output "Already pushed today; skipping."
    exit 0
}

# Use 'python' on Windows (change to 'python3' if that's your command).
python scripts/publish_next.py

git add -A
git diff --cached --quiet
if ($LASTEXITCODE -eq 0) {
    Write-Output "Nothing new to publish (all 50 done)."
    exit 0
}

$day  = (Get-ChildItem solutions/*.cpp).Count
$last = (Get-ChildItem solutions/*.cpp | Sort-Object Name | Select-Object -Last 1).BaseName
$name = ($last -replace '^\d+_', '') -replace '-', ' '
git commit -m "Day $day/50: $name"
git push
Write-Output "Pushed Day $day/50 - $name"
