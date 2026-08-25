#include "path.h"
inherit "/std/room";

void setup() {
    set_light(50);
    set_short("City of Dendall:  Cemetary");
    set_long("\nCity of Dendall:  Cemetary\n\n"
      "    Dominating this small cemetary is a large statue of "
      "Grimbrand, God of Death.  Placed atop a black onyx pedestal, "
      "the statue is of a standing figure with a large tiger wrapped "
      "around his legs.  Spiraling out from the statue are a dozen "
      "sarcophagi.  To the south is an entrance to a large "
      "mausoleum.\n\n");
    add_item("spire", "Rounded spires ending in sharp points reach "
      "up into the darkness of the highest reaches of this "
      "cavern.  The massive stone buildings that support these "
      "spires wield them as a seasoned warrior wields his sword.\n");
    //  I am aware this sounds DUMB
    add_item(({"structure", "building", "mausolem"}),
      "Huge buildings of dark grey stone stand to the south "
      "and west of you.  Gargoyles stare down at you from them, "
      "grimacing in disgust at your presence.\n");
    add_item("gargoyle", "Large, carved, guardian beasts, the gargoyles "
      "watch over the area, protecting it from tainted, impure "
      "visitors.  Grotesque features send chills down your spine "
      "as you continue to stare at them.\n");
    add_item(({"window", "door"}), "Large iron doors add to the fortress "
      "like aspect of the buildings, while the windows are placed "
      "high and are little more than tiny slivers in the faces of "
      "the buildings.\n");
    add_item(({"statue", "pedestal", "tiger", "figure"}), 
      "A large statue done in the purest of electrum, this "
      "representation of Grimbrand is obviously meant to watch "
      "over those buried here.  A large tiger wraps around "
      "Grimbrand's legs, seemingly ready to unleash its "
      "magnificent power at any second.  The pedestal of deep, "
      "rich black onyx counts down three steps before reaching "
      "the ground.\n");
    add_item(({"sarcophagus", "sarcophagi"}), "These above ground burial "
      "places spiral out from the statue of Grimbrand.  All are in "
      "shades of black, though none come close to the darkness "
      "seen in the statue, itself.\n");

   add_property("no_undead",1);

    add_exit("east", HERE+"den03", "road");
   add_exit("west",HERE+"con03","path");
    add_exit("north",HERE+"den06","path");
    add_exit("south", HERE+"den02", "door");
    set_zone("dendall");
}
