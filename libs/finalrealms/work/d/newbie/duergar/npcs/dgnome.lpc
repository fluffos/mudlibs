/*  File upgrade by Grimbrand 2-11-96                                   */

#include "path.h"
inherit "obj/monster";
 
void init() { ::init(); }

void setup() {
   set_name("gnome");
   add_alias("captive");
   add_alias("Captive");
   set_short("Gnome Captive");
   set_long("   This is a furry little gnome.  She was taken captive "
            "in the last raid on the surface cities by the duergar.   "
            "She looks at you with intense hatred."
            "\n\n");
   set_main_plural("Captives");
   set_gender(2);
   set_race("gnome");
   set_guild("fighter");
   set_random_stats(10,15);
   set_aggressive(0);
   set_level(10);
   set_max_hp(44);
   set_wimpy(0);
   set_al(0);
   set_kill_xp(631);
   adjust_money(1,"gold");
 
  add_language("gnome");
  do_command("speak gnome");
  load_chat(30,({
     1, ":penetrates your soul with her hatred.",
     1, "' The duergar will need to do much more than this to break my spirit.",
  }));
 
  load_a_chat(25, ({
     1, "'Aaah, so you've come to fight the weak and oppressed.  So noble.",
     1,"'I have not endured this prison to be killed by you.",
 
  }));
}
