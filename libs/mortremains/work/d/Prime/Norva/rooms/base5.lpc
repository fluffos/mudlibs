// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM ;

void create() {
  seteuid(getuid()) ;
  set("author", "chronos");
  set("light", 1) ;
  set("short", "Independence Avenue, Naval Station Norva.");
  set("long", @ENDLONG
You are on Independence Avenue on Naval Station Norva.
A parking lot lies to the west, and the Base Gym is to the east.
To the south is a large track.
ENDLONG
  );
  set("exits", ([
    "north" : ROOMS(base4),
    "south" : ROOMS(track2),
    "east"  : ROOMS(gym),
    "west"  : ROOMS(plot4),
  ]) ) ;
  ::create();
  reset();
}
