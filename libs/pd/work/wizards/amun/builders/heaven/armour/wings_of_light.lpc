#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    			
void create() {
    ::create();                                                                        
    set_name("Wings of Light");
    set("id", ({ "wings", "wing", "wings of light", "of light", "light" }) );
    set("short", "%^BOLD%^%^WHITE%^W%^YELLOW%^i%^WHITE%^ngs of L%^YELLOW%^i%^WHITE%^ght%^RESET%^");
    set("long", "%^BOLD%^%^WHITE%^These wings were forged for the pure and holy.%^RESET%^");
    set_type("wing armour");
    set_ac(5);
    set_limbs( ({ "right wing", "left wing" }) );
    set_weight(20);
    set_curr_value("gold", 200);  
}
int query_auto_load() {
    if (this_player()->query_level() >= 36)
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
