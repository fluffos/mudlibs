// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;
inherit DOORS ;

void create() {
  seteuid(getuid());
  set("short", "An armory.") ;
  set("long", @ENDLONG
You stand in an armory for the castle guards.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
  "south" : ROOMS(guard_station1),
  "north" : ROOMS(guard_storage2) ,
  ]) );
  set("item_desc", ([
  ]) );
  set("objects", ([
  WEP(royal_weapon) : random(5) ,
 ]) );
  create_door("south", "north", "It's a strong iron door.", "locked",
   "guard_captain", 45) ;
  ::create();
}
