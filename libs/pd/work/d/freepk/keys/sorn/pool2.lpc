#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("In a fresh water pond");
   set_long("%^CYAN%^"
	"Swimming further down into the small pond, the water has "
	"become a bit darker, but the ground is in sight from here. "
	"A quick swim upwards is the surface of the pond.");
   set_exits(([
	"up"   : "/d/freepk/keys/sorn/pool1",
	"down" : "/d/freepk/keys/sorn/pool3"
   ]));
}

void reset() {
 ::reset();
   if (!present("catfish"))
     new("/d/freepk/keys/sorn/catfish")->move(this_object());
}
