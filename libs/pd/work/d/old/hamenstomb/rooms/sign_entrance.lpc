#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Guardians Room");
    set("long","%^BOLD%^%^YELLOW%^You have reached the end of the marsh.  You see a gate a little ways north and you contemplate turning around to save your life.  You notice a sign layed infront of you.\n");
    set_exits( ([ "enter" : ROOMS+"guardians_room", "west" : ROOMS+"marsh_217" ]) );
    new(MARSHARM+"sign")->move(this_object());
}
