#include <std.h>
#include <amun.h>
inherit ROOM;
int sp_sap();
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^There is a small patch of shrubs along side the mountain that is on %^RESET%^%^ORANGE%^f%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^e. There are a combined group of noises with the thunder, the v%^WHITE%^u%^BLACK%^lt%^WHITE%^u%^BLACK%^r%^WHITE%^e%^BLACK%^s and the sound of voices. The ground becomes a little slippery as a few raindrops begin to fall, making it harder to walk. A few caves can be seen up the mountain.%^RESET%^");
    set_items( ([ "shrubs": "%^BOLD%^%^BLACK%^These shrubs are blazing with fire." ]) );
    set_exits( ([ "west" : MARSHROOM+"marsh_50", "east" : MARSHROOM+"marsh_52" ]) );
    add_pre_exit_function("east", "sp_sap");
    add_pre_exit_function("west", "sp_sap");
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
