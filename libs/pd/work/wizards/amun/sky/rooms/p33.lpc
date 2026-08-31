#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Park");
    set_long("%^BOLD%^%^WHITE%^All around the park the clouds stick up like grass, with a soft tint of %^GREEN%^green %^WHITE%^on the tips. As the wind blows, the lightly %^GREEN%^green %^WHITE%^tinted grass flows like a river. Many groups of white flowers can be seen divinely growing out of the clouds. A small squirrel runs across the path into a cluster of clouds.%^RESET%^");

    set_items((["squirrel" : "%^RESET%^ORANGE%^The small squirrel runs across the path and into a patch of %^BOLD%^%^WHITE%^clouds%^RESET%^%^ORANGE%^.%^RESET%^", "path" : "The path is made up of small %^BOLD%^%^BLACK%^s%^RESET%^t%^BOLD%^%^BLACK%^o%^RESET%^n%^BOLD%^%^BLACK%^e %^RESET%^p%^BOLD%^%^BLACK%^l%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^s%^RESET%^.", "clouds" : "%^BOLD%^%^WHITE%^The clouds are white and fluffy and take the shape of many objects.%^RESET%^", "flowers" : "%^BOLD%^%^WHITE%^Beautiful white flowers grow magically through the clouds.%^RESET%^", "grass" : "%^BOLD%^%^WHITE%^The grass is made of clouds, but has soft %^GREEN%^green t%^WHITE%^ips.%^RESET%^", "plates" : "The %^BOLD%^%^BLACK%^s%^RESET%^t%^BOLD%^%^BLACK%^o%^RESET%^n%^BOLD%^%^BLACK%^e %^RESET%^p%^BOLD%^%^BLACK%^l%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^s %^RESET%^make the path easier to walk on.%^RESET%^"]));
    set_exits( ([ "north" : SKYROOM "p21", "east" : SKYROOM "p34", "southeast" : SKYROOM "p47" ]) );
}
void reset() {
    ::reset();
    if (!present("moose", this_object()))
	new(SKYMOB "moose")->move(this_object());
    if (!present("tiger", this_object()))
	new(SKYMOB "tiger")->move(this_object());
    if (!present("boar", this_object()))
	new(SKYMOB "boar")->move(this_object());
    if (!present("dog", this_object()))
	new(SKYMOB "dog")->move(this_object());
}
