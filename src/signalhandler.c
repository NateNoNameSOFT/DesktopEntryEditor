#include "../include/signalhandler.h"
void handle_exit(int signum) {
  if (signum == SIGINT) {
    puts("Recived Ctrl+C exiting...");
    exit(EXIT_SUCCESS);
  } else if (signum == SIGSEGV) {
    puts("Recived Segmentation Fault exiting...");
    exit(EXIT_FAILURE);
  }
}
