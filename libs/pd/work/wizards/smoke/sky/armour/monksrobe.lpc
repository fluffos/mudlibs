#include <std.h>                                                               
#include <cp.h>
inherit ARMOUR;                                                                

void create() 
{ 
    ::create();  
        set_name("monks robe");
        set_id( ({ "robe", "monks robe" }) );
        set_short("%^BOLD%^%^CYAN%^mo%^RESET%^%^CYAN%^nk%^BOLD%^s r%^RESET%^%^CYAN%^ob%^BOLD%^e");
        set_long("%^BOLD%^%^CYAN%^Made from a thin cloth, this cloak was "
        "blessed by a dwarven priest. There is a symbol "
	"of a golden dragon on the back.%^RESET%^ ");
        set_ac(5);
        set("value", 170);
        set_limbs( ({ "head", "right arm", "left arm", "torso" }) );
        set_weight(24);
        set_type("cloak");
	set_wear("%^CYAN%^You pull the hood over your head and wrap the "
		 "robe around your body.%^RESET%^");
	set_remove("%^CYAN%^You remove the hood and fold the "
	 "robe up.%^RESET%^");
        }
int query_auto_load() {
      object tp=this_player();
      int tp_lvl=(this_player()->query_level());

      if(tp_lvl >=40) {return 1;}
      else {return 0;}
}
