#include <std.h>
#include <amun.h>
inherit ROOM;
int sp_sap();
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^The rocks begin to wind around towards the center of the mountain. It is a tight path as the rocks are so close together, threatening to cut all who enter. There is a dead body lying in the middle of the path making it harder to get by. V%^WHITE%^u%^BLACK%^lt%^WHITE%^u%^BLACK%^r%^WHITE%^e%^BLACK%^s are flying above preparing to swoop.%^RESET%^");
    set_items( ([ "body": "%^BOLD%^%^BLACK%^This body is of a poor soul that has lost his life to the horrors of the island." ]) );
    set_exits( ([ "south" : MARSHROOM+"marsh_63", "east" : MARSHROOM+"marsh_65" ]) );
    add_pre_exit_function("south", "sp_sap");
    add_pre_exit_function("east", "sp_sap");
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
