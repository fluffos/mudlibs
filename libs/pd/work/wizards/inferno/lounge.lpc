#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_property("no teleport", 1);
   set_short("In a Comfortable lounge");
   set_long("A couch lays in front of a tv. The ground is carpeted and "
     "the walls are painted white. A large ceiling fan spins above your "
     "head. A soda machine lies in the far corner of the room.");
   set_items(([
     "tv" : "Nothing good on."
   ]));
   set_exits(([ "south" : "/wizards/inferno/workroom",
                "north" : "/wizards/inferno/sanctuary"
   ]));
}

void reset() {
 ::reset();
   if (!present("machine"))
      new("/wizards/inferno/soda")->move(this_object());
}
