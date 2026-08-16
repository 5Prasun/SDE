# sde

A 50-day auto-committed archive of the most famous SDE coding interview
questions, solved in C++. One solution is published automatically every day
by a scheduled GitHub Actions workflow — no manual work after setup.

- **Solutions** land in [`solutions/`](solutions/), one per day.
- The full source set lives in [`vault/`](vault/); the bot reveals them in order.
- Problem metadata is in [`data/problems.json`](data/problems.json).

<!-- PROGRESS:START -->
### Progress: 6 / 50  (12%)

_Last updated: 2026-08-16_

| Day | Problem | Difficulty | Topic | Status |
|----:|---------|:----------:|-------|:------:|
| 01 | [Two Sum](solutions/01_two-sum.cpp) | Easy | Arrays / Hashing | ✅ |
| 02 | [Best Time to Buy and Sell Stock](solutions/02_best-time-to-buy-and-sell-stock.cpp) | Easy | Arrays / Sliding Window | ✅ |
| 03 | [Contains Duplicate](solutions/03_contains-duplicate.cpp) | Easy | Arrays / Hashing | ✅ |
| 04 | [Product of Array Except Self](solutions/04_product-of-array-except-self.cpp) | Medium | Arrays / Prefix | ✅ |
| 05 | [Maximum Subarray](solutions/05_maximum-subarray.cpp) | Medium | Dynamic Programming | ✅ |
| 06 | [Maximum Product Subarray](solutions/06_maximum-product-subarray.cpp) | Medium | Dynamic Programming | ✅ |
| 07 | Find Minimum in Rotated Sorted Array | Medium | Binary Search | ⬜ |
| 08 | Search in Rotated Sorted Array | Medium | Binary Search | ⬜ |
| 09 | 3Sum | Medium | Two Pointers | ⬜ |
| 10 | Container With Most Water | Medium | Two Pointers | ⬜ |
| 11 | Number of 1 Bits | Easy | Bit Manipulation | ⬜ |
| 12 | Counting Bits | Easy | Bit Manipulation / DP | ⬜ |
| 13 | Missing Number | Easy | Math / Bit | ⬜ |
| 14 | Reverse Bits | Easy | Bit Manipulation | ⬜ |
| 15 | Longest Substring Without Repeating Characters | Medium | Sliding Window | ⬜ |
| 16 | Longest Repeating Character Replacement | Medium | Sliding Window | ⬜ |
| 17 | Minimum Window Substring | Hard | Sliding Window | ⬜ |
| 18 | Valid Anagram | Easy | Hashing | ⬜ |
| 19 | Group Anagrams | Medium | Hashing | ⬜ |
| 20 | Valid Parentheses | Easy | Stack | ⬜ |
| 21 | Reverse Linked List | Easy | Linked List | ⬜ |
| 22 | Linked List Cycle | Easy | Linked List | ⬜ |
| 23 | Merge Two Sorted Lists | Easy | Linked List | ⬜ |
| 24 | Merge k Sorted Lists | Hard | Heap / Linked List | ⬜ |
| 25 | Remove Nth Node From End of List | Medium | Linked List | ⬜ |
| 26 | Reorder List | Medium | Linked List | ⬜ |
| 27 | Invert Binary Tree | Easy | Trees | ⬜ |
| 28 | Maximum Depth of Binary Tree | Easy | Trees | ⬜ |
| 29 | Same Tree | Easy | Trees | ⬜ |
| 30 | Subtree of Another Tree | Easy | Trees | ⬜ |
| 31 | Lowest Common Ancestor of a BST | Medium | Trees / BST | ⬜ |
| 32 | Binary Tree Level Order Traversal | Medium | Trees / BFS | ⬜ |
| 33 | Validate Binary Search Tree | Medium | Trees / BST | ⬜ |
| 34 | Kth Smallest Element in a BST | Medium | Trees / BST | ⬜ |
| 35 | Construct Binary Tree from Preorder and Inorder | Medium | Trees | ⬜ |
| 36 | Find Median from Data Stream | Hard | Heap / Design | ⬜ |
| 37 | Top K Frequent Elements | Medium | Heap / Bucket Sort | ⬜ |
| 38 | Combination Sum | Medium | Backtracking | ⬜ |
| 39 | Word Search | Medium | Backtracking / DFS | ⬜ |
| 40 | Number of Islands | Medium | Graphs / DFS | ⬜ |
| 41 | Clone Graph | Medium | Graphs / DFS | ⬜ |
| 42 | Course Schedule | Medium | Graphs / Topological Sort | ⬜ |
| 43 | Pacific Atlantic Water Flow | Medium | Graphs / DFS | ⬜ |
| 44 | Climbing Stairs | Easy | Dynamic Programming | ⬜ |
| 45 | Coin Change | Medium | Dynamic Programming | ⬜ |
| 46 | Longest Increasing Subsequence | Medium | Dynamic Programming | ⬜ |
| 47 | Longest Common Subsequence | Medium | Dynamic Programming | ⬜ |
| 48 | Word Break | Medium | Dynamic Programming | ⬜ |
| 49 | House Robber | Medium | Dynamic Programming | ⬜ |
| 50 | Unique Paths | Medium | Dynamic Programming | ⬜ |
<!-- PROGRESS:END -->

---

## How the automation works

`.github/workflows/daily-push.yml` runs once a day. It calls
`scripts/publish_next.py`, which counts the files already in `solutions/`,
copies the next problem from `vault/`, refreshes the progress table above,
then commits and pushes a single commit (`Day N/50: <Problem>`). After 50
days everything is published and the workflow becomes a no-op.

## One-time setup

1. Create an empty repo named **`sde`** on GitHub (no README).
2. Push this project into it:
   ```bash
   git init
   git add -A
   git commit -m "Initial setup: 50-day SDE auto-push"
   git branch -M main
   git remote add origin https://github.com/<your-username>/sde.git
   git push -u origin main
   ```
3. In the repo: **Settings → Actions → General → Workflow permissions** →
   select **Read and write permissions** → Save.
4. Open `.github/workflows/daily-push.yml` and set your author identity in the
   *Commit and push* step:
   - `user.name`  → your GitHub username
   - `user.email` → your GitHub **noreply** email
     (`Settings → Emails`, looks like `1234567+username@users.noreply.github.com`).
     This is what makes the daily commits show up as green squares on your profile.
5. (Optional) Change the schedule time. The cron line is in **UTC**;
   IST = UTC + 5:30. `30 4 * * *` = 10:00 AM IST.
6. Test it now: **Actions → Daily SDE Push → Run workflow**. It should commit
   Day 01 immediately. After that it runs on its own each day.

## Notes

- GitHub can delay scheduled workflows by a few minutes under load; the day it
  runs is what matters, not the exact minute.
- A same-day guard prevents a second scheduled run from publishing twice;
  manual **Run workflow** always publishes (handy for testing).
