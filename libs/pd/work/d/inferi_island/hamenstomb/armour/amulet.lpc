#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    
void create() {
    ::create();                                                                        
    set_name("Amulet");
    set("id", ({ "amulet", "dragon_amulet" }) );
    set("short", "%^BOLD%^%^GREEN%^Am%^WHITE%^ul%^GREEN%^et%^RESET%^");
    set("long", "%^BOLD%^%^WHITE%^The brightest %^YELLOW%^gold chain %^WHITE%^brings out the %^GREEN%^e%^CYAN%^m%^GREEN%^e%^CYAN%^r%^GREEN%^a%^CYAN%^l%^GREEN%^d %^WHITE%^st%^RESET%^%^WHITE%^o%^BOLD%^%^WHITE%^ne in the front.%^RESET%^" );
    set_type("necklace");
    set_ac(2);
    set_limbs( ({ "torso" }) );
    set_weight(18);
    set_curr_value("gold", 200); 
    set_wear("%^BOLD%^%^WHITE%^The st%^RESET%^%^WHITE%^o%^BOLD%^%^WHITE%^ne %^GREEN%^glows %^WHITE%^as you wear it.%^RESET%^");
    set_remove("%^BOLD%^%^WHITE%^The st%^RESET%^%^WHITE%^o%^BOLD%^%^WHITE%^ne stops %^GREEN%^glowing %^WHITE%^when you remove it.%^RESET%^");
}
int query_auto_load() {
    if (this_player()->query_level() >= 36)
	return 1;
}
