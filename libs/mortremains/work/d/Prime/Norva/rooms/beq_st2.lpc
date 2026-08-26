// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM ;

void create() {
  seteuid(getuid()) ;
  set("author", "chronos");
  set("light", 1) ;
  set("short", "BEQ Stairwell - 2nd Floor.");
  set("long", @ENDLONG
You stand in a stairwell in the BEQ on the second floor.  It leads up from
here.
ENDLONG
  );
  set("item_desc", ([
  ]) ) ;
  set("exits", ([
    "up" : ROOMS(beq_st3),
    "down" : ROOMS(beq_st1),
    "south" : ROOMS(2beq1),
  ]) ) ;
  ::create();
  reset();
}
