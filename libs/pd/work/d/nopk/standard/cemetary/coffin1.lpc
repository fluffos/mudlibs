#include <std.h>
#include <sindarii.h>
inherit VAULT;
object coffin;

void create() {
 ::create();
   set_property("light", 0);
   set_short("Inside Melissa Praxis' coffin");
   set_long("You have climbed inside of Melissa Praxis' coffin. "
            "Not but eerie thoughts cross your mind as the "
            "cold, wooden walls close claustrophobicly in on you. "
            "The bottom of the coffin has rotted away, exposing "
            "the soil beneath.");
   set_items(
	([
	  "soil" : "The cold, black soil has been exposed by the rotting coffin.",
          "bottom":"It has been replaced with this strange soil.",
	  "grave" : "The grave is horribly empty and sad."]));
    set_exits(([
                 "out" : ROOMS"cemetary/grave" ]));
   set_door("coffin", ROOMS"cemetary/grave", "out", "");
}

