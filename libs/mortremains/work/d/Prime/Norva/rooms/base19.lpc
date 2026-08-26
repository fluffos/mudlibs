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
Construction prevents you from going any further south on this road.
ENDLONG
  );
  set("exits", ([
    "north" : ROOMS(base18),
  
  ]) ) ;
  ::create();
  reset();
}
