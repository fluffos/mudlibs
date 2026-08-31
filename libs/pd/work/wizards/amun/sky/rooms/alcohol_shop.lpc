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
    set("short", "The Cathedral Vinyard");
    set("long", "%^BOLD%^%^WHITE%^The C%^RESET%^a%^BOLD%^%^WHITE%^th%^RESET%^e%^BOLD%^%^WHITE%^dr%^RESET%^a%^BOLD%^%^WHITE%^l Vineyard%^RESET%^\n" 
      "%^BOLD%^WHITE%^This Vineyard is a quaint little shop that is spilt in two sections. On one side of the shop, there is a %^RESET%^%^ORANGE%^large table %^BOLD%^%^WHITE%^where wine testing takes place, as well as a few %^RESET%^%^ORANGE%^small tables %^BOLD%^%^WHITE%^for customers to sit and sip on their wine. On the other side of the shop, the bar is cleanly placed, with a %^CYAN%^gorgeous %^WHITE%^woman behind it waiting to take the customers orders.%^RESET%^");
    set_exits(([ "south" : SKYROOM "ls_2" ]));
}
void reset() {
    ::reset();
    /*
	    new("/std/obj/player_list")->move(this_object()); 
    */
    if(!present("summer")) 
	new(SKYMOB "summer")->move(this_object());
}
