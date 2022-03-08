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
      file_remove();
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
