// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "A large museum.");
  set("long", @ENDLONG
You stand in a section of the museum that is dedicated to ancient
weaponry and armours.  All the equipment is in locked glass display
cases.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
    "east" : ROOMS(museum1),
  ]) );
  set("item_desc", ([
    "equipment" : @ENDDESC
It's all locked up - You can't get to it.
ENDDESC
  ,    "weapons" : @ENDDESC
You see swords, maces, pole-axes, and more.  All the equipment is 
locked up in the display cases.
ENDDESC
  ,    "armours" : @ENDDESC
You see platemail, chainmail, and some shields, all battle-worn.
All the equipment is locked up in display cases.
ENDDESC
  ,  ]) );
  set("search_desc", ([
  ]) );
  set("objects", ([
  ]) );
  set("exit_msg", ([
  ]) );
  ::create();
}
