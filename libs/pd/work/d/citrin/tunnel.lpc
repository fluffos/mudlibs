#include <std.h>

inherit VIRTUALSERVER;
void create() {
    ::create();
    set_how_long(1);
    set_day_sentances( ({
	"The ancient tunnels span under the great Citrin forest.  The "
	"tunnels must have been made by some ancient race.  Roots dangle "
	"from the ceiling.  The walls are made of nothing but dirt.  "
	"Small lamp holders on the sides of the walls provide light "
	"throughout the narrow corridors."
      }) );
    set_night_sentances( ({
	"The ancient tunnels span under the great Citrin forest.  The "
	"tunnels must have been made by some ancient race.  Roots dangle "
	"from the ceiling.  The walls are made of nothing but dirt.  "
	"Small lamp holders on the sides of the walls provide light "
	"throughout the narrow corridors."
      }) ); 
    set_item_list(([ 
	({"lamp", "lamp holder", "lamp holders", "lamps"}):"The lamps provide "
	"light throughout the narrow corridors.",
      ]));
    set_properties( ([ "light" : 1,
	"night light" : 1,
	"indoors" : 1,
      ]) );
    set_short("Tunnels beneath the Citrin Forest");
}

