#include <std.h>
#include <amun.h>
inherit ROOM;
int sp_sap();
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^The path ahead splits around a tall spire. A large skull of some unknown beast rests on top it. Small puddles of dark, putrid water dot the ground. Just past the spire the path forks, one path leading to a cave that has been blocked by an avalanche and the other leading into a what looks like a graveyard. The bodies are piled on top of one another and the v%^WHITE%^u%^BLACK%^lt%^WHITE%^u%^BLACK%^r%^WHITE%^e%^BLACK%^s are rested atop them pecking at their rotting flesh.%^RESET%^");
    set_exits( ([ "east" : MARSHROOM+"marsh_29", "west" : MARSHROOM+"marsh_31" ]) );
    add_pre_exit_function("west", "sp_sap");
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
