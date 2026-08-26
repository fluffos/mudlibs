// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM ;

void create() {
  seteuid(getuid()) ;
  set("author", "chronos");
  set("light", 1) ;
  set("short", "Pacific Avenue, Naval Station Norva.");
  set("long", @ENDLONG
You are on Pacific Avenue on Naval Station Norva.
A very large, very expensive-looking house lies to the east.
ENDLONG
  );
  set("exits", ([
    "north" : ROOMS(base15),
    "south"  : ROOMS(base17),
    "east"  : ROOMS(co),
  ]) ) ;
  ::create();
  reset();
}
