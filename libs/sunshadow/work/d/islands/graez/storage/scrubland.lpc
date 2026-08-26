

#include <std.h>
#include "../graez.h"

inherit CORE;

void create() {
    ::create();

    set_travel(PAVED_ROAD);
    set_terrain(SCRUB_LANDS);
    set_property("indoors",0);

    set_name("scrubland");
    set_short("%^C064%^scrubland%^CRST%^");
    set_long("The area around you is filled with "+
	"%^C064%^long hearty grasses%^CRST%^ and little "+
	"else. Otherwise most of the %^C094%^ground "+
	"%^CRST%^is %^C244%^hard rock%^CRST%^. The "+
	"signs of %^C088%^battle %^CRST%^are everywhere. "+
	"The ground is %^C060%^scarred %^CRST%^from "+
	"battle and the %^C034%^grass %^CRST%^is all "+
	"that has survived. To the west you can see "+
	"the %^C060%^city walls%^CRST%^, to the north "+
	"a %^C241%^mountain range%^CRST%^, and to the "+
	"south, the %^C111%^ocean%^CRST%^.\n");


    set_items(([
        ({"grass","grasses"}) : "Short %^C064%^hearty grass%^CRST%^ grows in clumps amongst the %^C243%^rocks%^CRST%^.",
        ({"ground"}) : "The %^C094%^ground %^CRST%^has been %^C059%^scarred %^CRST%^from battle and horrible %^C134%^magics %^CRST%^that have been used.",
    ]));

    set_smell("default","You smell %^C241%^ash %^CRST%^and %^C088%^blood%^CRST%^.");
    set_listen("default","You smell the %^C244%^battle %^CRST%^all around you.");

}

