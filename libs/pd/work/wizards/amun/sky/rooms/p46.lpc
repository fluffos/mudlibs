#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Park");
    set_long("%^BOLD%^%^WHITE%^The path is made up of small %^BLACK%^s%^RESET%^t%^BOLD%^%^BLACK%^o%^RESET%^n%^BOLD%^%^BLACK%^e %^RESET%^p%^BOLD%^%^BLACK%^l%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^s %^WHITE%^and it provides a clear way throughout the park. Mini statues of %^CYAN%^pygmies%^WHITE%^, that are made from clouds, line the pathway. A group of dogs run and play together in a clouded meadow to the east. All around the park the clouds stick up like grass, with a soft tint of %^GREEN%^green %^WHITE%^on the tips.%^RESET%^");

    set_items((["path" : "The path is made up of small %^BOLD%^%^BLACK%^s%^RESET%^t%^BOLD%^%^BLACK%^o%^RESET%^n%^BOLD%^%^BLACK%^e %^RESET%^p%^BOLD%^%^BLACK%^l%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^s%^RESET%^.", "clouds" : "%^BOLD%^%^WHITE%^The clouds are white and fluffy and take the shape of many objects.%^RESET%^", "dogs" : "The dogs are running around the park playing and hiding under patches of clouds.%^RESET%^", "meadow" : "%^BOLD%^%^WHITE%^The meadow is made of a soft white bed of cloudy grass that has %^GREEN%^green tinted %^WHITE%^on its %^GREEN%^t%^WHITE%^ips.%^RESET%^", "statues" : "%^BOLD%^%^CYAN%^These statues depict pygmies flying or running around playing.%^RESET%^", "pygmies" : "%^BOLD%^%^CYAN%^The pygmies are statues made of clouds.%^RESET%^", "pathway" : "The pathway is lined with pygmy statues.%^RESET%^", "grass" : "%^BOLD%^%^WHITE%^The grass is made of clouds, but has soft %^GREEN%^green t%^WHITE%^ips.%^RESET%^", "plates" : "The %^BOLD%^%^BLACK%^s%^RESET%^t%^BOLD%^%^BLACK%^o%^RESET%^n%^BOLD%^%^BLACK%^e %^RESET%^p%^BOLD%^%^BLACK%^l%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^s %^RESET%^make the path easier to walk on.%^RESET%^"]));
    set_exits( ([ "northwest" : SKYROOM "p32", "south" : SKYROOM "p56" ]) );
}
