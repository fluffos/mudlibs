#include <std.h>
#include <metallicana.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("Angelic Cloak");
    set_short("%^BOLD%^YELLOW%^A%^WHITE%^ngel%^YELLOW%^ic C%^WHITE%^lo%^YELLOW%^ak%^RESET%^");
    set_long("The cloak is imbued with angelic goodness and a holy aura surronds it.");
    set_id(({"angelic cloak", "cloak"}));
    set_ac(6);
    set_weight(25);
    set_curr_value("gold",183);
    set_type("cloak");
    set_limbs(({"torso", "head"}));
}
int query_auto_load() {
    if (this_player()->query_level() > 44) return 1;
}
