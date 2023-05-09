#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to count the frequency of each character in a given line
void count_chars(const char *line, int *char_freq) {
    for (int i = 0; line[i] != '\0'; i++) {
        if (isalpha(line[i])) {
            char_freq[tolower(line[i]) - 'a']++;
        }
    }
}

// Function to count the frequency of words with different lengths in a given line
void count_words(const char *line, int *word_freq) {
    char word[100];
    int i = 0, j = 0;

    while (line[i] != '\0') {
        if (isalpha(line[i])) {
            word[j++] = tolower(line[i]);
        } else if (j > 0) {
            word[j] = '\0';
            word_freq[strlen(word) - 1]++;
            j = 0;
        }
        i++;
    }

    if (j > 0) {
        word[j] = '\0';
        word_freq[strlen(word) - 1]++;
    }
}

int main() {
    char para[1000];
    memset(para, '\0', sizeof para);

    // Read the input text from a file, or create a file and store user input
    FILE *input = fopen("input.txt", "r");
    if (input == NULL) {
        FILE *input = fopen("input.txt", "w");
        printf("Enter paragraph: ");
        scanf("%[^\n]", para);
        fprintf(input, "%s", para);
        fclose(input);
    } else {
        fgets(para, sizeof para, input);
        fclose(input);
    }

    // Open the output file to write character frequencies
    FILE *output = fopen("char_frequency.csv", "w");
    if (!output) {
        perror("Error opening output file");
        return 1;
    }

    fprintf(output, "Line,Character,Frequency\n");

    int line_number = 0;

    // Process each line in the paragraph
    for (char *line = strtok(para, "."); line != NULL; line = strtok(NULL, ".")) {
        line_number++;

        int char_freq[26] = {0};
        int word_freq[100] = {0};

        // Call functions to count character and word frequencies
        count_chars(line, char_freq);
        count_words(line, word_freq);

        // Print and write character frequencies to the output file
        printf("Line %d character frequency:\n", line_number);
        for (int i = 0; i < 26; i++) {
            printf("%c: %d\n", 'a' + i, char_freq[i]);
            fprintf(output, "%d,%c,%d\n", line_number, 'a' + i, char_freq[i]);
        }

        // Print word frequencies
        printf("Line %d word frequency:\n", line_number);
        for (int i = 0; i < 100; i++) {
            if (word_freq[i] > 0) {
                printf("%d-letter words: %d\n", i + 1, word_freq[i]);
            }
        }
        printf("\n");
    }

    // Close the output file
    fclose(output);

    return 0;
}
