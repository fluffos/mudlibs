#include <std.h>
#include <amun.h>
inherit ROOM;
int sp_sap();
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^The jagged rocks smell of blood and death. There are stray pieces of rotten flesh lying along the small path warning passerbys. Giant bugs can be seen moving around in search of their next meal. A v%^WHITE%^u%^BLACK%^lt%^WHITE%^u%^BLACK%^r%^WHITE%^e %^BLACK%^swoops down and grabs part of the rotting flesh.%^RESET%^\n");
    set_items( ([ "flesh": "%^BOLD%^%^BLACK%^This is the flesh of the ones who have died here recently." ]) );
    set_exits( ([ "north" : MARSHROOM+"marsh_31", "south" : MARSHROOM+"marsh_33" ]) );
    add_pre_exit_function("north", "sp_sap");
    add_pre_exit_function("south", "sp_sap");
}
void reset() {
    ::reset();
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
