inherit ARMOUR;

void create() {
    ::create();
    set_name("cloak");
    set_short("%^BOLD%^Wol%^RESET%^%^RED%^fs%^RESET%^%^BOLD%^kin Cl%^RESET%^%^RED%^o%^RESET%^%^BOLD%^ak%^RESET%^");
    set_long("This cloak is made from the skin of a huge silver wolf, as you look closer blood can be seen all over it.");
    set_id( ({ "cloak" , "wolfskin cloak" }) );
    set_ac(3);
    set_wear("%^BOLD%^%^WHITE%^Your Cloak seems to growl as you don it.%^RESET%^");
    set_remove("%^BOLD%^%^YELLOW%^The noise is gone.%^RESET%^");
    set_mass(20);
    set_value(25);
    set_type("cloak");
    set_limbs( ({ "torso","head","right arm","left arm" }) );
}

int query_auto_load()
{
    if (wizardp(this_player())) return 1;
    return 1;
}
