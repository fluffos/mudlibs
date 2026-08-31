#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long","%^BOLD%^YELLOW%^It is a little darker in this room than it wa%^RESET%^%^ORANGE%^s before.  The torches are beginning to flicker slightly less.  There must be some reason behind this.\n");
    set_items( ([ "torch": "%^BOLD%^%^BLACK%^The torches are flickering a little less than before." ]) );
    set_exits( ([ "east": ROOMS+"hamen_tomb_223", "west": ROOMS+"hamen_tomb_227", "up": ROOMS+"hamen_tomb_229" ]) );
    new(MON+"giant_lion")->move(this_object());
    new(MON+"giant_lion")->move(this_object());
}
