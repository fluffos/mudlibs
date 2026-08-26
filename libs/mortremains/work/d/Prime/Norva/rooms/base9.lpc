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
Constitution Street heads south from here, and Pier 1 is to the north.
ENDLONG
  );
  set("exits", ([
    "north" : ROOMS(pier1-1),
    "south" : ROOMS(base8),
    "east"  : ROOMS(base10),
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
