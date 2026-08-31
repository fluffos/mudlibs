#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 2, "indoors" : 1, "night light" : 2,
                "no teleport" : 1]) );
   set_short("Tunnels beneath Steel Hammer Monestary");
   set_long(
            "%^BOLD%^%^BLACK%^The rough stone walls lead in various "
            "directions. Everything looks the same in every "
            "direction. Periodically a lit torch will be "
            "stuck into the wall, providing little light.");
   set_items(([
            "walls" : "The rough stone walls lead in various "
		 "directions. They have been carved out, but "
		 "never did get finished.",                 
            "torch" : "Lit torches are scarcely scattered about "
		 "the tunnels, providing little light."
   ]));
   set_smell("default", "A musty odor fills the tunnels.");
   set_listen("default", "It is very quiet.");
   set_exits( ([ 
	"northeast" : ROOMS "cav1_16",
	"southwest" : ROOMS "cav1_18"]));
}
