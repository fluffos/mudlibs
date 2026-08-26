// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM ;

void create() {
  seteuid(getuid()) ;
  set("author", "chronos");
  set("light", 1) ;
  set("short", "Saipan Avenue, Naval Station Norva.");
  set("long", @ENDLONG
You are on Saipan Avenue on Naval Station Norva.
The piers are to the north.
ENDLONG
  );
  set("exits", ([
    "north" : ROOMS(base26),
    "south" : ROOMS(base23),    

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

