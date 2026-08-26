// Atrium for Port Serith Institute

#include <std.h>
#include "../../serakii.h"

inherit ROOM;

void create() {
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);

    set_name("atrium");
    set_property("light",2);
    set_short("%^C029%^a%^C028%^t%^C029%^ri%^C028%^u%^C029%^m%^CRST%^");
set_long("This large, circular %^C029%^atrium %^CRST%^is surrounded by covered galleries and covered by a spectacular %^C221%^glass %^CRST%^and %^C208%^copper dome%^CRST%^. %^C248%^Stone paths%^CRST%^ lead from enormous, decorated %^C248%^arches %^CRST%^in the cardinal directions towards the central forum; a series of %^C094%^broad wooden steps%^CRST%^ that serve as %^C094%^seating%^CRST%^ leading to a %^C059%^sunken platform%^CRST%^. Beyond the forum a series of %^C028%^formal gardens%^CRST%^ are being installed, currently all %^C094%^churned ground%^CRST%^ and %^C028%^planted saplings%^CRST%^. To the %^C045%^north%^CRST%^, one can see the Institute's grand foyer, and apprentices of woodwork; apprentices of %^C142%^tailoring %^CRST%^and leatherwork move to and from the %^C045%^east%^CRST%^; apprentices of armorsmithing, %^C248%^weaponsmithing%^CRST%^, and %^C220%^jewelling %^CRST%^congregate to the %^C045%^south%^CRST%^; apprentices of enchanting and brewing spend the majority of their time to the %^C045%^west%^CRST%^.\n");

    set_items(([
    ({"dome"}) : "This %^C248%^enormous dome%^CRST%^ arches high overhead, %^C159%^cut glass%^CRST%^ reinforced with %^C178%^copper%^CRST%^. There are several concentric circles, the lines defining triangular and trapezoidal pieces of %^C159%^glass %^CRST%^interrupted by round, %^C133%^colored orbs%^CRST%^ that refract the light and %^C037%^cast rainbows%^CRST%^ in the atrium below. The bottom ring takes up two thirds the space and evokes sacred geometry with its multitude of overlapping curved lines creating a %^C248%^lotus flower%^CRST%^ effect, orbs embedded in each point.\n",
    ({"forum"}) : "The circular form is meant as a gathering place, %^C094%^four cardinal staircases%^CRST%^ giving access to the broader %^C094%^taller steps%^CRST%^. Here students may sit or lounge, attend theoretical lectures, debate %^C248%^techniques %^CRST%^and %^C079%^materials%^CRST%^, or simply %^C037%^socialize %^CRST%^and enjoy their lunch.\n",
    ({"garden"}) : "These %^C028%^gardens %^CRST%^will someday grow to provide the %^C029%^herbalists %^CRST%^with materials %^C043%^medicinal%^CRST%^ and otherwise, the %^C094%^woodworkers %^CRST%^with aid in identifying %^C028%^exotic trees%^CRST%^, dye plants for %^C222%^tailors %^CRST%^and %^C142%^leatherworkers%^CRST%^, and students with the pleasure of a %^C046%^lush %^CRST%^environment. For now these are all dreams and plans, %^C028%^saplings %^CRST%^amidst %^C094%^damp churned earth%^CRST%^, staked with small labels to identify what has been planted and where.\n",
    ]));


set_smell("default","%^C094%^The atrium currently smells of fresh-turned soil.%^CRST%^");
set_listen("default","%^C044%^Sounds of conversation, laughter, and occasional disagreement fill the atrium.%^CRST%^");


   set_exits(([

          "south" : TOWN"metals_vendor",
          "north" : TOWN"foyer",
          "east" : TOWN"fabric_vendor",
          "west" : TOWN"herb_vendor",


   ]));

}
