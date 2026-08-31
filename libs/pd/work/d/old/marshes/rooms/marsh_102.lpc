#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^BLACK%^Looking in all directions you notice the marshes stretch as far as your eyes can see.  It look that you have to find you way through this maze.\n");
    set_items( ([ "faces": "%^BOLD%^%^BLACK%^These faces, are the faces of those who came, fought and died.", "bodies": "These bodies are those of many races." ]) );
    set_exits( ([ "east" : MARSHROOM+"marsh_101", "north" : MARSHROOM+"marsh_105", "south" : MARSHROOM+"marsh_85" ]) );
    new(MARSHMON+"inferi_goblin")->move(this_object());
    new(MARSHMON+"inferi_imp")->move(this_object());
    new(MARSHMON+"inferi_raknid")->move(this_object());
}
