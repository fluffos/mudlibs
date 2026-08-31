// Aziraphale

#include <std.h>
inherit WEAPON;
 
void create() {
::create();
    set_id(({"cracked", "hammer", "cracked hammer", "warhammher", "crackhammer"}));
    set_name("cracked warhammer");
    set_short("cracked warhammer");
    set_long("This warhammer is old and has a massive crack in the head, making it almost useless as a weapon.");
    set_mass(15);
    set_curr_value("gold", 55);
    set_wc(8);
    set_type("blunt");
    set_hands(1);
    set_wield( (: call_other, this_object(), "wield_weapon" :)  );
    set_unwield("You let go of the weapon, thankful to be rid of it.");
}

int query_auto_load() {
    if (this_player()->query_level() > 15) return 1; 
}

int wield_weapon() {
    object tp;
    tp = this_player();
    if (tp->query_skill("blunt") < 50) {
       write("You cannot wield this weapon.");
       return 0;
       }
    return 1;
}
