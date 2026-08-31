#include <std.h>
#include <amun.h>
inherit WEAPON;
int weapon_hit();
create() {
    ::create();
    set_id(({"sword", "sword of serpents", "serpents"}));
    set_name("Sword of Serpents");
    set_short("%^RESET%^%^GREEN%^S%^BOLD%^%^GREEN%^w%^RESET%^%^ORANGE%^o%^RESET%^%^GREEN%^r%^BOLD%^%^GREEN%^d %^RESET%^%^ORANGE%^o%^RESET%^%^GREEN%^f %^BOLD%^%^GREEN%^S%^RESET%^%^ORANGE%^e%^RESET%^%^GREEN%^r%^BOLD%^%^GREEN%^p%^RESET%^%^ORANGE%^e%^RESET%^%^GREEN%^n%^BOLD%^%^GREEN%^t%^RESET%^%^ORANGE%^s%^RESET%^");
    set_long("%^RESET%^%^GREEN%^The %^BOLD%^%^GREEN%^handle %^RESET%^%^ORANGE%^of %^RESET%^%^GREEN%^the %^BOLD%^%^GREEN%^sword %^RESET%^%^ORANGE%^is %^RESET%^%^GREEN%^made %^BOLD%^%^GREEN%^with %^RESET%^%^ORANGE%^snake%^RESET%^%^GREEN%^skin %^BOLD%^%^GREEN%^and %^RESET%^%^ORANGE%^the %^RESET%^%^GREEN%^blade %^BOLD%^%^GREEN%^is %^RESET%^%^ORANGE%^made %^RESET%^%^GREEN%^of %^BOLD%^%^GREEN%^undiluted %^RESET%^%^ORANGE%^metal%^GREEN%^.%^RESET%^");
    set_weight(30);
    set_curr_value("gold", 150);
    set("skill level", 225);
    set_wc(14);
    set_decay_rate(200);
    set_ac(3);
    set_type("blade");
    set_wield("%^GREEN%^The snake head on the handle slithers up your wrist keeping the sword steady.%^RESET%^");
    set_unwield("%^GREEN%^The snake unwraps itself from around your arm, allowing you to unwield it.%^RESET%^");
    set_hit((:this_object(),"weapon_hit":));
}
int weapon_hit() {
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(100) > 90) {
	write("%^RESET%^%^GREEN%^The snakehead lunges at your opponent as your sword slices them open!%^RESET%^");
	say((string)"%^RESET%^%^GREEN%^"+this_player()->query_cap_name()+"%^GREEN%^'s sword slices deep into you as the sword's snake lunges for a bite!%^RESET%^");
	result=(random(50))+((this_player()->query_level())*2/3);
	if(random(100) > 74) {
	    write("%^RESET%^%^ORANGE%^The sword plunges deep into your opponent paralyzing them!%^RESET%^ ");
	    say("%^RESET%^%^ORANGE%^The sword plunges deep into your stomach causing you to be paralyzed!%^RESET%^");
	    atk->set_paralyzed(random(2));
	    return result;
	}
    }
}
int query_auto_load() {
    if(this_player()->query_level() < 40) return 0;
    return 1; 
}
