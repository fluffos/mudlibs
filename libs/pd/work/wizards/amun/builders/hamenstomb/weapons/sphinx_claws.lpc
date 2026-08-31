#include <std.h>
int query_auto_load() {
    if (this_player()->query_level() >= 40)
	return 1;
}
#include <amun.h>
inherit WEAPON;                                                                   
void create() {
    ::create();                                                                       
    set_name("Sphinx Claws");
    set("id", ({ "claw", "claws","knife" }) );
    set("short", "%^BOLD%^%^YELLOW%^Sp%^RESET%^%^ORANGE%^hi%^BOLD%^%^YELLOW%^nx %^WHITE%^Claws");
    set("long", "%^BOLD%^%^YELLOW%^These are the claws of a Sphinx, they are very 
sharp and very long." );
set_type("knife");
set_weight(25);
set_curr_value("gold", 145);
set_wc(11);
set_type("knife");
set("skill level", 175);
 }
