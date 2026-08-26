// Path to Puppet - LoKi 2022

#include <std.h>
#include "puppet.h"

inherit ROOM;

void create() {
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_property("no_teleport",1);
    set_name("dark passageway");
    set_property("light",2);
    set_short("%^C060%^da%^C243%^r%^C060%^k pa%^C240%^s%^C060%^sag"+
        "ew%^C241%^a%^C060%^y%^CRST%^");
    set_long("%^C060%^You are standing in a wide %^C241%^dark "+
        "passageway%^C060%^. The air around you and the walls "+
        "are %^C249%^cold%^C060%^ and slightly %^C075%^damp%^C060%^, "+
        "and it is obvious that you have passed well underneath "+
        "the %^C058%^basements%^C060%^ and %^C065%^sewers%^C060%^ of the "+
        "city. The ground is a well fit %^C244%^stone%^C060%^ of obvious "+
        "craftsmanship. %^C238%^Black iron sconces%^C060%^ hold %^C094%^torches%^C060%^ "+
        "that have been %^C160%^lit%^C060%^ recently, though a thick layer of "+
        "%^C245%^dust%^C060%^ lines everything so you do see so you are unsure "+
        "who even could have %^C160%^lit%^C060%^ the %^C094%^torches%^C060%^.%^CRST%^\n");

    set_items(([
      ({"floor"}) : "%^C246%^The floor is set with %^C240%^large interlocking stones%^C246%^. "+
      "The floor is covered in a thick layer of %^C060%^dust%^C246%^.%^CRST%^\n",
      ({"sconces","torches"}) : "%^C060%^Along the wall are %^C239%^iron sconces%^C060%^ "+
      "holding %^C100%^oily %^C094%^torches%^C060%^. The %^C094%^torches%^C060%^ themself seem "+
      "to burn with a %^C088%^dirty flame%^C060%^ filling the air with %^C100%^acrid "+
      "smoke%^C060%^.%^CRST%^\n",
      ({"walls"}) : "%^C060%^The walls are mostly %^C244%^bare stone%^C060%^, but with "+
      "a %^C081%^wetness%^C060%^ to them, like there was %^C153%^condensation%^C060%^ "+
      "or %^C081%^water%^C060%^ seeping from somewhere.%^CRST%^\n"
    ]));


set_smell("default","%^C130%^You smell acrid smoke.%^CRST%^");
set_listen("default","%^C141%^You hear muffled.. laughter?%^CRST%^");

}
