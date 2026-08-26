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
To the south lies the Enlisted Recreation Center.
ENDLONG
  );
  set("exits", ([
    "south" : ROOMS(rec_cen),
    "east"  : ROOMS(base26),
    "west" : ROOMS(base11),
  ]) ) ;
  ::create();
  reset();
}
