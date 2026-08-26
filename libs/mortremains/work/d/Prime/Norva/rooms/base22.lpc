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
You are at the end of Main Street on Naval Station Norva.
Saipan Avenue is to the north.
ENDLONG
  );
  set("exits", ([
    "north" : ROOMS(base23),
    "west" : ROOMS(base21),    
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
