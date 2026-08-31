// Aziraphale

#include <std.h>
inherit WEAPON;
 
void create() {
::create();
    set_id(({"rusted blade", "blade", "rustblade"}));
    set_name("%^RESET%^RED%^rusty%^RESET%^ blade");
    set_short("a %^RESET%^RED%^rusted%^RESET%^ blade");
    set_long("This sword is very old and has not been looked after. The blade is notched and very rusty.");
    set_mass(10);
    set_curr_value("gold", 50);
    set_wc(8);
    set_type("blade");
    set_hands(1);
    set_wield( (: call_other, this_object(), "wield_weapon" :)  );
    set_unwield("You feel glad to be rid of the weapon.");
}

int query_auto_load() {
    if (this_player()->query_level() > 10) return 1; 
}

int wield_weapon() {
    object tp;
    tp = this_player();
    if (tp->query_skill("blade") < 50) {
       write("You cannot wield this weapon.");
       return 0;
       }
    return 1;
}
