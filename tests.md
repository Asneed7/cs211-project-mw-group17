# CS211 Group Project — Test Results
## Part B: Luhn Checksum Validation

## Luhn Test Results

| Test | Input | Expected Result | Actual Result | Status |
|---|---|---|---|---|
| 1 | 4532015112830366 | Checksum passes | Checksum passes | PASS |
| 2 | 4532015112830367 | Checksum fails | Checksum fails | PASS |
| 3 | 0000000000000018 | Checksum passes | Checksum passes | PASS |
| 4 | 453201511283036 | Reject 15 digits | Invalid input | PASS |
| 5 | 45320151128303666 | Reject 17 digits | Invalid input | PASS |
| 6 | 453201511283036X | Reject non-digit | Invalid input | PASS |
| 7 | 4532 015112830366 | Reject internal space | Invalid input | PASS |
| 8 | Multiple checks in one session | Continue prompting | Continued prompting | PASS |
| 9 | q | Exit program | Goodbye! | PASS |


## Testing Summary

The Luhn Validation program successfully completed
all nine recorded tests.

The program accepts exactly 16 numeric digits,
preserves leading zeros, and calculates the
Luhn checksum correctly.

Inputs containing letters, spaces, or incorrect
lengths are rejected.

The program allows multiple checks without
restarting and exits cleanly when the user
enters Q or q.

## Build Command

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic luhn/main.cpp luhn/luhn.cpp -o luhn_app.exe
```

## Run Command (Windows PowerShell)

```powershell
.\luhn_app.exe
```

## Remaining Project Testing

Part A (2048 game) test results will be added
after integration and verification by the group.