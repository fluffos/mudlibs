
#include <std.h>
#include <metallicana.h>
int weapon_hit(object atk);
inherit WEAPON;

void create() {
    ::create();
    set_name("Barbed Whiplash");
    set_short("%^BOLD%^GREEN%^Ba%^WHITE%^rb%^GREEN%^ed %^WHITE%^Whi%^GREEN%^pla%^WHITE%^sh%^RESET%^");
    set_long("The handle of this whip is made frok oak wood. The vines attached to it have an array of large thorns.");
    set_id(({"barbed whip", "whip", "whiplash", "barbed whiplash"}));
    set_mass(43);
    set_curr_value("gold", 139);
    set_type("flail");
    set_hit ( (: weapon_hit :) );
    set_wield("%^BOLD%^%^GREEN%^You become more intune with nature.%^RESET%^\n");
    set_unwield("%^BOLD%^%^GREEN%^You feel your unity with nature fade.%^RESET%^\n");
    set_wc(9);
    set_ac(0);
}


int weapon_hit(object atk)
{
    int result;
    if(random(90) > 72) {
        write("%^BOLD%^GREEN%^The whip catchs your enemy around the throat, digging the thorns in.%^RESET%^\n");
        say("%^BOLD%^%^GREEN%^"+this_player()->query_cap_name()+"'s whip catchs you around the throat, digging the thorns in.%^RESET%^\n");
        result=(random(50))+((this_player()->query_level()));
        result = random(result) + 9;
    }
}

int query_auto_load(){ 
    if (this_player()->query_level() > 44) return 1;
}
