// mmountain - LoKi 2022

#include <std.h>
#include "../graez.h"

inherit ROOM;

void create() {
    set_terrain(ROCKY);
    set_travel(RUBBLE);
    set_property("indoors",0);
    set_name("rough mountain trail");
    set_short("%^C060%^rough mountain trail%^CRST%^");
    set_long("The %^C060%^path%^CRST%^ along the %^C240%^mountain%^CRST%^ "+
        "switches back and forth aggressively to head through the only "+
        "traversable %^C060%^paths%^CRST%^ between %^C239%^high mountain tops%^CRST%^. "+
        "The %^C060%^rocks%^CRST%^ around you are %^C067%^jagged%^CRST%^ and any misstep "+
        "would mean almost %^C066%^certain death%^CRST%^ as you tumbled down. There is "+
        "no %^C028%^vegetation%^CRST%^ here, either something has eaten it all or "+
        "the %^C240%^rock%^CRST%^ is too inhospitable for anything to grow. On all "+
        "sides of you are %^C241%^bleak mountains%^CRST%^ but knowing there is "+
        "a %^C088%^pitched battle%^CRST%^ against the %^C061%^undead%^CRST%^ so close "+
        "by the relative %^C153%^silence%^CRST%^ and %^C147%^safety%^CRST%^ of a bad "+
        "fall is almost calming. This high up the %^C075%^sky%^CRST%^ reaches out "+
        "impossibly around you.\n");
    set_items(([
      ({"rocks","trail"}) : "All around you are %^C241%^massive jagged "+
      "rocks%^CRST%^. This %^C060%^trail%^CRST%^ seems to be seldom passed and "+
      "switches back and forth as you go up and back down the %^C241%^mountain%^CRST%^.\n",
      ({"sky"}) : "The %^C081%^sky%^CRST%^ this high up stretches out above you.\n",

    ]));

set_smell("default","You smell %^C081%^crisp clean air%^CRST%^");
set_listen("default","everything %^C243%^echos%^CRST%^ a thousand times around you.");

}



