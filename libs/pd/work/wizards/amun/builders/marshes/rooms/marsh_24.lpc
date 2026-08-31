#include <std.h>
#include <amun.h>
inherit ROOM;
int sp_sap();
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^A large cave lies to the east, large eyes can be seen peeking out ready to attack anyone who gets too close. Deciding everything looks safe, the eyes disappear. The rocks open up to where the marshes can be seen for miles on end. Something can be seen coming out of the marshy waters and ducking behind a shrub.%^RESET%^");
    set_items( ([ "cave": "%^BOLD%^%^BLACK%^Large eyes can be seen peeking out ready to attack anyone who gets too close." ]) );
    set_exits( ([ "south" : MARSHROOM+"marsh_23", "north" : MARSHROOM+"marsh_25" ]) );
    add_pre_exit_function("north", "sp_sap");
    add_pre_exit_function("south", "sp_sap");
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
