#include "tasks.h"
#include <stdio.h>
#include <string.h>

// Calculates the area of a rectangle
// Example: calc_area(2, 3) -> 6
long calc_area(int width, int height) {
  long area = (long)width * (long)height;
  return area;
}

// Checks if an integer is odd
// Example: is_odd(5) -> 1
// Example: is_odd(6) -> 0
int is_odd(int n) {
  return (n % 2 == 1 || n % 2 == -1);
}

// Counts the sum of integers between 1 and n
// Example: range_sum(5) -> 15
long range_sum(int n) {
  long sum = 0;
  for (int i = 0; i < n; i++) {
    sum += i + 1;
  }
  return sum;
}

// Counts the sum of squares between 1 and n
// Example: squared_sum(5) -> 55
long squared_sum(int n) {
  long sum = 0;
  for (long i = 1; i < n + 1; i++) {
    sum += i * i;
  }
  return sum;
}

// Divides n apples evenly for two persons
// Example: divide_apples(5) -> 2.5
// Example: divide_apples(6) -> 3
double divide_apples(int n) {
  return (double)n / 2;
}

// Calculates rectangle area and perimeter
//   - Results are returned through pointers
// Example: analyze_rectangle(3, 4, &area, &perimeter)
//   - area -> 12
//   - perimeter -> 14
void analyze_rectangle(int width, int height, long *area, long *perimeter) {
  *area = (long)width * (long)height;
  *perimeter = (long)width * 2 + (long)height * 2;
}

// Counts the steps in the following process:
//   - If n is even, divide it by two
//   - If n is odd, subtract one
//   - If n is zero, stop
// Example: count_steps(10) -> 5 (10 -> 5 -> 4 -> 2 -> 1 -> 0)
int count_steps(int n) {
  int steps = 1;
  while(1) {
    if (n % 2 == 1) {
      n -= 1;
    } else {
      n /= 2;
    }
    if (n <= 0) { break; }
    steps += 1;
  }
  return steps;
}

// Returns the week day name in English
//   - day is between 1 and 7
// Example: week_day_name(1) -> "Monday"
// Example: week_day_name(2) -> "Tuesday"
char* week_day_name(int day) {
  switch (day) {
    case 1:
      return "Monday";
    case 2:
      return "Tuesday";
    case 3: 
      return "Wednesday";
    case 4:
      return "Thursday";
    case 5:
      return "Friday";
    case 6:
      return "Saturday";
    case 7:
      return "Sunday";
  }
}

// Counts the number of digits in the given integer
//   - You can assume that n is nonnegative
// Example: digit_count(123) -> 3
int digit_count(int n) {
  double x = n;
  int count = 0;
  if (n == 0) { return 1; };
  while (x >= 1) {
    x /= 10;
    count += 1;
  }
  return count;
}

// Calculates the Manhattan distance between two positions
//   - Formula: |x1 - x2| + |y1 - y2| where |...| is absolute value
// Example: p1 = {2, 3}, p2 = {1, 5} -> |2 - 1| + |3 - 5| = 3
int abs_sub(int a, int b) {
  int result = a - b;
  if ( result < 0 ) {
    return result * -1;
  } else {
    return result;
  }
}

int manhattan_distance(struct Position p1, struct Position p2) {
  return abs_sub(p1.x, p2.x) + abs_sub(p1.y, p2.y);
}

// Calculates the sum of two fractions
//   - Return the result in simplest form
// Example: f1 = {1, 4}, f2 = {1, 12} -> {1, 3}
struct Fraction {
    int a, b;
};

int abs(int a) {
  if (a < 0) {
    return -a;
  } else {
    return a;
  }
}

int find_gcd(int a, int b) {
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return abs(a);
}

struct Fraction simplify_fraction(struct Fraction f) {
  int gcd = find_gcd(f.a, f.b);
  f.a /= gcd;
  f.b /= gcd;

  if (f.b < 0) {
    f.a = -f.a;
    f.b = -f.b;
  }
  return f;
}

struct Fraction fraction_sum(struct Fraction f1, struct Fraction f2) {
  struct Fraction result;

  result.a = (f1.a * f2.b) + (f2.a * f1.b);
  result.b = (f1.b * f2.b);

  return simplify_fraction(result);
}

