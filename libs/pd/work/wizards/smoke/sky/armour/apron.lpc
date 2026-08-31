#include <std.h>                                                               
#include <cp.h>
inherit ARMOUR;                                                                

void create() 
{ 

    ::create();  
        set_name("leather blacksmith apron");
        set_id( ({ "apron", "leather apron", "blacksmith apron", "leather blacksmith apron" }) );
        set_short("%^RESET%^%^ORANGE%^leather blacksmith apron%^RESET%^");
        set_long("This apron is used while forging weapons "
        "and other steel items. It is heavy and warm, but "
        "is rather thick and durable.");
        set_ac(3);
        set("value", 95);
        set_limbs( ({ "right leg", "left leg", "torso" }) );
        set_weight(24);
        set_type("vest");
}
int query_auto_load() {
      object tp=this_player();
      int tp_lvl=(this_player()->query_level());
      if(tp_lvl >=40) {return 1;}
      else {return 0;}
}
