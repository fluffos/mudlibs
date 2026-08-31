#include <std.h>
inherit WEAPON;
int weapon_hit();
create() {
::create();
set_id(({"staff", "tolarian staff","staff"}));
set_name("Tolarian Staff");
set_short("%^BOLD%^%^BLUE%^Tol%^RESET%^%^BLUE%^ari%^BOLD%^%^WHITE%^an S%^RESET%^%^BLUE%^ta%^BOLD%^%^BLUE%^ff%^RESET%^");
set_long("This Staff seems to have a strange symbol on the side of "
"it. It seems as if its made of water.");
set("skill level", 20);
set_weight(14);
     set_curr_value("gold",150+random(40));
set_wc(10);
set_ac(2);
set_type("blunt");
set_hands(1);
set_wield("%^BOLD%^%^RED%^Water rushs into your vain's.");
set_unwield("%^BOLD%^%^BLUE%^The water vanishs.");



set_hit((:this_object(),"weapon_hit":));
}

int weapon_hit()
{
int result;
object atk;
atk = (object)this_player()->query_current_attacker();
if(random(100) > 69) {
write("%^BOLD%^%^BLUE%^You twirl around and smack your Foe across the head with your staff!");
say("%^BOLD%^%^BLUE%^Tol%^RESET%^%^BLUE%^ari%^BOLD%^%^WHITE%^an S%^RESET%^%^BLUE%^ta%^BOLD%^%^BLUE%^ff smacks its Foe across the face!"); 
result=(random(55))+((this_player()->query_level()));
return result;


}
}

int query_auto_load()
{                                  
 if (wizardp(this_player())) return 1;
 return 1;
}
