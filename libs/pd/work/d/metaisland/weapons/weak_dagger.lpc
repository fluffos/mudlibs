#include <std.h>
#include <metallicana.h>
inherit WEAPON;

void create() {
    ::create();
    set_name("weak dagger");
    set_short("Weak Dagger");
    set_long("The blade is thin and rather weak, it wouldnt do anyone much harm.");
    set_id(({"dagger", "weak dagger"}));
    set_mass(21);
    set_curr_value("gold", 107);
    set_type("knife");
    set_wc(7);
    set_ac(0);
}
int query_auto_load(){ 
    if (this_player()->query_level() > 44) return 1;
}
