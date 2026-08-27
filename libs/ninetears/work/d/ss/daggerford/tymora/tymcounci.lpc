inherit "std/room";
#include "path.h"

int test1;
object bell;

void init()
{
::init();
}
void setup() {
   set_short("High Cleric's Council Room");
   set_long(
      "This is the High Cleric's Council room. This is where the higher "+
      "level Clerics can relax or discuss their plans or tactics to make this "+
      "the best guild in the realms. "+
      "The room has many portraits hanging on the walls.  A huge table "+
      "with many chairs sits in the center of the room.  A large bookcase "+
      "covers the west wall.\n" + 
      "To the north is the entrance to the meeting room for Clerics.\n");
   set_light(100);
add_exit("south", ROOM+"tymora", "door");
add_exit("north", "/w/baldrick/meeting", "door");
add_exit("up", ROOM + "cgmaster", "door");
add_alias("chairs","chair");
add_alias("portraits","portrait");
add_item ("bookcase","It is filled with many fine books, some in languages "+
"long forgotten.\n");
add_item ("chair","You see many wooden chairs surrounding the large table.\n");
add_item ("table","A heavy wooden table with many ornate carvings on it.\n");
add_item ("portrait","You see portraits of many Clerics, new and old.  "+
".\n");
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

void dest_me()
{
  if (bell)
  bell->dest_me();
} /* void dest_me */
