#include <std.h>

inherit STONE;

void create() {
  ::create();
    set_name("arctic orb");
    set_short("%^BOLD%^%^WHITE%^a%^CYAN%^r%^RESET%^%^CYAN%^ct%^BOLD%^%^CYAN%^i%^WHITE%^c%^RESET%^ orb");
    set_long("This mana orb will replenish your MP. <%^BOLD%^%^WHITE%^invoke arctic%^RESET%^> to activate
it.");
    set_id( ({ "arctic", "orb" }) );
    set_mass(1);
    set_value(0);
    set_action("invoke");
    set_remove_mess("The %^BOLD%^%^WHITE%^a%^CYAN%^r%^RESET%^%^CYAN%^ct%^BOLD%^%^CYAN%^i%^WHITE%^c%^RESET%^ orb has thawed completely.");
    set_levels(({"dripping","thawing","chilly","cold","frosty","frozen"}));   
    set_use_mess("%^BOLD%^%^WHITE%^A flash of %^BLUE%^blue light %^WHITE%^surrounds you as you invoke the %^BOLD%^%^WHITE%^a%^CYAN%^r%^RESET%^%^CYAN%^ct%^BOLD%^%^CYAN%^i%^WHITE%^c orb.\n%^CYAN%^You feel mana rushing through your veins.%^RESET%^");
}
