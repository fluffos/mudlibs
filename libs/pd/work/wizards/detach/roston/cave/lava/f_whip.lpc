#include <std.h>
inherit WEAPON;

create() {
::create();
    set_id(({"whip","lava whip"}));
    set_name("Lava Whip");
    set_short("%^BOLD%^%^RED%^L%^RESET%^%^RED%^a%^BOLD%^%^RED%^v"
              "%^RESET%^%^RED%^a %^BOLD%^%^RED%^W%^RESET%^%^RED%^h"
              "%^BOLD%^%^RED%^i%^BOLD%^%^RED%^p");
    set_long( "%^RED%^ This Whip is one of a kind, that could only "
              "be found in the firey deeps..");
    set_mass(50);
    set_value(400+random(40));
    set_wc(10);
    set_ac(5);
    set_type("flail");
    set_hands(1);
}                     
int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}              
