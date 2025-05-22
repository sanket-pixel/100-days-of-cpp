# 100 Days of C++ – Leetcode Challenge

Track of all problems solved with C++ solutions and concise revision notes.

---

## ✅ Day 1 – May 19, 2025

| # | Problem                 | Summary                                                                                                   |
|--:|-------------------------|-----------------------------------------------------------------------------------------------------------|
| 0 | **Contains Duplicate**  | Check for duplicates using sort and compare adjacent elements. Time: O(n log n), Space: O(1)              |
| 1 | **Missing Number**      | Use sum formula: `n*(n+1)/2 - actual_sum`. Time: O(n), Space: O(1)                                        |
| 2 | **All Missing Numbers** | Use cyclic sort to position numbers. Then collect indices where `nums[i] != i+1`. Time: O(n), Space: O(1) |

---

## ✅ Day 2 – May 20, 2025

| # | Problem                          | Summary                                                                                          |
|--:|----------------------------------|--------------------------------------------------------------------------------------------------|
| 3 | **Two Sum**                      | Store value→index in hash map, look for `target - nums[i]`. Time: O(n), Space: O(n)              |
| 4 | **String Operator**              | Simple string ops like `"--X"` and `"X++"` adjust a counter. Easy logic.                         |
| 5 | **Smaller Number Count**         | Sort and use map to record the first index of each value. Count values before current index.     |
| 6 | **Min Time Visiting All Points** | Time to move from (x1, y1) to (x2, y2) is `max(abs(x2 - x1), abs(y2 - y1))`. Sum over all pairs. |

---

## ✅ Day 3 – May 22, 2025

| # | Problem           | Summary                                                                                                                                      |
|--:|-------------------|----------------------------------------------------------------------------------------------------------------------------------------------|
| 7 | **Spiral Matrix** | Get first row top++, get last column right--,until top<=bottom get last row bottom--,<br/> if left<=right get first column left++. Time:O(N) |

---