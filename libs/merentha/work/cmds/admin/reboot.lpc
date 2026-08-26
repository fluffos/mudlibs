// Petrarch
// Merentha Lib 1.0
// <shutdown>

#include <daemons.h>

varargs int command(int i) {
  REBOOT_D->reboot((i?to_int(i):10));
  return 1;
}

string help() {
  return "Syntax: reboot [minutes]\n\nStarts the reboot sequence for the number of minutes entered.  If no time is entered the default 10 minute countdown is issued.";
}
