#include "tasks.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Counts the number of times pattern occurs in string
// Example: count("aybabtu", "bab") -> 1
// Example: count("aaaaaa", "aa") -> 5
int count(char *string, char *pattern) {
    int pattern_len = strlen(pattern);
    int string_len = strlen(string);
    int occurs = 1;
    int count = 0;
    for (int i = 0; i < string_len - pattern_len + 1; i++) {
        occurs = 1;
        for (int j = 0; j < pattern_len; j++) {
            if (string[i+j] != pattern[j]) {
                    occurs = 0;
                break;
            }
        }
        if (occurs) {
            count++;
        }
    }
    return count;
}

// Checks if string starts with prefix
// Example: starts_with("aybabtu", "ayb") -> 1
// Example: starts_with("aybabtu", "lol") -> 0
int starts_with(char *string, char *prefix) {
    int check = 1;
    for (int i = 0; i < strlen(prefix); i++) {
        if (string[i] != prefix[i]) {
            check = 0;
            break;
        }
    }
    return check;
}

// Checks if string ends with suffix
// Example: ends_with("aybabtu", "btu") -> 1
// Example: ends_with("aybabtu", "lol") -> 0
int ends_with(char *string, char *suffix) {
    int check = 1;
    int len_string = strlen(string);
    int len_suffix = strlen(suffix);
    if (len_string - len_suffix < 0) {
        return 0;
    }
    for (int i = 0; i < strlen(suffix); i++) {
        if (string[len_string - len_suffix + i] != suffix[i]) {
            check = 0;
            break;
        }
    }
    return check;
}

// Concatenates the strings in the array into a single string
// Example: {"apina", "banaani", "cembalo"} -> "apinabanaanicembalo"
char* concat(char **array, int n) {
    if (array == NULL || n <= 0) {
       char *empty = malloc(1); 
       if (empty) { empty[0] = '\0'; }
       return empty;
    }

    int total_len = 0; 
    for (int i = 0; i < n; i++) {
        if (array != NULL) {
            total_len += strlen(array[i]);
        }
    }

    char *result = malloc(total_len + 1);
    if (result == NULL) { return NULL; };
    result[0] = '\0';

    for (int i = 0; i < n; i++) {
        if (array[i] != NULL) {
            strcat(result, array[i]);
        }
    }
    return result;
}

// Returns the first position where pattern occurs in string
//   - If pattern doesn't occur in string, return -1
// Example: find("aybabtu", "bab") -> 2
// Example: find("aybabtu", "lol") -> -1
int find(char *string, char *pattern) {
    int len_string = strlen(string);
    int len_pattern = strlen(pattern);
    for (int i = 0; i < len_string - len_pattern + 1; i++) {
        if (!strncmp(string + i, pattern, len_pattern)) { 
            return i; 
        }
    }
    return -1;
}

// Creates a string that repeats pattern n times
// Example: repeat("abc", 4) -> "abcabcabcabc"
char* repeat(char *pattern, int n) {
    char *result = malloc(strlen(pattern) * n + 1);
    result[0] = '\0';
    for (int i = 0; i < n; i++) {
        strcat(result, pattern);
    }
    return result;
}

// Removes spaces around the string
// Example: trim(" aybabtu   ") -> "aybabtu"
char* trim(char *string) {
    // TODO
}

// Replaces characters a-z with A-Z in string
// Example: upper("aybabtu") -> "AYBABTU"
// Example: upper("AyBaBtU") -> "AYBABTU"
char* upper(char *string) {
    // TODO
}

// Replaces characters A-Z with a-z in string
// Example: upper("AYBABTU") -> "aybabtu"
// Example: upper("AyBaBtU") -> "aybabtu"
char* lower(char *string) {
    // TODO
}

// Returns a substring from the string
//   - Stop if the position goes past the end of the string
// Example: substr("aybabtu", 2, 3) -> "bab"
// Example: substr("aybabtu", 10, 3) -> ""
// Example: substr("aybabtu", 2, 10) -> "babtu"
char* substr(char *string, int start, int length) {
    // TODO
}

// Replaces all occurrences of old with new in string
//   - Don't replace an already replaced character
// Example: replace("aybabtu", "bab", "lol") -> "ayloltu"
// Example: replace("aa", "a", "aa") -> "aaaa"
char* replace(char *string, char *old, char *new) {
    // TODO
}

// Applies ROT13 transformation to string
//   - Rotate each letter (a-z and A-Z) 13 steps
//   - More information: https://en.wikipedia.org/wiki/ROT13
// Example: rot13("aybabtu") -> "nlonogh"
char* rot13(char *string) {
    // TODO
}

// Concatenates the strings into a single string using a delimiter
// Example: {"apina", "banaani", "cembalo"} '|' -> "apina|banaani|cembalo"
char* join(char **array, int n, char delimiter) {
    // TODO
}

// Splits the string into an array using a delimiter
//   - Return the array length
//   - Reserve memory for the array
// Example: "apina|banaani|cembalo" '|' -> {"apina", "banaani", "cembalo"}
int split(char* string, char delimiter, char*** array) {
    // TODO
}

// Sorts the given array of strings
//   - Use strcmp to compare the strings
// Example: {"all", "your", "base", "are", "belong", "to", "us"} ->
//          {"all", "are", "base", "belong", "to", "us", "your"}
void sort_strings(char **array, int n) {
    // TODO
}

#ifdef TEST_MODULE
void main() {
  char *parts[] = {"ayabtu", "aaa"};
  int result = find("aybabtu", "u");
  printf("%d\n", result);

  return;
}
#endif