#include <std.h>
#include <metallicana.h>
inherit WEAPON;
int weapon_hit(object atk);

void create() {
    ::create();
    set_name("Blacksmiths hammer");
    set_short("%^MAGENTA%^Bla%^BOLD%^%^BLACK%^ck Smi%^RESET%^%^MAGENTA%^ths H%^BOLD%^%^BLACK%^amm%^RESET%^%^MAGENTA%^er%^RESET%^");
    set_long("An Anceint hammer used by the blacksmith of the scarlett claw.");
    set_id(({"blacksmiths hammer", "hammer"}));
    set_mass(56);
    set_curr_value("gold", 101);
    set_type("blunt");
    set_hit ( (: weapon_hit :) );
    set_wc(11);
    set_ac(0);
    set_hands(2);
}
int weapon_hit(object atk)
{
    int result;
    if(random(90) > 36) {
        write("%^MAGENTA%^You smash your enemy crushing their lungs!%^RESET%^\n");
        say("%^MAGENTA%^"+this_player()->query_cap_name()+"'s Hammer crushes your lungs!%^RESET%^\n");
        result=(random(76))+((this_player()->query_level()));
        result = random(result) + 9;
    }
}
int query_auto_load(){ 
    if (this_player()->query_level() > 44) return 1;
}
