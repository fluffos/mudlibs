#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Temple");
    set("long","%^BOLD%^%^WHITE%^As the path leads up, the hustle and bustle of the main trail can no longer be heard. Much like trail before, %^BLACK%^H%^YELLOW%^o%^BLACK%^pe T%^YELLOW%^r%^BLACK%^ail%^WHITE%^ is full of %^CYAN%^life%^WHITE%^. %^YELLOW%^Sunbeams %^WHITE%^dance off the c%^RESET%^l%^BOLD%^%^WHITE%^o%^RESET%^u%^BOLD%^%^WHITE%^d%^RESET%^s%^BOLD%^%^WHITE%^, offering a s%^RESET%^i%^BOLD%^%^WHITE%^lv%^RESET%^e%^BOLD%^%^WHITE%^r lining to each and every one of them. A soft %^CYAN%^breeze %^WHITE%^flows through the area causing passerbys to stop and enjoy the beautiful day.%^RESET%^");
    set_items( ([ "main trail": "%^BOLD%^%^WHITE%^Belief Trail can be seen from up here. There are many travelers walking around trying to find their destinations.%^RESET%^", "trail": "%^BOLD%^%^WHITE%^Faith Trail is very warm and inviting. Those with strong faith live around here.%^RESET%^", "clouds" : "%^BOLD%^%^YELLOW%^Sunbeams %^WHITE%^dance off the c%^RESET%^l%^BOLD%^%^WHITE%^o%^RESET%^u%^BOLD%^%^WHITE%^d%^RESET%^s%^BOLD%^%^WHITE%^, offering a s%^RESET%^i%^BOLD%^%^WHITE%^lv%^RESET%^e%^BOLD%^%^WHITE%^r lining to each and every one of them." ]) );
    set_exits( ([ "south" : SKYROOM "rsup_6", "north" : SKYROOM "rsup_4", "down" : SKYROOM "rs_6" ]) );
}
void reset() {
    ::reset();
    if (!present("guardian", this_object()))
	new(SKYMOB "angel_guardian")->move(this_object());
}
