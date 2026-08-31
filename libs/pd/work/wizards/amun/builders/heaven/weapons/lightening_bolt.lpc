#include <std.h>
#include <amun.h>
inherit WEAPON;
int weapon_hit();
create() {
    ::create();
    set_name("Lightening Bolt");
    set("id", ({ "lightening bolt", "bolt", "spear" }) );
    set("short", 
      "%^BOLD%^%^YELLOW%^L%^BLACK%^i%^YELLOW%^ght%^BLACK%^e%^YELLOW%^n%^BLACK%^i%^YELLOW%^ng B%^BLACK%^o%^YELLOW%^lt%^RESET%^");
    set("long", "%^BOLD%^%^YELLOW%^This bolt of lightening was forged in Heaven. It has a small handle on the end for the wielder to hold and changes shapes as you look at it.%^RESET%^" );
    set_type("projectile");
    set_weight(10);
    set_curr_value("gold", 75);
    set_wc(6);
    set_type("projectile");
    set("skill level", 115);
    set_wield("%^BOLD%^%^YELLOW%^Your hand is engulfed in a bright %^WHITE%^light%^YELLOW%^.%^RESET%^");
    set_unwield("%^BOLD%^%^YELLOW%^The %^WHITE%^light %^YELLOW%^subsides around your hand.%^RESET%^");
    set_hit((:this_object(),"weapon_hit":));
}
int weapon_hit() {
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(100) > 90) {
	write("%^BOLD%^%^YELLOW%^You throw a bolt of lightening into "+ atk->query_cap_name() +"'s face, setting them on %^RED%^fire%^YELLOW%^!%^RESET%^");
	say((string)"%^BOLD%^%^YELLOW%^"+this_player()->query_cap_name()+"'s throws a bolt of lightening into " + atk->query_cap_name() + "'s face setting them on %^RED%^fire%^YELLOW%^!%^RESET%^");
	result=(random(50))+((this_player()->query_level())*2/3);
	if(random(100) > 74) {
	    write("%^BOLD%^%^YELLOW%^%^The bolt of lightening flashes in "+ atk->query_cap_name() +"'s eyes burning them!%^RESET%^");
	    say("%^BOLD%^%^YELLOW%^The bolt of lightening flashes in " + atk->query_cap_name() + "'s eyes causing them to burn!%^RESET%^");
	    result = 10 +random(30);
	    this_player()->add_sp(result);
	    return result;
	}
	return 0;
    }
}
int query_auto_load() {
    if(this_player()->query_class() != "clergy") return 0;
    if(this_player()->query_level() < 36) return 0;
    return 1; 
}
