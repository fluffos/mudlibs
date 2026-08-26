#include "../defs.h"
int pulled;
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
    "weapons" : "Your eyes are drawn to a magnificent sword.\n",
    "guardrail" : "This guardrail is made of humanoid bones, picked clean and lashed
togther with tendons and seinew.\n",
    "bones" : "They are blood-stained and are very hard to the touch.  There is no du
st on them, suggesting that someone takes care of them.\n",
    "story" : "In short, every story tells about how these weapons helped eradicate t
he area of humanoids.\n",
    "stone" : "The stone of this temple is a smooth marble.\n",
    "sword" : "It seems that you could pull this outstanding weapon off the wall.",
"weapon" : "There are numerous weapons attached to the walls here.\n",
   ]) );

  set("smell", ([
    "default" : "You smell the sickening, gut-wrenching smell of death.\n",

  ]) );

  set("exits", ([
    "east" : ROOMS(temple2),
    "west" : ROOMS(temple4),
  ]) );


  ::create();
}
void init(){

add_action("pull","pull");
}

int pull(string str) {
  if (!str || str !="sword" ) return 0;
  if (pulled){
        write("The sword has already been pulled from its position.\n");
        return 1;
  }
  write("You grasp the sword and a pit opens beneath you!\n");
  set("long", @ENDLONG
This dark hallway extends west about 200 meters.  To the east, the
first room of the temple can be seen.  Here, a guardrail made of bones
runs down the left and the right of the corridor.  Every few feet, a
weapon of some kind is attached to the wall.  Under each weapon, a
short story is etched into the stone.  A gaping pit can be seen in the
center of the floor.
ENDLONG
);
  set("item_desc/pit", "There is a great darkness within the pit, it seems it contains
darkness itself.\n");
        TP->move_player(ROOMS(pit));
        add_exit("down", ROOMS(pit));
  return 1;
pulled = 1;
}