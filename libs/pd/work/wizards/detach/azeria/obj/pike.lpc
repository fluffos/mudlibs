#include <std.h>
inherit WEAPON;
int weapon_hit();
create() {
::create();
set_id(({"pike", "demon pike","pike"}));
set_name("Demon Pike");
set_short("%^BOLD%^%^BLACK%^De%^BOLD%^%^RED%^m%^BLACK%^on P%^RED%^i%^BLACK%^ke");
set_long("%^BOLD%^%^BLACK%^A long Black pike, covered with millions of tiny horns, at the tip is a giant Demon Horn.");
set("skill level", 75);
set_weight(25);
    set_curr_value("gold",150+random(40));
set_wc(13);
set_ac(2);
set_type("projectile");
set_hands(1);
set_wield("%^BOLD%^%^BLACK%^Blood Trickles from your hands.");
set_unwield("%^BOLD%^%^WHITE%^The Blood vanishs.");



set_hit((:this_object(),"weapon_hit":));
}

int weapon_hit()
{
int result;
object atk;
atk = (object)this_player()->query_current_attacker();
if(random(100) > 69) {
write("%^BOLD%^%^BLACK%^Your Pike impales into your opponent, you twist leaving a deep wound!");
say("%^BOLD%^%^BLACK%^De%^BOLD%^%^RED%^m%^BLACK%^on P%^RED%^i%^BLACK%^ke impales into its opponent, leaving a deep wound!");
result=(random(59))+((this_player()->query_level()));
return result;


}
}

int query_auto_load()
{                                  
 if (wizardp(this_player())) return 1;
 return 1;
}
