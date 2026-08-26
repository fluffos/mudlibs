// brewery lab Port Serith Institute

#include <std.h>
#include "../../serakii.h"

inherit ROOM;

void create() {
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);

    set_name("brewery");
    set_property("light",2);
    set_short("%^C190%^br%^C142%^e%^C190%^we%^C142%^r%^C190%^y%^CRST%^");
set_long(" Thick %^C245%^stone tabletops%^CRST%^ support complex networks "+
"of %^C159%^alchemical glassware%^CRST%^ and %^C143%^burners%^CRST%^, "+
"%^C094%^four stools%^CRST%^ placed neatly at each one. %^C094%^Cabinets%^CRST%^ "+
"line the walls, some with %^C159%^glass doors%^CRST%^ displaying items inside, "+
"while others consist of a multitude of %^C059%^square drawers%^CRST%^, all "+
"neatly labeled for the ingredients they hold. The end of the room has a "+
"large %^C243%^slab of slate%^CRST%^ affixed to the wall, %^C043%^obscure "+
"alchemical%^CRST%^ equations, diagrams and notes scrawled over it in "+
"%^C231%^chalk%^CRST%^. A series of %^C245%^stone sinks%^CRST%^ that drain "+
"into a %^C094%^barrel%^CRST%^ are nestled into one corner, drying racks for "+
"equipment suspended overhead; nestled under these %^C094%^tables%^CRST%^ are "+
"several %^C094%^casks%^CRST%^, covered with a %^C073%^fabric curtain%^CRST%^. "+
"Overhead, %^C028%^herbs%^CRST%^ hang to dry. Despite this department being the "+
"cleanest of them all, with no ingredients left strewn or unattended, no "+
"%^C142%^spills%^CRST%^ not immediately cleaned up, there are already signs of "+
"wear; %^C242%^scorch%^CRST%^ marks betraying experiments gone wrong, and the "+
"desperate attempts to scrub them away.\n");


    set_items(([

    ({"glassware"}) : "%^C043%^Brightly colored%^CRST%^ %^C159%^liquids%^CRST%^ "+
    "are %^C124%^heated%^CRST%^ and %^C158%^bubble%^CRST%^ in the gourd-like "+
    "%^C159%^cucurbit%^CRST%^; the vapor flows up into beaked alembics of "+
    "various shapes and sizes leaving %^C059%^precipitate%^CRST%^ behind. It "+
    "then condenses and runs down the beak into the %^C159%^receiver%^CRST%^ "+
    "as %^C163%^distilled potion%^CRST%^. Similar processes appear to be "+
    "happening with %^C058%^dry%^CRST%^ ingredients in shorter, squatter "+
    "retorts, %^C248%^dust%^CRST%^ and %^C142%^grains%^CRST%^ changing color "+
    "as they are worked.",
    ({"cabinet"}) : "A series of %^C159%^glass-doored%^CRST%^ "+
    "%^C094%^cabinets%^CRST%^ lines the walls, alternating with neatly "+
    "labeled %^C094%^apothecary cabinets%^CRST%^. Inside the class cabinets "+
    "are shelves lined with %^C133%^medicine jars%^CRST%^ and %^C159%^bottles%^CRST%^, "+
    "also neatly labeled in elegant %^C248%^script%^CRST%^ and perfectly stoppered. "+
    "Inside them are all manner of ingredients; eyeballs, %^C246%^metal filings%^CRST%^, "+
    "%^C094%^herbs%^CRST%^, %^C178%^beetles%^CRST%^ to name but a few. On other "+
    "%^C094%^shelves%^CRST%^, racks holding rows of empty, %^C159%^sterile vials%^CRST%^ "+
    "sit next to stacks of %^C247%^crucibles%^CRST%^, %^C060%^clay jars%^CRST%^, "+
    "%^C247%^mortars%^CRST%^ and %^C247%^pestles%^CRST%^, and packages of "+
    "%^C143%^delicate papers%^CRST%^ for powders and tobacco. There are some books on "+
    "the topics of herbalism, alchemy, and brewing, and the odd cloche jar displaying "+
    "specimens such as skeletal birds, or enclosed, mossy ecosystems.",
    ({"casks"}) : "It should surprise no one that students with access to this "+
    "kind of equipment would take the opportunity for some extracurricular "+
    "experimentation - namely, the brewing of %^C051%^moonshine%^CRST%^. These "+
   "%^C094%^small barrels%^CRST%^ are kept out of the way; not so well hidden "+
    "the instructors could possibly be unaware of them, but unobtrusive enough "+
    "to allow plausible deniability.",

    ]));


set_smell("default","%^C041%^A confusion of pungent, sweet, herbal, and "+
"resinous scents combine with the sterile scent of chemicals "+
"used in cleaning.%^CRST%^");
set_listen("default","%^C060%^Bubbling, hissing, and drip-drip-dripping of distilling potions fills the room. There are only very rarely explosions.%^CRST%^");

   set_exits(([

          "south" : TOWN"herb_vendor",
          
   ]));

}

int is_lab(){ return 1;}

