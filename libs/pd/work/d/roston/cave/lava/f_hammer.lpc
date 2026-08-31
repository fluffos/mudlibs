#include <std.h>
inherit WEAPON;

create() {
::create();
    set_id(({"hammer","lava hammer"}));
    set_name("lava Hammer");
    set_short("%^BOLD%^%^RED%^L%^RESET%^%^RED%^a%^BOLD%^%^RED%^v"
              "%^RESET%^%^RED%^a %^BOLD%^%^RED%^H%^RESET%^%^RED%^a"
              "%^BOLD%^%^RED%^m%^RESET%^%^RED%^m%^BOLD%^%^RED%^e"
              "%^RESET%^%^RED%^r");
    set_long( "%^RED%^ This Hammer is one of a kind, that could only "
              "be found in the firey deeps..");
    set_mass(18);
    set_curr_value("gold", 58);
    set_wc(10);

    set_type("blunt");
    set_hands(1);
}                    
int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}        
