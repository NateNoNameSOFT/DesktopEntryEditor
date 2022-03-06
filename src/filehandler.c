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

void file_new(void) {
  FILE *fp = NULL;
  size_t buf_size = 255;
  char *filename = xmalloc(buf_size * sizeof(char));
  char *buf = NULL;
  char random[4] = {};

  // generate random 3 character string so we dont accidently edit a file
  // instead of create a new one
  srand(time(NULL));
  random[0] = 'A' + rand() % 26;
  random[1] = 'A' + rand() % 26;
  random[2] = 'A' + rand() % 26;
  random[3] = '\0';

  printf("--Creating New Desktop Entry--\n\n");
  printf("What would you like this desktop entry to be named?\n");

  FLUSH_STDIN;

  getline(&filename, &buf_size, stdin);
  REMOVE_NEWLINE(filename);

  buf = xmalloc(sizeof(filename));
  strcpy(buf, filename);

  // resize memory
  filename = (char *)realloc(filename, sizeof(filename) + sizeof(DEPATH) +
                                           sizeof(random) + sizeof(".desktop"));
  DEBUG("FILENAME BUF RESIZED TO: %li\n", sizeof(filename) + sizeof(DEPATH) +
                                              sizeof(random) +
                                              sizeof(".desktop"));

  char *tmp = xmalloc(sizeof(filename));
  strcpy(tmp, filename);

  sprintf(filename, "%s%s%s%s", DEPATH, tmp, random, ".desktop");
  free(tmp);

  DEBUG("FILENAME: %s\n", filename);
  DEBUG("BUF: %s\n", buf);

  if (!(fp = fopen(filename, "w+")))
    ERROR("Could not open new desktop entry file\n");

  free(filename);

  fputs("[Desktop Entry]\n", fp);

  fprintf(fp, "%s%s%s", "Name=", buf, "\n");

  free(buf);

  printf("What would you like this desktop entry to execute?\n");

  buf = xmalloc(buf_size * sizeof(char));

  getline(&buf, &buf_size, stdin);
  REMOVE_NEWLINE(buf);

  DEBUG("BUF MEMORY RESIZED TO: %li\n", sizeof(buf));

  // pack memory
  buf = realloc(buf, sizeof(buf));

  fprintf(fp, "%s%s%s", "Exec=", buf, "\n");

  printf("What would you like this desktop entrys icon (path) to be?\n");

  printf("\n--Additional Options--\n");
}

void file_edit(void) {}

void file_list(void) {
  char command[255] = {};
  sprintf(command, "%s%s", "ls -l ", DEPATH);
  system(command);

  FLUSH_STDIN;
}
