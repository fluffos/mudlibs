#include <std.h>
inherit WEAPON;

create() {
::create();
    set_id(({"dirk","lava dirk"}));
    set_name("lava Dirk");
    set_short("%^BOLD%^%^RED%^L%^RESET%^%^RED%^a%^BOLD%^%^RED%^v"
              "%^RESET%^%^RED%^a %^BOLD%^%^RED%^D%^RESET%^%^RED%^i"
              "%^BOLD%^%^RED%^r%^RESET%^%^RED%^k");
    set_long( "%^RED%^ This Dirk is one of a kind, that could only "
              "be found in the firey deeps..");
    set_mass(12);
    set_curr_value("gold", 58);
    set_wc(10);

    set_type("knife");
    set_hands(1);
}              
int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}                       
