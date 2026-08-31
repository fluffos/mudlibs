#include <std.h>

inherit WEAPON;

void create() {
  ::create();
    set_name("The Golden Trident");
    set_short("The %^BOLD%^%^YELLOW%^Golden %^WHITE%^Tr%^YELLOW%^id%^WHITE%^ent");
    set_long("%^BOLD%^%^YELLOW%^This trident belongs to the ruler of NuShae. It seems to glow in your presense.");
    set_id(({"trident"}));
    set_mass(20);
    set_curr_value("gold", 100+random(50));
    set_type("projectile");
    set_wc(10);
    set_hands(2);
    set_wield("%^BOLD%^YELLOW%^The %^BLUE%^Oceans %^YELLOW%^sing your praise as you wield the weapon.");
    set_unwield("%^BOLD%^%^YELLOW%^The yellow glow fades away, the singing disappears...");
    set_ac(1);
    set_hit((: this_object(), "weapon_hit" :));
}

int weapon_hit() {
    int result, chance;
    object obname, tpname;
    obname = this_player()->query_current_attacker()->query_cap_name();
    tpname = this_player()->query_cap_name();
    if(random(10) == 0) {
      message("info", "%^BOLD%^%^YELLOW%^"+tpname+" spears "+obname+" deeply.%^RESET%^",
environment(this_player()), ({ this_player(),
this_player()->query_current_attacker() }) );
      message("info", "%^BOLD%^%^YELLOW%^"+tpname+" deeply spears you.%^RESET%^",
this_player()->query_current_attacker());
      message("info", "%^BOLD%^%^YELLOW%^You spear "+obname+" deeply.", this_player() );
    result=(100 - random(50));
    }
}

int query_auto_load(){
    if (this_player()->query_level() > 25) return 1;
    return 1;
}
