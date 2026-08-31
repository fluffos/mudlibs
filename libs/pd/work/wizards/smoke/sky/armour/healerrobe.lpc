#include <std.h>                                                               
#include <cp.h>
inherit ARMOUR;                                                                

void create() 
{ 

    ::create();  
        set_name("healer robe");
        set_id( ({ "robe", "healer robe" }) );
        set_short("%^BOLD%^%^YELLOW%^he%^WHITE%^al%^CYAN%^er%^YELLOW%^ r%^WHITE%^ob%^CYAN%^e%^RESET%^");
        set_long("This colorful robe doesn't look like it's "
        "anything special. The only unique thing about it is "
        "the yellow aura that radiates from it.");
        set_ac(4);
        set("value", 220);
        set_limbs( ({ "right arm", "left arm", "torso" }) );
        set_weight(28);
        set_type("cloak");
}
int query_auto_load() {
      object tp=this_player();
      int tp_lvl=(this_player()->query_level());
      if(tp_lvl >=40) {return 1;}
      else {return 0;}
}
