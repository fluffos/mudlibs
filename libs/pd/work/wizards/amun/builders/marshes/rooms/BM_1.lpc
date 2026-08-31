#include <std.h>
#include <amun.h>
inherit ROOM;
int sp_sap();
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^RESET%^%^ORANGE%^The ground is covered in shrubs and bogs making it trialing to find solid ground to walk on. The waters to the east and west show dead bodies floating. There must have been a great battle here long ago of all races. To the north something can be seen coming out of the water.%^RESET%^");
    set_exits( ([ "west" : MARSHROOM+"BM_2", "east" : MARSHROOM+"BM_3", "south" : MARSHROOM+"marsh_22" ]) );
    add_pre_exit_function("east", "sp_sap");
    add_pre_exit_function("west", "sp_sap");
    add_pre_exit_function("south", "go_south");
}
void reset() {
    ::reset();
    if (!present("minotaur", this_object()))
	new(MARSHMON+"inferi_minotaur")->move(this_object());
    if (!present("giant", this_object()))
	new(MARSHMON+"inferi_giant")->move(this_object());
}
int go_south() {
    if(!this_player()->is_player()) return 0;
    return 1;
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
