/*  Text alterations and additions by Grimbrand 2-1-96                   */

#include "path.h"
inherit "/std/underground";

void setup() {
  add_property("no_undead",1); set_light(10);

set_short("Realm of the Duergar:  Proving Grounds");

set_long("\n   Realm of the Duergar:  Proving Grounds.\n\n"
         "     You have entered a rather plain and squarish looking room. "
         " The walls, floor, and ceiling are made out of a solid granite-"
         "like stone and appear to be smooth except for an occasional "
         "stray mark here and there.  The only items within the room are "
         "a few rocks which are all of irregular shape and size.  No "
         "doubt the rocks have been left here for you to work on.  "
         "Covering the walls is a strange type of moss that gives off its "
         "own light, providing the only illumination in the room.\n"
         "\n");

add_item("rocks",
         "   Looking at the rocks you notice they are all rough and "
         "irregular in shape.  Thinking back to what Hewlen told you "
         "it might be best if you started picking the rocks if you "
         "have any hopes of progressing.\n\n");

add_item("walls",
         "   As you look at the walls, you notice that in "
         "various places, it looks like someone has tried to chip "
         "away at the walls.  You wonder why they would bother "
         "picking in any direction.  It's not like they would dig "
         "into another room.\n");

add_item("moss",
         "   As you look at the moss, you can see that it is "
         "growing directly upon the rock.  It gives off a blueish "
         "glow that helps to light the area up enough to where you "
         "can see fairly well.\n");


add_exit("southeast",NEWBIE+"dlev1_01","path");
add_exit("south",NEWBIE+"dlev1_03","path");
add_clone(DNPC+"rat",2);
}
