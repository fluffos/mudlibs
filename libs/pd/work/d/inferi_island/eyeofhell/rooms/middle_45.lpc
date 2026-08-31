#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "EYE OF HELL");
    set("long","%^BOLD%^%^WHITE%^The path now ends in the middle of the eye.  There is a bright light causing the room to become blinding.  There are many cages, holding prisoners, dangling in the air. Some poor souls are crucified upside down on inverted crosses made from black, rotting wood. Large rusting spikes hold feet and hands in place and more screams of suffering fill the air as small bat-like demons swoop down, clawing and biting and devouring the flesh of helpless men and women.%^RESET%^");
    set_exits( ([ "southeast": HELLROOM+"middle_44", "northeast": HELLROOM+"middle_43" ]) );
}
void reset() {
    ::reset();
    if (!present("lucy", this_object()))
	new(HELLMON+"lucy")->move(this_object());
}
