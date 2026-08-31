#include <std.h>
#include <metallicana.h>
int weapon_hit(object atk);
inherit WEAPON;

void create() {
    ::create();
    set_name("War Scepter");
    set_short("%^YELLOW%^W%^WHITE%^a%^YELLOW%^r %^WHITE%^S%^YELLOW%^c%^WHITE%^e%^YELLOW%^p%^WHITE%^t%^YELLOW%^e%^WHITE%^r");
    set_long("The Scepter of the ka'karl Warlord.");
    set_id(({"war scepter", "scepter", "warlord scepter"}));
    set_mass(56);
    set_curr_value("gold", 102);
    set_type("blunt");
    set_hit ( (: weapon_hit :) );
    set_wc(11);
    set_ac(0);
    set_hands(2);
}
int weapon_hit(object atk)
{
    int result;
    if(random(99) > 17) {
        write("%^BOLD%^The hammer %^YELLOW%^glows %^WHITE%^as you smash the ground, knocking your enemy to the ground!\n");
        say("%^BOLD%^"+this_player()->query_cap_name()+"'s scepter %^YELLOW%^glows %^WHITE%^as it smashes the ground throwing you to the ground!%^RESET%^\n");
        result=(random(50))+((this_player()->query_level()));
        result = random(result) + 22;
    }
}
int query_auto_load(){ 
    if (this_player()->query_level() > 44) return 1;
}
