#include <std.h>
#include <roston.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Dark Soul's Cloak");
    set_short("%^BOLD%^%^BLACK%^D%^WHITE%^a%^BLACK%^r%^WHITE%^k "
"%^BLACK%^S%^WHITE%^o%^BLACK%^u%^WHITE%^l%^BLACK%^'%^WHITE%^s "
"%^BOLD%^%^BLACK%^C%^WHITE%^l%^BLACK%^o%^WHITE%^a%^BLACK%^k%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This Cloak is given to each "
"member of the D%^WHITE%^a%^BLACK%^r%^WHITE%^k %^BLACK%^S%^WHITE%^o"
"%^BLACK%^u%^WHITE%^l%^BLACK%^s to represent what guild they are "
"apart of. It hangs from the head down. It is a Deep black and white color");
    set_id( ({ "cloak" , "dark souls cloak" }) );
    set_property("no steal", 1);
    set_ac(1);
    set_wear("%^BOLD%^%^BLACK%^You feel the power of the Elder souls merge into you, as you finally feel true power.");
    set_remove("%^BOLD%^%^WHITE%^The Souls leave you.");
    set_mass(1);
    set_value(0);
    set_type("Guild");
    set_limbs( ({ "torso"}) );
}

int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}


