#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Park");
    set_long("%^RESET%^%^ORANGE%^An eagle flies over the area searching for something small to eat. The ground trembles under the %^BOLD%^%^WHITE%^clouds%^RESET%^%^ORANGE%^, causing a slight shift. All around the park the %^BOLD%^%^WHITE%^clouds %^RESET%^%^ORANGE%^stick up like grass, with a soft tint of %^BOLD%^%^GREEN%^green %^RESET%^%^ORANGE%^on the tips. A large %^BOLD%^%^BLACK%^gray statue made of clouds %^RESET%^%^ORANGE%^depicts an angel with its wings spread as if it's in flight.%^RESET%^");

    set_items((["clouds" : "%^BOLD%^%^WHITE%^The clouds are white and fluffy and take the shape of many objects.%^RESET%^", "eagle" : "%^RESET%^%^ORANGE%^The eagle flies over the clouds looking for its next meal.%^RESET%^", "statue" : "%^BOLD%^%^BLACK%^The large gray statue is made of dark rain clouds, and it is of an angel with its wings spread in flight.  %^BOLD%^%^BLACK%^L%^WHITE%^i%^BLACK%^g%^YELLOW%^h%^BLACK%^t%^RESET%^MAGENTA%^n%^BOLD%^%^BLACK%^i%^RED%^n%^BLACK%^g can be seen flashing in the angel's eyes.%^RESET%^", "ground" : "The ground trembles under the clouds, causing a slight shift in them.%^RESET%^", "grass" : "%^BOLD%^%^WHITE%^The grass is made of clouds, but has soft %^GREEN%^green t%^WHITE%^ips.%^RESET%^", "plates" : "The %^BOLD%^%^BLACK%^s%^RESET%^t%^BOLD%^%^BLACK%^o%^RESET%^n%^BOLD%^%^BLACK%^e %^RESET%^p%^BOLD%^%^BLACK%^l%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^s %^RESET%^make the path easier to walk on.%^RESET%^"]));
    set_exits( ([ "northeast" : SKYROOM "p17", "south" : SKYROOM "p41", "east" : SKYROOM "p29" ]) );
}
void reset() {
    ::reset();
    if (!present("giraffe", this_object()))
	new(SKYMOB "giraffe")->move(this_object());
    if (!present("zebra", this_object()))
	new(SKYMOB "zebra")->move(this_object());
}
