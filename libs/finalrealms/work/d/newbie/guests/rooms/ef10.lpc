inherit "std/room";
 
#include "path.h"
 
void setup()
{
  //ef10.c
  set_light(70);
  set_short("Gnarlwood Forest Rose Bush Thicket");
  set_long("Gnarlwood Forest Rose Bush Thicket\n"
           "Once beautiful wild roses flourished here, as "
           "attested by the few mildewed petals that still "
           "litter the floor.  Instead, now, each bud bears "
           "nothing but thorns, and the wiry branches seem to "
           "wrap around you and entrap you.  Every move you make "
           "ensnarls you even more, and though you see pathways out "
           "to your northwest and northeast a short distance away, "
           "the thorns refuse to let you walk towards them. Never "
           "did you think that a rose bush - a symbol of beauty and "
           "love -- could be turned into a snare of entrapment.\n");
  add_item(({"rose","roses","bud","buds","bush","bushes","snare"}),
          "These bushes and their aborted flowers reak of mildew, of "
          "death, and of evil.\n");
  add_item(({"thorn","thorns","branch","branches"}),
          "Branches and thorns intertwine amongst themselves like "
          "barbed wire, protecting the plants not from hungry animals "
          "or amorous travellers, but from anything good and just.\n");
 
  add_item(({"petal","petals"}),
            "Green mottled specks hide the fragile shades of pink and "
            "red that once colored these petals.\n");
   add_property("no_undead",1);
  add_exit("north", HERE+"ef13", "path");
  add_exit("south", HERE+"ef4", "path");
 
}

