// Woodshop for Port Serith Institute

#include <std.h>
#include "../../serakii.h"

inherit ROOM;

void create() {
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);

    set_name("woodshop");
    set_property("light",2);
set_short("%^C094%^w%^C095%^o%^C094%^odsh%^C095%^o%^C094%^p%^CRST%^");
set_long("A few steps down from the %^C094%^foyer "+
"%^CRST%^leads to the woodshop. Though %^C060%^"+
"apprentices %^CRST%^are tasked with keeping the "+
"space tidy, it's active nature ensures a perpetual "+
"buildup of %^C094%^woodchips %^CRST%^and %^C101%^"+
"dust %^CRST%^in the corners. The %^C248%^flagstone "+
"floor%^CRST%^ has orderly rows of %^C094%^work "+
"benches%^CRST%^, both tall and low, and a "+
"pedal-powered %^C059%^pole lathe%^CRST%^ sits "+
"to one side. %^C251%^Plastered walls%^CRST%^ are "+
"lined with %^C248%^tools%^CRST%^, %^C117%^teaching "+
"devices%^CRST%^, %^C094%^shelves%^CRST%^ holding "+
"various %^C245%^mechanics %^CRST%^such as %^C248%^"+
"stops %^CRST%^and %^C095%^vices%^CRST%^, and "+
"%^C094%^materials %^CRST%^for current and immediate "+
"projects. %^C094%^Boxes%^CRST%^ of %^C060%^scrap "+
"materials%^CRST%^ for practice seem to multiply "+
"at an alarming rate, vying for space with "+
"partially-completed projects. Practical household "+
"objects such as %^C094%^furniture%^CRST%^, %^C095%^"+
"storage boxes%^CRST%^ and %^C209%^bread bowls%^CRST%^ "+
"sit side by side with %^C248%^weapons%^CRST%^, "+
"%^C081%^instruments %^CRST%^and objects intended for "+
"%^C044%^enchanting%^CRST%^. Suspended from the ceiling "+
"above is a partially completed %^C094%^hull of a "+
"boat%^CRST%^. %^C111%^Windows %^CRST%^overhead "+
"have %^C190%^charms %^CRST%^etched into them, ensuring "+
"they provide %^C111%^air circulation%^CRST%^ even on "+
"days with %^C110%^still wind%^CRST%^. Particles "+
"of %^C142%^wood dust%^CRST%^ swirl in the light.\n");

    set_items(([
    ({"tools"}) : "There are %^C060%^tools %^CRST%^of "+
	"all sizes and shapes, %^C248%^large axes%^CRST%^ such "+
	"as %^C108%^adzes%^CRST%^; %^C242%^chisels %^CRST%^and "+
	"%^C095%^gouges%^CRST%^; %^C102%^draw-knives%^CRST%^ "+
	"and %^C103%^planes %^CRST%^from large to miniature; "+
	"various %^C248%^saws %^CRST%^and %^C094%^mallets%^CRST%^; "+
	"measuring and marking tools such as %^C255%^chalk%^CRST%^, "+
	"%^C143%^lines%^CRST%^, %^C248%^awls%^CRST%^, %^C059%^"+
	"twyvettes%^CRST%^, %^C095%^squares %^CRST%^and %^C248%^"+
	"compasses%^CRST%^. Each of these tools are either in "+
	"use, or precicely where they belong.\n",
    ({"teaching"}) : "There are a collection of items in "+
	"cross-section or parital construction, %^C094%^boxes "+
	"of wood samples%^CRST%^, a set of %^C059%^joinery "+
	"%^CRST%^examples, and the all important pile of 'this "+
	"is what happens when something goes wrong' - %^C247%^"+
	"over-tensioned instruments%^CRST%^ that snapped; "+
	"%^C022%^green wood%^CRST%^ that shrank, twisted, or "+
	"cracked as it dried too quickly; %^C142%^split "+
	"arrows%^CRST%^ nocked along the grain instead of "+
	"across it; a %^C094%^snapped bow%^CRST%^ drawn "+
	"too far without first being warmed up; a fine "+
	"looking %^C158%^bowl %^CRST%^ruined by an unexpected "+
	"knot - several of these items have %^C088%^blood "+
	"stains%^CRST%^.\n",
    ({"benches"}) : "%^C094%^Benches %^CRST%^are of "+
	"various heights, some intended to be straddled "+
	"while others stood at. The have %^C246%^holes %^CRST%^and "+
	"slot to fit aids such as %^C060%^stops %^CRST%^into.\n",
({"floor","flagstone"}) : "The floor here is simple flagstone.\n",
    ]));


set_smell("default","%^C094%^This area is filled with the satisfying scent of cut wood.%^CRST%^");
set_listen("default","%^C059%^A cacophany of hammering, wood shaving, sawing, and conversation mingles together.%^CRST%^");


   set_exits(([

          "east" : TOWN"foyer",

   ]));

}
