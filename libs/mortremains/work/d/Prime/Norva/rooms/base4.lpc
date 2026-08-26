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
The Electronics Training School lies to the east.
ENDLONG
  );
  set("exits", ([
    "north" : ROOMS(base3),
    "south" : ROOMS(base5),
    "east"  : ROOMS(school),
    "west"  : ROOMS(plot3),
  ]) ) ;
  ::create();
  reset();
}

void init() {
  add_action("go", "go") ;
}

int go(string str) {
  if (!str || str != "east") return 0 ;
   write("The Electronics Training School is closed right now.\n") ;
  return 1;
  }

void reset() {
   if (sizeof(children(MON(wander_sailor)))<7) {
      clone_object(MON(wander_sailor))->move(TO) ;
  }
  ::reset() ;
}

