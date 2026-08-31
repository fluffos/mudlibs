#include <std.h>
#include <amun.h>
inherit WEAPON;
int weapon_hit();
create() {
    ::create();
    set_name("Pumpkin");
    set("id", ({ "pumpkin" }) );
    set("short", "%^RESET%^%^ORANGE%^Pum%^BOLD%^%^BLACK%^p%^RESET%^%^ORANGE%^kin%^RESET%^");
    set("long", "%^RESET%^%^ORANGE%^This pumpkin is lit with fire.  The Headless horeseman will surely want it back some day." );
    set_type("projectile");
    set_weight(10);
    set_curr_value("gold", 200);
    set_wc(8);
    set_type("projectile");
    set("skill level", 115);
    set_wield("%^BOLD%^%^BLACK%^The %^RESET%^%^ORANGE%^Pum%^BOLD%^%^BLACK%^p%^RESET%^%^ORANGE%^kin %^BOLD%^%^BLACK%^cackles as you wield it.%^RESET%^");
    set_unwield("%^BOLD%^%^BLACK%^The %^RESET%^%^ORANGE%^Pum%^BOLD%^%^BLACK%^p%^RESET%^%^ORANGE%^kin %^BOLD%^%^BLACK%^stops cackling as you release it.%^RESET%^");
    set_hit((:this_object(),"weapon_hit":));
}
int weapon_hit() {
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(100) > 90) {
	write("%^BOLD%^%^BLACK%^You throw the %^RESET%^%^ORANGE%^Pum%^BOLD%^%^BLACK%^p%^RESET%^%^ORANGE%^kin %^BOLD%^%^BLACK%^into "+ atk->query_cap_name() +"'s face, setting them on %^RED%^fire%^BLACK%^!%^RESET%^");
	say((string)this_player()->query_cap_name() + " %^BOLD%^%^BLACK%^throws the %^RESET%^%^ORANGE%^Pum%^BOLD%^%^BLACK%^p%^RESET%^%^ORANGE%^kin %^BOLD%^%^BLACK%^into " + atk->query_cap_name() + "'s face setting them on %^RED%^fire%^BLACK%^!%^RESET%^");
	result=(random(50))+((this_player()->query_level())*2/3);
	if(random(100) > 74) {
	    write("%^BOLD%^%^BLACK%^You notice the %^RESET%^%^ORANGE%^Pum%^BOLD%^%^BLACK%^p%^RESET%^%^ORANGE%^kin %^BOLD%^%^BLACK%^jumps to life and lunges at "+ atk->query_cap_name() +"'s causing them to %^RED%^engulf in flames%^BLACK%^!%^RESET%^");
	    say((string)this_player()->query_cap_name() + " %^BOLD%^%^BLACK%^notices the %^RESET%^%^ORANGE%^Pum%^BOLD%^%^BLACK%^p%^RESET%^%^ORANGE%^kin %^BOLD%^%^BLACK%^jump to life and lunge at " + atk->query_cap_name() + " causing them to %^RED%^engulf in flames%^BLACK%^!%^RESET%^");
	    atk->set_paralyzed(random(2));
	    return result;
	}
    }
}
int query_auto_load() {
    if (this_player()->query_level() >= 36)
	return 1;
}
