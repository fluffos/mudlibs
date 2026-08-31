#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    
void create() {
    ::create();                                                                        
    set_name("Red Diamond Amulet");
    set("id", ({ "amulet", "amun_amulet" }) );
    set("short", "%^BOLD%^%^RED%^Red %^WHITE%^Diamond %^RED%^Am%^WHITE%^ul%^RED%^et%^RESET%^");
    set("long", "%^BOLD%^%^RED%^This amulet has a %^YELLOW%^golden chain %^RED%^with a bright red diamond to lay upon your chest.  It looks as if there are writings on the back of the diamond." );
    set_type("necklace");
    set_ac(2);
    set_limbs( ({ "torso" }) );
    set_weight(18);
    set_curr_value("gold", 200); 
    set_wear("%^BOLD%^%^RED%^The amulet glows bright red as you don it.");
    set_remove("%^BOLD%^%^RED%^The glowing of the amulet fades away.");
    set("read", "\"%^BOLD%^%^WHITE%^This necklace seems to give protection to those who wear it against a large beast.\"");
}
int query_auto_load() {
    if (this_player()->query_level() >= 50)
	return 1;
}
