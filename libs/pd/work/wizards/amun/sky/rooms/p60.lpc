#include <std.h>
#include <amun.h>
inherit AMUNLIGHTNINGROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Park");
    set_long("%^BOLD%^%^BLACK%^L%^WHITE%^i%^BLACK%^g%^YELLOW%^h%^BLACK%^t%^RESET%^MAGENTA%^n%^BOLD%^%^BLACK%^i%^RED%^n%^BLACK%^g strikes through the clouds, causing them break. The path is made up of small s%^RESET%^t%^BOLD%^%^BLACK%^o%^RESET%^n%^BOLD%^%^BLACK%^e %^RESET%^p%^BOLD%^%^BLACK%^l%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^s and it provides a clear way throughout the park. Many groups of %^WHITE%^white flowers %^BLACK%^can be seen divinely growing out of the clouds. A horse trots along the side of the path.%^RESET%^");

    set_items((["path" : "The path is made up of small %^BOLD%^%^BLACK%^s%^RESET%^t%^BOLD%^%^BLACK%^o%^RESET%^n%^BOLD%^%^BLACK%^e %^RESET%^p%^BOLD%^%^BLACK%^l%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^s%^RESET%^.", "clouds" : "%^BOLD%^%^BLACK%^Black clouds encompass the area, l%^WHITE%^i%^BLACK%^g%^YELLOW%^h%^BLACK%^t%^RESET%^MAGENTA%^n%^BOLD%^%^BLACK%^i%^RED%^n%^BLACK%^g strikes from within them.%^RESET%^", "horse" : "%^BOLD%^%^RED%^The %^WHITE%^beautiful %^MAGENTA%^horse %^GREEN%^of %^BLACK%^many %^YELLOW%^colors %^BLUE%^trots %^RESET%^%^MAGENTA%^along %^GREEN%^the %^RED%^side %^BLUE%^of %^ORANGE%^the %^BOLD%^%^CYAN%^path.%^RESET%^", "flowers" : "%^BOLD%^%^WHITE%^Beautiful white flowers grow magically through the clouds.%^RESET%^", "lightning" : "%^BOLD%^%^BLACK%^The l%^WHITE%^i%^BLACK%^g%^YELLOW%^h%^BLACK%^t%^RESET%^MAGENTA%^n%^BOLD%^%^BLACK%^i%^RED%^n%^BLACK%^g flashes brightly in the clouds all around.%^RESET%^", "plates" : "The %^BOLD%^%^BLACK%^s%^RESET%^t%^BOLD%^%^BLACK%^o%^RESET%^n%^BOLD%^%^BLACK%^e %^RESET%^p%^BOLD%^%^BLACK%^l%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^s %^RESET%^make the path easier to walk on.%^RESET%^"]));
    set_exits( ([ "south" : SKYROOM "p70" ]) );
}
void reset() {
    ::reset();
    if (!present("hornet", this_object()))
	new(SKYMOB "hornet")->move(this_object());
    if (!present("horse", this_object()))
	new(SKYMOB "horse")->move(this_object());
    if (!present("skunk", this_object()))
	new(SKYMOB "skunk")->move(this_object());
}
