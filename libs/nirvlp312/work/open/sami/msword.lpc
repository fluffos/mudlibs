inherit "obj/weapon";
#include "/obj/ansi.h"


int i;
reset(arg) {
   ::reset(arg);
   if(arg) return;
      set_alias("sword");
	  set_type("sword");
        set_short(""+BOLD+"Master Sword"+NORM+"");
        set_long("This is the Legendary "+BOLD+"Master Sword"+NORM+" wielded by\n"+
		"The famous Hero of Hyrule, Link. This blade hums with "+HIY+"HOLY"+NORM+"power.\n");
        set_params("other|good",20,0);
	    set_class(17);
        set_weight(3);
        set_value(7200);
        set_name(""+BOLD+"Master Sword"+NORM+"");
		set_min_xlevel(5);
    set_min_xlevel_message("Foolish Moral. Try again when you are more Experienced.\n");
        message_hit = 
    ({
        BOLD+" EVISCERATED "+NORM," Blood gushes everywhere",
        HIR+" HACKED "+NORM," extremely hard",
        HIY+" CHOPPED "+NORM," viciously",
        HIC+" minced "+NORM,", with precision",
        HIG+" sliced "+NORM," drawing a little blood",
        HIB+" struck "+NORM," lightly",
        HIW+" grazed "+NORM," very lightly"
    });

      set_hit_func(this_object());
}
weapon_hit(attacker) {
  i=random(20);
  if (i>12) {

        say(this_player()->query_name()+"'s "+BOLD+"Master Sword"+HIY+" glows"+NORM+" with a "+HIR+"raging"+NORM+" fury!\n");
        write(""+BOLD+"Master Sword"+NORM+" summons "+BOLD+"HOLY SPIRITS"+NORM+" upon its FOE!\n");
  return 6;
    }
   return 0;
}
