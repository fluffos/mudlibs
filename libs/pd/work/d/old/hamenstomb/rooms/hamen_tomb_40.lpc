#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long","%^BOLD%^YELLOW%^As you enter this room you notice how bright it is compared to the one below it.  There are torches everywhere and they seem to be blowing stronger than the ones at the base of the pyramid.\n");
    set_items( ([ "torch": "%^BOLD%^%^BLACK%^The torches are flickering a little more than the ones at the base of the pyramid." ]) );
    set_exits( ([ "west" : ROOMS+"hamen_tomb_42", "down": ROOMS+"hamen_tomb_36" ]) );
    new(MON+"androsphinx")->move(this_object());
}
