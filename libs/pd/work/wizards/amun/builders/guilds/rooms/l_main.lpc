#include <std.h>
#include <daemons.h>
#include <guild.h>
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
    set("long","The main path throughout the town stretches east and west. Although it has no actual name, it is known as 'Skid Row'. Along the g%^BOLD%^%^BLACK%^r%^RESET%^a%^BOLD%^%^BLACK%^v%^RESET%^e%^BOLD%^%^BLACK%^l%^RESET%^e%^BOLD%^%^BLACK%^d %^RESET%^path, there are small groups of %^ORANGE%^plants %^RESET%^that look like they have been forgotten. Shops and other buildings can be seen towards the west.%^RESET%^");
    set_items(([ "path" : "This main path simply known as 'Skid Row' got it's name because it is in the run-down outskirts of town. It is made of g%^BOLD%^%^BLACK%^r%^RESET%^a%^BOLD%^%^BLACK%^v%^RESET%^e%^BOLD%^%^BLACK%^l %^RESET%^and offers very little beauty.%^RESET%^", "plants" : "%^RESET%^%^ORANGE%^The plants are not well kept and look as if they are close to death.%^RESET%^", "shops" : "%^RESET%^%^ORANGE%^Shops can be seen towards the west.%^RESET%^", "buildings" : "%^RESET%^Buildings can be seen towards the west.%^RESET%^" ]));
    set_exits( ([ "southeast" : GROOM "board_room", "west" : GROOM"l_main2" ]) );
}
