
#include <std.h>

inherit SENSE_CMD;

int cmd_touch(string str) {
  set_sense("touch");
  set_stealth(4);
  set_can_stealth_tgt(0);
  set_msg_failenv("You don't feel that here.");
  set_msg_failob("You don't feel that on $O.");
  set_msg_toenvdef("$N feels around.");
  set_msg_totgt("$N touches you.");
  set_msg_toenv("$N touches $I.");
  set_msg_toenvown("$N touches $P $R.");
  set_msg_toenvob("$N touches $O.");
  return ::cmd(str);
}

