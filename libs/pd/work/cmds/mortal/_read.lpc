
#include <std.h>

inherit SENSE_CMD;

int cmd_read(string str) {
  set_sense("read");
  set_stealth(1);
  set_msg_failenv("You don't see that here.");
  set_msg_failob("You don't see that on $O.");
  set_msg_totgt("$N looks you over.");
  set_msg_toenvdef("");
  return ::cmd(str);
}

