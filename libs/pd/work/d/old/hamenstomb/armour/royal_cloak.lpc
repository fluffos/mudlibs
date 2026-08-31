#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    
void create() {
    ::create();                                                                        
    set_name("Royal Cloak");
    set("id", ({ "cloak" }) );
    set("short", "%^BOLD%^%^BLUE%^R%^WHITE%^o%^GREEN%^y%^WHITE%^a%^MAGENTA%^l  %^WHITE%^C%^RESET%^%^MAGENTA%^l%^BOLD%^%^WHITE%^%^o%^YELLOW%^a%^WHITE%^k");
    set("long", "%^BOLD%^%^WHITE%^Made of many colors, this Cloak was made by the queen and given to her husband as a gift." );
    set_type("cloak");
    set_ac(3);
    set_limbs( ({ "torso", "right arm", "left arm" }) );
    set_weight(30);
    set_curr_value("gold", 200); 
}
int query_auto_load() {
    if (this_player()->query_level() >= 30)
	return 1;
}
