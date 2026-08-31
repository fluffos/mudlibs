#include <std.h>
#include <amun.h>
inherit ROOM;

void init() {
    ::init();
    add_action("read", "read");
}

void create() {
    ::create();
    set_properties( ([ "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"night light" : 2,
	"no steal"    : 1 ]) );
    set("short", "The Cathedral Restaurant");
    set("long",
      "%^BOLD%^%^WHITE%^The C%^RESET%^a%^BOLD%^%^WHITE%^th%^RESET%^e%^BOLD%^%^WHITE%^dr%^RESET%^a%^BOLD%^%^WHITE%^l Restaurant%^RESET%^\n" 
      "%^BOLD%^%^WHITE%^This room has small posters hanging across the walls of healthy fruits and veggies. Aside from promoting healthy foods, this room is quite small and has a short curly %^YELLOW%^blonde haired %^WHITE%^owner standing behind the counter. A cool breeze flows through, allowing the smell bananas to dominate the room. Tinonia, has a sign on the wall for all to read.%^RESET%^");
    set_smell("default", "%^BOLD%^%^YELLOW%^The smell of bananas moves through the air.%^RESET%^");
    set_items(([ "posters"  : "%^BOLD%^%^WHITE%^These posters are here for customers to see the delight veggies and fruits can provide.%^RESET%^" ]));
    set_exits(([ "north" : SKYROOM "ls_5" ]));
}

void reset() {
    ::reset();
    /*
	    new("/std/obj/player_list")->move(this_object()); 
    */
    if(!present("tinonia")) 
	new(SKYMOB "tinonia")->move(this_object());
}

int read(string str) {
    object ob;
    ob = present("tinonia");
    if(!ob) {
	write("You cannot read the menu, as it is splattered with blood.");
	return 1;
    }
    write("The menu lists different foods along with prices:");

    write("--------------------------------------------------------------------");
    message("info", "A Carrot\t\t\t"+ob->get_price("carrot")+" gold", this_player());
    message("info", "An Apple\t\t\t"+(int)ob->get_price("apple")+" gold", this_player());
    message("info", "A Banana\t\t\t"+(int)ob->get_price("banana")+" gold", this_player());
    write("-----------------------------------------------------------");
    write("<buy [dish_name]> gets you the food.");
    return 1;
}
