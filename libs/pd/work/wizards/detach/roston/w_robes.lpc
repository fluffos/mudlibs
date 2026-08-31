#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("robes");
    set_short("%^YELLOW%^W%^BOLD%^%^CYAN%^i%^RED%^z%^BLUE%^a%^GREEN%^r"
              "%^BOLD%^%^BLACK%^d %^BOLD%^%^RED%^R%^BOLD%^%^BLUE%^"
              "o%^BOLD%^%^GREEN%^b%^BOLD%^%^ORANGE%^e%^CYAN%^s%^RESET%^");
    set_long("These Robes are made for a great Wizard. These "
             "robes are made of a great  cloth, that is only "
             "found deep in the mountains of Roston.");
    set_id( ({ "robes" , "wizard robes" }) );
    set_ac(8);
    set_mass(25);
    set_value(400);
    set_type("robe");
    set_limbs( ({ "torso","head",}));
}
int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}               
