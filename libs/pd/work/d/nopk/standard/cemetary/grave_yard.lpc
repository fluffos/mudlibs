#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
  ::create();
    set_property("light", 2);
    set_exits( 
              (["west" : ROOMS"dusk3",
                "east" : ROOMS"cemetary/gravyar2"]) );
    set("short","Cemetary Entrance");
    set("long",
	"You stand below the ancient Tirunian Gates of Dusk. The air is very "
	"still here, and unnaturally quiet. The village of Tirun goes no further "
	"Northeast. Past the gates of Dusk is a quiet cemetary. There is a "
	"headstone off to the east.");
   set_items(([
         "headstone" : "The headstone is too far away to read."
   ]));
}

/*
void reset() {
 ::reset();
   if (!present("gates"))
     new(OBJ"dusk")->move(this_object());
}
*/

