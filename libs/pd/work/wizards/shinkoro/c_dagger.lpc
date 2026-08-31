#include <std.h>
#include <metallicana.h>
inherit WEAPON;

void create() {
    ::create();
    set_name("Curved Dagger");
    set_short("%^BOLD%^%^BLACK%^Cu%^RESET%^%^BLUE%^rv%^BOLD%^BLACK%^ed %^BOLD%^%^BLACK%^Da%^RESET%^%^BLUE%^gg%^BOLD%^BLACK%^er");
    set_long("A thin steel blade that is curved in the shape of a half moon.");
    set_id(({"knife", "curved dagger", "dagger"}));
    set_mass(32);
    set_curr_value("gold", 200);
    set_type("knife");
    set_hit ( (: this_object(), "weapon_hit" :) );
    set_wc(10);
    set_ac(0);
}
int weapon_hit()
{
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(42) > 9) {
        write("%^BOLD%^%^BLACK%^Your dagger gleams as it seers the flesh!\n");
        say("%^BOLD%^"+this_player()->query_cap_name()+"'s dagger gleams as it seers your flesh!%^RESET%^\n");
        result=(random(50))+((this_player()->query_level()));
        result = random(result) + 11;
    }
}
int query_auto_load(){ 
    if (this_player()->query_level() > 44) return 1;
}
