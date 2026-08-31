#include <std.h>
#include <amun.h>
inherit WEAPON; 
int weapon_hit();                                                        
void create() {
    ::create();                                                             
    set_name("Black Crystal Dagger");
    set_id( ({ "black", "black crystal", "black crystal dagger", "crystal dagger", "dagger", "crystal" }) );
    set_short("%^BOLD%^%^BLACK%^Black Crystal Dagger%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^The blade of this dagger is made of pure black crystal. The handle is black and has an indentation of Natas that glows %^RED%^red %^BLACK%^when being used.%^RESET%^" );
    set_type("knife");
    set_weight(20);
    set_decay_rate(200);
    set_curr_value("gold", 125);
    set_wc(10);
    set("skill level", 200);
    set_wield("%^BOLD%^%^BLACK%^The dagger %^RED%^glows %^BLACK%^as you wield it.%^RESET%^");
    set_unwield("%^BOLD%^%^BLACK%^The %^RED%^glowing %^BLACK%^subsides as you unwield the dagger.%^RESET%^");
    set_hit((:this_object(),"weapon_hit":));
}
int weapon_hit() {
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(100) > 90) {
	write("%^BOLD%^%^BLACK%^The dagger seeps deep into your opponent, splurting %^RED%^blood %^BLACK%^everywhere!%^RESET%^");
	say((string)"%^BOLD%^%^BLACK%^"+this_player()->query_cap_name()+"%^BLACK%^'s dagger seeps into you, causing your %^RED%^blood %^BLACK%^to splurt everywhere!%^RESET%^");
	result=(random(50))+((this_player()->query_level())*2/3);
	if(random(100) > 74) {
	    write("%^BOLD%^%^BLACK%^The symbol of Natas %^RED%^glows %^BLACK%^mezmerizing your opponent!%^RESET%^ ");
	    say("%^BOLD%^%^BLACK%^The symbol of Natas glows mezmerizing you into paralyzation!%^RESET%^");
	    atk->set_paralyzed(random(2));
	    return result;
	}
    }
}
int query_auto_load() {
    if(this_player()->query_level() < 40) return 0;
    return 1; 
}
