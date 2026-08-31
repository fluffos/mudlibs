#include <std.h>
#include <purgatory.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("%^BLACK%^Wraiths Armour");
    
    set_short("%^BLACK%^Wraiths Armour");
    set_long("%^BLACK%^Wraiths Armour");
    set_id(({"armour"}));
    set_ac(1);        
    set_mass(2000);
    set_type("Wraith Armour");
    set_curr_value("gold", 0); 
    set_wear("Oh my what did you do?"); 
    set_remove("Uh oh, now youve done it, you messed evrything up");
    set_limbs(({ "torso", "right arm", "left arm", "right leg", "left leg", "right hand", "left hand", "right foot", "left foot", "head"
}));
}


int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_name() == "wraith") return 0;
   write("No, no, no.. you've got it all wrong. You may not wear Wraiths Armour.");
   say(this_player()->query_cap_name()+" is an idiot for wearing something "
      "that they do not own.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wear");
}

 int query_auto_load() { if (this_player()->query_level() > 35) return 1; }
