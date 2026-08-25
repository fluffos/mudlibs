/*  File upgrade by Grimbrand 2-11-96                                   */

#include "path.h"
inherit "obj/monster";
 
void init() { ::init(); }

void setup() {
   set_name("captive");
   add_alias("halfling");
   add_alias("Captive");
   set_short("Halfling Captive");
   set_long("   This is a cute little halfling female.  She has been "
            "brought here to die for the Duergar.  Her contempt "
            "for you makes her seethe with anger."
            "\n\n");
   set_main_plural("Captives");
   set_gender(2);
   set_race("halfling");
   set_guild("fighter");
   set_random_stats(10,15);
   set_aggressive(0);
   set_level(10);
   set_max_hp(44);
   set_wimpy(0);
   set_al(0);
   set_kill_xp(631);
   adjust_money(random(30), "copper");
 
  load_chat(30,({
     1, "' I'm just an innocent little creature.  Please let me go.",
     1, "' The duergar will need to do much more than this to break my spirit.",
 
  }));
 
  load_a_chat(25, ({
     1, ":gracefully dodges your clumsy attacks.",
     1, "'Aaah, so you've come to fight the weak and oppressed.  So noble.",
     1, ":spits at your feet.",
     1,"'I have not endured this prison to be killed by you.",
 
  }));
}
