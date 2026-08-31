#include <std.h>
inherit WEAPON;
int weapon_hit();
create() {
::create();
set_id(({"staff", "fire staff","staff"}));
set_name("Fire Staff");
set_short("%^BOLD%^%^RED%^F%^RESET%^ir%^BOLD%^%^RED%^e St%^RESET%^a%^BOLD%^%^RED%^ff");
set_long("%^RESET%^%^RED%^Flames burst for the staff, surrounding it with fire.");
set("skill level", 75);
set_weight(20);
    set_curr_value("gold",150+random(40));
set_wc(11);
set_ac(2);
set_type("blunt");
set_hands(1);
set_wield("%^RED%^Flames surround your hand.");
set_unwield("%^RED%^The Flames vanish.");



set_hit((:this_object(),"weapon_hit":));
}

int weapon_hit()
{
int result;
object atk;
atk = (object)this_player()->query_current_attacker();
if(random(100) > 69) {
write("%^BOLD%^%^RED%^Your Staff burns a hole in your oppponents chest!");
say("%^BOLD%^%^RED%^F%^RESET%^ir%^BOLD%^%^RED%^e St%^RESET%^a%^BOLD%^%^RED%^ff burns its opponent!");
result=(random(62))+((this_player()->query_level()));
return result;


}
}

int query_auto_load()
{                                  
 if (wizardp(this_player())) return 1;
 return 1;
}
