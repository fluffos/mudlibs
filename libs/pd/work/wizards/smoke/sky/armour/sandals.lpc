#include <std.h>                                                               
#include <cp.h>
inherit ARMOUR;                                                                

void create() 
{ 
    ::create();  
        set_name("leather sandals");
        set_id( ({ "sandals", "leather sandals" }) );
        set_short("%^RESET%^%^ORANGE%^leather sandals%^RESET%^");
        set_long("These sandals are extremely comfortable but "
	   "provide very little armor. A thick leather sole "
	   "protects the bottom of your feet well, but that's "
	   "about it.");
        set_ac(1);
        set("value", 85);
        set_limbs( ({ "right foot", "left foot"}) );
        set_weight(8);
        set_type("boots");
	set_wear("You slip on your leather sandals.");
        }
int query_auto_load() {
      object tp=this_player();
      int tp_lvl=(this_player()->query_level());

      if(tp_lvl >=10) {return 1;}
      else {return 0;}
}
