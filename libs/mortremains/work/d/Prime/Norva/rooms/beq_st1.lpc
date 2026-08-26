// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM ;

void create() {
  seteuid(getuid()) ;
  set("author", "chronos");
  set("light", 1) ;
  set("short", "BEQ Stairwell - 1st Floor.");
  set("long", @ENDLONG
You stand in a stairwell in the BEQ on the first floor.  It leads up from
here.
ENDLONG
  );
  set("item_desc", ([
  ]) ) ;
  set("exits", ([
    "up" : ROOMS(beq_st2),
    "south" : ROOMS(beq1),
  ]) ) ;
  ::create();
  reset();
}
