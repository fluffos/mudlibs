// institute shop Port Serith Institute

#include <std.h>
#include "../../serakii.h"

inherit ROOM;

void create() {
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);

    set_name("Institute Shop");
    set_property("light",2);
    set_short("%^C029%^I%^C043%^"+
	"n%^C029%^stit%^C045%^u%^C029%^te "+
	"Sh%^C045%^o%^C029%^p%^CRST%^");
    set_long("This room is more %^C143%^"+
	"bare %^CRST%^than most of the rooms "+
	"in the %^C045%^Institute%^CRST%^. The "+
	"%^C248%^simple flagstone%^CRST%^ floor "+
	"is covered with a fine %^C243%^gray "+
	"carpet%^CRST%^ and a %^C094%^long oak "+
	"table%^CRST%^ is set against the western "+
	"wall. What does catch your attention is "+
	"the massive %^C231%^white flag%^CRST%^ "+
	"hangs on the wall.\n");

    set_items(([
    ({"table"}) : "This ten foot %^C094%^oak "+
	"table%^CRST%^ has a series of %^C245%^"+
	"tools%^CRST%^ and %^C059%^kits %^CRST%^set out on it. Everything a junior student would need is here. \n",
    ({"tools","kits"}) : "%^C060%^Kits %^CRST%^"+
	"and %^C244%^tool sets%^CRST%^ for "+
	"repairing %^C245%^armor%^CRST%^, "+
	"%^C226%^jewelry%^CRST%^, %^C110%^"+
	"clothing %^CRST%^and %^C094%^leatherwork%^CRST%^ "+
	"are carefully laid out on the %^C094%^"+
	"table%^CRST%^. While not the top of the "+
	"end equipment masters would use, these "+
	"tool sets would suit a student or "+
	"journeyman quite well. \n",
    ({"flag"}) : "This %^C255%^massive "+
	"white flag%^CRST%^, easily ten foot wide, "+
	"is made from the %^C255%^purest white "+
	"silk%^CRST%^ and has been %^C060%^"+
	"painted %^CRST%^with the utmost care "+
	"and precision. The cost of such an item "+
	"would be astronomical though you get "+
	"the impression it was made by the masters "+
	"here at the %^C045%^Institute%^CRST%^. On "+
	"the flag are %^C245%^three towers%^CRST%^, "+
	"with a %^C243%^crossed hammer%^CRST%^ "+
	"and %^C243%^needle%^CRST%^. Underneath "+
	"in common is written in flowing script "+
	"three words. %^C043%^Reclaim%^CRST%^, "+
	"%^C043%^Rebuild%^CRST%^, %^C043%^Prosper%^CRST%^.\n",
    ]));


set_smell("default","%^C059%^No specific smell here is evident.%^CRST%^");
set_listen("default","With all the fabric sounds eem muted here.");


   set_exits(([

          "north" : TOWN"brewery",
          "south" : TOWN"lab",
          "northeast" : TOWN"foyer",
          "southeast" : TOWN"metals_vendor",
          "east" : TOWN"garden",

   ]));

}

void reset()
{
        ::reset();
        if(!present("trader"))
        {
           new(MOBS"rasdal")->move(TO);
        }
}

