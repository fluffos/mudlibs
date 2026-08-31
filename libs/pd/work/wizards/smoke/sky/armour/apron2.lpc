#include <std.h>                                                               
#include <cp.h>
inherit ARMOUR;                                                                

void create() 
{ 

    ::create();  
        set_name("cloth apron");
        set_id( ({ "apron", "cloth apron" }) );
        set_short("%^BOLD%^%^BLUE%^c%^WHITE%^l%^BLUE%^o%^WHITE%^t%^BLUE%^h %^BLUE%^a%^WHITE%^p%^BLUE%^r%^WHITE%^o%^BLUE%^n%^RESET%^");
        set_long("This apron is used by a tailor from "
        "Steel Hammer Armory. It isn't much for armor, "
        "but it isn't going to fall apart.");
        set_ac(1);
        set("value", 60);
        set_limbs( ({ "right leg", "left leg", "torso" }) );
        set_weight(14);
        set_type("vest");
}
int query_auto_load() {
      object tp=this_player();
      int tp_lvl=(this_player()->query_level());
      if(tp_lvl >=40) {return 1;}
      else {return 0;}
}
