#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "EYE OF HELL");
    set("long","%^BOLD%^%^RED%^The earth rises in the west, the rock is sharp, broken, and stabbing upward as if to pierce it along with the heavens. Huddled, %^BLACK%^dark forms %^RED%^perch upon those stone daggers, glaring hate with %^YELLOW%^yellow eyes%^RED%^. A thick river lies ahead, its waters are %^BLACK%^black and uninviting%^RED%^. Fallen stones arovide a somewhat safe passage across.%^RESET%^");
    set_exits( ([ "southwest": HELLROOM+"middle_45", "northeast": HELLROOM+"middle_31" ]) );
}
void reset() {
    ::reset();
    if (!present("siren", this_object()))
	new(HELLMON+"siren")->move(this_object());
}
