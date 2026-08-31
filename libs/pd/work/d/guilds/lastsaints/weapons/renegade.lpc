#include <std.h>
#include <amun.h>
inherit WEAPON;
create() {
    ::create();
    set_id(({"renegade", "sword", "blade"}));
    set_name("renegade");
    set_short("%^BOLD%^%^BLACK%^R%^WHITE%^e%^BLACK%^n%^WHITE%^e%^BLACK%^g%^YELLOW%^a%^BLACK%^d%^WHITE%^e%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This %^BOLD%^%^BLACK%^R%^WHITE%^e%^BLACK%^n%^WHITE%^e%^BLACK%^g%^YELLOW%^a%^BLACK%^d%^WHITE%^e%^BLACK%^ was blessed by the %^WHITE%^%^God %^BLACK%^who made it and was given to the Last Saints to rid the world of evil.%^RESET%^");
    set_mass(20);
    set_curr_value("gold", 120);
    set_wc(1);
    set_type("blade");
    set_decay_rate(500);
    set("skill level", 125);
    set_hands(1);
//    set_hit( (: weapon_hit :) );  
}
int weapon_hit(object atk)
{
    int result, chance;
    object tp;
    tp = this_player();
    if(random(100) < 30) {
	message("info", tp->query_cap_name()+"'s %^BOLD%^%^BLACK%^R%^WHITE%^e%^BLACK%^n%^WHITE%^e%^BLACK%^g%^YELLOW%^a%^BLACK%^d%^WHITE%^e%^BLACK%^ flashes as it sucks the %^RED%^evil %^BLACK%^from thier opponent.%^RESET%^", environment(tp), ({tp, atk }) );
	message("info", "Your %^BOLD%^%^BLACK%^R%^WHITE%^e%^BLACK%^n%^WHITE%^e%^BLACK%^g%^YELLOW%^a%^BLACK%^d%^WHITE%^e%^BLACK%^ flashes as it sucks the %^RED%^evil %^BLACK%^ out of "+atkr->query_cap_name()+".", tp, );
	message("info", tp->query_cap_name()+"'s %^BOLD%^%^BLACK%^R%^WHITE%^e%^BLACK%^n%^WHITE%^e%^BLACK%^g%^YELLOW%^a%^BLACK%^d%^WHITE%^e%^BLACK%^ flashes as it sucks the %^RED%^evil %^BLACK%^ out of you!", atk, );
//	result=(100 - random(25));
//	tp->heal(result);
	return result;
    }
}
int query_auto_load(){ 
    if (this_player()->query_original_guild()=="lastsaints") return 1; 
}
