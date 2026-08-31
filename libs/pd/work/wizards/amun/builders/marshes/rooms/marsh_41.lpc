#include <std.h>
#include <amun.h>
inherit ROOM;
int sp_sap();
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^A large depression lies in the path ahead. However, on closer inspection it is actually the footprint of a large dragon. The rocks rise high, like walls, on either side of the path closing it in uncomfortably. A harp turn towards the west cuts off a further view of the path. Overhead the clouds thicken into a dark sea of gray.%^RESET%^ ");
    set_exits( ([ "east" : MARSHROOM+"marsh_40", "west" : MARSHROOM+"marsh_42" ]) );
    add_pre_exit_function("east", "sp_sap");
    add_pre_exit_function("west", "sp_sap");
}
void reset() {
    ::reset();
    if (!present("netherman", this_object()))
	new(MARSHMON+"inferi_netherman")->move(this_object());
    if (!present("skeleton", this_object()))
	new(MARSHMON+"skeleton")->move(this_object());
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
