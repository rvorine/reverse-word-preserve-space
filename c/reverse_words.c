#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Reverse words in a string while preserving the positions of spaces.
 *
 * Example:
 *   Input:  "Hello   World"
 *   Output: "World   Hello"
 */

/* Split s into words, store pointers in words[], return word count */
int split_words(const char *s, char **words, int max_words) {
    int count = 0;
    int len = strlen(s);
    int i = 0;

    while (i < len && count < max_words) {
        if (s[i] == ' ') {
            i++;
        } else {
            int j = i;
            while (j < len && s[j] != ' ') j++;
            int word_len = j - i;
            words[count] = (char *)malloc(word_len + 1);
            if (!words[count]) {
                for (int k = 0; k < count; k++) free(words[k]);
                return 0;
            }
            strncpy(words[count], s + i, word_len);
            words[count][word_len] = '\0';
            count++;
            i = j;
        }
    }
    return count;
}

void reverse_words_preserve_spaces(const char *s, char *result) {
    int len = strlen(s);
    char *words[256];
    int num_words = split_words(s, words, 256);

    int word_index = num_words - 1; /* reversed order */
    int i = 0, r = 0;

    while (i < len) {
        if (s[i] == ' ') {
            result[r++] = ' ';
            i++;
        } else {
            int j = i;
            while (j < len && s[j] != ' ') j++;
            /* place the reversed word */
            int wlen = strlen(words[word_index]);
            strncpy(result + r, words[word_index], wlen);
            r += wlen;
            word_index--;
            i = j;
        }
    }
    result[r] = '\0';

    for (int k = 0; k < num_words; k++) {
        free(words[k]);
    }
}

int main(void) {
    const char *test_cases[] = {
        "Hello World",
        "Hello   World",
        "  Hello   World  ",
        "a b   c",
        "one two three four"
    };
    int n = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < n; i++) {
        int buf_len = strlen(test_cases[i]) + 1;
        char *result = (char *)malloc(buf_len);
        if (!result) {
            fprintf(stderr, "malloc failed\n");
            return 1;
        }
        reverse_words_preserve_spaces(test_cases[i], result);
        printf("Input:  '%s'\n", test_cases[i]);
        printf("Output: '%s'\n\n", result);
        free(result);
    }

    return 0;
}
