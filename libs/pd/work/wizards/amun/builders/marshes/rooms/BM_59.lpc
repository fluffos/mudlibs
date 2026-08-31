#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^RESET%^%^ORANGE%^Vegetation threatens to overtake the path as %^BOLD%^%^BLACK%^smoke %^RESET%^%^ORANGE%^rises in the distance. The death cry of some poor animal calls out from the thick shrubs and vines. A %^RESET%^sk%^BOLD%^%^WHITE%^e%^RESET%^l%^BOLD%^%^WHITE%^e%^RESET%^t%^BOLD%^%^WHITE%^o%^RESET%^n %^ORANGE%^of some poor soul lies stretched across the way, its %^RESET%^b%^BOLD%^%^WHITE%^o%^RESET%^n%^BOLD%^%^WHITE%^e%^RESET%^s %^ORANGE%^long since picked clean by carrion birds. The skies rumble causing the water to shiver.%^RESET%^");
    set_items( ([ "faces": "%^BOLD%^%^BLACK%^These faces, are the faces of those who came, fought and died.", "bodies": "These bodies are those of many races." ]) );
    set_exits( ([ "northwest" : MARSHROOM+"BM_66", "southeast" : MARSHROOM+"BM_49", "south" : MARSHROOM+"BM_57", "southwest" : MARSHROOM+"BM_65" ]) );
}
void reset() {
    ::reset();
    if (!present("gnome", this_object()))
	new(MARSHMON+"inferi_gnome")->move(this_object());
    if (!present("ogre", this_object()))
	new(MARSHMON+"inferi_ogre")->move(this_object());
}
