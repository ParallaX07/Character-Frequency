# Character and Word Frequency Analyzer

This C program reads a paragraph of text from a file or user input, and it calculates the frequency of each character and the frequency of words with different lengths for each line in the paragraph. The program writes the character frequency results to a CSV file and prints both character and word frequency results to the console.

## Features

- Read input text from a file or user input
- Analyze character frequency in each line of the paragraph
- Analyze word frequency with different lengths in each line
- Write character frequency results to a CSV file
- Print character and word frequency results to the console

## Usage

1. Ensure you have a C compiler installed (e.g., GCC or Visual Studio).
2. Compile the program using the C compiler.
3. Run the compiled program.
4. If there is no `input.txt` file, the program will prompt the user to enter a paragraph, which will then be stored in the `input.txt` file.
5. The program will analyze the character and word frequency of each line in the paragraph and write the character frequency results to a CSV file called `char_frequency.csv`.
6. The program will print the character and word frequency results to the console.

## Files

- `CharacterFrequency.c`: The main source code of the character and word frequency analyzer program.
- `input.txt`: The input text file containing the paragraph to analyze (created if it does not exist).
- `char_frequency.csv`: The output CSV file containing the character frequency results.
