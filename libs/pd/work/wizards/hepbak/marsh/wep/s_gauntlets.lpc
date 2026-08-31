#include <std.h>
inherit WEAPON;
int weapon_hit();
create() {
::create();
set_id(({"gauntlets","spiked gauntlets","spikes"}));
set_name("Spiked Gauntlets");
set_short("%^BOLD%^Spiked Gauntlets");
set_long("These look like ordinary spiked gauntlets. You noticed"
        " that they are %^BOLD%^RED%^blood%^RESET%^ stained. They"
        " must have been well used in their earlier days. You think"
        " that an insane person with these must have done some serious"
        " damage to someone, or something with these./n");
set("skill level", 250);
set_weight(60);
set_value(80);
set_wc(20);
set_ac(2);
set_type("melee");
set_hands(1);
set_wield("%^BOLD%^CYAN%^As you dawn them, you feel the urge to destroy!");

set_unwield("%^BOLD%^MAGENTA%^You remove the weapons of destruction!");



set_hit((:this_object(),"weapon_hit":));
}

int weapon_hit()
{
int result;
object atk;
atk = (object)this_player()->query_current_attacker();
if(random(100) > 69) {
write("You tilt your opponent back and %^RESET%^BOLD%^SMASH%^RESET%^ them in the neck!");
say("%^BOLD%^RED%^BLOOD%^RESET%^ hits your feet in a bloody gore!");
result=(random(100))+((this_player()->query_level()));
return result;


}

}

int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
