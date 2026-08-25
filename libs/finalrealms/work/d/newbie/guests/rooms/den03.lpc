#include "path.h"
inherit "/std/room";

void setup() {
    set_light(80);
    add_property("no_undead",1);
    set_short("Dendall:  Forge");
    set_long("\n   Dendall:  Forge.\n\n"
      "     You have set foot in the Dendall Forge.  The only "
      "light in the room radiates from the glow of the cooling "
      "coals in the fire pit.  Off to your left you see the large pit  "
      "with a great bellows erected beside it.  You come "
      "to a stark realization that this forge has been abandoned.  "
      "Tools lay scattered about, and the water barrel has been "
      "knocked over.  Although not in a complete state of disarray,  "
      "does not coincide with the normal habits of the Duergar.  "
      "You begin to feel a creeping sense of dread as you realize "
      "the implications of an abandoned Duergar forge.  Perhaps the "
      "previous Forge Master was not pious enough to please Grimbrand.\n"
      "\n");

    add_item("bellows",
      "These great bellows look as if it would take at least five "
      "Duergar to operate them.  You can imagine what kind of heat "
      "the fire pit puts out when they are in operation.\n"
      "\n");
    add_item("pit",
      "The fire pit is a huge sunken area in the floor with two bellows "
      "leading to it in order to fan the coals.  The "
      "temperature must become unbearable in here when it is lit.\n"
      "\n");
    add_item("coals",
      "The coals are cold now, due to the lack of a smithy.\n"
      "\n");
    add_item("tools",
      "There are many smithy tools laying about in disrepair.  "
      "None of them look like they would hold up to much work anymore.\n"
      "\n");
    add_item("barrel",
      "This barrel probably held the water with which the smithy cooled "
      "the weapons and armour he created.\n"
      "\n");

    add_exit("west", HERE+"den01", "road");

    set_zone("dendall");
}

