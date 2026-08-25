inherit "std/room";
 
#include "path.h"
 
void setup()
{
  //ef9.c
  set_light(70);
  set_short("Gnarlwood Forest");
  set_long("Gnarlwood Forest\n"
           "The ground dissolves into a fine powder with "
           "each step you take through this forsaken forest "
           "until it disappears altogether, and you are on the "
           "edge of a crevice filled only with darkness.  Although "
           "tangled roots twist out of the crevice side, they "
           "are too weak and dry to support your weight.  You wonder "
           "if the forest continues, or if this is where the land was "
           "torn from the surface.  For now, however, you cannot investigate "
           "it further; you may only return to the "
"living yet lifeless forest behind you to the northeast.\n");
 
  add_item(({"ground","dirt"}),
            "The dirt has seen no rain or snow since its captivity, and now "
            "is barely more than fine brown dust.\n");
 
  add_item(({"forest","land"}),
             "This midnight forest ends here at the outline of the crevice, "
             "and the trees are sparcer than in the heart of "
             "the forest to the northeast.\n");
 
  add_item(({"tree","trees"}),
             "Colorless bark coats the trees as "
             "the roots try in vain to nourish the leaves in this cursed woods.\n");
  add_item(({"crevice"}),
             "You peer over the edge, hoping to find some clues as to the "
             "origins of this forest here.  The only thing you see is dark "
             "space, however, and the deep fear that overcomes you as "
             "you kneel over this chasm to nowhere convinces you to avert "
             "your glance and look elsewhere.\n");
 
  add_item(({"roots","root"}),
             "Emaciated roots dangle like thin vines through the "
             "side of the cliff as they continue their search for "
             "water and life.\n");
 
   add_property("no_undead",1);
  add_exit("northeast", HERE+"ef4", "path");
  //add-on
 
}

