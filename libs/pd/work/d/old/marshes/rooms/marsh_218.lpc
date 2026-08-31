#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^Looking in all directions you notice the marshes stretch as far as your eyes can see.  It look that you have to find you way through this maze.\n");
    set_items( ([ "faces": "These faces, are the faces of those who came, fought and died.", "bodies": "These bodies are those of many races." ]) );
    set_exits( ([ "east" : MARSHROOM+"marsh_217", "south" : MARSHROOM+"marsh_215", "west" : MARSHROOM+"marsh_219", "southeast" : 
	MARSHROOM+"marsh_216", "southwest" : MARSHROOM+"marsh_214" ]) );
    new(MARSHMON+"inferi_orc")->move(this_object());
    new(MARSHMON+"skeleton")->move(this_object());
}
