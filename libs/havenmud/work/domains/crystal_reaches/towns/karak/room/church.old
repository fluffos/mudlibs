// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include <vendor_types.h>
#include "../karak.h"
inherit LIB_CHAPEL;

static void create() {
  chapel::create();
  SetClimate("indoors");  	
  SetAmbientLight(45);
  SetShort("the Church of Saahagoth");
  SetLong(
    "Once inside the church it can be seen that the building is not made of "
    "several stories, but instead is one enormous chamber reaching hundreds "
    "of feet into the air. Columns of black marble are arranged throughout "
    "the church, reflecting the nearby lights from their polished surfaces, "
    "except in those areas where they have been engraved with runes. Three "
    "candelabra of huge, twisted demon horns hang in the air, arranged to "
    "form a triangle above the open space in the center of the church."
  );
  SetItems( ([
    ({ "church", "building" }) : (: GetLong :),
    ({ "column", "columns" }) : "Thick columns of polished black marble are "
    "set throughout the church, their reflective surfaces disturbed only "
    "where they have been carved with runes.",
    ({ "rune", "runes" }) : "Intricate runes are carved upon the columns, "
    "appearing to depict a complete history of the rise of Saahagoth.",
    ({ "candelabra", "candelabrum" }) : "Candelabra of huge, twisted demon "
    "horns hang in the air, forming a triangle over the center of the church.",
    ({ "horn", "horns" }) : "These huge, twisted horns were harvested from "
    "demons and used to create the candelabra which illuminate this church.",	
  ]) );
  SetItemAdjectives( ([
    "column" : ({ "black", "marble", "thick", "polished", "reflective" }),
    "rune" : ({ "intricate", "carved", "engraved" }),
    "candelabra" : ({ "huge", "twisted", "horn", "horns" }),
    "horn" : ({ "huge", "twisted", "demon" }),
  ]) );
  SetListen( ([
    "default" : "Light chanting can be heard.",
  ]) );
  SetSmell( ([
    "default" : "The tang of old blood is faint in the air.",
  ]) );
  SetInventory( ([
    KARAK_NPC + "leader_shaman" : 1,
  ]) );
  SetExits( ([
    "out" : KARAK_ROOM + "rd6",
  ]) );
}
