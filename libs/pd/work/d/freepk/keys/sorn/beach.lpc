#include <std.h>
inherit BEACH;

void create() {
 ::create();
   set_short("Sorn Isle");
   set_long("The small tropical Merkkirrian Isle, Sorn, has a small "
	"pool of fresh water, which sits right next to a tall coconut "
	"tree. Wild flowers grow around the pond and tree. The island "
	"of sorn is like an oasis of land amidst water.");
   set_items(([
	"ocean" : "Cool blue waves crash onto the sand.",
	"flowers":"Beautiful wild flowers grow on this island.",
	"sand"  : "Warm sand covers this small island."
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
   set_letter("f");
}

void reset() {
 ::reset();
   if (!present("tree"))
     new("/d/freepk/keys/sorn/tree")->move(this_object());
   if (!present("pool"))
     new("/d/freepk/keys/sorn/pool")->move(this_object());
}
