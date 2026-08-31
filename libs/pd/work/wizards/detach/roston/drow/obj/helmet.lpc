#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Helmet");
set_short("%^YELLOW%^L%^BOLD%^%^WHITE%^i%^YELLOW%^g%^WHITE%^h%^YELLOW%^"
          "t %^WHITE%^H%^YELLOW%^e%^WHITE%^l%^YELLOW%^m%^WHITE%^e"
          "%^YELLOW%^t%^RESET%^");
    set_long("This helmet was made by the evil drow pyromacer, they "
             "say this helmet contains the true powers of the sun.");
    set_id( ({ "helmet" , "light helmet" }) );
    set_ac(18);
    set_wear("%^YELLOW%^Your head is surrounded with a bright "
             "yellow light.");
    set_remove("%^YELLOW%^The Light disapears.");
    set_mass(14);
    set_value(250);
    set_type("helmet");
    set_limbs( ({ "head" }) );
}                     















int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}            
