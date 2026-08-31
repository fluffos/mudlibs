#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Ice Plate");
    set_short("%^BLUE%^I%^BOLD%^%^WHITE%^c%^RESET%^e "
"Pl%^BOLD%^%^WHITE%^a%^RESET%^%^BLUE%^te%^RESET%^");
   set_long("This Plate is formed from A deep blue Ice. It looks "
"as if this plate will cover your head and torso.");
    set_id( ({"plate","ice plate" }) );
    set_ac(10);
    set_mass(22);
    set_curr_value("gold",150+random(40));
    set_type("body armour");
    set_limbs(({ "torso","head" }));
}                  
int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
