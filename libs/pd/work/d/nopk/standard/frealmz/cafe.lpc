#include <std.h>

inherit ROOM;

void init() {
    ::init();
    add_action("read", "read");
}

void create() {
    ::create();
    set_property("light", 3);
    set_property("indoors", 1);
    set_property("no castle", 1);
    set("short", "The Golden Talon Cafe");
     set_long("Welcome to the Golden Talon Cafe! People "
              "from all over Asgard and even visitors in "
              "town gather here for a meal. When Talon is "
              "around, he'll be happy to serve you. A large menu "
             "has been hung on the far wall.");
    set_items(
	(["restaurant" : "The Golden Talon Cafe, home of "
	    "great Asgardian cuisine.",
	  "wall" : "The menu is posted there.",
	  "menu" : "You may read it if you like."]) );
      set_exits(([
      ]));
}

void reset() {
  ::reset();
    if(!present("talon")) 
      new("d/standard/frealmz/mob/talon")->move(this_object());
}

int read(string str) {
    object ob;
    int i;

    ob = present("talon");
    if(!ob) {
	write("You cannot read the menu, as it is splattered with blood.");
	return 1;
    }
    write("The following great foods are served here at the Golden Talon Cafe.");
    write("--------------------------------------------------------------------");
    write("A fresh crab\t\t\t"+ (int)ob->get_price("crab") + " gold");
    write("Perfectly cooked salmon\t\t"+(int)ob->get_price("salmon")+" gold");
   write("Some fries           \t\t"+(int)ob->get_price("fries")+" gold");
   write("A crispy leg of chicken\t\t"+ (int)ob->get_price("chicken")+" gold");
    write("-----------------------------------------------------------");
    write("<buy dish_name> gets you the food.");
    return 1;
}

