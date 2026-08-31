#include <std.h>
inherit WEAPON;

create() {
::create();
    set_name("dagger");
    set_short("%^BOLD%^%^BLACK%^D%^WHITE%^ar%^BLACK%^k T%^WHITE%^wi%^BLACK%^st%^WHITE%^ed %^BLACK%^D%^WHITE%^ag%^BLACK%^g%^WHITE%^er");
    set_long( "This dagger was created in the evil land of %^BOLD%^%^BLACK%^Gehenna.");
    set_id(({"dagger", "knife", "dark twisted dagger"}));
    set_mass(12);
    set_value(900);
    set_wc(16);  
    set_ac(1);
    set_type("knife");
    set_hit((:this_object(),"weapon_hit":));
}

int weapon_hit()
{
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(102) > 80) {
       write("The %^BOLD%^%^BLACK%^da%^WHITE%^g%^BLACK%^g%^WHITE%^er'%^BLACK%^s t%^WHITE%^w%^BLACK%^is%^WHITE%^e%^BLACK%^d %^WHITE%^e%^BLACK%^dg%^WHITE%^e %^RED%^tears into your opponent!");
       say((string)this_player()->query_cap_name()+
	  "'s %^BOLD%^%^BLACK%^d%^WHITE%^ag%^BLACK%^ge%^WHITE%^r%^RESET%^ %^RED%^%^BOLD%^tears through his opponent! "
	  +this_player()->query_possessive()+".");
        result=(random(5+random(5)-random(5))*((this_player()->query_level()/5)+1));
        result=random(result)+1;
        this_player()->add_hp(result);
        return result;
}
return 0;
}
int query_auto_load() { if (this_player()->query_level() > 19) return 1; }
