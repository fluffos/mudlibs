#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    			
void create() {
    ::create();                                                                        
    set_name("Black Wings");
    set("id", ({ "wings", "wing" }) );
    set("short", "%^BOLD%^%^BLACK%^B%^RESET%^%^WHITE%^l%^BOLD%^%^BLACK%^ack W%^RESET%^%^WHITE%^i%^BOLD%^%^BLACK%^ngs");
    set("long", "%^BOLD%^%^BLACK%^These wings were once forged for the pure and holy.%^RESET%^");
    set_type("wings");
    set_ac(2);
    set_limbs( ({ "right wing", "left wing" }) );
    set_weight(30);
    set_curr_value("gold", 100);  
}
int query_auto_load() {
    if (this_player()->query_level() >= 25)
	return 1;
}
void init() {
    ::init();
    add_action("do_fly", "fly");
}
int do_fly(string str) {
    if(this_player() != this_object()->query_worn())
	return 0;
    write("As you try to fly, you find yourself unable to move your wings because of the heavy armor.");
    return 1;
}
