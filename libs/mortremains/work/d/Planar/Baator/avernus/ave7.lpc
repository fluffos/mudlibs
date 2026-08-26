#include <mudlib.h>

inherit ROOM ;

void create() {
  seteuid(getuid()) ;
  set("short", "A small alcove.") ;
  set("light", 1) ;
  set("long", @ENDLONG
You stand in a small alcove in the path.  There are scorch marks filling
the ground here.
ENDLONG
  ) ;
  set("exits", ([
   "north" : "/d/Planar/Baator/avernus/ave4",
   ]) ) ;
  set("objects", ([
       "portal" : "/d/Planar/Baator/avernus/portal1",
   ]) ) ;
  ::create() ;
  reset() ;
}
