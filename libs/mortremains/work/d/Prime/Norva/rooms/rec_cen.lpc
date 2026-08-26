// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM ;

void create() {
  seteuid(getuid()) ;
  set("author", "chronos");
  set("light", 1) ;
  set("short", "The Recreation Center.");
  set("long", @ENDLONG
You stand in a very lame Recreation Center for the enlisted personnel
on the base.  A couple ancient arcade games are on the walls, and a large
TV adorns the southern wall.  A broken pool table lies right in the middle
of the room.
ENDLONG
  );
  set("item_desc", ([
    "pool table" : "The pool table has been smashed in half.\n",
    "table" : "The pool table has been smashed in half.\n",
    "tv" : "It's currently showing \"McHale's Navy.\"\n",
    "television" : "It's currently showing \"McHale's Navy.\"\n",
    "games" : "You see Spy Hunter, Donkey Kong, and Duck Hunt among the line-up.\n",
    "arcade games" : "You see Spy Hunter, Donkey Kong, and Duck Hunt among the line-up.\n",
  ]) ) ;
  set("exits", ([
    "north" : ROOMS(base25),
    "west" : ROOMS(base12),
   ]) ) ;
  set("objects", ([
    MON(young_sailor) : 2 ,
  ]) ) ;
  ::create();
  reset();
}
