/*  Text alterations and additions by Grimbrand 2-2-96                   */

#include "path.h"
inherit "/std/underground";

object *npcs;

void reset() {
int i;
 for(i=0;i<sizeof(npcs);i++) {
  if(!npcs[i]) {
  npcs[i]=clone_object(DNPC+"dkobold");
  npcs[i]->move(this_object());
  }
 }
}

void setup() {
  add_property("no_undead",1); set_light(85);
  npcs = allocate(1);
set_short("Realm of the Duergar:  Surface Proving Grounds");

set_long("\n   Realm of the Duergar:  Surface Proving Grounds.\n\n"
         "     As you walk into the room, your eyes are blasted with the "
         "glare from some intense light source.  It almost "
         "blinds you making it very hard for you to see.\n\n"
         "     As your eyes adjust, you dont appear to be in "
         "the caverns of your homeland anymore.  There isn't a "
         "ceiling anymore, it is no longer dark, and the colors!  "
         "The more that you look around, the more you begin to "
         "realize that this must be the surface world, with all its trees, "
         "open sky, and hideous ball of fire in the sky.  As you "
         "walk around you suddenly bang into a wall!  It is only then "
         "that you can see the faint outline of the comfortable grey "
         "room.  It must have taken a great Duergar cleric to create "
         "this illusion for the academy.\n"
         "\n");

add_item("sun",
         "   As you try to look up to where the ceiling of a "
         "cavern would normally be, all you see is an endless sea of "
         "blue sky.\n\n");

add_item("colors",
         "   As you look around, the entire area is covered by "
         "large plants with a multitude of colors.  This place is "
         "obviously trying to confuse you with all the colors to "
         "aid the creatures that lurk somewhere near.\n\n");

add_exit("south", NEWBIE+"dlev3_04", "path");
add_exit("west", NEWBIE+"dlev3_07", "path");
add_exit("southeast",NEWBIE+"dlev3_01","path");
}

void dest_me() {
int i;
for(i=0;i<sizeof(npcs);i++)
  if(npcs[i]) npcs[i]->dest_me();

 ::dest_me();
}
 
