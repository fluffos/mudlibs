/* Added by Galvin 95-05-07 */
#include "unarmed_combat.h"
inherit "/obj/monster";

void setup() 
  {
      set_name("black lizard");
      add_alias("lizard");
      add_alias("black lizard");
      set_main_plural("black lizards");
      set_race("lizard");
      set_level(3);
      set_gender(0);
      set_random_stats(6, 10);
      set_dex(18);
      set_al(random(10));
      set_short("Black lizard");
      set_long("An ugly little creature. It attacks you in a mad "
      "frenzy, it's blood boiling. Lucky you, it's just a child.\n");
  }

mapping valid_attack()
  {
   return([
   "punch"     :  ({ AN+" chews on "+DN+"'s neck. \n",
                     "You chew on "+DN+"'s neck. \n",
                     AN+" chews on your neck. \n" }),
   "kick"      :  ({ AN+" tries to eat "+DN+"'s hand. \n",
                     "You try to eat "+DN+"'s hand. \n",
                     AN+" tries to eat your hand. \n" }),
   "headbutt"  :  ({ AN+" bites "+DN+" on the leg. \n",
                     "You try to bite "+DN+" on the leg. \n",
                     AN+" bites you on the leg. \n" }),
   ]);
  } /* valid_attack() */
