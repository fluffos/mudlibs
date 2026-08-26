#include <std.h>
#include "../graez.h"

inherit CORE;

void create() {
    ::create();

    set_terrain(DESERT);
    set_travel(DIRT_ROAD);
    set_property("indoors",0);

    set_name("desert");
    set_short("%^C142%^desert%^CRST%^");
    set_long("The land around you is a %^C060%^dry "+
	"desert%^CRST%^. Little at all can grow here and "+
	"course %^C058%^debris filled%^CRST%^ %^C116%^wind "+
	"%^CRST%^blows everywhere. There are not massive "+
	"%^C220%^sand dunes%^CRST%^, instead there are "+
	"more %^C243%^rocky outcroppings%^CRST%^ and "+
	"simply a void of %^C141%^life %^CRST%^or "+
	"%^C111%^water %^CRST%^here. It is truly "+
	"%^C142%^desolate%^CRST%^. Off to the west you "+
	"can see a %^C028%^forest%^CRST%^ and the %^C060%^walls "+
	"of a city%^CRST%^. To the north is a %^C245%^mountain "+
	"range%^CRST%^, and the %^C111%^ocean %^CRST%^to "+
	"the south.\n");


    set_items(([
        ({"ground","outcroppings"}) : "The ground here is %^C142%^desolate %^CRST%^and devoid of life. There is a small amount of %^C245%^pebbles %^CRST%^and %^C244%^rocks %^CRST%^but little else.",
    ]));

    set_smell("default","%^CRST%^you smell %^C245%^little %^CRST%^here.");
    set_listen("default","%^CRST%^The %^C188%^wind %^CRST%^tears through the area.");

}
