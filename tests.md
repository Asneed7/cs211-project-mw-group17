# CS211 Project - Test Results
## MW Group 17

## Part A: 2048 Testing

Testing environment: Windows, VS Code, C++17

### Test 1: Starting the Game

- Input: Run the program.
- Expected result: The game should start with two randomly placed 2 tiles on a 5x5 board. The score and move count should both be 0.
- Actual result: When I started the game, two 2 tiles appeared in different spots. The score and move count were both 0, and the highest tile was 2.
- Status: PASS

### Test 2: Three Equal Tiles

- Starting row: 2 2 2 0 0
- All other rows are empty.
- Starting score: 0
- Starting move count: 0
- Input: l (move left)
- Expected result: The row should become 4 2 0 0 0 before a new random 2 is added. The score should increase to 4.
- Actual result: The first two tiles merged into a 4, and the third tile stayed a 2. A new random 2 appeared, the score was 4, and the move count was 1.
- Status: PASS

### Test 3: Four Equal Tiles

- Starting row: 2 2 2 2 0
- All other rows are empty.
- Starting score: 0
- Starting move count: 0
- Input: l (move left)
- Expected result: The row should become 4 4 0 0 0 before a new random 2 is added. The two 4 tiles should not merge again.
- Actual result: I got two separate 4 tiles and one new random 2. The score increased to 8, and the move count increased to 1.
- Status: PASS
### Test 4: Making Sure Tiles Only Merge Once

- Starting row: 2 2 4 0 0
- All other rows are empty.
- Starting score: 0
- Starting move count: 0
- Input: l (move left)
- Expected result: The row should become 4 4 0 0 0 before a new random 2 is added. The two 4 tiles should not merge into an 8.
- Actual result: I got two separate 4 tiles and a new random 2. The score was 4, and the move count was 1.
- Status: PASS

### Test 5: Moving Without Changing the Board

- Starting row: 2 4 8 0 0
- All other rows are empty.
- Starting score: 0
- Starting move count: 0
- Input: l (move left)
- Expected result: Nothing should change because the tiles are already as far left as they can go and none of them match.
- Actual result: The board stayed exactly the same. No new tile appeared, the score and move count stayed at 0, and the highest tile stayed at 8.
- Status: PASS

### Test 6: Full Board With a Possible Move

Starting board:

```
2 2 8 4 2
4 8 4 2 4
2 4 8 4 2
4 8 4 2 4
2 4 8 4 2
```

- Starting score: 0
- Starting move count: 0
- Input: l (move left)
- Expected result: The game should not end because the first two tiles can still merge. The first row should become 4 8 4 2 0 before a new 2 is added.
- Actual result: The game allowed me to move left. The first row became 4 8 4 2 2, and the other rows stayed the same. The score was 4, and the move count was 1.
- Status: PASS
### Test 7: Game Over

Starting board:

```
2 4 2 4 2
4 2 4 2 4
2 4 2 4 2
4 2 4 2 4
2 4 2 4 2
```

- Starting score: 100
- Starting move count: 20
- Input: Load the board and try moving left.
- Expected result: A game over message should appear because the board is full and none of the tiles can merge.
- Actual result: The game over message appeared, and I was not able to move left. The board, score, and move count stayed the same. I was still able to use the other commands.
- Status: PASS

### Test 8: Reaching 2048

- Starting row: 1024 1024 0 0 0
- All other rows are empty.
- Starting score: 0
- Starting move count: 0
- Input: l (move left)
- Expected result: The two 1024 tiles should merge into a 2048 tile before a new random 2 is added. A congratulations message should appear, but the game should let me keep playing.
- Actual result: The tiles merged into 2048, and a new 2 appeared. The score was 2048, and the move count was 1. The congratulations message appeared, and I was able to continue playing.
- Status: PASS

### Test 9: Saving and Loading the Game

Starting board:

