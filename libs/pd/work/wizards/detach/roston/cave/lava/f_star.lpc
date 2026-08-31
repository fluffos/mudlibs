#include <std.h>
inherit WEAPON;

create() {
::create();
    set_id(({"morning star","morningstar","lava morning star"}));
    set_name("lava Morning Star");
    set_short("%^BOLD%^%^RED%^L%^RESET%^%^RED%^a%^BOLD%^%^RED%^v"
              "%^RESET%^%^RED%^a %^BOLD%^%^RED%^M%^RESET%^%^RED%^o"
              "%^BOLD%^%^RED%^r%^RESET%^%^RED%^n%^BOLD%^%^RED%^i"
              "%^RESET%^%^RED%^n%^BOLD%^%^RED%^g %^RESET%^%^RED%^S"
              "%^BOLD%^%^RED%^t%^RESET%^%^RED%^a%^BOLD%^%^RED%^r");
    set_long( "%^RED%^ This Morning Star is one of a kind, that could only "
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
