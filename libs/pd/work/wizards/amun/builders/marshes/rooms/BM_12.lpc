#include <std.h>
#include <amun.h>
inherit ROOM;
int sp_sap();
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^RESET%^%^ORANGE%^The path of the marsh is riddled with %^BOLD%^%^BLACK%^dark %^RESET%^%^ORANGE%^and murky water. A decrepit w%^RED%^o%^ORANGE%^oden b%^RED%^r%^ORANGE%^idge can be seen to the east, but is broken offering no way across with ease. A body, severed at the waist, crawls through the thick reeds in the water. A sudden strong gust of wind causes a few pieces from the b%^RED%^r%^ORANGE%^idge to fall into the water with a noisy splash, sending some small creature into a flight of terror.%^RESET%^");
    set_items( ([ "bridge": "%^BOLD%^%^BLACK%^This bridge is old and worn. It is broken half way through the marsh.", "body": "These bodies are those of many races." ]) );
    set_exits( ([ "south" : MARSHROOM+"BM_6", "north" : MARSHROOM+"BM_16", "northwest" : MARSHROOM+"BM_14" ]) );
    add_pre_exit_function("north", "sp_sap");
    add_pre_exit_function("south", "sp_sap");
}
void reset() {
    ::reset();
    if (!present("dwarf", this_object()))
	new(MARSHMON+"inferi_dwarf")->move(this_object());
    if (!present("halfling", this_object()))
	new(MARSHMON+"inferi_halfling")->move(this_object());
    if (!present("weimic", this_object()))
	new(MARSHMON+"inferi_weimic")->move(this_object());
    if (!present("elf", this_object()))
	new(MARSHMON+"inferi_elf")->move(this_object());
    if (!present("illithid", this_object()))
	new(MARSHMON+"inferi_illithid")->move(this_object());
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
