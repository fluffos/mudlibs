#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("boots");
    set_short("%^MAGENTA%^M%^CYAN%^i%^RED%^s%^CYAN%^t%^RESET%^%^MAGENTA%^y B%^CYAN%^o%^RED%^o%^CYAN%^t%^RESET%^%^MAGENTA%^s%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^These boots seem to be made of a magical metal, you have never seen it before.");
    set_id( ({ "boots" , "misty boots" }) );
    set_ac(4);
    set_mass(5);
    set_value(22);
    set_type("boots");
    set_limbs( ({ "left foot","right foot" }) );
}

int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
