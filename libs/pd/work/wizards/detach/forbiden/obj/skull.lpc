#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("skull");
    set_short("%^BOLD%^%^RED%^Wol%^BLACK%^f Sku%^RED%^ll%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This mask seems to be a giant wolf skull, it's bloody and covered in dirt.%^RESET%^");
    set_id( ({ "skull" , "wolf skull" }) );
    set_ac(6);
    set_mass(3);
    set_curr_value("gold", 3);
    set_type("helmet");
    set_limbs( ({ "head" }) );
}

int query_auto_load()
{
    if (wizardp(this_player())) return 1;
    return 1;
}
