#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("helmet");
    set_short("A small %^ORANGE%^greasy%^RESET%^ hat");
   set_long("This is a commonly worn hat around the mines. "
     " it doesnt offer much protection but hell, its better than nothing.");
   set_id( ({ "hat" , "small hat" }) );
    set_ac(2);
    set_mass(16);
    set_value(27);
    set_type("helmet");
    set_limbs( ({ "head" }) );
}
int query_auto_load()
{
if (wizardp(this_player())) {return 1;}
else { return 0; }
}
