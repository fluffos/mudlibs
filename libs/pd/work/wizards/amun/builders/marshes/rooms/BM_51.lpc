#include <std.h>
#include <amun.h>
inherit ROOM;
int sp_sap();
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^RESET%^%^ORANGE%^In all directions, the marsh stretches as far as the naked eye can see. To the east, %^BOLD%^%^BLACK%^black smoke %^RESET%^%^ORANGE%^can be seen rising above a few small f%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^s. More dragons can be seen flying south towards the ocean. They seem to be running away.%^RESET%^");
    set_items( ([ "smoke": "%^BOLD%^%^BLACK%^There are fires light all around." ]) );
    set_exits( ([ "southeast" : MARSHROOM+"BM_15", "northwest" : MARSHROOM+"BM_61" ]) );
    new(MARSHMON+"inferi_halfling")->move(this_object());   
    new(MARSHMON+"inferi_weimic")->move(this_object());     
    new(MARSHMON+"inferi_elf")->move(this_object());        
    new(MARSHMON+"inferi_illithid")->move(this_object());
    add_pre_exit_function("northwest", "sp_sap");
    add_pre_exit_function("southeast", "sp_sap");
}
void reset() {
    ::reset();
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
