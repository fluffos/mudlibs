#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Dwarven Battle Armour");

set_short("%^BOLD%^%^BLACK%^D%^RED%^w%^BLACK%^a%^RED%^r%^BLACK%^v%^RED%^e%^BLACK%^n "
"%^RED%^B%^BLACK%^a%^RED%^t%^BLACK%^t%^RED%^l%^BLACK%^e "
"%^RED%^A%^BLACK%^r%^RED%^m%^BLACK%^o%^RED%^u%^BLACK%^r%^RESET%^");
    set_long("This armour was made from dragon scales and copper. "
 "This armour will protect anyone very well.");
    set_id( ({ "armour" , "dwarven battle armour"}) );
    set_ac(16);
    set_mass(55);
    set_value(600);
    set_type("body armour");
    set_limbs( ({ "torso","head","right arm","left arm" }) );
}

int query_auto_load()
{                                   
if (this_player()->query_level() > 10) return 1;
if (wizardp(this_player())) return 1;
 return 0;
}     
