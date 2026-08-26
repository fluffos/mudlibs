// cloth shop Port Serith Institute

#include <std.h>
#include "../../serakii.h"

inherit ROOM;

void create() {
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);

    set_name("cloth shop");
    set_property("light",2);
    set_short("%^C068%^clo%^C024%^t%^C068%^h sh%^C025%^o%^C068%^p%^CRST%^");
    set_long(" This area is packed floor to ceiling with %^C060%^bolts%^CRST%^ of %^C078%^cloth%^CRST%^, %^C094%^crates%^CRST%^ of %^C039%^cloth%^CRST%^, and random %^C163%^swatches%^C197%^ %^CRST%^everywhere. It is hard to see a safe route through at first though you realize there is a %^C246%^route%^CRST%^ mapped out and a high level of organization where each %^C059%^bolt%^CRST%^ is placed. Nestled against the eastern wall is a %^C094%^long oak table%^CRST%^ with an %^C248%^open ledger%^CRST%^ and a child's toy, a %^C110%^small stuffed animal%^CRST%^.\n");

    set_items(([
    ({"table"}) : "%^C094%^This long oak table, maybe 10 feet long, is covered in %^C045%^swatches of cloth%^C094%^, an open ledger, and a %^C111%^small stuffed wolf%^C094%^.\n%^CRST%^",
    ({"bolts","cloth"}) : "%^C109%^Cloth is everywhere! %^C223%^Cotton%^C109%^, %^C161%^silk%^C109%^, %^C057%^velvets%^C109%^ and %^C142%^muslin%^C109%^. The cloth is available both %^C250%^raw%^C109%^ and dyed to any %^C041%^color%^C109%^.\n%^CRST%^",
    ({"stuffed animal","toy"}) : "%^C111%^Stitched with cotton dyed a %^C074%^gray-blue%^C111%^ and stuffed with %^C254%^lamb's wool%^C111%^, this small child's toy is a stuffed %^C248%^wolf%^C111%^. It is positively adorable, with a small %^C207%^pink tongue%^C111%^ sticking out of the side of its snout and extra large %^C248%^paws%^C111%^ on poseable %^C248%^stumpy%^C111%^ legs.%^CRST%^\n",
    ({"floor","flagstone"}) : "%^C243%^The floor here is simple flagstone%^CRST%^",
    ]));


set_smell("default","%^C221%^You smell rich %^C214%^dyes%^C221%^ and clean %^C142%^cloth%^C221%^.%^CRST%^");
set_listen("default","%^C101%^With all the fabric, sounds seem %^C060%^muted%^C101%^ here.%^CRST%^");


   set_exits(([

          "north" : TOWN"tailors_shop",
          "south" : TOWN"leatherwork",
          "northwest" : TOWN"foyer",
          "southwest" : TOWN"metals_vendor",
          "west" : TOWN"garden",
          
   ]));

}

void reset()
{
	::reset();
	if(!present("trader"))
	{
	   new(MOBS"marina")->move(TO);
	}
}

