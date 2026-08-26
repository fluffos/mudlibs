#include <mudlib.h>           
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("light", 1);
  set( "short", "The Petting Zoo." );
  set( "long", @ENDLONG
You are in a small petting zoo.
ENDLONG
  );
  set( "exits", ([
   "north" : "/d/Start/town/rooms/tssw",
    "south" : ROOMS(zoo4),
  ]) );
  set("objects", ([
    "zookeeper" : MON(zookeeper),
    "child" : MON(child),
    "monkey" : MON(monkey),
    "kitten" : MON(kitten),
  ]) );
  ::create();
}

