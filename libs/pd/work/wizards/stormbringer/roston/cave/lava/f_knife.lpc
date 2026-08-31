#include <std.h>
inherit WEAPON;

create() {
::create();
    set_id(({"knife","lava knife"}));
    set_name("Lava Knife");
    set_short("%^BOLD%^%^RED%^L%^RESET%^%^RED%^a%^BOLD%^%^RED%^v"
              "%^RESET%^%^RED%^a %^BOLD%^%^RED%^K%^RESET%^%^RED%^n"
              "%^BOLD%^%^RED%^i%^RESET%^%^RED%^f%^BOLD%^%^RED%^e");
    set_long( "%^RED%^ This knife is one of a kind, that could only "
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
