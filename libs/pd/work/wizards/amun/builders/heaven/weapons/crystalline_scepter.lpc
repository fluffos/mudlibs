#include <std.h>
#include <amun.h>
inherit WEAPON;
int weapon_hit();
create() {
    ::create();
    set_id(({"Scepter", "scepter", "blunt"}));
    set_name("Crystalline Scepter");
    set_short("%^BOLD%^%^WHITE%^C%^RESET%^r%^BOLD%^%^WHITE%^y%^RESET%^s%^BOLD%^%^WHITE%^t%^RESET%^a%^BOLD%^%^WHITE%^l%^RESET%^l%^BOLD%^%^WHITE%^i%^RESET%^n%^BOLD%^%^WHITE%^e %^RESET%^S%^BOLD%^%^WHITE%^c%^RESET%^e%^BOLD%^%^WHITE%^p%^RESET%^t%^BOLD%^%^WHITE%^e%^RESET%^r");
    set_long("%^BOLD%^%^WHITE%^This %^RESET%^scepter %^BOLD%^%^WHITE%^has %^RESET%^gorgeous %^BOLD%^%^WHITE%^diamonds %^RESET%^embedded %^BOLD%^%^WHITE%^within %^RESET%^a %^BOLD%^%^WHITE%^crystalline %^RESET%^shell %^BOLD%^%^WHITE%^that %^RESET%^sits %^BOLD%^%^WHITE%^upon %^RESET%^a %^BOLD%^%^WHITE%^crystalline %^RESET%^staff %^BOLD%^%^WHITE%^that %^RESET%^is %^BOLD%^%^WHITE%^riddled %^RESET%^with %^BOLD%^%^WHITE%^even %^RESET%^more %^BOLD%^%^WHITE%^diamonds.%^RESET%^");
    set_weight(30);
    set_curr_value("platinum", 250);
    set("skill level", 125);
    set_wc(16);
    set_ac(2);
    set_type("blunt");
    set_wield("%^BOLD%^%^WHITE%^The %^RESET%^diamonds %^BOLD%^%^WHITE%^glow %^RESET%^with %^BOLD%^%^WHITE%^a %^RESET%^white %^BOLD%^%^WHITE%^light %^RESET%^as %^BOLD%^%^WHITE%^you %^RESET%^hold %^BOLD%^%^WHITE%^the %^RESET%^crystalline %^BOLD%^%^WHITE%^staff.%^RESET%^");
    set_unwield("%^BOLD%^%^WHITE%^The %^RESET%^diamonds %^BOLD%^%^WHITE%^stop %^RESET%^glowing %^BOLD%^%^WHITE%^as %^RESET%^the %^BOLD%^%^WHITE%^scepter %^RESET%^leaves %^BOLD%^%^WHITE%^your %^RESET%^fingertips.");
    set_hit((:this_object(),"weapon_hit":));
}
int weapon_hit() {
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(100) > 90) {
	write("%^BOLD%^%^WHITE%^The %^RESET%^diamonds %^BOLD%^%^WHITE%^rip %^RESET%^deeply %^BOLD%^%^WHITE%^opening %^RESET%^a %^BOLD%^%^WHITE%^large %^RESET%^gash!");
	say((string)"%^BOLD%^%^WHITE%^"+this_player()->query_cap_name()+"'s %^RESET%^diamonds %^BOLD%^%^WHITE%^rip %^RESET%^deeply %^BOLD%^%^WHITE%^opening %^RESET%^a %^BOLD%^%^WHITE%^large %^RESET%^gash!");
	result=(random(50))+((this_player()->query_level())*2/3);
	if(random(100) > 74) {
	    write("%^BOLD%^%^WHITE%^The diamonds fl%^RESET%^a%^BOLD%^%^WHITE%^sh brightly dis%^RESET%^a%^BOLD%^%^WHITE%^bling your %^RESET%^a%^BOLD%^%^WHITE%^ttacker!%^RESET%^");
	    say("%^BOLD%^%^WHITE%^The bright light c%^RESET%^a%^BOLD%^%^WHITE%^uses a dis%^RESET%^a%^BOLD%^%^WHITE%^bling blindness!");
	    atk->set_paralyzed(random(2));
	    return result;
	}
    }
}
int query_auto_load() {
    if(this_player()->query_level() < 30) return 0;
    return 1; 
}
