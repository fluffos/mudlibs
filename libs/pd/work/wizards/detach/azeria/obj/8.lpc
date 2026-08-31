#include <std.h>
inherit WEAPON;
int weapon_hit();
create() {
::create();
set_id(({"dagger", "balduvian dagger","dagger"}));
set_name("Bladuvian Dagger");
set_short("%^BOLD%^%^BLACK%^Baldu%^RED%^vian Dag%^BLACK%^ger%^RESET%^");
set_long("This Dagger is one of few daggers left from the one "
"great horde. The person that carriers this daggers holds the "
"powers of a true balduvian in there hands.");
set("skill level", 75);
set_weight(13);
     set_curr_value("gold",150+random(40));
set_wc(10);
set_ac(1);
set_type("knife");
set_hands(1);
set_wield("%^BOLD%^%^RED%^The Powers of the Balduvian's enter you.");
set_unwield("%^BOLD%^%^BLUE%^The powers vanishs.");



set_hit((:this_object(),"weapon_hit":));
}

int weapon_hit()
{
int result;
object atk;
atk = (object)this_player()->query_current_attacker();
if(random(100) > 77) {
write("%^BOLD%^%^RED%^Your knife sinks into your Foe's Throat!");
say("%^BOLD%^%^BLACK%^Baldu%^RED%^vian Dag%^BLACK%^ger %^RED%^sinks into its Foe's Throat!"); 
result=(random(50))+((this_player()->query_level()));
return result;


}
}

int query_auto_load()
{                                  
 if (wizardp(this_player())) return 1;
 return 1;
}
