#include "../include/common.h"
#include "../include/filehandler.h"
#include "../include/signalhandler.h"
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Operations
#define OPTION_AMOUNT 5

#define NEW '1'
#define EDIT '2'
#define REMOVE '3'
#define LIST '4'

int main(int argc, char *argv[]) {

  // TODO handle arguments instead of options
  // in arguments add quickicon option DEE -q /opt/app.appimage will create a
  // desktop entry named app the executes /opt/app.appimage

  char choice = '\0';
  signal(SIGINT, handle_exit);

  INIT_DEPATH;
  puts(DEPATH);

  if (argc > 1) {
    if (argv[1][0] == '-') {
      switch (argv[1][1]) {
      case 'n':

        break;
      case 'e':
        break;
      case 'r':
        file_remove(argv[2]);
        break;
      case 'l':
        file_list();
        break;
      }
      exit(EXIT_SUCCESS);
    } else {
      ERROR("Usage: DEE -option change\n");
    }
  }

  while (1) {
    choice = '\0';
    printf("Which Operation Would You Like to Perform?\n"
           "1. New Desktop Entry\n"
           "2. Edit Desktop Entry\n"
           "3. Remove Desktop Entry\n"
           "4. List Desktop Entrys\n");

    choice = getchar();

    DEBUG("USER ENTERED %c\n", choice);

    switch (choice) {
    case NEW:
      file_new();
      break;
    case EDIT:
      file_edit();
      break;
    case REMOVE:
      file_remove(NULL);
      break;
    case LIST:
      file_list();
      break;
    default:
      printf(CLEAR);

      puts("Invalid Option\n");

      break;
    }
    getchar();
  }

  return 0;
}
