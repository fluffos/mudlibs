
#include <std.h>

inherit SENSE_CMD;

int cmd_search(string str) {
  set_sense("search");
  set_separators( ({ "on", "of", "in" }) );
  set_can_stealth_tgt(0);
  set_stealth(3);
  set_msg_failenvdef("You find nothing odd.");
  set_msg_failenv("You find nothing odd.");
  set_msg_failobdef("You find nothing odd about $O.");
  set_msg_failob("You find nothing odd $S $O.");
  set_msg_totgt("$N searches about you.");
  set_msg_toenvdef("$N searches around.");
  set_msg_toenv("$N searches $I.");
  set_msg_toenvown("$N searches $P $R.");
  set_msg_toenvob("$N searches $O.");
  return ::cmd(str);
}

