#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Temple");
    set("long","%^BOLD%^%^WHITE%^As the path leads towards the south, the clouds begin to become thin, allowing travelers to get sparatic glimpses of %^BLACK%^l%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^ghtni%^YELLOW%^n%^BLACK%^g %^WHITE%^below them. To the north, the %^YELLOW%^Temple's %^BLUE%^f%^CYAN%^o%^BLUE%^unta%^CYAN%^i%^BLUE%^n %^WHITE%^can be seen with the reflection of passerbys encompassing it's mirror. Passerbys make their way through the room towards their destinations.%^RESET%^");
    set_items( ([ "clouds": "%^BOLD%^%^WHITE%^The clouds begin to become thin, allowing travelers to get sparatic glimpses of %^BLACK%^l%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^ghtni%^YELLOW%^n%^BLACK%^g %^WHITE%^below them.%^RESET%^", "fountain": "%^BOLD%^%^WHITE%^This fountain was made by the Angel's and it offers the healing powers they posses. It stands 15 feet in the air, with a small circluar mirror set between a large pair of stone angel wings. The mirror looks quite interesting, the glass seems to be flowing as if there is a current towards the center of it, creating circular waves.%^RESET%^", "lightning" : "%^BOLD%^%^BLACK%^This l%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^ghteni%^YELLOW%^n%^BLACK%^g can sparactically be seen under the %^WHITE%^clouds%^BLACK%^. Maybe there is something beneath the park.%^RESET%^" ]) );
    set_exits( ([ "north" : SKYROOM "square", "south" : SKYROOM "rs_10" ]) );
}
void reset() {
    ::reset();
    if (!present("guardian", this_object()))
	new(SKYMOB "angel_guardian")->move(this_object());
}
