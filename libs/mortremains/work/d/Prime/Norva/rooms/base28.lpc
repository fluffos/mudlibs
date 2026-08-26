// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM ;

void create() {
  seteuid(getuid()) ;
  set("author", "chronos");
  set("light", 1) ;
  set("short", "Atlantic Avenue, Naval Station Norva.");
  set("long", @ENDLONG
You are on Atlantic Avenue on Naval Station Norva.
Pier 4 lies to the north, and the street continues both east and west from here.
ENDLONG
  );
  set("exits", ([
    "north" : ROOMS(pier4-1),
    "east" : ROOMS(base29),
    "west" : ROOMS(base27),
  ]) ) ;
  ::create();
  reset();
}
