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
The piers are to the north and Port Operations is to the east.
ENDLONG
  );
  set("exits", ([
    "north" : ROOMS(base9),
    "south" : ROOMS(base7),
    "east"  : ROOMS(portops),
  ]) ) ;
  ::create();
  reset();
}
