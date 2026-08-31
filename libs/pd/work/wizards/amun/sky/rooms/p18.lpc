#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Park");
    set_long("%^RESET%^%^ORANGE%^An eagle flies over the area searching for something small to eat. Mini statues of %^BOLD%^%^CYAN%^pygmies%^RESET%^%^ORANGE%^, that are made from clouds, line the pathway. As the wind picks up, the big %^BOLD%^%^WHITE%^fluffy clouds %^RESET%^%^ORANGE%^begin to shift, causing the path to be covered. Roots from trees stretch out far and wide, it is a wonder how the trees grow in the clouds.%^RESET%^");

    set_items((["path" : "The path is made up of small %^BOLD%^%^BLACK%^s%^RESET%^t%^BOLD%^%^BLACK%^o%^RESET%^n%^BOLD%^%^BLACK%^e %^RESET%^p%^BOLD%^%^BLACK%^l%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^s%^RESET%^.", "clouds" : "%^BOLD%^%^WHITE%^The clouds are white and fluffy and take the shape of many objects.%^RESET%^", "eagle" : "%^RESET%^%^ORANGE%^The eagle flies over the clouds looking for its next meal.%^RESET%^", "statues" : "%^BOLD%^%^CYAN%^These statues depict pygmies flying or running around playing.%^RESET%^", "pygmies" : "%^BOLD%^%^CYAN%^The pygmies are statues made of clouds.%^RESET%^", "pathway" : "The pathway is lined with pygmy statues.%^RESET%^", "plates" : "The %^BOLD%^%^BLACK%^s%^RESET%^t%^BOLD%^%^BLACK%^o%^RESET%^n%^BOLD%^%^BLACK%^e %^RESET%^p%^BOLD%^%^BLACK%^l%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^s %^RESET%^make the path easier to walk on.%^RESET%^"]));
    set_exits( ([ "east" : SKYROOM "p19", "south" : SKYROOM "p30" ]) );
}
void reset() {
    ::reset();
    if (!present("pony", this_object()))
	new(SKYMOB "pony")->move(this_object());
    if (!present("giraffe", this_object()))
	new(SKYMOB "giraffe")->move(this_object());
    if (!present("zebra", this_object()))
	new(SKYMOB "zebra")->move(this_object());
}
