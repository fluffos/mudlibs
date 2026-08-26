// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM ;

void create() {
  seteuid(getuid()) ;
  set("author", "chronos");
  set("light", 1) ;
  set("short", "Room 105.");
  set("long", @ENDLONG
A rather non-descript room in the BEQ, exactly the same as every other
room in here.  It's mostly concrete, with no windows or anything.
ENDLONG
  );
  set("item_desc", ([
  ]) ) ;
  set("exits", ([
    "north" : ROOMS(beq3),
  ]) ) ;
  set("objects", ([ 
     "sailor" : MON(beq_sailor),
   ]) ) ;
  ::create();
  reset();
}
