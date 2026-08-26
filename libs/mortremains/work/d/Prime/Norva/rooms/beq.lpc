// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM ;

void create() {
  seteuid(getuid()) ;
  set("author", "chronos");
  set("light", 1) ;
  set("short", "The Bachelor Enlisted Quarters.");
  set("long", @ENDLONG
You stand at the front desk of what appears to be a shitty hotel,
but is in fact the Bachelor Enlisted Quarters for the enlisted
personnel stationed on this base.
ENDLONG
  );
  set("item_desc", ([
  ]) ) ;
  set("exits", ([
    "west" : ROOMS(base3),
    "east" : ROOMS(beq1),
  ]) ) ;
  ::create();
  reset();
}
