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
The Base Galley is to the west.
ENDLONG
  );
  set("exits", ([
    "north" : ROOMS(base1),
    "south" : ROOMS(base3),
    "west"  : ROOMS(galley),
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

