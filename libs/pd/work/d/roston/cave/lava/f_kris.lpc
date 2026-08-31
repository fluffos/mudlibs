#include <std.h>
inherit WEAPON;

create() {
::create();
    set_id(({"kris","lava kris"}));
    set_name("lava Kris");
    set_short("%^BOLD%^%^RED%^L%^RESET%^%^RED%^a%^BOLD%^%^RED%^v"
              "%^RESET%^%^RED%^a %^BOLD%^%^RED%^K%^RESET%^%^RED%^r"
              "%^BOLD%^%^RED%^i%^RESET%^%^RED%^s");
    set_long( "%^RED%^ This kris is one of a kind, that could only "
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
