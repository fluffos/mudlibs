#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    
void create() {
    ::create();                                                                        
    set_name("amulet");
    set("id", ({ "collar" }) );
    set("short", "%^BOLD%^%^YELLOW%^Golden Collar%^RESET%^");
    set("long", "%^BOLD%^%^WHITE%^The %^YELLOW%^collar %^WHITE%^is %^CYAN%^be%^RESET%^%^MAGENTA%^au%^BOLD%^%^MAGENTA%^ti%^GREEN%^fu%^YELLOW%^l %^WHITE%^but offers little protection.%^RESET%^" );
    set_type("necklace");
    set_ac(1);
    set_limbs( ({ "torso" }) );
    set_weight(30);
    set_curr_value("gold", 75); 
}
int query_auto_load() {
    if (this_player()->query_level() >= 30)
	return 1;
}
