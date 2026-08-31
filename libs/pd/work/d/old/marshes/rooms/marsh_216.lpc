#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^Looking in all directions you notice the marshes stretch as far as your eyes can see.  It look that you have to find you way through this maze.\n");
    set_items( ([ "faces": "These faces, are the faces of those who came, fought and died.", "bodies": "These bodies are those of many races." ]) );
    set_exits( ([ "north" : MARSHROOM+"marsh_217", "southwest" : MARSHROOM+"marsh_200", "northwest" : MARSHROOM+"marsh_218", "south" : MARSHROOM+"marsh_199" ]) );
    new(MARSHMON+"inferi_goblin")->move(this_object());
    new(MARSHMON+"inferi_netherman")->move(this_object());
}
