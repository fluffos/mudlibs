// Hallway

#include <std.h>
#include "../../serakii.h"

inherit ROOM;

void create() {
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);

    set_name("caer hallway");
    set_property("light",2);
    set_short("%^C246%^ca%^C250%^e%^C246%^r ha%^C250%^l%^C246%^lway%^CRST%^");
    set_long("The hallway has a %^C245%^large arched ceiling%^CRST%^ and columns that line both sides of the wide hall. %^C220%^gold sconces%^CRST%^ hold %^C038%^glowing crystals%^CRST%^ that softly %^C227%^illuminate %^CRST%^the area. The %^C245%^floor %^CRST%^here is a marble made of interlocking slabs forming a complicated pattern. The hallway itself is spacious enough for crowds of people to congregate however most move at a brisk pace moving around the %^C245%^fortress%^CRST%^. There are %^C160%^comfortable couches%^CRST%^ and %^C094%^tables %^CRST%^dotting the hallway.\n");

    set_items(([
      ({"floor"}) : "The floor is marble, with interlocking slabs forming a geometric pattern. With how large it is, its hard to tell what the pattern is from here.\n",
      ({"ceiling","arched ceiling"}) : "The ceiling above you is high and arched. On it is a a fine painting of a %^C116%^sky %^CRST%^with %^C231%^fluffy clouds%^CRST%^ and a %^C227%^bright sun%^CRST%^.\n",
      ({"tables","couches"}) : "Small %^C130%^wood tables%^CRST%^ dot the hallway flanked by %^C124%^comfortable couches%^CRST%^. \n",
      ({"crowds"}) : "Small crowds of people wander the hallways. Most are dressed in %^C037%^fine robes%^CRST%^ of archivists, however there are %^C242%^soldiers %^CRST%^around as well.\n",
    ]));


    set_smell("default","%^C028%^You smell fresh cut flowers.%^CRST%^");
    set_listen("default","%^C111%^The sounds of conversations float through the hallway.%^CRST%^");


   set_exits(([
        "east" : CAER"foyer",
		"northwest" : CAER"3",
   ]));

}


