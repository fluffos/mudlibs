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
    set("long","%^BOLD%^%^BLACK%^The more the path goes west, the more it becomes darkened. Almost all life has vanished as if darkness has strangled the light from exsisting. Those few %^RESET%^%^GREEN%^plants %^BOLD%^%^BLACK%^that have clutched onto life have begun to fall limp. The temperature has dropped considerably as %^WHITE%^snow %^BLACK%^begins to fall gently.%^RESET%^");
    set_items(([ "path" : "%^BOLD%^%^BLACK%^The path grows dark and moist.%^RESET%^", "plants" : "%^GREEN%^The plants are wilting in their attempts to hold onto life.%^RESET%^", "snow" : "%^BOLD%^%^WHITE%^Snow begins to fall as the temperature drops.%^RESET%^" ]));
    set_exits( ([ "east" : GROOM "l_main2", "west" : GROOM "l_main4" ]) );
}
void init() {
    ::init();
    add_action("say_breath", "say");
}

int say_breath(string str) {
    write("As you speak, your breath shows up in the air.");
    say("As "+this_player()->query_cap_name()+" speaks, their breath becomes visible.");
    return 0;
}
