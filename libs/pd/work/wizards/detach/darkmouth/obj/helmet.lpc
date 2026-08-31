#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("helmet");
    set_short("%^BOLD%^%^WHITE%^Dra%^YELLOW%^gon%^WHITE%^ian He%^YELLOW%^lm%^WHITE%^et%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This Helmet is formed from Dragon-scales, They are a deep white colour with a yellow tint.%^RESET%^");
    set_id( ({ "helmet" , "dragonian helmet" }) );
    set_ac(5);
    set_mass(4);
    set_curr_value("gold",100+random(40));
    set_type("helmet");
    set_limbs( ({ "head" }) );
}

int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}

