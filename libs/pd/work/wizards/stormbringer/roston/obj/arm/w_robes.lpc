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
    set_ac(3);
    set_mass(25);
    set_curr_value("gold", 40);
    set_type("robes");
    set_limbs( ({ "torso","head",}));
}
int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 if (this_player()->query_level() < 12) return 0;
 return 1;
}               
