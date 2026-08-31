#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Helm of the Demons");
    set_short("%^RED%^D%^BOLD%^e%^BLACK%^m%^RESET%^o%^BOLD%^%^RED%^n "
      "%^BLACK%^Helm%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^A helm specially made for the %^RED%^D"
      "%^BOLD%^e%^BLACK%^m%^RESET%^o%^BOLD%^%^RED%^n%^RESET%^%^RED%^s"
      "%^BOLD%^%^BLACK%^ of the %^BLUE%^For%^RESET%^sa%^BOLD%^%^BLUE%^"
      "ken%^BLACK%^.%^RESET%^");
    set_id (({"helm", "helmet", "demon helm"}));
    set_ac (5);
    set_mass (15);
    set_curr_value ("gold", 100);
    set_type("helmet");
    set_limbs (({"head"}));
}
int query_auto_load() 
{
    if(this_player()->query_guild() == "forsaken") return 1; else return 0;
}

