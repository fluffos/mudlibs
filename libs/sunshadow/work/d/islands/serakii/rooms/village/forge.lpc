// Grand Forge for Port Serith Institute

#include <std.h>
#include "../../serakii.h"

inherit ROOM;

void create() {
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_property("smithy",1);
    set_name("grand forge");
    set_property("light",3);
    set_short("%^C242%^g%^C245%^r%^C242%^a%^C088%^"+
	"n%^C242%^d f%^C245%^o%^C242%^r%^C088%^"+
	"g%^C245%^e%^CRST%^");
set_long("This end of the %^C246%^smithing "+
"%^CRST%^wing is dominated by the %^C242%^"+
"enormous for%^C244%^g%^C242%^e%^CRST%^, "+
"around which everything seems to revolve. "+
"Shaped to look like a %^C088%^monstrous "+
"dragon head%^CRST%^, the open jaws serve as "+
"%^C124%^hearth%^CRST%^. %^C196%^Dragonfire "+
"%^C124%^flickers %^CRST%^and %^C052%^pulses "+
"%^CRST%^in the %^C245%^throat %^CRST%^of the "+
"thing, belching outwards as the %^C095%^"+
"massive bellows%^CRST%^ are worked; the %^C186%^"+
"air %^CRST%^around it %^C215%^shimmers %^CRST%^"+
"from the %^C088%^heat%^CRST%^, becoming more "+
"oppressive the nearer one gets. %^C244%^Smoke "+
"%^CRST%^the %^C241%^forge %^CRST%^generates "+
"escapes the %^C088%^dragon's nostrils%^CRST%^, "+
"twin plumes billowing up to collect in the %^C242%^"+
"blackened ceiling%^CRST%^ before drifting out "+
"the open roof vent. Surrounding the forge are a "+
"fan of %^C241%^anvils %^CRST%^and %^C060%^"+
"troughs%^CRST%^, allowing multiple people to "+
"work projects at once. The space is cluttered "+
"will all manner of %^C242%^tools %^CRST%^to "+
"%^C094%^hammer%^CRST%^, %^C058%^pierce%^CRST%^, "+
"%^C109%^draw%^CRST%^, and %^C198%^cast%^CRST%^; "+
"chaos to the uninitiated when in reality, every "+
"%^C242%^tool %^CRST%^has its place. %^C094%^"+
"Enormous barrels%^CRST%^ of %^C111%^water%^CRST%^"+
", %^C220%^oil%^CRST%^, and more %^C050%^mysterious "+
"substances%^CRST%^ line part of one wall, with "+
"%^C094%^heavy aprons%^CRST%^, %^C095%^gloves%^CRST%^"+
", and %^C060%^protective masks%^CRST%^ hanging next "+
"to them. Along the other wall are %^C094%^"+
"shelves%^CRST%^, %^C094%^barrels %^CRST%^and "+
"%^C094%^crates %^CRST%^storing various projects "+
"students have been working on; piles of %^C245%^"+
"slag%^CRST%^ have been shoved into the corner, "+
"removed daily by apprentices. %^C062%^Arcane "+
"symbols%^CRST%^ have been carved into the centre "+
"of the %^C243%^flagstone floor%^CRST%^ here, "+
"protecting against uncontrolled spread "+
"of %^C124%^fire%^CRST%^.\n");

    set_items(([
    ({"forge"}) : "%^C243%^Grates %^CRST%^circle "+
	"the base of the %^C241%^forge%^CRST%^, allowing "+
	"%^C111%^air%^CRST%^ to be sucked in. A large set "+
	"of %^C095%^bellows %^CRST%^crafted of imbued "+
	"%^C241%^Fernian Ash%^CRST%^ and %^C052%^dragonskin "+
	"leather%^CRST%^ stands as tall as a human adult, "+
	"and are operated using a %^C095%^long lever%^CRST%^ "+
	"to amplify force. The %^C241%^forge %^CRST%^itself "+
	"seems to be made of a %^C088%^red stone%^CRST%^, "+
	"glimmering in such a fashion as to suggest some "+
	"%^C052%^crystaline %^CRST%^content. The shape of "+
	"it is eerily life-like, as if the jaws might "+
	"snap shut at any moment. What's curious is there "+
	"seems to be no %^C241%^coal %^CRST%^in the belly "+
	"of this %^C241%^furnace%^CRST%^, though there is "+
	"the sensation of a %^C088%^heart beat%^CRST%^ at "+
	"the edge of hearing.\n",
    ({"heart","heart beat"}) : "If one dares approach close "+
	"enough to the %^C241%^forge %^CRST%^to bear its "+
	"%^C088%^scorching heat%^CRST%^, they might find "+
	"the source of it's %^C196%^flame%^CRST%^; the "+
	"still-beating %^C196%^heart %^CRST%^of an %^C088%^"+
	"ancient red dragon%^CRST%^. It %^C226%^flares %^CRST%^"+
	"and %^C196%^spits fire%^CRST%^ with each pull of "+
	"the %^C094%^bellows%^CRST%^.\n",
    ({"projects"}) : "Items range from blacksmithed "+
	"mundane requirements of daily life such "+
	"as %^C241%^nails%^CRST%^, %^C059%^hinges%^CRST%^, "+
	"%^C245%^tools %^CRST%^and %^C136%^horseshoes%^CRST%^, "+
	"through to a multitude of %^C220%^kne cops%^CRST%^ "+
	"and %^C247%^daggers%^CRST%^, learning pieces for "+
	"the newer students. Journeymen projects include "+
	"more exotic materials such as %^C254%^Mithril %^CRST%^"+
	"and %^C045%^Arundur%^CRST%^; a set of "+
	"in-progress %^C043%^Sirithian Banded%^CRST%^ Mail "+
	"indicates an advanced student.\n",
({"floor","flagstone"}) : "The floor here is simple flagstone.\n",
    ]));


set_smell("default","%^C220%^The acrid scent of molten metal "+
"mingles with sweat and a subtle sweet scent%^CRST%^.");
set_listen("default","%^C196%^A constant tinging of "+
"metal-on-metal accompanies the rhythmic roar of the "+
"forge. Tickling at the edge of hearing, more felt than "+
"heard, is the ever-present beating of a heart.%^CRST%^");


   set_exits(([

          "east" : TOWN"metals_vendor",

   ]));

}
