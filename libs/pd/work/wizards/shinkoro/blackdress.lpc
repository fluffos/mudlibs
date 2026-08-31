#include <std.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("black silk dress");
    
    set_short("%^BOLD%^%^BLACK%^Black silk%^RESET%^ and %^BOLD%^%^WHITE%^lace %^RESET%^dress");
set_long("This is Rika's %^BOLD%^%^BLACK%^black silk%^RESET%^and %^BOLD%^%^WHITE%^lace%^RESET%^ dress.");
    set_id(({"dress"}));
set_ac(0);
    set_mass(10);
    set_type("dress");
    set_curr_value("gold", 1);  
    set_limbs(({ "torso", "right arm", "left arm", "right leg", "left leg"
}));
}
int query_auto_load()
{
if(this_player()->query_name() == "karyn")
return 1;
}
