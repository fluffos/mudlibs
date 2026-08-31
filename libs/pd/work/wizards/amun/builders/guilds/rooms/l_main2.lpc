#include <std.h>
#include <daemons.h>
#include <guild.h>
#include <boat.h>
inherit ROOM;
void create() {
    ::create();
    set_properties( ([ "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"night light" : 2,
	"no steal"    : 1 ]) );
    set_property("town",1);
    set("short", "Guild Town");
    set("long","%^RESET%^The path branches off towards the north and south to the shops. The %^BOLD%^%^BLACK%^gravel %^RESET%^has darkened along the path as if all color is being stripped from it. There is very little %^GREEN%^v%^ORANGE%^e%^GREEN%^getation %^RESET%^in the area, but some %^BOLD%^%^GREEN%^plants %^RESET%^grow slightly as if barely clutching onto life. %^BOLD%^%^BLACK%^Clouds %^RESET%^begin to form in the sky blocking the area of light.%^RESET%^");
    set_items(([ "path" : "%^BOLD%^%^BLACK%^The path begins to darken as if all life is threatening to become extinct.%^RESET%^", "gravel" : "%^BOLD%^%^BLACK%^The gravel has barely any color left in it, just blackness.%^RESET%^", "vegetation" : "%^RESET%^%^GREEN%^The vegetation is very little and dying quickly.%^RESET%^", "plants" : "%^BOLD%^%^GREEN%^Some plants are attempting to clutch onto life.%^RESET%^", "clouds" : "%^BOLD%^%^BLACK%^Black clouds form in the sky blocking the light.%^RESET%^" ]));
    set_exits( ([ "east" : GROOM "l_main", "west" : GROOM"l_main3", "enter bar" : GROOM"shop1", "enter restaurant" : GROOM"shop2" ]) );
    add_exit_alias("enter bar", "bar");
    add_exit_alias("enter restaurant", "restaurant");
}
