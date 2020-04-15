# Test file for "lab2_part4"


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n

# Example test:
test "PINA: 0x00, PINB: 0x00, PINC: 0x00 => PORTD ** testing to see all 0's"
# Set inputs
setPINA 0x00
setPINB 0x00
setPINC 0x00
# Continue for several ticks
continue 1
# Set expect values
expectPORTD 0
# Check pass/fail
checkResult

# Add tests below
test "PINA: 100, PINB: 100, PINC: 100 => PORTD ** testing balanced car GREATER than 140"
setPINA 100
setPINB 100
setPINC 100
continue 1
expectPORTD 301
checkResult

test "PINA: 20, PINB 30, PINC 50 ** testing balanced car, less than 140"
setPINA 20
setPINB 30
setPINC 50
continue 1
expectPORTD 100
checkResult

test "PINA: 20, PINB 30, PINC 90 ** testing a balanced car, where total IS 140"
  setPINA 20                                                                                              setPINB 30                                                                                              setPINC 90                                                                                              continue 1                                                                                              expectPORTD 140                                                                                         checkResult

test "PINA: 30, PINB: 100, PINC: 120 ** testing an unbalanced car exceeding 140"
setPINA 30
setPINB 100
setPINC 120
continue 1
expectPORTD 253
checkResult
# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
