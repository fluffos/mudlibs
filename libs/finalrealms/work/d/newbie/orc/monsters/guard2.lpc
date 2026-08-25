// A large orc guard

inherit "/obj/monster";
#include "path.h"

void setup() {
set_name("Orc Guard");
add_alias("orc");
add_alias("guard");
set_short("orc guard");
set_main_plural("orc guards");
add_plural("guards");
      set_long("A scarred up muscle bound orc who guards this gate.\n");
      set_race("orc");
set_level(5 + random(6));
      set_wimpy(0);
      set_random_stats(9, 18);
      set_al(-100+random(201));
adjust_money(2+random(8), "silver");
      load_chat(90,
         ({
               1, "@spit $hcname$",
               1, "@grunt",
               1, "'Are you trying to provoke me ?",
      1,"'You can't leave!! Unless you have permission from the chief.",
               1, "'Go away, wimp!"
          }));
      load_a_chat(80,
         ({
               1, "'YOU'RE GONNA DIE FOR THIS.",
               1, "'Let's see who's boss here $acname$",
               1, "'Ughh!",
               1, "'Don't you dare leave in the middle of my fight!"
          }));
      if(random(2))
new(ARMOR+"chainmail")->move(this_object());
      else
new(ARMOR+"ringmail")->move(this_object());
new(WEAPON+"bastard_sword")->move(this_object());
      this_object()->init_equip();

} /* void setup() */
