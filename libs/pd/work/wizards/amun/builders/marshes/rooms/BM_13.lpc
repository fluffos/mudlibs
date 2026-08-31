#include <std.h>
#include <amun.h>
inherit ROOM;
int sp_sap();
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^RESET%^%^ORANGE%^Vegetation threatens to overtake the path as %^BOLD%^%^BLACK%^smoke %^RESET%^%^ORANGE%^rises in the distance. The death cry of some poor animal calls out from the thick shrubs and vines. A %^RESET%^sk%^BOLD%^%^WHITE%^e%^RESET%^l%^BOLD%^%^WHITE%^e%^RESET%^t%^BOLD%^%^WHITE%^o%^RESET%^n %^ORANGE%^of some poor soul lies stretched across the way, its %^RESET%^b%^BOLD%^%^WHITE%^o%^RESET%^n%^BOLD%^%^WHITE%^e%^RESET%^s %^ORANGE%^long since picked clean by carrion birds. The skies rumble causing the water to shiver.%^RESET%^");
    set_items( ([ "faces": "%^BOLD%^%^BLACK%^These faces, are the faces of those who came, fought and died.", "bodies": "These bodies are those of many races." ]) );
    set_exits( ([ "southeast" : MARSHROOM+"BM_21", "south" : MARSHROOM+"BM_11", "north" : MARSHROOM+"BM_15" ]) );
    add_pre_exit_function("north", "sp_sap");
    add_pre_exit_function("south", "sp_sap");
}
void reset() {
    ::reset();
    if (!present("faerie", this_object()))
	new(MARSHMON+"inferi_faerie")->move(this_object());
    if (!present("imp", this_object()))
	new(MARSHMON+"inferi_imp")->move(this_object());
}
int sp_sap() {if (this_player()->query_stats("dexterity") <= 50)
    {  this_player()->add_sp(-30);
	return 1;}
    if (this_player()->query_stats("dexterity") > 50 &&

      this_player()->query_stats("dexterity") <= 75) { 
	this_player()->add_sp(-25); return 1; }
    if (this_player()->query_stats("dexterity") > 75 &&
      this_player()->query_stats("dexterity") <= 100) {
	this_player()->add_sp(-20); return 1; }
    if (this_player()->query_stats("dexterity") > 100 &&
      this_player()->query_stats("dexterity") <= 150) { 
	this_player()->add_sp(-15); return 1; }
    if (this_player()->query_stats("dexterity") >= 150) { 
	this_player()->add_sp(-10); return 1; }
}
