#include <telnet.h>

inherit COMMAND_BASE;

mixed cmd(string str) {
  printf("%c%c%c", IAC, DO, TELOPT_NAWS);
  write("Okay, resizing your terminal...\n");
  return 1;
}

