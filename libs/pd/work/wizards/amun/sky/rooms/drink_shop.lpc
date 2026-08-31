#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_properties( ([ "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"night light" : 2,
	"no steal"    : 1 ]) );
    set("short", "The Cathedral Drink Shop");
    set("long", "%^BOLD%^%^WHITE%^The C%^RESET%^a%^BOLD%^%^WHITE%^th%^RESET%^e%^BOLD%^%^WHITE%^dr%^RESET%^a%^BOLD%^%^WHITE%^l Drink Shop%^RESET%^\n" 
      "%^BOLD%^WHITE%^This Drink Shop is a small shop that has very little need for more room. There is a small area where the drinks are prepared, and a small area for them to be sold. Completely outside, there is a %^CYAN%^cool breeze %^WHITE%^flowing around the entire area. Behind the small stand, there is a %^CYAN%^beautiful %^YELLOW%^Archangel %^WHITE%^awaiting customers. There is a small sign for all to read.%^RESET%^");
    set_exits(([ "north" : SKYROOM "ls_3" ]));
}
void reset() {
    ::reset();
    /*
	    new("/std/obj/player_list")->move(this_object()); 
    */
    if(!present("kelesia")) 
	new(SKYMOB "kelesia")->move(this_object());
}
