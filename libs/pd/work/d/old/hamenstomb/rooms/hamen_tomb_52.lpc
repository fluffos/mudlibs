#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long","%^BOLD%^YELLOW%^It is a little darker in this room than it wa%^RESET%^%^ORANGE%^s before.  The torches are beginning to flicker slightly more.  There must be some reason behind this.\n");
    set_items( ([ "torch": "%^BOLD%^%^BLACK%^The torches are flickering a little more than before." ]) );
    set_exits( ([ "east" : ROOMS+"hamen_tomb_50", "west": ROOMS+"hamen_tomb_54" ]) );
    new(MON+"black_vulture")->move(this_object());
    new(MON+"camel")->move(this_object());
    new(MON+"magi")->move(this_object());
}
