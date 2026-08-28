#include <lib.h>
#include "../rome.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("the Sanctum Bazaar");
  SetExits( ([
    "north" : ROME_ROOM "rd01",
    "south" : ROME_ROOM "rd12",
    "west"  : ROME_ROOM "vi06",
    ]) );
  SetSmell( ([
    "default" : "Various exotic smells of spices and other exotic trade "
                "goods fill the bazaar.",
    ]) );
  SetListen( ([
    "default" : "At all hours, the bazaar is filling with haggling citizens.",
    ]) );

  SetLong("The Sanctum Bazaar is a strange mix of chaos and order. "
          "Various merchants have small tents set up to hawk their "
          "wares, and their shouts drown out into a din of raw noise "
          "that makes casual conversation impossible. In the center "
          "of the bazaar is Tylus' of Sanctum's large and impressive tent. "
          "His shop is larger than all others in the bazaar. "
          "A small blue tent sits off to one corner of the bazaar, "
         "marked with signs of torches and other tools of exploration."
    );

  SetItems( ([
    ({ "tents" }) : "The tents of the various merchants vary "
          "from meager to elaborate.",
    ({ "tent", "shop", "tylus" }) : "Tylus' tent is the biggest shop "
        "in the bazaar.",
    ({ "tent", "explorer"}) : "The tent of the explorer is a faint "
           "blue color, making it unique.",
    ]) );
  SetItemAdjectives( ([
    "tylus" : ({ "large", "impressive", "tylus'", "tylus" }),
    "explorer" : ({ "small", "blue", "explorer" }),
    ]) );
  SetEnters( ([
    "tylus" : ROME_ROOM "tylus",
    "explorer" : ROME_ROOM "explorer",
    ]) );
  SetInventory( ([
    ROME_NPC "t_bargain" : 1,
    ROME_NPC "farmer" : 1,
    ]) );
}
