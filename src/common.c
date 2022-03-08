
#include "../include/common.h"

char *DEPATH = NULL;

void *xcalloc(size_t multiplier, size_t size) {
  void *result = calloc(multiplier, size);
  if (result == NULL)
    ERROR("error: unable to allocate memory!");
  return result;
}

void *xmalloc(size_t size) {
  void *result = malloc(size);
  if (result == NULL)
    ERROR("error: unable to allocate memory!");
  return result;
}

bool yes_or_no(char ch) {
  switch (ch) {
  case '\n':
  case 'Y':
  case 'y':
    return true;
  case 'N':
  case 'n':
    return false;
  default:
    return false;
  }
}
