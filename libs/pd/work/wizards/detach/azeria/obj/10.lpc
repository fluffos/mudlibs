#include <std.h>
inherit WEAPON;
int weapon_hit();
create() {
    ::create();
    set_id(({"pike", "thran pike", "pike"}));
    set_name("Thran Pike");
    set_short("%^ORANGE%^Th%^RED%^ra%^RESET%^n P%^RED%^i%^ORANGE%^ke%^RESET%^");
    set_long("This Pike looks as if it was formed from a golden metal "
      "that shines very bright.");
    set("skill level", 75);
    set_weight(14);
    set_curr_value("gold",150+random(40));
    set_wc(10);
    set_ac(2);
    set_type("projectile");
    set_hands(1);
    set_wield("%^BOLD%^%^RED%^The pike reflects light into your eyes.");
    set_unwield("%^BOLD%^%^BLUE%^The light goes out.");



    set_hit((:this_object(),"weapon_hit":));
}

int weapon_hit()
{
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(100) > 69) {
	write("%^BOLD%^%^WHITE%^Your Pike impales into your Foe's chest!");
	say("%^ORANGE%^Th%^RED%^ra%^RESET%^n P%^RED%^i%^ORANGE%^ke Impales into its Foe's chest!"); 
	result=(random(60))+((this_player()->query_level()));
	return result;


    }
}

int query_auto_load()
{                                  
    if (wizardp(this_player())) return 1;
    return 1;
}
