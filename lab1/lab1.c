#include <stdio.h>  //for printf, getline
#include <stdlib.h> //for free, and malloc
#include <string.h> // For strtok_r

int main() {
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  printf("Please enter some text: ");
  read = getline(&line, &len, stdin);

  if (read == -1) {
    printf("Error reading input.\n");
    return 1; // exit if getline fails
  }

  char *token;
  char *saveptr;

  printf("Tokens:\n");
  token = strtok_r(line, " ", &saveptr);
  while (token != NULL) {
    printf(" %s\n", token);
    token = strtok_r(NULL, " ", &saveptr);
  }

  free(line);

  return 0;
}
