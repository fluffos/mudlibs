# include <std.h>
inherit ARMOUR;

void create() {
::create();
  
    set_name("shoulder plating");
    
set_short("%^BOLD%^%^BLACK%^Bla%^RESET%^%^BOLD%^ck Sh%^RESET%^oulder %^BOLD%^Plat%^BLACK%^ing%^RESET%^");
    set_long("Three layers of plates fit over a suit of platemail for additional protection.");
    set_id(({"plating", "shoulder plating"}));
    set_ac(5);            
    set_mass(20);
    set_type("shoulder plating");   
set_limbs(({"right arm", "left arm", "torso" }));
set_properties(([
     "no steal" : 1,
      ]));
}
int query_auto_load() { if (this_player()->query_level() >=100) return 1; }

