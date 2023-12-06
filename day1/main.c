#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 200
#define MAX_LINES 1000

int readInput(const char *filename, char arr[MAX_LINES][MAX_LENGTH]) {
  FILE *file = fopen(filename, "r");
  char buffer[MAX_LENGTH];
  int idx = 0;
  while (fgets(buffer, MAX_LENGTH, file)) {
    strncpy(arr[idx], buffer, MAX_LENGTH);
    ++idx;
  }
  return idx;
}

int8_t isDigit(char c) { return c >= 48 && c <= 57; }

int twoDigitNumber(const char *s) {
  int high = strlen(s) - 2;
  int low = 0;
  char num[2];
  int flagLow = 0, flagHigh = 0;
  while (low <= high) {
    if (flagLow && flagHigh)
      break;
    if (!flagLow) {
      if (isDigit(s[low])) {
        num[0] = s[low];
        flagLow = 1;
      } else {
        low++;
      }
    }
    if (!flagHigh) {
      if (isDigit(s[high])) {
        num[1] = s[high];
        flagHigh = 1;
      } else {
        high--;
      }
    }
  }
  return atoi(num);
}

int main() {
  char inputArray[MAX_LINES][MAX_LENGTH];
  const int size = readInput("input", inputArray);
  int idx = 0;
  int sum = 0;
  while (idx < size) {
    sum += twoDigitNumber(inputArray[idx]);
    idx += 1;
  }
  printf("Sum is %d", sum);
  return 0;
}
