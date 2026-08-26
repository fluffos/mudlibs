// Puppet's Banquet - LoKi 2022

#include <std.h>
#include "puppet.h"

inherit ROOM;

void create() {
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_property("no_teleport",1);
    set_name("dusty banquet hall");
    set_property("light",2);
    set_short("dusty banquet hall");
    set_long("%^C058%^The room around you is massive, with a high vaulted ceiling "+
        "that disappears into %^C238%^complete darkness%^C058%^. The room is filled "+
        "with a %^C094%^long banquet table%^C058%^ with a %^C061%^rich arrangement%^C058%^ of food "+
        "that has %^C136%^rotted completely%^C058%^. At the %^C094%^table%^C058%^ sit "+
        "hundreds of %^C247%^corpses%^C058%^, each in an almost perfect quality as if they died "+
        "minutes before you entered. Each are dressed in the %^C057%^finery of nobles%^C058%^, "+
        "the %^C075%^uniforms of military%^C058%^, or the %^C245%^armor of knights%^C058%^, and "+
        "each have been arranged as if like dolls in a scene. Here you see a %^C056%^dead noble%^C058%^ "+
        "flirting with a %^C087%^young princess%^C058%^, there a %^C246%^knight%^C058%^ in the midst of "+
        "a grand tale. The room is completely %^C249%^silent%^C058%^ except for the sounds you make.%^CRST%^\n");

    set_items(([
      ({"floor"}) : "%^C246%^The floor is set with %^C240%^large interlocking stones%^C246%^. "+
      "The floor is covered in a thick layer of %^C060%^dust%^C246%^.%^CRST%^\n",
      ({"sconces","torches"}) : "%^C060%^Along the wall are %^C239%^iron sconces%^C060%^ "+
      "holding %^C100%^oily %^C094%^torches%^C060%^. The %^C094%^torches%^C060%^ themself seem "+
      "to burn with a %^C088%^dirty flame%^C060%^ filling the air with %^C100%^acrid "+
      "smoke%^C060%^.%^CRST%^\n",
      ({"walls"}) : "%^C060%^The walls are mostly %^C244%^bare stone%^C060%^, but with "+
      "a %^C081%^wetness%^C060%^ to them, like there was %^C153%^condensation%^C060%^ "+
      "or %^C081%^water%^C060%^ seeping from somewhere.%^CRST%^\n",
      ({"tables","feast"}) : "%^C094%^The long tables dominating most of the "+
      "room are loaded up with every type of %^C028%^food%^C094%^ imaginable. All "+
      "the %^C063%^richness%^C094%^ and hard to get %^C081%^gourmet%^C094%^ options. "+
      "However every item is %^C102%^rotted%^C094%^ beyond any chance at salvation. "+
      "Some of it has even decomposed to the point just moving near it reduces "+
      "it to %^C246%^dust%^C094%^.%^CRST%^\n",
      ({"corpses","diners"}) : "%^C067%^The %^C144%^corpses%^C067%^ around "+
      "the %^C094%^table%^C067%^ have been arranged and look as if they are a "+
      "part of a scene. None show any signs of how they died, no %^C160%^wounds%^C067%^ or "+
      "obvious %^C088%^violence%^C067%^. Yet each one is quite dead.%^CRST%^\n",

    ]));


set_smell("default","%^C130%^You smell acrid smoke.%^CRST%^");
set_listen("default","%^C141%^You hear muffled.. laughter?%^CRST%^");

}
