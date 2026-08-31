#include <std.h>
#include <metallicana.h>
int weapon_hit(object atk);
inherit WEAPON;

void create() {
    ::create();
    set_name("Cerberus Tooth");
    set_short("%^BOLD%^%^BLACK%^Ce%^RED%^r%^WHITE%^be%^RED%^r%^BLACK%^us %^RED%^T%^WHITE%^oo%^BLACK%^t%^RED%^h%^RESET%^");
    set_long("The tooth has been crafted with other bones to fit the hand, It was made from the tooth of the Hell Hound Serbarus.");
    set_id(({"cerberus tooth", "tooth", "melee"}));
    set_mass(46);
    set_curr_value("gold", 200);
    set_type("melee");
    set("skill level", 300);
    set_hit ( (: weapon_hit :) );
    set_wield("%^BOLD%^%^RED%^Your Soul burns with Fury!%^RESET%^\n");
    set_unwield("%^BOLD%^%^RED%^Calm returns to you once more!%^RESET%^\n");
    set_wc(12);
    set_ac(1);
}


int weapon_hit(object atk)
{
    int result;
    if(random(100) > 87) {
        write("%^BOLD%^RED%^As you strike your foe three claws appear from the bone piercing their chest!%^RESET%^\n");
        say("%^BOLD%^RED%^As "+this_player()->query_cap_name()+"'s strikes you three claws appear from the bone piercing your chest!%^RESET%^\n");
        result=(random(50))+((this_player()->query_level()));
        result = random(result) + 23;
    }
}

int query_auto_load() { 
if(this_player()->query_level() > 45) return 0;

 return 1; 
}
