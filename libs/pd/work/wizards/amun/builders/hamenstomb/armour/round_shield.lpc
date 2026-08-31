#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    
void create() {
    ::create();                                                                        
    set_name("shield");
    set("id", ({ "shield" }) );
    set("short", "%^RED%^Round Shield");
    set("long", "Made of %^RED%^wood %^WHITE%^and rather small, how can you protect yourself with this?" );
    set_type("shield");
    set_ac(2);
    set_limbs( ({ "right hand", "right arm", "torso" }) );
    set_weight(50);
    set_curr_value("gold", 75); 
}
int query_auto_load() {
    if (this_player()->query_level() >= 20)
	return 1;
}
