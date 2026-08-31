#include <std.h>
#include <nushae.h>

inherit ROOM;

void create() {
  ::create();
    set_properties((["light" : 2, "night light" : 2, "beach" : 1]) );
    set_short("South Anga Street");
    set_smell("default", "Heated metal and smelted iron release harsh smells around the area.");
    set_listen("default", "The noise of the busy public square is washed away by the sounds of metal works.");
    set_long("Anga Street shows heavy signs of usage, by feet and carts carrying large loads of %^BOLD%^%^BLACK%^Iron%^RESET%^ and %^BOLD%^%^GREEN%^Seaweed%^RESET%^. To the north is the busy and loud NuShae Public Square. Further south is a shop and the path towards the %^BOLD%^%^BLACK%^Iron Mines%^RESET%^. Southeast the farms can be seen.");
    set_night_long("Anga Street is deserted, except for the odd animal here and there. Lights can be seen north, marking the Public Square of NuShae. Lamps are lit towards the south and southeast.");
    set_items((["mines" : "The %^BOLD%^%^BLACK%^Iron mines%^RESET%^ of NuShae are legendary for their fine deposits of Iron Ore, easily made into weapons and armour for the fighting members of the guardians of NuShae.", "farms" : "%^BOLD%^%^GREEN%^Seaweed%^RESET%^ in all its abundance can be found farmed to the south.", "lights" : "The bright lights mark the presence of the NuShae Public Square.", "street" : "Many ditches and holes mark the street, showing clear signs of heavy use by heavy loads."]));
    set_exits( (["north" : ROOMS "t1", "south" : ROOMS "iron1"]) );
}
