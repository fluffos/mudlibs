#include <std.h>
#include <amun.h>
inherit AMUNLIGHTNINGROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Park");
    set_long("%^BOLD%^%^BLACK%^L%^WHITE%^i%^BLACK%^g%^YELLOW%^h%^BLACK%^t%^RESET%^MAGENTA%^n%^BOLD%^%^BLACK%^i%^RED%^n%^BLACK%^g strikes through the clouds, causing them break. A large tree stands just off the path, somehow magically growing taller by the minute. As the wind picks up, the big %^WHITE%^fluffy clouds %^BLACK%^begin to shift, causing the path to be covered. A horse trots along the side of the path.%^RESET%^");

    set_items((["path" : "The path is made up of small %^BOLD%^%^BLACK%^s%^RESET%^t%^BOLD%^%^BLACK%^o%^RESET%^n%^BOLD%^%^BLACK%^e %^RESET%^p%^BOLD%^%^BLACK%^l%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^s%^RESET%^.", "clouds" : "%^BOLD%^%^BLACK%^Black clouds encompass the area, l%^WHITE%^i%^BLACK%^g%^YELLOW%^h%^BLACK%^t%^RESET%^MAGENTA%^n%^BOLD%^%^BLACK%^i%^RED%^n%^BLACK%^g strikes from within them.%^RESET%^", "horse" : "%^BOLD%^%^RED%^The %^WHITE%^beautiful %^MAGENTA%^horse %^GREEN%^of %^BLACK%^many %^YELLOW%^colors %^BLUE%^trots %^RESET%^%^MAGENTA%^along %^GREEN%^the %^RED%^side %^BLUE%^of %^ORANGE%^the %^BOLD%^%^CYAN%^path.%^RESET%^", "lightning" : "%^BOLD%^%^BLACK%^The l%^WHITE%^i%^BLACK%^g%^YELLOW%^h%^BLACK%^t%^RESET%^MAGENTA%^n%^BOLD%^%^BLACK%^i%^RED%^n%^BLACK%^g flashes brightly in the clouds all around.%^RESET%^", "tree" : "%^RESET%^ORANGE%^A large tree magically stands just off the path.%^RESET%^", "plates" : "The %^BOLD%^%^BLACK%^s%^RESET%^t%^BOLD%^%^BLACK%^o%^RESET%^n%^BOLD%^%^BLACK%^e %^RESET%^p%^BOLD%^%^BLACK%^l%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^s %^RESET%^make the path easier to walk on.%^RESET%^"]));
    set_exits( ([ "northwest" : SKYROOM "p16", "south" : SKYROOM "p39", "southeast" : SKYROOM "p40" ]) );
}
void reset() {
    ::reset();
    if (!present("wasp", this_object()))
	new(SKYMOB "wasp")->move(this_object());
    if (!present("elephant", this_object()))
	new(SKYMOB "elephant")->move(this_object());
    if (!present("phoenix", this_object()))
	new(SKYMOB "phoenix")->move(this_object());
    if (!present("pony", this_object()))
	new(SKYMOB "pony")->move(this_object());
}
