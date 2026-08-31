#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^RESET%^%^ORANGE%^Broken trees and crushed shrubs show signs of something big having recently traveled through this way. The path of destruction thankfully heads away from the main trail. More sporadic %^RED%^f%^BOLD%^%^RED%^i%^BLACK%^r%^RED%^e%^RESET%^%^RED%^s %^ORANGE%^make the air thick with %^BOLD%^%^BLACK%^smoke%^RESET%^%^ORANGE%^. Laying forgotten on the ground, a small rusty blade sits embedded in the soft earth.%^RESET%^");
    set_items( ([ "faces": "%^BOLD%^%^BLACK%^These faces, are the faces of those who came, fought and died.", "bodies": "These bodies are those of many races." ]) );
    set_exits( ([ "northeast" : MARSHROOM+"BM_20", "north" : MARSHROOM+"BM_18" , "southeast" : MARSHROOM+"BM_12", "south" : MARSHROOM+"BM_10" ]) );
}
void reset() {
    ::reset();
    if (!present("ferrel", this_object()))
	new(MARSHMON+"inferi_ferrel")->move(this_object());
    if (!present("minotaur", this_object()))
	new(MARSHMON+"inferi_minotaur")->move(this_object());
}
