
#include <std.h>

inherit SENSE_CMD;

int cmd_smell(string str) {
  set_sense("smell");
  set_stealth(1);
  set_msg_failenvdef("You notice no interesting odors.");
  set_msg_failobdef("You don't smell anything from $O.");
  set_msg_toenvdef("$N smells around.");
  return ::cmd(str);
}

