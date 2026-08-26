// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM ;

void create() {
  seteuid(getuid()) ;
  set("author", "chronos");
  set("light", 1) ;
  set("short", "Room 201.");
  set("long", @ENDLONG
A rather non-descript room in the BEQ, exactly the same as every other
room in here.  It's mostly concrete, with no windows or anything.
ENDLONG
  );
  set("item_desc", ([
  ]) ) ;
  set("exits", ([
    "north" : ROOMS(2beq1),
  ]) ) ;
set("objects", ([
   MON(beq_sailor) : random(2)+1,
 ]) ) ; 
  ::create();
  reset();
}
