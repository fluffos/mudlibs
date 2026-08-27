inherit "std/room";
#include "path.h"

int test1;
object bell;

void init()
{
::init();
add_action("do_pray","pray");
}
void setup() {
   set_short("The Directorate's room");
   set_long(
      "This is the Directorate's meeting room. This is where the higher "+
"level Priests can relax or discuss their plans or tactics to make this "+
"the best guild in the realms. "+
      "The room has an altar against the east wall.  A large fireplace "+
"sits against the north wall.  A large majestic "+
"tapestry covers the west wall.  \n");
   set_light(100);
add_exit("out", ROOM+"temaltar", "door");
add_exit("meeting", "/w/baldrick/meeting", "door");
add_exit("up", ROOM + "gmaster", "door");
add_item ("altar","This is a small altar to Tempus.\n");
add_item ("fire","This is a nice warm fire.  You cuddle up in your blanket "+
"and nearly fall asleep, but you stop yourself before you doze off.\n");
add_item ("fireplace","This fireplace has a nice fire burning in it.  A "+
"large flaming sword sits above the mantle.\n");
add_item ("tapestry","You look at the tapestry and notice that this isn't "+
"an ordinary tapestry.  The pictures in the tapestry are ever changing.  In "+
"one scene, you are saving villagers from orcs.  In another "+
"scene, you are giving a helping hand to a new member of the Priest's guild.  "+
"You finally pull yourself away from the tapestry, because you have work "+
"to finish.\n");
   set_co_ord( ({ -2, -1, 1 }) );
}

void reset()
{
  if (!bell)
  {
    bell = clone_object("/w/baldrick/items/cleric_bell");
    bell->move(this_object());
  } /* if */
} /* void Reset */

void do_pray()
{
notify_fail("You pray to Tempus.\n"+
"You feel another presence enter the room.\n"+
"You feel all your worries and sorrow lift away from you.\n"+
"You feel the other presence leave.\n");
return 0;
}

void dest_me()
{
  if (bell)
  bell->dest_me();
} /* void dest_me */
