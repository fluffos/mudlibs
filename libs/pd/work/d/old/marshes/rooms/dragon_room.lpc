#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^RED%^It seems you have stumbled into a room that does not belong.  Looking around, you notice this is a giant cave that homes a three headed dragon.  This seems like a wierd place for a dragon.%^RESET%^%^BLACK%^");
    set_exits( ([ "out" : MARSHROOM+"marsh_144" ]) );
    new(MARSHMON+"three_headed_dragon")->move(this_object());
}
