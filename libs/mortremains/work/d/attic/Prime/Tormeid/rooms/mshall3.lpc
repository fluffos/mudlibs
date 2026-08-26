// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

object servant ;

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "A large hallway.");
  set("long", @ENDLONG
This large hallway runs north and south through the castle.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
  "east" : ROOMS(kitchen1) ,
  "west" : ROOMS(ballroom1),
    "north" : ROOMS(mshall2),
    "south" : ROOMS(mshall4),
  ]) );
  set("item_desc", ([
  ]) );
  set("search_desc", ([
  ]) );
  set("objects", ([
  ]) );
  set("exit_msg", ([
  ]) );
  ::create();
}

void reset() {
  if (!servant) {
    servant=clone_object(MON(moving_servant)) ;
    servant->move(TO) ;
  }
  ::reset() ;
}
