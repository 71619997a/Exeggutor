#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
  printf("What would you like to do? ");
  char command[256];
  fgets(command, 256, stdin);
  char *after = command;
  char *words[128];
  int i = 0;
  while (i < 128) {
    words[i] = 0;
    i++;
  }
  i = 0;
  while (after) {
    //    printf("After: %s, ", after);
    words[i] = strsep(&after, " \n\t");
    //    printf("words[i]: %s\n", words[i]);
    i++;
  }
  words[i - 1] = 0;  // removing empty string at the end
  return execvp(words[0], words);
}
