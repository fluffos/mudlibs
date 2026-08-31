#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^Looking in all directions you notice the marshes stretch as far as your eyes can see.  It look that you have to find you way through this maze.\n");
    set_items( ([ "faces": "These faces, are the faces of those who came, fought and died.", "bodies": "These bodies are those of many races." ]) );
    set_exits( ([ "east" : ROOMS+"sign_entrance", "south" :  MARSHROOM+"marsh_216", "west" : MARSHROOM+"marsh_218" ]) );
    add_pre_exit_function("east", "go_east");
    new(MARSHMON+"inferi_minotaur")->move(this_object());
    new(MARSHMON+"inferi_illithid")->move(this_object());
    new(MARSHMON+"inferi_netherman")->move(this_object());
}
int go_east() {
    if(!this_player()->is_player()) return 0;
    return 1;
}
