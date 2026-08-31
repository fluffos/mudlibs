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
    set("long","%^BOLD%^%^GREEN%^The area is full of lushous green pl%^RESET%^%^ORANGE%^a%^BOLD%^%^GREEN%^nts around the small %^RESET%^%^ORANGE%^path %^BOLD%^%^GREEN%^leading to the east. Trees sway in the %^WHITE%^b%^CYAN%^r%^WHITE%^eeze %^GREEN%^as a flock of %^WHITE%^s%^BLACK%^e%^WHITE%^agul%^BLACK%^l%^WHITE%^s %^GREEN%^fly overhead. The ground begins to soften and %^RESET%^%^ORANGE%^sand %^BOLD%^%^GREEN%^can be seen down the small group of steps. The faint smell of the %^CYAN%^sea %^GREEN%^mixed with %^RESET%^%^ORANGE%^horses %^BOLD%^%^GREEN%^filters through the room.%^RESET%^");
    set_items( (["plants" : "%^BOLD%^%^GREEN%^The plants are lushous and green.%^RESET%^", "path" : "%^ORANGE%^The path leads towards the east.%^RESET%^", "trees" : "%^BOLD%^%^GREEN%^The trees sway in the %^WHITE%^b%^CYAN%^r%^WHITE%^eeze%^GREEN%^.%^RESET%^", "seagulls" : "%^BOLD%^%^WHITE%^The seagulls fly overhead.", "sand" : "%^ORANGE%^The sand can be seen down the stone steps.%^RESET%^", "steps" : "%^BOLD%^%^WHITE%^The steps move down to the sand.%^RESET%^" ]) );
    set_exits( ([ "enter stable" : GROOM "coaches", "north" : GROOM"coach_entrance", "down" : GROOM"docks_entrance" ]) );
    add_exit_alias("enter stable", "stable");
}
