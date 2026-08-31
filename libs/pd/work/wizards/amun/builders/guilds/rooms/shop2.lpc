#include <std.h>
#include <guild.h>
inherit ROOM;

void init() {
    ::init();
    add_action("read", "read");
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "The Guild Town Restaurant");
    set("long",
      "%^RED%^The GT Restaurant%^RESET%^\n" 
      "%^BOLD%^%^BLACK%^Mixtures of foods can be smelled throughout the room. There are tables placed against the wall, leaving the center open. A small girl sits on a chair behind the front counter. Next to the counter is a sign for customers to read. %^RESET%^");
    set_smell("default", "An array of smells filters through the air.");
    set_items(([
	"tables"  : "The tables are lined against the walls, allowing a large open space in the middle of the room.",
	"counter" : "The counter has sweets placed sparatically across it. Next to the counter is a sign for customers to read."
      ]));
    set_exits((["north" : GROOM"l_main2"]));
}

void reset() {
    ::reset();
    if(!present("dru")) 
	new(GMOB"dru")->move(this_object());
}

int read(string str) {
    object ob;

    ob = present("dru");
    if(!ob) {
	write("You cannot read the menu, as it is %^RED%^splattered with blood.%^RESET%^");
	return 1;
    }
    write("The menu lists different foods along with prices:");
    write("--------------------------------------------------------------------");
    write("cornbread\t\t"+ob->get_price("cornbread")+" gold");
    write("pickled beak\t\t"+ob->get_price("pickled beak")+" gold");
    write("angelcake\t\t"+ob->get_price("angelcake")+" gold");
    write("pygmy cupcake\t\t"+ob->get_price("pygmy cupcake")+" gold");
    write("ribeye steak\t\t"+ob->get_price("ribeye steak")+" gold");
    write("-----------------------------------------------------------");
    write("<buy [dish_name]> gets you the food.");
    return 1;
}
