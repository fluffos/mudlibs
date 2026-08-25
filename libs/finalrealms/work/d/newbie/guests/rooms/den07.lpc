#include "path.h"
inherit "/std/room";

#define LIMIT 1
int foo = 0;

void reset() { foo = 0; }
void setup() {
    set_light(50);
    add_property("no_undead",1);
    set_short("City of Dendall:  Farm");
    set_long("\nCity of Dendall:  Farm\n\n"
      "    The wind howls in protest as you enter this stretch of "
      "farmland.  Looking around carefully, you see no tangible "
      "evidence that anyone else is here, but you sense that your "
      "presence has been noted by something.  The crops stretch out "
      "around you, shvering and swaying to the breeze as if beckoning "
      "you to join their dance of death.  An eerie glimmer fills the "
      "cavern with a pale shadow of light.  As you watch the shadow "
      "servants of Grimbrand creep and crawl towards you, you begin "
      "to know what real fear is.\n\n");
    add_item(({"shadow", "servant"}),
      "Dark shadows dance across the crops growing on this "
      "small section of the farm.\n");
    add_item(({"light", "luminescence", "glow", "glimmer"}),
      "The fungi growing all around you "
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
    add_feel(({"wind", "howl", "protest"}), "The wind roars across this "
      "area, threatening to uproot you.  Strangely, the crops here "
      "seem to invite the embrace of the wind, as no harm comes to "
      "them from its presence.\n");
    add_sound(({"wind", "howl", "protest"}), "The wind carries almost "
      "understood threats and warnings to unwary visitors.\n");                                                                                                                         
    add_item("fence", "The fence looks fairly sturdy and just high enough to "
      "make you think twice about climbing over it.\n");
    add_exit("north", HERE+"den08", "road");
    add_exit("south", HERE+"den06", "fence");
    set_zone("farm");
}

