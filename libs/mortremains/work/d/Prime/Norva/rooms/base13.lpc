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
There are parking lots to the east and west.
The piers are to the north.
ENDLONG
  );
  set("exits", ([
    "north" : ROOMS(base12),
    "south" : ROOMS(base15),
    "east"  : ROOMS(plot2),  
    "west"  : ROOMS(plot1),  
  ]) ) ;
  ::create();
  reset();
}

void reset() {
   if (sizeof(children(MON(wander_sailor)))<7) {
      clone_object(MON(wander_sailor))->move(TO) ;
  }
  ::reset() ;
}

