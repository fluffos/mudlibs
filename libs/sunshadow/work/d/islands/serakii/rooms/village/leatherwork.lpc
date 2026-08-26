// leatherwork Port Serith Institute

#include <std.h>
#include "../../serakii.h"

inherit ROOM;

void create() {
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);

    set_name("leathercraft workshop");
    set_property("light",2);
    set_short("%^C094%^le%^C060%^a%^C094%^therc%^C060%^r%^C094%^aft "+
    "w%^C060%^o%^C094%^rksh%^C060%^o%^C094%^p%^CRST%^");
set_long("This large %^C060%^workshop%^CRST%^ is sectioned in two; "+
"at the far end a series of %^C244%^deep stone troughs%^CRST%^ "+
"filled with %^C070%^foul substances%^CRST%^ soak %^C143%^hides%^CRST%^ "+
"to depilate and preserve them as %^C095%^leather%^CRST%^. There is a "+
"line engraved into the floor just before this area with %^C044%^arcane "+
"script%^CRST%^, and a %^C037%^shimmering%^CRST%^ to the air above; "+
"stepping beyond it, one is assaulted with strong and unpleasant scents "+
"of %^C220%^ammonia%^CRST%^ and %^C109%^decay%^CRST%^. The odour is kept "+
"from being overwhelming by %^C049%^charms%^CRST%^ to freshen the "+
"%^C111%^air%^CRST%^, but it can't be suppressed entirely. On the other "+
"side of that line, %^C142%^furs%^CRST%^ and %^C094%^hides%^CRST%^ are "+
"stretched on %^C094%^frames%^CRST%^, %^C251%^scraped%^CRST%^, "+
"%^C231%^salted%^CRST%^ and %^C109%^drying%^CRST%^. The centre of the "+
"room is littered with %^C094%^work tables%^CRST%^, %^C094%^stools%^CRST%^, "+
"and cobbler's %^C094%^benches%^CRST%^. Various %^C244%^tools%^CRST%^ are "+
"set out on the %^C094%^desks%^CRST%^ and kept near at %^RESET%^hand, though "+
"%^C094%^shelves%^CRST%^ along the walls contain larger %^C060%^jars of "+
"oils%^CRST%^ and %^C041%^dyes%^CRST%^, %^RESET%^lasts of all sizes, and some "+
"communal materials such as %^C142%^hide cordage%^CRST%^. Smaller "+
"projects sit there, out of the way when not being actively worked on, "+
"while larger items such as %^C244%^armour%^CRST%^ sit on their own racks.\n");

    set_items(([

    ({"tools"}) : "A wide array of %^C246%^tools%^CRST%^ are used in the "+
    "%^C061%^workshop%^CRST%^, some specially made, while others seem to "+
    "be just found objects that got a job done. There are %^C252%^bone "+
    "awls%^CRST%^, %^C248%^needles%^CRST%^ straight and curved, %^C220%^burnishers%^CRST%^, "+
    "%^C220%^brass stamps%^CRST%^ to impress patterns into the surface, "+
    "edging and carving %^C244%^knives%^CRST%^, %^C094%^lasts%^CRST%^ "+
    "and %^C094%^headforms%^CRST%^ to shape shoes and hats, curved "+
    "lunellum %^C250%^knives%^CRST%^, and %^C060%^jars of oil%^CRST%^, "+
    "%^C220%^beeswax%^CRST%^, %^C226%^hide glue%^CRST%^, and %^C231%^salt%^CRST%^.",
    ({"projects"}) : "A wide variety of products are being produced. Large "+
    "items such as %^C094%^leather armor%^CRST%^ and %^C059%^furniture%^CRST%^ "+
    "catch the eye, some simple and others embossed or dyed. Cobblers "+
    "craft %^C136%^shoes%^CRST%^ and %^C094%^boots%^CRST%^, while others "+
    "create household goods such as bags, waterskins, and protective cases. "+
    "The finest, most delicate work are done for scribes; splitting leather "+
    "paper-thin for %^C221%^book covers%^CRST%^, to transparent range from "+
    "thick armor to delicate book covers and %^C143%^parchment%^CRST%^.",
    ({"troughs"}) : "Most of these %^C246%^troughs%^CRST%^ are not something "+
    "one would want to put their hand in unprotected. One trough appears to "+
    "simply be water; the next trough is filled with %^C227%^golden liquid%^CRST%^ "+
    "depilating furs; another is %^C060%^murky%^CRST%^ and %^C058%^brown%^CRST%^ "+
    "with bits of %^C094%^wood%^CRST%^ and %^C060%^bark%^CRST%^ soaking "+
    "the %^C094%^leather%^CRST%^ in %^C175%^vegetable tannins%^CRST%^; next to "+
    "this, %^C172%^rawhides%^CRST%^ rest covered in a slurry of %^C200%^brains%^CRST%^; "+
    "in the final trough delicate calf%^C222%^ %^CRST%^and %^C059%^goat%^CRST%^ "+
    "skins soak in an %^C229%^lime%^CRST%^ mixture to produce %^C143%^parchment%^CRST%^.",

    ]));

set_smell("default","%^C142%^The room smells of leather, oil and wax, with "+
"the faintest undercurrent of ammonia.%^CRST%^");
set_listen("default","%^C247%^Conversation mingles with the sounds of "+
"crafting; hobnails being hammered, flesh being scraped.%^CRST%^");

   set_exits(([

          "north" : TOWN"fabric_vendor",
          
   ]));

}


