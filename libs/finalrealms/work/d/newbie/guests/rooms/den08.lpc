#include "path.h"
inherit "/std/room";

#define LIMIT 2
int foo = 0;

void reset() { foo = 0; }
void setup() {
    set_light(50);
    add_property("no_undead",1);
    set_short("City of Dendall:  Farm");
    set_long("\nCity of Dendall:  Farm\n\n"
      "    The back section of the farm is cloaked in dark, writhing "
      "shadows.  An eerie luminescence animates the strange crops grown "
      "by the Duergar farmers of this region.  Looking through the darkness, "
      "you note that the main crop of this farm is mushrooms.  It is from "
      "this fungi that what little light there is here emanates.  Rumor has "
      "it that some of these mushrooms have healing properties, but that "
      "others can kill you.\n\n");
    add_item("shadow", "Dark shadows dance across the crops growing on this "
      "small section of the farm.\n");
    add_item(({"light", "luminescence"}), "The fungi growing all around you "
      "emit a pale, green light which casts strange shadows across "
      "the farm.\n");
    add_item("crop", "The only crop you recoginize is the mushrooms.  The "
      "rest are strange exotic plants that only a Duergar grandmother "
      "would know.\n");
    add_item("darkness", "The darkness that hovers, embracing all of the "
      "underdark covers this area like a shroud.\n");
    add_item(({"mushroom", "fungi"}), "As you study the strangely glowing "
      "mushrooms, you try to figure out which are poisonous.  Perhaps "
      "it would help to pick a few for closer examination.\n");
    add_item("farm", "Duergar farmers are a rare breed, most prefering "
      "to devote their lives to mining in the deep forges or in "
      "service to Grimbrand.  This particular farm is a study in "
      "the meticulous orderliness of the Duergar.  Neat rows of "
      "crops grow in abundance, awaiting harvest.\n");

    add_exit("south",HERE+"den07","road");
   add_exit("east",HERE+"gate","path");
   set_zone("farm");
}
