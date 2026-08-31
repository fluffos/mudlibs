#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Temple");
    set("long","%^BOLD%^%^WHITE%^While walking more north along the path, the sound of running %^BLUE%^w%^CYAN%^a%^BLUE%^t%^CYAN%^e%^BLUE%^r %^WHITE%^can be heard. The %^YELLOW%^sunlight %^WHITE%^along the same path seems to grow more dim, making it feel as if it is a place for relaxation. Travelers swarm around in packs moving in all directions to get to their desired destinations. Those travelers that are heading south seem to be %^GREEN%^serene %^WHITE%^and %^MAGENTA%^calm %^WHITE%^with a %^CYAN%^soft light blue aura %^WHITE%^shining about them.  %^RESET%^");
    set_listen("default", "%^BOLD%^%^BLUE%^The sound of running water encompasses the area.%^RESET%^");
    set_items( ([ "travelers": "%^BOLD%^%^WHITE%^Travelers swarm around in packs moving in all directions to get to their desired destinations. Those travelers that are heading south seem to be serene and calm with a %^CYAN%^soft light blue aura %^WHITE%^shining about them.%^RESET%^" ]) );
    set_exits( ([ "north" : SKYROOM "rs_11", "south" : SKYROOM "square" ]) );
}
void reset() {
    ::reset();
    if (!present("guardian", this_object()))
	new(SKYMOB "angel_guardian")->move(this_object());
}
