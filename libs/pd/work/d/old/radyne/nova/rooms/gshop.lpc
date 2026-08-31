#include <std.h>
#include <radyne.h>
inherit ROOM;


void create() {
    ::create();
    set_properties(([ "light" : 2, "indoors" : 1, "no bump" : 1 ]));
   set_short("Radyne Nova General Supply Shop");
    set_long(
     "%^BOLD%^%^BLUE%^Radyne Nova General Supply Shop%^RESET%^\n"
     "There are a variety of things here for sale. Terra, the shopkeep will be more than happy to help you with anything you need."
      );
    set_items(([
	"shop" : "The only general supply shop in town."
      ]));
    set_exits(([
      "north" : ROOMS "esquare4",
      ]));
}

void reset() {
    ::reset();
   if(!present("terra"))
   new(MON"terra")->move(this_object());
}

