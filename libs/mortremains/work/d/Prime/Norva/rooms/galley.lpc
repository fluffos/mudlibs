// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM ;

void create() {
  seteuid(getuid()) ;
  set("author", "chronos");
  set("light", 1) ;
  set("short", "The Galley.");
  set("long", @ENDLONG
You stand in the Galley, where all the squids eat.
ENDLONG
  );
  set("item_desc", ([
  ]) ) ;
  set("exits", ([
    "east" : ROOMS(base2),
  ]) ) ;
  ::create();
  reset();
}
