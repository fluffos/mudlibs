#include <std.h>
inherit WEAPON;

create() {
::create();
    set_id(({"sword","lava sword"}));
    set_name("lava sword");
    set_short("%^BOLD%^%^RED%^L%^RESET%^%^RED%^a%^BOLD%^%^RED%^v"
              "%^RESET%^%^RED%^a %^BOLD%^%^RED%^S%^RESET%^%^RED%^w"
              "%^BOLD%^%^RED%^o%^RESET%^%^RED%^r%^BOLD%^%^RED%^d");
    set_long( "%^RED%^ This sword is one of a kind, that could only "
              "be found in the firey deeps..");
    set_mass(13);
    set_curr_value("gold", 58);
    set_wc(10);

    set_type("blade");
    set_hands(1);
}                      

int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}                  
