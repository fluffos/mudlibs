#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^Looking in all directions you notice the marshes stretch as far as your eyes can see.  It look that you have to find you way through this maze.\n");
    set_items( ([ "faces": "These faces, are the faces of those who came, fought and died.", "bodies": "These bodies are those of many races." ]) );
    set_exits( ([ "east" : MARSHROOM+"marsh_179", "northeast" : MARSHROOM+"marsh_182", "west" : MARSHROOM+"marsh_177", "northwest" : MARSHROOM+"marsh_184", "southwest" : MARSHROOM+"marsh_166", "southeast" : MARSHROOM+"marsh_164", "south" :
	MARSHROOM+"marsh_165" ]) );
    new(MARSHMON+"inferi_orc")->move(this_object());
    new(MARSHMON+"inferi_dwarf")->move(this_object());
}
