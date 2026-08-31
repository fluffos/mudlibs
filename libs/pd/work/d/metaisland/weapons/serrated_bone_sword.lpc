#include <std.h>
#include <metallicana.h>
int weapon_hit(object atk);
inherit WEAPON;

void create() {
    ::create();
    set_name("Serrated Bone Sword");
    set_short("%^BOLD%^BLACK%^Se%^WHITE%^rr%^BLACK%^ated B%^WHITE%^o%^BLACK%^ne S%^WHITE%^wo%^BLACK%^rd%^RESET%^");
    set_long("The bone of the swords has a faint glow surronding it.");
    set_id(({"serrated bone sword", "bone sword", "sword"}));
    set_mass(34);
    set_curr_value("gold", 119);
    set_type("blade");
    set_hit ( (: weapon_hit :) );
    set_wield("%^BOLD%^%^BLACK%^It looks like a good time for people die.%^RESET%^\n");
    set_unwield("%^BOLD%^%^BLACK%^The urge to kill leaves as you let go of the sword.%^RESET%^\n");
    set_wc(8);
    set_ac(0);
}


int weapon_hit(object atk)
{
    int result;
    if(random(90) > 72) {
        write("%^BOLD%^The sword catchs their leg sending flesh flying everywhere.%^RESET%^\n");
        say("%^BOLD%^"+this_player()->query_cap_name()+"'s sword catchs your leg sending flesh flying everywhere.%^RESET%^\n");
        result=(random(50))+((this_player()->query_level()));
        result = random(result) + 11;
    }
}

int query_auto_load(){ 
    if (this_player()->query_level() > 44) return 1;
}
