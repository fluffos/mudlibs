#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("In a fresh water pond");
   set_long("%^CYAN%^"
	"Bubbles and fish float past you. This is a fresh water "
	"pond. It feels great on your skin. The surface is right "
	"above you, and the small pool goes a little deeper down.");
   set_exits(([
	"up"   : "/d/freepk/keys/sorn/beach",
	"down" : "/d/freepk/keys/sorn/pool2"
   ]));
}

void reset() {
 ::reset();
   if (!present("arowana"))
     new("/d/freepk/keys/sorn/arowana")->move(this_object());
}
