/*  Shaman's Tent */
#include <lib.h>
#include "../../goblins.h"
inherit LIB_ROOM;
static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(25);
  SetShort("inside a smoke filled tent");
  SetLong("The tent is filled with smoke an incense in what can only be "
          "a primative shaman's tent. The room is filled with items used "
          "in the worship of Kharn the Destroyer.");
  SetSmell( ([
     "default" : "The tent reeks of incense.",
      ]) );
  SetListen( ([
    "default" : "The tent seems oddly unquiet.",
      ]) );
  SetInventory( ([
    GOBLIN_NPC + "shaman" : 1,
    GOBLIN_NPC + "healer" : 1,
      ]) );
  SetExits( ([
     "out" : GOBLIN_ROOM + "cem",
    ]) );
  }
