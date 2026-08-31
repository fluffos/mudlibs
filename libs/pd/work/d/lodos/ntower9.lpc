#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("A small waiting room");
   set_properties((["light" : 2]));
   set_properties((["town" : 1, "indoors" : 1, "building" : 1]));
   set_long("The lavishly decorated room belongs to someone of great "
      "power. Red carpet can be seen in the southern room. Light blue "
      "tiles line the walls and floor. A door leads back to the south.");
   set_exits(([ "south" : ROOMS"ntower8" ]));
   set_items(([
      "door" : "The door leads south, out of the room.",
      "room" : "The room is well decorated and nicely laid out.",
      "carpet" : "It can be seen in the southern room.",
      "tiles" : "The %^BOLD%^%^CYAN%^light blue tiles%^RESET%^ line the walls and floor."
   ]));
}

void reset() {
 ::reset();
   if (!present("samurai")) {
     make(MOB"samurai");
     make(MOB"samurai");
   }
   if (!present("warlord"))
     make(MOB"warlord");
}
