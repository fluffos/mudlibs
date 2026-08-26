// (??-??-95) Written by Chronos to trans wizards to the player start.
// (04-06-98) Chronos added a help() function.
#include <mudlib.h>
#include <config.h>

int cmd_start() {
  if (file_name(environment(TP)) == START) {
   write("You are already here!\n");
  return 1;
  }
  TP->move_player(START, TP->query_mmout()+"\n") ;
  return 1;
}

string help() {
  return @END
Usage: start

Transports you to the player starting room.

See also: goto, return, wizhall, home
END
;
}
