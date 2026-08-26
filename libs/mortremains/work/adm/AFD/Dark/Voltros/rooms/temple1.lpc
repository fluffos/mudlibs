#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());

  set("author", "Gendor");

  set("light", 0);


  set("short", "In the temple.");

set("long", @ENDLONG
This dark hallway extends west about 200 meters.  To the east, the
first room of the temple can be seen.  Here, a guardrail made of bones
runs down the left and the right of the corridor.  Every few feet, a
weapon of some kind is attached to the wall.  Under each weapon, a
short story is etched into the stone.
ENDLONG
   );

  set("item_desc", ([
"weapons" : "There are numerous weapons attached to the walls here.\n",
"guardrail" : "This guardrail is made of humanoid bones, picked clean and lashed
togther with tendons and seinew.\n",
"bones" : "They are blood-stained and are very hard to the touch.  There is no du
st on them, suggesting that someone takes care of them.\n",
"story" : "In short, every story tells about how these weapons helped eradicate t
he area of humanoids.\n",
"stone" : "The stone of this temple is a smooth marble.\n",
"weapon" : "There are numerous weapons attached to the walls here.\n",   
]) );

  set("smell", ([
    "default" : "You smell the sickening, gut-wrenching smell of death.\n",

  ]) );

  set("exits", ([
    "east" : ROOMS(temple),
    "west" : ROOMS(temple2),
  ]) );

set("objects", ([
    MON(skeleton) : 1,
  ]) );


  ::create();
reset();
}