// Counts the number of even numbers in the array
// Example: {2, 1, 2, 4, 5} -> 3
int array_even_count(int *array, int n) {
  int count = 0;
  for (int i; i < n; i++) {
    if (array[i] % 2 == 0) {
      count += 1;
    }
  }
  return count;
}

// Finds the minimum value in the array
// Example: {2, 1, 2, 4, 5} -> 1
int array_min_value(int *array, int n) {
  int min = array[0];
  for (int i = 1; i < n; i++) {
    if (array[i] < min) {
      min = array[i];
    }
  }
  return min;
}

// Checks if the given array is sorted
// Example: {1, 3, 2, 4} -> 0
// Example: {1, 2, 2, 5} -> 1
int array_is_sorted(int *array, int n) {
  for (int i; i < n - 1; i++) {
    if (array[i] > array[i + 1]) {
      return 0;
    }
  }
  return 1;
}

// Converts all array values to absolute values
// Example: {1, -1, -5, 0} -> {1, 1, 5, 0}
void convert_array(int *array, int n) {
  for (int i; i < n ; i++) {
    if (array[i] < 0) {
      array[i] *= -1; 
    }
  }
}

// Counts the number of distinct values in the array
// Example: {1, 2, 1, 5, 2} -> 3
int array_distinct_count(int *array, int n) {
  int distinct_values[n];
  distinct_values[0] = array[0];
  int count = 1;
  int appears = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < count; j++) {
      if (array[i] == distinct_values[j]) {
        appears = 1;
        break;
      }
    }
    if (appears == 0) {
      distinct_values[count] = array[i];
      count += 1;
    }
    appears = 0;
  }
  return count; 
}

// Counts the number of times a letter appears in a string
// Example: count_letters("aybabtu", 'a') -> 2
int count_letters(char *string, char letter) {
  int count = 0;
  int str_len = strlen(string);
  for (int i = 0; i < str_len; i++) {
    if (string[i] ==  letter) {
      count++;
    }
  }
  return count;
}

// Counts the number of words in the given string
//   - Each word consists of letters a..z
//   - There is a single space between each consecutive words
// Example: count_words("all your base") -> 3
int count_words(char *words) {
  int count = 0;
  int str_len = strlen(words);
  int is_word = 1;
  char *p = words;
  for (int i = 0; i < str_len; i++) {
    if (p[i] == ' ') {
      if (is_word) {
        count++;
      }
      is_word = 1;
    } else if (!((p[i] >= 'a' && p[i] <= 'z') || (p[i] >= 'A' && p[i] <= 'Z'))) {
      is_word = 0;
    }
  }
  if (is_word) {
    count++;
  }
  return count;
}

// Finds the maximum word length in the given string
//   - Each word consists of letters a..z
//   - There is a single space between each consecutive words
// Example: count_words("all your base") -> 4
int max_word_length(char *words) {
    // TODO
}

// Checks if the given word is a palindrome
//   - The word consists of letters a..z
// Example: is_palindrome("abba") -> 1
// Example: is_palindrome("abca") -> 0
int is_palindrome(char *word) {
    // TODO
}

// Counts the number of times any letter appears in a string
// Example: count_letters("aybabtu", "au") -> 3
int count_letters_set(char *string, char *letters) {
    // TODO
}

// Checks if two words are anagrams of each other
//   - The words consist of letters a..z
// Example: check_anagrams("abca", "aacb") -> 1
// Example: check_anagrams("abca", "abcb") -> 0
int check_anagrams(char *word1, char *word2) {
    // TODO
}

// Checks a University of Helsinki student number
//   - The number consists of nine digits 0-9 and the first digit is 0
//   - The last digit is a checksum calculated from other digits
//   - The checksum is calculated as a sum using the weights {3,7,1,3,7,1,3,7}
//   - If the result is divisible by 10, the checksum is 0
//   - Otherwise the checksum is the distance to the next multiple of ten
// Example: consider 012749139
//   - The format of the number is correct (nine digits, first digit 0)
//   - Let's calculate the checksum: 3*0+7*1+1*2+3*7+7*4+1*9+3*1+7*3 = 91
//   - The distance to the next multiple of ten is 9
//   - The checksum matches the last digit, so the number is valid
int valid_student_number(char *number) {
    // TODO
}

#ifdef TEST_MODULE
void main() {
  char str[] = "is a word";
  int result = count_words(str);
  printf("%d\n", result);

  return;
}
#endif