#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    
void create() {
    ::create();                                                                        
    set_name("Helmet");
    set("id", ({ "helm", "helmet" }) );
    set("short", "%^BOLD%^%^BLUE%^R%^WHITE%^o%^BLUE%^y%^WHITE%^a%^BLUE%^l H%^WHITE%^e%^BLUE%^lm%^WHITE%^e%^BLUE%^t");
    set("long", "%^BOLD%^%^WHITE%^This %^BLUE%^h%^WHITE%^e%^BLUE%^lm%^WHITE%^e%^BLUE%^t %^WHITE%^is %^BLUE%^blue %^WHITE%^and has feathers sticking out of the top like something a %^YELLOW%^King %^WHITE%^would wear." );
    set_type("helmet");
    set_ac(4);
    set_limbs( ({ "head" }) );
    set_weight(30);
    set_curr_value("gold", 155);
}
int query_auto_load() {
    if (this_player()->query_level() >= 30)
	return 1;
}
