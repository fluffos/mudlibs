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
There are piers to the east and west on this street.
ENDLONG
  );
  set("exits", ([
    "east" : ROOMS(base28),
    "west" : ROOMS(base26),
  ]) ) ;
  ::create();
  reset();
}
