#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^Looking in all directions you notice the marshes stretch as far as your eyes can see.  It look that you have to find you way through this maze.\n");
    set_items( ([ "faces": "These faces, are the faces of those who came, fought and died.", "bodies": "These bodies are those of many races." ]) );
    set_exits( ([ "northwest" : MARSHROOM+"marsh_178", "northeast" : MARSHROOM+"marsh_180", "north" : MARSHROOM+"marsh_179", "west" : MARSHROOM+"marsh_165", "south" : MARSHROOM+"marsh_161", "east" : MARSHROOM+"marsh_163", "southeast" : MARSHROOM+"marsh_162", "southwest" : MARSHROOM+"marsh_160" ]) );
    new(MARSHMON+"inferi_weimic")->move(this_object());
}
