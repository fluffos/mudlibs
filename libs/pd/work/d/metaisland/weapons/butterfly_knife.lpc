#include <std.h>
#include <metallicana.h>
int weapon_hit(object atk);
inherit WEAPON;

void create() {
    ::create();
    set_name("Butterfly Knife");
   
set_short("%^BOLD%^%^GREEN%^Bu%^BOLD%^%^WHITE%^tte%^GREEN%^rfl%^BOLD%^WHITE%^y kn%^GREEN%^i%^WHITE%^fe%^RESET%^");
    set_long("The hilt is made from dead butterflies, you wont think it to be very strong but it is quite sturdy. The blade is made from a collection of bee stingers.");
    set_id(({"dagger", "butterfly knife", "knife"}));
    set_mass(32);
    set_curr_value("gold", 200);
    set_type("knife");
    set_hit ( (: weapon_hit :) );
    set_wield("%^BOLD%^GREEN%^The knife is light in your hand, and tingling sensation flows through you.%^RESET%^\n");
    set_unwield("%^BOLD%^GREEN%^Releasing the knife you lose the sensation and feel at a loss.%^RESET%^\n");
    set_wc(9);
    set_ac(0);
}

int weapon_hit(object atk)
{
    int result;
    if(random(90) > 72) {
        write("%^BOLD%^WHITE%^The knife slicies through your enemys veins poisioning their blood.%^RESET%^\n");
        say("%^BOLD%^WHITE%^"+this_player()->query_cap_name()+"'s knife slicies through your veins poisioning your blood.%^RESET%^\n");
        result=(random(50))+((this_player()->query_level()));
        result = random(result) + 9;
    }
}
int query_auto_load() {
if (this_player()->query_level() > 30) return 1;
}
