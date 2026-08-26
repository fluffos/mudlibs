
// Coded by Chronos.
#include <mudlib.h>
#include <daemons.h>
#include "../defs.h"

inherit ROOM ;

void create() {
  seteuid(getuid()) ;
  set("author", "chronos");
  set("light", 1) ;
  set("short", "Port Operations.");
  set("long", @ENDLONG
You stand in a large office in the Port Operations building on Naval Station
Norva.  There is a dry erase board behind a counter here.
You see a clerk busy doing some paperwork behind the counter.
ENDLONG
  );
  set("item_desc", ([
    "clerk" : "It's an older guy with a large mustache.\n",
  ]) ) ;
  set("item_func", ([
    "board" : "read_board",
    "dry erase board" : "read_board",
  ]) ) ;
  set("exits", ([
    "north" : ROOMS(base10),
    "west" : ROOMS(base8),
   ]) ) ;
  ::create();
  reset();
}

void init() {
  add_action("read_board", "read") ;
}

int read_board(string str) {
  if (str && str != "board" && str != "dry erase board") return 0 ;
  write(@ENDSIGN
You carefully examine the dry erase board.  It seems to be a ship schedule.

Ship Name            Current Location         Next Scheduled Port
-----------------------------------------------------------------------------
ENDSIGN
  );
  write(
  SHIP_D->schedule_info() 
  ) ;
  say(TPN+" carefully examines the dry erase board.\n");
  return 1;
}
