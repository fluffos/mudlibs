#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_properties( ([ "light" : 2, "indoors" : 1]) );
    set_short("Venenum's Main Hall");
    set_long("This part of the den is a huge, gaping cavern which overlooks an undermountain lake. The roof of this cavern looks like an upturned bowl, dark grey in colour, with several small holes where flowing water has ebbed out little vents to let light and air in. It is possibly several hundred feet across, and equal that high at the highest point. The entire surface of the roof is smooth but not symetrical, inconsistancies in the water flow creating a wavy shape. The water itself is a deep, clear blue, being fresh and very pure. This could be a wonderful place to go for a swim. The only way out is one of the several shimmering teleport fields which lead to the square, and other places.");
    set_items(([
	"room" : "The dorm room is rather drab looking.",
      ]));
    set_smell("default", "There is a slightly damp smell here, and the air is humid.");
    set_listen("default", "Faint dripping water can be heard here.");
    set_exits( ([ 
	"dungeon" :  "/wizards/venenum/workroom/dungeon",
	"helena" :  "/wizards/helena/workroom",
	"square" :  "/d/nopk/tirun/square",
	"hall"  :  "/d/nopk/standard/adv_inner",
	"private"  :  "/wizards/venenum/workroom/private"
      ]) );
}
