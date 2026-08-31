#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Water Boots");
    set_short("%^BOLD%^%^BLUE%^Wa%^RESET%^%^BLUE%^te%^GREEN%^r "
      "B%^BLUE%^oo%^BOLD%^%^BLUE%^ts%^RESET%^");
    set_long("These boots are made from water, they seem as if "
      "surround your feet. It seems that a magician formed these.");
    set_id( ({ "boots" ,"water boots" }) );
    set_ac(3);
    set_type("boots");
    set_mass(18);
    set_curr_value("gold",70+random(40));
    set_limbs( ({ "right foot","left foot"}) );
}                  
int query_auto_load()
{
    if (wizardp(this_player())) return 1;
    if(this_player()->query_level() < 10) return 0;
    return 1;
}
