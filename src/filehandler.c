#include "../include/filehandler.h"

void file_remove(void) {
  size_t filename_size = 255;
  char *filename = xmalloc(filename_size * sizeof(char));

  puts("Which Desktop Entry Would You Like to Remove?");
  FLUSH_STDIN;
  getline(&filename, &filename_size, stdin);

  // resize memory
  filename = (char *)realloc(filename, sizeof(filename) + sizeof(DEPATH));
  char *tmp = xmalloc(sizeof(filename));
  strcpy(tmp, filename);

  // format tmp to filepath to desktop files
  sprintf(filename, "%s%s", DEPATH, tmp);
  free(tmp);

  DEBUG("FILENAME : %s\n", filename);
  if (remove(filename) < 0)
    puts("Could not remove file or file does not exist: continuing\n\n");
  free(filename);
  puts("\nDone!\n");
}

void file_new(void) {}

void file_edit(void) {}

void file_list(void) {
  char command[255] = {};
  sprintf(command, "%s%s", "ls -l ", DEPATH);
  system(command);

  WAIT_FOR_INPUT;
}
