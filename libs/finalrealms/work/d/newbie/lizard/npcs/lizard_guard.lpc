// A large bugbear guard

inherit "/obj/monster";
#include "path.h"

void setup() {
set_name("Bugbear");
add_alias("bugbear");
set_short("bugbear");
set_main_plural("bugbears");
add_plural("bugbears");
      set_long("A scarred up muscle bound bugbear who guards this gate.\n");
      set_race("bugbear");
set_level(5 + random(6));
      set_wimpy(0);
      set_random_stats(9, 18);
      set_al(-100+random(201));
this_object()->init_command("protect bugbear");
adjust_money(2+random(8), "gold");
      load_chat(90,
         ({
               1, "@spit $hcname$",
               1, "@grunt",
               1, "'Are you trying to provoke me ?",
         1, "'None shall pass!! Unless you have a key.",
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

} /* setup() */
