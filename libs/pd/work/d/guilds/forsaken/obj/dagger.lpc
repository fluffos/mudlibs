#include <std.h>
inherit WEAPON;

create() {
    ::create();
    set_id(({"dagger", "knife"}));
    set_name("forsaken dagger");     set_short("%^RESET%^%^BOLD%^%^BLUE%^For%^RESET%^%^WHITE%^sa%^BOLD%^%^BLUE%^ken %^BLACK%^Dagger%^RESET%^");
    set_long("With a nine inch serrated blade, %^BOLD%^%^BLUE%^blue %^YELLOW%^f%^RED%^la%^YELLOW%^mes%^RESET%^ spiral around the hilt. Definitely, a creation of the %^BOLD%^%^BLUE%^For%^RESET%^sa%^BOLD%^%^BLUE%^ken.%^RESET%^");
    set_mass(10);              
    set_curr_value("gold", 2000);
    set_wc(1);                
    set_ac(1);                 
    set_type("knife");         
    set_hands(1);              
    set_wield("As you grip the hilt, %^YELLOW%^f%^RED%^la%^YELLOW%^mes%^RESET%^ burst around your arm up to your shoulder.");
    set_unwield("The %^YELLOW%^f%^RED%^la%^YELLOW%^mes%^RESET%^ dissipate as you sheath the dagger.");
}

int query_auto_load() { 
    if(this_player()->query_guild() == "forsaken") return 1;

}
