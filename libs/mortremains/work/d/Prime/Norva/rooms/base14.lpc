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
The street continues to the east and west.
ENDLONG
  );
  set("exits", ([
    "east" : ROOMS(base15),
    "west" : ROOMS(base6),    
  ]) ) ;
  ::create();
  reset();
}
