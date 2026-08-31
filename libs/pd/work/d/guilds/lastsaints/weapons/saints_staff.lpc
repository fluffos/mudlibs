#include <std.h>
#include <amun.h>
inherit WEAPON;
create() {
    ::create();
    set_id(({"saints staff", "staff", "saint staff"}));
    set_name("Saints Staff");
    set_short("%^BOLD%^%^WHITE%^Saints %^RESET%^%^ORANGE%^Staff%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^This staff was blessed by the %^BOLD%^%^WHITE%^%^God %^RESET%^%^ORANGE%^who made it and was given to the Last Saints to rid the world of evil.%^RESET%^");
    set_mass(20);
    set_curr_value("gold", 120);
    set_wc(1); 
    set_type("blunt");
    set("skill level", 125);
    set_hands(1);
//    set_hit( (: this_object(),"weapon_hit" :) );  
}
int weapon_hit()
{
    int result, chance;
    object atkr, tp;
    atkr = this_player()->query_current_attacker();
    tp = this_player();
    if(random(100) < 30) {
	message("info", tp->query_cap_name()+"'s %^RESET%^%^ORANGE%^staff smashes your opponent updside the head.%^RESET%^",
	  environment(tp), ({tp, atkr }) );
	message("info", "Your %^RESET%^%^ORANGE%^staff smashes "+atkr->query_cap_name()+" upside the head!", tp, );
	message("info", tp->query_cap_name()+"'s %^RESET%^%^ORANGE%^staff smashes you updside the head.%^RESET%^!", atkr, );
	result=(100 - random(25));
	tp->heal(result);
	return result;
    }
}
int query_auto_load(){ 
    if (this_player()->query_guild()=="last saints") return 1; 
}
