#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^Looking in all directions you notice the marshes stretch as far as your eyes can see.  It look that you have to find you way through this maze.\n");
    set_items( ([ "faces": "These faces, are the faces of those who came, fought and died.", "bodies": "These bodies are those of many races." ]) );
    set_exits( ([ "northwest" : MARSHROOM+"marsh_117", "northeast" : MARSHROOM+"marsh_115", "southeast" : MARSHROOM+"marsh_95", "south" : MARSHROOM+"marsh_96", "southwest" : MARSHROOM+"marsh_97", "east" : MARSHROOM+"marsh_112", "west" : 
	MARSHROOM+"marsh_110" ]) );
    new(MARSHMON+"inferi_gremlin")->move(this_object());
    new(MARSHMON+"inferi_elf")->move(this_object());
}
