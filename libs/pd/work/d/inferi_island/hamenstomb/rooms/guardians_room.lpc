#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Guardians Room");
    set("long","%^BOLD%^%^YELLOW%^This room was made for the Magi Guardian.  He alone wields the power to move forward into an area of strength and wisdom. This room is riddled with decayed bodies and broken bones. It maybe best to turn back now.\n");
    set_exits( ([ "up" : ROOMS+"marsh_end", "out" : ROOMS+"sign_entrance" ]) );
}
void reset() {
    ::reset();
    if (!present("guardian", this_object()))
	new(MARSHMON+"magi_guardian")->move(this_object());
}
