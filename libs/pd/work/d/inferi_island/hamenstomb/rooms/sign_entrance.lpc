#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Guardians Room");
    set("long","%^BOLD%^%^YELLOW%^This is the end of the marsh, vegetation seems to grow nicely around this area. A gate can be seen a little ways north and just the sight of it makes passerbys contemplate turning around to save thier life. A sign is hangs to the left of the area for all to read.\n");
    set_exits( ([ "enter" : ROOMS+"guardians_room", "down" : MARSHROOM+"BM_66" ]) );
    new(MARSHARM+"sign")->move(this_object());
}
