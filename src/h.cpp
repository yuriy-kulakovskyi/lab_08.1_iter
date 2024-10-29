#include "../include/main.h"
#include <algorithm>


int Count(char* str) {
  if (strlen(str) < 4)
    return 0;

  int k = 0;
  for (int i = 0; str[i + 3] != 0; i++) {
    if (str[i] == str[i + 1] && str[i + 1] == str[i + 2] && str[i + 2] == str[i + 3])
      k++;
  }
  return k;
}

char* Change(char* str) {
  size_t len = strlen(str);
  if (len < 4)
    return str;

  char* tmp = new char[len * 2 + 1];
  char* t = tmp;
  tmp[0] = '\0';

  size_t i = 0;
  while (i < len) {
    if (str[i] == str[i + 1] && str[i + 1] == str[i + 2] && str[i + 2] == str[i + 3]) {
      strcat(t, "**");
      t += 2;
      i += 4;
    } else {
      *t++ = str[i++];
      *t = '\0';
    }
  }
  *t = '\0';
  strcpy(str, tmp);
  delete[] tmp;
  return str;
}