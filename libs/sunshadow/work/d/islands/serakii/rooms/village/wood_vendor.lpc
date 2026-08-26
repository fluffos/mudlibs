// wood shop Port Serith Institute

#include <std.h>
#include "../../serakii.h"

inherit ROOM;

void create() {
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);

    set_name("wood shop");
    set_property("light",2);
    set_short("%^C094%^wo%^C059%^o%^C094%^d s%^C060%^h%^C094%^op%^CRST%^");
    set_long("Nestled in the northeast corner of the building, this room has been set out with an array of %^C095%^beautiful display cabinets%^CRST%^ that are filled with lengths of %^C095%^wood%^CRST%^. A %^C095%^long oak table%^CRST%^ is set against the wall with an %^C248%^open ledger%^CRST%^ and small %^C221%^teak sculpture%^CRST%^. A %^C028%^long green rug%^CRST%^ runs throughout the room. Unlike the rest of the school there is a simple %^C111%^serenity%^CRST%^ here.\n");

   set_items(([
    ({"table"}) : "%^C094%^This long oak table, maybe 10 feet long. It is varnished to a deep shine and an open ledger, and a %^C058%^small teak sculpture%^C094%^ sit on it.\n%^CRST%^",
    ({"display","cabinets"}) : "The %^C094%^display cabinets%^CRST%^ include a variety of types of %^C094%^wood%^CRST%^. They have been placed behind the glass almost with %^C171%^reverence%^CRST%^.\n",
    ({"sculpture"}) : "This half-foot tall sculpture, carved from a single piece of %^C142%^teak%^CRST%^, is a masterwork of %^C248%^intricacy%^CRST%^. It is of four figures standing in a tight circle facing outwards as if facing an onslaught from all sides. The first is a %^C248%^slight human male%^CRST%^, crouched low with %^C246%^twin daggers%^CRST%^. The second is a %^C067%^human man%^CRST%^ in %^C067%^heavy plate%^CRST%^ wielding a %^C067%^massive sword%^CRST%^ over his head. The third is a %^C148%^half-elven woman%^CRST%^ who looks %^C148%^mid song%^CRST%^, and the last an %^C196%^armored woman%^CRST%^ holding a %^C196%^shield resolutely%^CRST%^ over the group as if fending a blow from above. The craftsman has captured a moment of battle so well you can almost feel the next %^C088%^blows%^CRST%^ come to the figures. \n",
    ({"rug"}) : "This %^C028%^simple green rug%^CRST%^ offers some comfort in the room over the %^C243%^basic flagstone%^CRST%^\n",
    ({"floor","flagstone"}) : "%^C243%^The floor here is simple flagstone%^CRST%^",
    ]));


set_smell("default","%^C221%^You smell rich %^C214%^dyes%^C221%^ and clean %^C142%^cloth%^C221%^.%^CRST%^");
set_listen("default","%^C101%^With all the fabric sounds seem %^C060%^muted%^C101%^ here.%^CRST%^");



   set_exits(([

          "west" : TOWN"foyer",
          
   ]));

}

void reset()
{
	::reset();
	if(!present("trader"))
	{
           new(MOBS"beres")->move(TO);
	}
}

