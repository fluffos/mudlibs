#include <std.h>
inherit WEAPON;
int weapon_hit();
create() {
::create();
set_id(({"blade", "azeria blade","sword"}));
set_name("Azeria Blade");
set_short("%^BOLD%^%^BLUE%^Az%^RESET%^%^BLUE%^er%^BOLD%^%^BLUE%^ia Bl%^RESET%^%^BLUE%^a%^BOLD%^%^BLUE%^de");
set_long("This Blade is sharpend to a razor point, it is used to protect the city of Azeria.");
set("skill level", 55);
set_weight(19);
    set_curr_value("gold",150+random(40));
set_wc(8);
set_ac(2);
set_type("blade");
set_hands(1);



set_hit((:this_object(),"weapon_hit":));
}

int weapon_hit()
{
int result;
object atk;
atk = (object)this_player()->query_current_attacker();
if(random(100) > 69) {
write("%^BOLD%^%^WHITE%^Your Blade slices into your foe!");
say("%^BOLD%^%^BLUE%^Blade slices into its foe!");
result=(random(30))+((this_player()->query_level()));
return result;


}
}

int query_auto_load()
{                                  
 if (wizardp(this_player())) return 1;
 return 1;
}
