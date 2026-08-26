// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM ;

void create() {
  seteuid(getuid()) ;
  set("author", "chronos");
  set("light", 1) ;
  set("short", "Constitution Avenue, Naval Station Norva.");
  set("long", @ENDLONG
You are on Constitution Avenue on Naval Station Norva.
The piers are to the north and the Port Operations parking lot 
is to the east.
ENDLONG
  );
  set("exits", ([
    "north" : ROOMS(base8),
    "south" : ROOMS(base6),
    "east"  : ROOMS(plot1),
  ]) ) ;
  ::create();
  reset();
}
