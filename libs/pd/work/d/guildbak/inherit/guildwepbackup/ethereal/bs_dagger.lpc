#include <std.h>
#include <ether.h>
inherit ETHERWEP;
int weapon_hit();
void create() {
    ::create();
    set_name("dagger");
    set_short("%^RED%^b%^BOLD%^l%^RESET%^o%^RED%^o%^BOLD%^d%^RESET%^ s%^RED%^t%^BOLD%^a%^RESET%^i%^RED%^n%^BOLD%^e%^RESET%^d%^RED%^ d%^BOLD%^a%^RESET%^g%^RED%^g%^BOLD%^e%^RESET%^r");
    set_long("%^RED%^This dagger is stained with %^BOLD%^blood%^RESET%^%^RED%^, it looks as if it has been heavily used.%^RESET%^");
    set_weight(13);
    set_id( ({ "dagger", "blood dagger", "blood stained dagger" }) );
    set_curr_value("gold", 100);
    set_hit((:this_object(),"weapon_hit":));
    set_wc(14);
    set_ac(2);
    set_type("knife");
    set_hands(1);
} 
int query_auto_load() {
    if (this_player()->query_level() >= 36) return 1;
    else return 0; 
}
int weapon_hit() { 
    int the_pain;
    int spadd;
    object bastid = (object)this_player()->query_current_attacker();
    string gender_confused;
    if (bastid->query_gender() == "male") gender_confused = "him"; else gender_confused = "her";
    if (random(100) > 80) {
	write("%^RESET%^%^BOLD%^%^BLACK%^You get close to your opponent and%^RED%^ stab%^BLACK%^ "+gender_confused+" in the stomach%^RESET%^.");
	say((string)"%^BOLD%^%^BLACK%^"+this_player()->query_cap_name()+" inches close to "+bastid->query_name()+" and %^RED%^stabs%^BLACK%^ "+gender_confused+" in the chest%^RESET%^");
	bastid->do_damage("torso", random(15)+5);
	spadd = this_player()->query_stats("dexterity") / 2;
	this_player()->add_sp(spadd);
	spadd = this_player()->query_stats("dexterity") * 2;
	the_pain=(random(55))+(spadd);
	return the_pain; 
    }
}