4 4 0 0 0
0 0 0 0 0
2 0 0 0 0
0 0 0 0 0
0 0 0 0 0
```

- Starting score: 8
- Starting move count: 3
- Input: s (save), l (move left), and o (load)
- Expected result: The two 4 tiles should merge into an 8 before a new random 2 is added. When I load the saved game, everything should go back to how it was before I moved left.
- Actual result: The two 4 tiles merged into an 8, and a new 2 appeared in row 2, column 5. My score increased to 16, and my move count increased to 4.

Board after moving left and adding the new 2:

8 0 0 0 0
0 0 0 0 2
2 0 0 0 0
0 0 0 0 0
0 0 0 0 0

After loading the saved game, my board went back to the original starting board. My score went back to 8, my move count went back to 3, and no extra tile was added.

- Status: PASS
### Test 10: Invalid Save File Version

- Input: Change the version in savegame.txt to WRONG_VERSION and enter o (load).
- Expected result: The game should reject the save file and keep my current board, score, and move count the same.
- Actual result: An error message appeared, and the game did not load the invalid save file. Nothing on my current game changed.
- Status: PASS

### Test 11: Missing Save File

Starting board:

4 4 0 0 0
0 0 0 0 0
2 0 0 0 0
0 0 0 0 0
0 0 0 0 0

- Starting score: 8
- Starting move count: 3
- Input: Rename savegame.txt and enter o (load).
- Expected result: An error message should appear because the save file is missing. My current game should stay the same.
- Actual result: I got an error message saying the game could not open savegame.txt. My board stayed the same, my score stayed at 8, and my move count stayed at 3.
- Status: PASS

### Test 12: Invalid Tile Value

Starting board:

4 4 0 0 0
0 0 0 0 0
2 0 0 0 0
0 0 0 0 0
0 0 0 0 0

- Starting score: 8
- Starting move count: 3
- Input: Change the second 4 in savegame.txt to a 3 and enter o (load).
- Expected result: The game should reject the save file because 3 is not a power of two. My current game should stay the same.
- Actual result: I got an error message saying the save file was invalid. My board stayed the same, my score stayed at 8, and my move count stayed at 3.
- Status: PASS

### Test 13: Incomplete Save File

Starting board:

4 4 0 0 0
0 0 0 0 0
2 0 0 0 0
0 0 0 0 0
0 0 0 0 0

- Starting score: 8
- Starting move count: 3
- Input: Remove the last two rows from savegame.txt and enter o (load).
- Expected result: The game should reject the save file because part of the board is missing. My current game should stay the same.
- Actual result: I got an error message saying the save file was invalid. My board stayed the same, my score stayed at 8, and my move count stayed at 3.
- Status: PASS

### Test 14: Moving Right

- Starting row: 2 0 2 0 2
- All other rows are empty.
- Starting score: 0
- Starting move count: 0
- Input: r (move right)
- Expected result: The tiles should slide through the empty spaces and merge. The row should become 0 0 0 2 4 before a new random 2 is added.
- Actual result: The tiles moved to the right and the last two merged into a 4. A new 2 appeared in row 4, column 5. My score increased to 4, and my move count increased to 1.
- Status: PASS

### Test 15: Moving Up

- Starting column: 2 0 2 0 2
- All other columns are empty.
- Starting score: 0
- Starting move count: 0
- Input: u (move up)
- Expected result: The tiles should slide up through the empty spaces and merge. The first column should become 4 2 0 0 0 from top to bottom before a new random 2 is added.
- Actual result: The tiles moved up, and the first two merged into a 4. The remaining 2 stayed below the 4, and a new 2 appeared in row 4, column 5. My score increased to 4, and my move count increased to 1.
- Status: PASS

### Test 16: Moving Down

- Starting column: 2 0 2 0 2
- All other columns are empty.
- Starting score: 0
- Starting move count: 0
- Input: d (move down)
- Expected result: The tiles should slide down through the empty spaces and merge. The first column should become 0 0 0 2 4 from top to bottom before a new random 2 is added.
- Actual result: The tiles moved down, and the bottom two merged into a 4. The remaining 2 stayed above the 4, and a new 2 appeared in row 1, column 3. My score increased to 4, and my move count increased to 1.
- Status: PASS

## Test 17: Moving Without Merging

- Before: The first row was 0 2 0 4 8. The rest of the board was empty. Score and moves were both 0.
- Input: l
- Expected: The tiles should move to the left without merging. The score should stay at 0, the moves should increase to 1, and a new 2 should appear.
- Actual: The first row became 2 4 8 0 0. A new 2 appeared in row 3, column 3. The score stayed at 0, moves increased to 1, and the highest tile was 8.
- Result: Pass

## Test 18: No Double Merging

- Before: The first row was 2 2 4 0 0. The rest of the board was empty. Score and moves were both 0.
- Input: l
- Expected: The two 2s should merge into a 4, but the two 4s should not merge again. The score should increase to 4, moves should increase to 1, and a new 2 should appear.
- Actual: The first row became 4 4 0 0 0. A new 2 appeared in row 5, column 4. The score was 4, moves was 1, and the highest tile was 4.
- Result: Pass
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
