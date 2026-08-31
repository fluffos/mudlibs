#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("In a coconut tree");
   set_long("Coconuts grow on the branches of this coconut tree, "
	"though the majority of them are too high up to be reached. "
	"The tree sways and you wonder if you should climb back "
	"down to solid ground...");
   set_exits(([
	"down" : "/d/freepk/keys/sorn/beach"
   ]));
   set_listen("default", "The coconuts sing: Bahama, common pretty "
	"mamma. Come on down to cocomo.");
}

void reset() {
 ::reset();
   if (!present("coconut"))
     new("/d/freepk/keys/sorn/coconut")->move(this_object());
   if (!present("coconut 2"))
     new("/d/freepk/keys/sorn/coconut")->move(this_object());
   if (!present("coconut 3"))
     new("/d/freepk/keys/sorn/coconut")->move(this_object());
   if (!present("coconut 4"))
     new("/d/freepk/keys/sorn/coconut")->move(this_object());
   if (!present("coconut 5"))
     new("/d/freepk/keys/sorn/coconut")->move(this_object());
}
