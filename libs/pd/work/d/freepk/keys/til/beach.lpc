#include <std.h>
inherit BEACH;

void create() {
 ::create();
   set_short("Til");
   set_long("This small island is overgrowing with tropical plants and "
	"vines. The ground is soft, almost mud-like. Although there is "
	"a lot of underbrush and moss, there are strangly no trees on "
	"this island. A patch of thorny roses grows here.");
   set_items(([
	"roses"  : "A small bed of roses.",
	"ground" : "Great for growing plants, but not stable enough "
		   "for a tree.",
	({ "underbrush", "plants", "moss" }) : "All kinds of plants, "
		   "underbrush, and moss grow here.",
   ]));
   set_exits(([
     
   ]));
   set_max_catch(20);
   set_max_fishing(2);
   set_chance(75);
   set_fish(([
     "rainbow fish":10,
     "trout":15,
     "gold fish":5,
     "pirch":5,
     "stingray": 10,
     "lamprey":15
 ]));

   set_letter("e");
}

void reset() {
 ::reset();
   if (!present("rose"))
     new("/d/freepk/keys/til/rose")->move(this_object());
   if (!present("savage"))
     new("/d/freepk/keys/til/savage1")->move(this_object());
}
