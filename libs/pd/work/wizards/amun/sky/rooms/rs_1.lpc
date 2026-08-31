#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Temple");
    set("long","%^BOLD%^%^WHITE%^The east side of Belief Trail is full of life and excitement. Many races gather around to find the right shops to make their purchases. The sound of weapons can be heard, as some shoppers test them in the streets. To the west the %^YELLOW%^Sky Temple %^WHITE%^square can be found.%^RESET%^");
    set_exits( ([ "west" : SKYROOM "square", "east" : SKYROOM "rs_2" ]) );
}
void reset() {
    ::reset();
    if (!present("guardian", this_object()))
	new(SKYMOB "angel_guardian")->move(this_object());
}
