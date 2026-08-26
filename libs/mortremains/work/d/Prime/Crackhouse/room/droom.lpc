#include <mudlib.h>

inherit ROOM ;

void create() {
  seteuid(getuid()) ;
  set("light", 1 ) ;
  set("short", "A dirty bedroom.") ;
   set("long", @ENDLONG
You are in a seedy little bedroom.  The floor is covered with trash and
little plastic baggies.  A dirty mattress lies in the corner.
ENDLONG
  ) ;
  set("item_desc", ([
    "mattress" : "It looks like someone peed on it.\n",
   "baggies#bags" : "They smell faintly of pot.\n",
    "floor" : "It's covered with trash and shit.\n",
   "trash" : "Nothing of interest, really.\n",
  ]) ) ;
  set("exits", ([
    "west" : "/d/Prime/Crackhouse/room/top",
  ]) ) ;
   set("objects", ([
   "dealer" : "/d/Prime/Central/mon/dealer",
   ]) ) ;
  ::create() ;
  reset() ;
}
