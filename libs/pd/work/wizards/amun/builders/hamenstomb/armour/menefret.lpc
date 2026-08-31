#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    
void create() {
    ::create();                                                                        
    set_name("Menefret");
    set("id", ({ "bracer", "menefret" }) );
    set("short", "%^BOLD%^%^YELLOW%^Menefret");
    set("long", "%^BOLD%^%^YELLOW%^The thick golden bracer fits any arm." );
    set_type("bracers");
    set_ac(2);
    set_limbs( ({ "left arm" }) );
    set_weight(15);
    set_curr_value("gold", 100); 
}
int query_auto_load() {
    if (this_player()->query_level() >= 30)
	return 1;
}
