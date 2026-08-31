#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_name("Whit's Kitchen");
    set_long("The ceilings are very high in the kitchen just like "
      "all of the other rooms in the house.  A marble countertop "
      "is against the eastern wall.  Knives and other cooking "
      "utensils are ontop of the countertop.");
    set_short("Whit's Kitchen");
    set_smell("default", "A sweet aroma comes from the oven");
    set_items(([
	({"marble countertop", "countertop"}):"Its made from marble!",
	"knives":"There very sharp.",
	"utensils":"Various sharp objects that Whit's cooks play with.",
      ]));
    set_exits(([
	"south":"/d/tirun/houses/whit/livingroom",
      ]));
}


