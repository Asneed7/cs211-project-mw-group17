# Luhn Validation Flowchart

1. Start the program.
2. Display the welcome message.
3. Ask the user for a 16-digit number or Q to quit.
4. If input ends, exit cleanly.
5. If the user enters Q or q, display Goodbye and exit.
6. Otherwise, validate the input format.
7. If input is not exactly 16 numeric digits,
display an error and request another input.
8. If input is valid, calculate the Luhn checksum.
9. Starting from the rightmost digit, double
every second digit.
10. If a doubled value is greater than 9,
subtract 9.
11. Add all transformed digits.
12. If the sum is divisible by 10,
display "Luhn checksum PASSES!"
13. Otherwise, display "Luhn checksum FAILS!"
14. Return to the input prompt and repeat.

## Function Workflow

main()
- Reads input using getline()
- Checks for Q or q
- Calls validInput()
- Calls checkLuhn() for correctly formatted input
- Displays the result and repeats

validInput()
- Checks input length is exactly 16
- Checks every character is a digit
- Returns true or false

checkLuhn()
- Processes digits from right to left
- Doubles alternating digits
- Subtracts 9 from doubled values greater than 9
- Calculates the total sum
- Returns whether sum % 10 equals 0

## Luhn Program Flowchart

```mermaid
flowchart TD
A([Start]) --> B[Display welcome message]
B --> C[Read user input]
C --> D{Input ended?}
D -- Yes --> E([Exit])
D -- No --> F{Q or q?}
F -- Yes --> G[Display Goodbye]
G --> E
F -- No --> H{Exactly 16 digits?}
H -- No --> I[Display invalid input]
I --> C
H -- Yes --> J[Calculate Luhn checksum]
J --> K{Sum divisible by 10?}
K -- Yes --> L[Display PASSES]
K -- No --> M[Display FAILS]
L --> C
M --> C
```


## Luhn Function Workflow Diagram

```mermaid
flowchart TD
A["main()"] --> B["Read input with getline()"]
B --> C{"Input ended or Q/q?"}
C -- Yes --> D["Exit program"]
C -- No --> E["Call validInput()"]
E --> F{"Valid format?"}
F -- No --> G["Display invalid input"]
G --> B
F -- Yes --> H["Call checkLuhn()"]
H --> I["Double alternating digits and sum"]
I --> J{"Checksum divisible by 10?"}
J -- Yes --> K["Return true"]
J -- No --> L["Return false"]
K --> M["main() displays PASSES"]
L --> N["main() displays FAILS"]
M --> B
N --> B
```