#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long","%^BOLD%^YELLOW%^Now standing outside, the King bows to you as if he were waiting.  Bright and clear are the blue skys above you.  You fell the wind picking up and shiver, you debate turning back.\n");
    set_items( ([ "sky": "%^BOLD%^%^CYAN%^The sky is clear and blue." ]) );
    set_exits( ([ "down": ROOMS+"hamen_tomb_393" ]) );
    new(MON+"king_hamen")->move(this_object());
}
