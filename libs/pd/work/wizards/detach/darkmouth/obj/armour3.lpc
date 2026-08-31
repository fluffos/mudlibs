#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("armour");
    set_short("%^BOLD%^%^RED%^B%^WHITE%^l%^RED%^o%^RESET%^%^RED%^o%^BOLD%^%^RED%^d%^RESET%^%^RED%^y %^BOLD%^%^RED%^A%^WHITE%^r%^RED%^m%^RESET%^%^RED%^o%^BOLD%^%^RED%^u%^RESET%^%^RED%^r%^RESET%^");
    set_long("%^BOLD%^%^RED%^Blood drips off the armour, as you look closer the armour seems to be made of pure Blood, magical powers swarm through the Blood.%^RESET%^");
    set_id( ({ "armour" , "bloody armour" }) );
    set_ac(9);
    set_mass(25);
    set_curr_value("gold",100+random(40));
    set_type("body armour");
    set_limbs( ({ "torso","left arm","right arm","left leg","right leg"
}) );
}

int query_auto_load()
{

 if (wizardp(this_player())) return 1;
 return 1;
}
