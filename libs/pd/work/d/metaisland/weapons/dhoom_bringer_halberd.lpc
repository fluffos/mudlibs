#include <std.h>
#include <metallicana.h>
int weapon_hit(object atk);
inherit WEAPON;

void create() {
    ::create();
    set_name("Dhoom Bringer Halberd");
    set_short("%^BOLD%^%^BLACK%^Dh%^WHITE%^oom%^BLACK%^ Br%^WHITE%^ing%^BLACK%^er Ha%^WHITE%^lbe%^BLACK%^rd%^RESET%^");
    set_long("The Halberd is composed of bone, and has an inscrption carved into the blade "
             "An Inscription reads: "
             "Walk the path of Darkness, Embrace the flow of Evil.");
    set_id(({"dhoom bringer halberd", "bone halberd", "halberd"}));
    set_mass(53);
    set_curr_value("gold", 104);
    set_type("projectile");
    set_hit ( (: weapon_hit :) );
    set_wield("%^BOLD%^%^BLACK%^The Halberd feels like apart of
you.%^RESET%^\n");
    set_unwield("%^BOLD%^%^BLACK%^You feel as though you are being torn
apart.%^RESET%^\n");
    set_wc(9);
    set_ac(0);
}


int weapon_hit(object atk)
{
    int result;
    if(random(90) > 74) {
        write("%^BOLD%^Swinging the Halberd you strike bone, shattering their arm.%^RESET%^\n");
        say("%^BOLD%^"+this_player()->query_cap_name()+" Swings the Halberd striking your arm, shattering the bone.%^RESET%^\n");
        result=(random(50))+((this_player()->query_level()));
        result = random(result) + 14;
    }
}

int query_auto_load(){ 
    if (this_player()->query_level() > 44) return 1;
}
