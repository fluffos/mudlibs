#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^Looking in all directions you notice the marshes stretch as far as your eyes can see.  It look that you have to find you way through this maze.\n");
    set_items( ([ "faces": "These faces, are the faces of those who came, fought and died.", "bodies": "These bodies are those of many races." ]) );
    set_exits( ([ "east" : MARSHROOM+"marsh_90", "northeast" : MARSHROOM+"marsh_97", "west" : MARSHROOM+"marsh_88", "northwest" : MARSHROOM+"marsh_99", "southwest" : MARSHROOM+"marsh_79", "southeast" : MARSHROOM+"marsh_77", "south" : MARSHROOM+"marsh_78" ]) );
    new(MARSHMON+"skeleton")->move(this_object());
    new(MARSHMON+"undead_corpse")->move(this_object());
}
