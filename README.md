# Collatz conjecture test in C

A program written in C that tests the Collatz conjecture. It uses Intel's RDRAND instruction to generate a random number. In case RDRAND is not supported, the program utilizes the classic rand() function. 

## How to compile

You can compile the program with either GCC 4.6+ or Clang 3.2+ with the `-mrdrnd` flag.
