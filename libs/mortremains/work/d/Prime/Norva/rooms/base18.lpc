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
A large brick building looms to the east.
ENDLONG
  );
  set("exits", ([
    "north" : ROOMS(base17),
    "south"  : ROOMS(base19),
    "east"  : ROOMS(admin),
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

void init() {
  add_action("go", "go");
}

int go(string str) {
  if (!str || str != "east") return 0 ;
   write("The doors are locked.\n") ;
  return 1;
  }
