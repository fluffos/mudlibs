#include <std.h>
#include <lodos.h>
inherit ROOM;

/*
void init() {
    ::init();
    add_action("buy_coffee", "buy");
    add_action("read", "read");
}
*/

void create() {
    ::create();
    set_property("town", 1);
    set_property("light", 3);
    set_property("indoors", 1);
    set_property("building", 1);
    set("short", "The Golden Talon Cafe");
     set_long("Welcome to the Golden Talon Cafe! People "
              "from all over Lodos and even visitors in "
              "town gather here for a meal. When Talon is "
              "around, he'll be happy to serve you. A large menu "
             "has been hung on the far wall.");
    set_items(
	(["restaurant" : "The Golden Talon Cafe, home of "
	    "great Lodian cuisine.",
	  "wall" : "The menu is posted there.",
	  "menu" : "You may read it if you like."]) );
      set_exits( ([
         "south" : ROOMS"etown4"
       ]) );
}

void reset() {
  ::reset();
    if(!present("talon")) 
      new(MOB"talon")->move(this_object());
}

