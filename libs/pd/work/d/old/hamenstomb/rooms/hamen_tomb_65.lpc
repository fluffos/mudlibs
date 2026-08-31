#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long","%^BOLD%^BLACK%^It is becoming almost pitch black again.  The torches are beginning to flicker more and more the farther you move into the pyramid.\n");
    set_items( ([ "torch": "%^BOLD%^%^BLACK%^The torches are flickering faster." ]) );
    set_exits( ([ "east" : ROOMS+"hamen_tomb_67", "west": ROOMS+"hamen_tomb_63" ]) );
    new(MON+"child_of_the_sun")->move(this_object());
    new(MON+"giant_lion")->move(this_object());
    new(MON+"black_vulture")->move(this_object());
    new(MON+"sekhmet")->move(this_object());
}
