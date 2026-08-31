#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Temple");
    set("long","%^BOLD%^%^WHITE%^The west side of Belief Trail is full of life and excitement. Many races gather around to find the right shops to make their purchases. The smell of baked goods wafts through the breeze inviting all to find out where the delectable smell is coming from. To the east the %^YELLOW%^Sky Temple %^WHITE%^square can be found.%^RESET%^");
    set_smell("default", "%^BOLD%^%^WHITE%^The %^MAGENTA%^sweet %^WHITE%^smell of baked goods wafts through the air.%^RESET%^");
    set_exits( ([ "east" : SKYROOM "square", "west" : SKYROOM "ls_2" ]) );
}
void reset() {
    ::reset();
    if (!present("guardian", this_object()))
	new(SKYMOB "angel_guardian")->move(this_object());
}
