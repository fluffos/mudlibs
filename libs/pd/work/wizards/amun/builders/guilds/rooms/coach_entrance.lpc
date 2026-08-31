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
    set("long","%^ORANGE%^Large %^RED%^r%^ORANGE%^e%^RED%^dw%^GREEN%^o%^RED%^od %^ORANGE%^trees line the path leading along the %^GREEN%^f%^ORANGE%^o%^GREEN%^rest%^ORANGE%^. Showing off their age with height, the trees reach up towards the %^BOLD%^%^BLUE%^s%^CYAN%^k%^BLUE%^y%^RESET%^%^ORANGE%^ in hopes of kissing the %^BOLD%^%^WHITE%^clouds%^RESET%^%^ORANGE%^. The v%^GREEN%^e%^ORANGE%^ge%^GREEN%^ta%^ORANGE%^ti%^GREEN%^o%^ORANGE%^n is more abundant on the western side of the area. Some sort of prints can be seen embedded in the path headed south.%^RESET%^");
    set_items( (["trees" : "%^RED%^The trees reach up high to the heavens.%^RESET%^", "path" : "%^ORANGE%^The path leads towards the south.%^RESET%^", "vegetation" : "%^BOLD%^%^GREEN%^The grass is full and green, along with the rest of the plants in the area.%^RESET%^", "prints" : "%^ORANGE%^These are the prints of a horse!%^RESET%^"  ]) );
    set_exits( ([ "up" : GROOM "board_room", "south" : GROOM"coach_entrance2" ]) );
}
