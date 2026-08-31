#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long","%^BOLD%^YELLOW%^As you walk up towards the top of the pyramid, you notice a draft as there are windows all around you.  The pyramid is now in bright gold and you feel a royal presence.\n");
    set_items( ([ "windows": "%^BOLD%^%^CYAN%^You look out the window and see a clear bright blue sky.  It seems to always be daytime around here." ]) );
    set_exits( ([ "northwest": ROOMS+"hamen_tomb_393", "southwest": ROOMS+"hamen_tomb_390" ]) );
    new(MON+"anu")->move(this_object());
}
