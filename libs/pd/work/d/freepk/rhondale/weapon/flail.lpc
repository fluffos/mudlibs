// Aziraphale

#include <std.h>
inherit WEAPON;
 
void create() {
::create();
    set_id(({"flail"}));
    set_name("flail");
    set_short("flail");
    set_long("A flail, used to crack people on the head with. Unfortunately one of the heads is missing, making it unbalanced.");
    set_mass(10);
    set_curr_value("gold", 50);
    set_wc(8);
    set_type("");
    set_hands(1);
    set_wield( (: call_other, this_object(), "wield_weapon" :)  );
    set_unwield("Dropping the flail your hands feel better.");
}

int query_auto_load() {
    if (this_player()->query_level() > 15) return 1; 
}

int wield_weapon() {
    object tp;
    tp = this_player();
    if (tp->query_skill("flail") < 50) {
       write("You cannot wield this weapon.");
       return 0;
       }
    return 1;
}
