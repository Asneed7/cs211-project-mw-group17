# CS211 Group Project
## Part B: Luhn Checksum Manual Dry Run

### Purpose

This dry run demonstrates how the Luhn algorithm
processes the 16-digit number 4532015112830366.

Starting at the rightmost digit, the algorithm
doubles every second digit moving left.

If a doubled value exceeds 9, subtract 9.
Then add all transformed values.

### Manual Dry-Run Table

| Position from Right | Original Digit | Doubled? | Transformed Value |
|---|---|---|---|
| 1 | 6 | No | 6 |
| 2 | 6 | Yes | 3 |
| 3 | 3 | No | 3 |
| 4 | 0 | Yes | 0 |
| 5 | 3 | No | 3 |
| 6 | 8 | Yes | 7 |
| 7 | 2 | No | 2 |
| 8 | 1 | Yes | 2 |
| 9 | 1 | No | 1 |
| 10 | 5 | Yes | 1 |
| 11 | 1 | No | 1 |
| 12 | 0 | Yes | 0 |
| 13 | 2 | No | 2 |
| 14 | 3 | Yes | 6 |
| 15 | 5 | No | 5 |
| 16 | 4 | Yes | 8 |

### Final Calculation

6 + 3 + 3 + 0 + 3 + 7 + 2 + 2 +
1 + 1 + 1 + 0 + 2 + 6 + 5 + 8 = 50

50 % 10 = 0

Result: LUHN CHECKSUM PASSES

### Explanation

The sum of all transformed digits is 50.
Because 50 is divisible by 10, the number
passes the Luhn checksum.

This only verifies the checksum. It does not
confirm that a payment card exists or is valid
for transactions.