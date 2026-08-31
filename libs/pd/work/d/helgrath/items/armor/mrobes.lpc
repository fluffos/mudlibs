#include <std.h>
inherit ARMOUR;

void create() {
    :: create();

    set_name("robes");
    set_short("%^BOLD%^%^BLUE%^M%^WHITE%^a%^BLUE%^ge R%^WHITE%^o%^BLUE%^bes%^RESET%^");
    set_long("These robes are filled with magic, and are probably much better than they look.");
    set_id(({"robes", "mage robes"}));
    set_ac(2);
    set_mass(30);
    set_curr_value("gold",40+random(40));
    set_type("robes");
    set_limbs(({"torso", "left arm", "right arm"}));
    set_heart_beat(1);
}

int query_auto_load() { 
    if(this_player()->query_level() < 30) return 0;
    return 1;
}

void heart_beat() {
    object tp;
    tp = this_object()->query_worn();
    if(!tp) return;
    if(random(100) > 90 && tp->query_current_attacker()) {
	if(environment(tp)->query_property("no attack")) return;
	message("info", "%^YELLOW%^A yellow pulse from "+tp->query_cap_name()+"'s robes absorb the power of the blow and turn it into healing energies!", environment(tp), tp);
	message("info", "%^YELLOW%^A yellow pulse from your robes absorb the power of the blow and turn it into healing energies!", tp);
        tp->heal(random(tp->query_level())+10);
    }
}
