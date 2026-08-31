#include <std.h>
inherit ARMOUR;

void create() {
::create();
    set_name("armour");
    set_short("%^RED%^Cr%^WHITE%^i%^RED%^ms%^WHITE%^o%^RED%^n %^WHITE%^A%^RED%^rm%^WHITE%^ou%^RED%^r");
    set_long("This is the fabled armour worn by the guardians of %^RED%^hell.");
    set_id(({"armour", "armor", "crimson armour"}));
    set_ac(11);
    set_mass(22);
    set_value(400);
    set_type("armour");
    set_limbs(({"torso", "right arm", "left arm"}));
}
int query_auto_load() { if (this_player()->query_level() > 19) return 1; }
