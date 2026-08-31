#include <amun.h>
inherit ARMOUR;                                                                    
void create() {
    ::create();                                                                        
    set_name("Mummy Wraps");
    set("id", ({ "wraps" }) );
    set("short", "%^ORANGE%^Mum%^WHITE%^my Wr%^ORANGE%^aps");
    set("long", "%^WHITE%^These are old and continue to wear, they are useless." );
    set_type("shirt");
    set_ac(1);
    set_limbs( ({ "right arm", "left arm", "torso" }) );
    set_weight(5);
    set_curr_value("gold", 10);
}
int query_auto_load() {
    if (this_player()->query_level() >= 15)
	return 1;
}
