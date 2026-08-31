#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long","%^BOLD%^YELLOW%^As you walk into the now sunlit room, you notice there is a lot of noise coming from different directions.  You seem to be in a little town within the pyramid.  Listening to the conversations, you begin to hear a story about deadly things within the pyramid.  The writings on the walls glow softly.\n");
    set_items( ([ "writings": "%^BOLD%^%^BLACK%^In the darkness of the Pyramid, a mythical being can be found. If you find it, and respond to the unclear, you will find the '%^RED%^occulus inferi%^BLACK%^'." ]) );
    set_exits( ([ "east": ROOMS+"hamen_tomb_287", "west": ROOMS+"hamen_tomb_283" ]) );
    new(MON+"tree_of_life")->move(this_object());
    new(MON+"falcon")->move(this_object());
}
