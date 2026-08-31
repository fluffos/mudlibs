#include <std.h>
inherit WEAPON;
create() {
    ::create();
    set_id(({"knife"}));
    set_name(" knife ");
    set_short(" knife ");
    set_long( "knife "
    );
    set_mass(80+random(10));
    set_curr_value("gold",240+random(40));
    set_wc(90);
    set_ac(1);
    set_type("knife");
    set_wield("You wield a knife.");
    set_unwield("The knife pim-slap you and runs like hell.");
    set_hit((:this_object(), "weapon_hit":));
}
int weapon_hit()
{
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(100) > 10) {
        write("Pimps your mom.");
        say(""+(string)this_player()->query_cap_name()+" pimps "+atk->query_cap_name()+".");
       
result= (random(100)+10);
this_player()->add_hp(result);
;
        return result;
    }
}
 int query_auto_load() { if (this_player()->query_level() > 45) return 1; }
