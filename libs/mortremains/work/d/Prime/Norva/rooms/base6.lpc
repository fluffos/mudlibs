// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM ;

void create() {
  seteuid(getuid()) ;
  set("author", "chronos");
  set("light", 1) ;
  set("short", "Main Street, Naval Station Norva.");
  set("long", @ENDLONG
You are on the main street on Naval Station Norva.
To the north is Constitution Street, and Main Street continues to the east and west.
ENDLONG
  );
  set("exits", ([
    "north" : ROOMS(base7),    
    "east" : ROOMS(base14),
    "west" : ROOMS(base1),    
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

