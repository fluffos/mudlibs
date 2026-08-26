

#include <std.h>
#include "../graez.h"

inherit CORE;

void create() {
    ::create();

    set_travel(PAVED_ROAD);
    set_terrain(CITY);
    set_property("indoors",0);

    set_name("scarred battlefield");
    set_short("%^C142%^scarred battlefield%^CRST%^");
    set_long("This area has been %^C059%^blasted %^CRST%^by "+
	"years of %^C124%^battle %^CRST%^and is filled with "+
	"%^C242%^ruins %^CRST%^and %^C058%^debris%^CRST%^. "+
	"The %^C094%^ground %^CRST%^itself is chewed up "+
	"from charges and from %^C124%^blasts %^CRST%^from "+
	"spells. Very little %^C028%^foliage %^CRST%^has "+
	"survived. To the west you see %^C060%^city walls%^CRST%^, "+
	"the north a %^C243%^mountain range%^CRST%^ and "+
	"to the south the %^C111%^ocean%^CRST%^.\n");


    set_items(([
        ({"ruins"}) : "There are %^C059%^ruins %^CRST%^here where at some point the Graez forces tried to build %^C243%^fortifications%^CRST%^. Now though they are destroyed and useless.",
	    ({"ground"}) : "The %^C094%^ground %^CRST%^here has been %^C088%^marred %^CRST%^with the constant battle. Very little could grow here",
    ]));

    set_smell("default","You smell %^C241%^ash %^CRST%^and %^C088%^blood%^CRST%^.");
    set_listen("default","You smell the %^C244%^battle %^CRST%^all around you.");

}

