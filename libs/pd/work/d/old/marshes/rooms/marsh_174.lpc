#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^Looking in all directions you notice the marshes strech as far as your eyes can see.  It look that you have to find you way through this maze.\n");
    set_items( ([ "faces": "These faces, are the faces of those who came, fought and died.", "bodies": "These bodies are those of many races." ]) );
    set_exits( ([ "east" : MARSHROOM+"marsh_175", "northeast" : MARSHROOM+"marsh_186", "west" : MARSHROOM+"marsh_173", "northwest" : MARSHROOM+"marsh_188", "southwest" : MARSHROOM+"marsh_170", "southeast" : MARSHROOM+"marsh_168", "south" :
	MARSHROOM+"marsh_169" ]) );
    new(MARSHMON+"skeleton")->move(this_object());
    new(MARSHMON+"skeleton")->move(this_object());
}
