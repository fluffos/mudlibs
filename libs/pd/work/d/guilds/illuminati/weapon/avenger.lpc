// I added this after mail.
// I was writing it as we were talking.
#include <std.h>

inherit WEAPON;

void create() {
    ::create();
    set_id(({"avenger"}));
    set_name("avenger");
    set_short("%^YELLOW%^A%^WHITE%^ve%^RESET%^n%^BOLD%^WHITE%^ge%^YELLOW%^r%^RESET%^");
    set_long("");
    set_mass(25);
    set_curr_value("gold", 2000);
    set_wc(1);
    set_ac(2);
    set_type("blade");
    set_hands(1);
    //set_hit( (: this_object(),"weapon_hit" :) );  
}

int weapon_hit() {
    int result, chance;
    object atkr, tp;
    atkr = this_player()->query_current_attacker();
    tp = this_player();
    if(random(10) == 0) {
	message("info", "%^BOLD%^Y%^RESET%^o%^BOLD%^u%^RESET%^r %^BOLD%^s%^RESET%^w%^BOLD%^o%^RESET%^r%^BOLD%^d glows %^BOLD%^a%^RESET%^s %^BOLD%^i%^RESET%^t %^BOLD%^s%^RESET%^t%^BOLD%^r%^RESET%^i%^BOLD%^k%^RESET%^e%^BOLD%^s "+atkr->query_cap_name()+"%^RESET%^.", tp, );
	message("info", "%^BOLD%^WHITE%^"+tp->query_cap_name()+"'s %^RESET%^s%^BOLD%^w%^RESET%^o%^BOLD%^r%^RESET%^d %^BOLD%^g%^RESET%^l%^BOLD%^o%^RESET%^w%^BOLD%^s %^RESET%^a%^BOLD%^s %^RESET%^i%^BOLD%^t %^RESET%^s%^BOLD%^t%^RESET%^r%^BOLD%^i%^RESET%^k%^BOLD%^e%^RESET%^s %^BOLD%^y%^RESET%^o%^BOLD%^u%^RESET%^!", atkr, );
	message("info", "%^BOLD%^WHITE%^"+tp->query_cap_name()+"'s %^RESET%^s%^BOLD%^w%^RESET%^o%^BOLD%^r%^RESET%^d %^BOLD%^g%^RESET%^l%^BOLD%^o%^RESET%^w%^BOLD%^s %^RESET%^a%^BOLD%^s %^RESET%^i%^BOLD%^t %^RESET%^s%^BOLD%^t%^RESET%^r%^BOLD%^i%^RESET%^k%^BOLD%^e%^RESET%^s %^BOLD%^"+atkr->query_cap_name()+"%^RESET%^.", environment(tp), ({tp, atkr }) );
	result = 100 - random(20);
	if(atkr->query_alignment() < 0);
	result -= (tp->query_alignment()/10);
        tp->heal(result/2);
	if(random(100) < 10 && !atkr->query_paralyzed()) {
	    message("info", "%^YELLOW%^The Avenger flashes brightly!%^RESET%^", tp, );
	    message("info", "%^YELLOW%^The Avenger's glow blinds you!%^RESET%^", atkr, );
	    message("info", "%^YELLOW%^"+tp->query_cap_name()+"'s Avenger flashes brightly!%^RESET%^", environment(tp), ({tp, atkr}));
	    if(!atkr->query_paralyzed()) atkr->set_paralyzed(1, "You are blinded!", "Your sight returns.");
	}
	return result;
    }
}

int query_auto_load(){ 
    if (this_player()->query_guild()=="illuminati" && this_player()->query_level() >= 50) return 1; 
}
