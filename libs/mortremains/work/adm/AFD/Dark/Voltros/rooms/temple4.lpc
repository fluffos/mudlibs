#include "../defs.h"

object ske, ske2, ske3, ske4;

inherit ROOM;

void create() {
  seteuid(getuid());

  set("author", "Gendor");

  set("light", 0);


  set("short", "in the temple.");

set("long", @ENDLONG
This dark hallway extends west about 200 meters.  To the east, the
first room of the temple can be seen.  Here, a guardrail made of bones
runs down the left and the right of the corridor.  Every few feet, a
weapon of some kind is attached to the wall.  Under each weapon, a
short story is etched into the stone.  Another corridor can be seen
branching off towards the north.
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

set("exits", ([ "east" : ROOMS(temple3), "north" : ROOMS(ntemple1), ]) );
::create();
}

void reset(){
  if (!ske && !ske2 && !ske3 && !ske4){
    ske = clone_object(MON(skeleton.c));
    ske2 = clone_object(MON(skeleton.c));
    ske3 = clone_object(MON(skeleton.c));
    ske4 = clone_object(MON(skeleton.c));
    ske->move(TO);
    ske2->move(TO);
    ske3->move(TO);
    ske4->move(TO);
 }
::reset();
}
