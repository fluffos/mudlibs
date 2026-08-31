
#include <std.h>

inherit SENSE_CMD;

int cmd_taste(string str) {
  set_sense("taste");
  set_stealth(4);
  set_can_stealth_tgt(0);
  set_msg_toenvdef("$N tastes the air.");
  return ::cmd(str);
}

