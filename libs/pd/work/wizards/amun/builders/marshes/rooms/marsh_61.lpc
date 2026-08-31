#include <std.h>
#include <amun.h>
inherit ROOM;
int sp_sap();
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^The mountain pass is riddled with hot black rocks making it hard to move around. The lack of sunlight makes these rocks even more dull than they really are. The sky is made up of black rain clouds for miles. This is not a place of beauty, this is not a place of happiness. This place is cursed.%^RESET%^ ");
    set_items( ([ "rocks": "%^BOLD%^%^BLACK%^These gigantic rocks cover the entire path throughout the entire mountain.", "clouds": "%^BOLD%^%^BLACK%^The black rain clouds reach for miles." ]) );
    set_exits( ([ "east" : MARSHROOM+"marsh_60", "west" : MARSHROOM+"marsh_62" ]) );
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
