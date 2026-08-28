//  Khojem
//  Monster:  Hagar the Horrible
//  File:     hagar.c

#include <std.h>

inherit MONSTER;

create() {
  object ob;
  int   idx; 
  mixed ench_str; 
  ::create();
    set_name("hagar");
    set_id( ({ "hagar","hagar the horrible", "bruiser" }) );
    set_level(10);
    set_short("hagar the horrible");
    set_long("Hagar has a bad habit of picking his nose and has "+
      "long, bushy armpit air." 
      );
    set("race", "high-man");
    set_gender("male");
    set_body_type("human");
    
    
    ob = new("/d/damned/virtual/spear_6.weapon");
    ob -> set("short", "Khojem's Great Newbie-Wizard Skewer");
    ob -> set("long", "This is used to impale wizards who gen "+
            "big weapons in their areas."); 


       // set enchantment - *glow* in short description
    ob -> set_property("enchantment",4);

      // maximum spell stacking for flame blade is 4 
      // see /std/spells/flame_blade.c  
    ob -> set_property("flame blade", 4);


     // allows enchanter w/ detect magic skill to determine
     // magic and power of magic on LOOK AT SKEWER
    ench_str = ({ ({ "This weapon has %^ORANGE%^Flame Blade%^RESET%^.",
     "detect magic" }) });
    ob -> set_property("extra long",ench_str);

    ob -> set_verb("spear");
    ob -> set_parry_bonus(-10);
    ob -> set_weight(95);
    ob -> set_value(120);
    
    ob -> move(this_object());
    
  command("wield spear in right hand");
}
