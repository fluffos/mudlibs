#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Park");
    set_long("A group of dogs run and play together in a clouded meadow to the east. Many groups of %^BOLD%^%^WHITE%^white flowers %^RESET%^can be seen divinely growing out of the clouds. A large %^BOLD%^%^BLACK%^gray statue %^RESET%^made of clouds depicts an angel with its wings spread as if it's in flight. A large tree stands just off the path, somehow magically growing taller by the minute.%^RESET%^");

    set_items((["path" : "The path is made up of small %^BOLD%^%^BLACK%^s%^RESET%^t%^BOLD%^%^BLACK%^o%^RESET%^n%^BOLD%^%^BLACK%^e %^RESET%^p%^BOLD%^%^BLACK%^l%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^s%^RESET%^.", "clouds" : "%^BOLD%^%^WHITE%^The clouds are white and fluffy and take the shape of many objects.%^RESET%^", "dogs" : "The dogs are running around the park playing and hiding under patches of clouds.%^RESET%^", "meadow" : "%^BOLD%^%^WHITE%^The meadow is made of a soft white bed of cloudy grass that has %^GREEN%^green tinted %^WHITE%^on its %^GREEN%^t%^WHITE%^ips.%^RESET%^", "flowers" : "%^BOLD%^%^WHITE%^Beautiful white flowers grow magically through the clouds.%^RESET%^", "statue" : "%^BOLD%^%^BLACK%^The large gray statue is made of dark rain clouds, and it is of an angel with its wings spread in flight.  %^BOLD%^%^BLACK%^L%^WHITE%^i%^BLACK%^g%^YELLOW%^h%^BLACK%^t%^RESET%^MAGENTA%^n%^BOLD%^%^BLACK%^i%^RED%^n%^BLACK%^g can be seen flashing in the angel's eyes.%^RESET%^", "tree" : "%^RESET%^ORANGE%^A large tree magically stands just off the path.%^RESET%^", "plates" : "The %^BOLD%^%^BLACK%^s%^RESET%^t%^BOLD%^%^BLACK%^o%^RESET%^n%^BOLD%^%^BLACK%^e %^RESET%^p%^BOLD%^%^BLACK%^l%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^s %^RESET%^make the path easier to walk on.%^RESET%^"]));
    set_exits( ([ "west" : SKYROOM "p43", "northwest" : SKYROOM "p30" ]) );
}
void reset() {
    ::reset();
    if (!present("tiger", this_object()))
	new(SKYMOB "tiger")->move(this_object());
    if (!present("boar", this_object()))
	new(SKYMOB "boar")->move(this_object());
}
