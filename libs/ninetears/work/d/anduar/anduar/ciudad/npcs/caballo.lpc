#include "unarmed_combat.h"

inherit "/obj/monster";

void setup()
{
   set_name("caballo");
   set_short("caballo");
   set_wimpy(0);
   add_alias("equido");
   set_main_plural("caballos");
   add_plural("caballos");
   add_plural("equidos");
   set_gender(0);
   set_long("Es un hermoso corcel que parece pertenecer a algun noble de la "
   "ciudad, su amo no estara muy lejos.\n");
   set_al(random(11)-random(11));
   set_random_stats(7, 17);
   set_cha(15);
   set_level(5+random(2));
   add_move_zone("anduar");
} /* setup() */

valid_attack()
{
   return
   ([
      "punch"    : ({ AN+" muerde a "+DN+" en el pie.\n",
                      "Muerdes a "+DN+" en el pie.\n",
                      AN+" te muerde en el pie.\n"
                   }),
      "kick"     : ({ AN+" muerde a "+DN+" en la pierna.\n",
                      "Muerdes a "+DN+" en la pierna.\n",
                      AN+" te muerde en la pierna.\n"
                   }),
      "knee"     : ({ AN+" muerde a "+DN+" en la mano.\n",
                      "Muerdes a "+DN+" en la mano.\n",
                      AN+" te muerde en la mano.\n"
                   }),
      "headbutt" : ({ AN+" muerde a "+DN+" en la ingle.\n",
                      "Muerdes a "+DN+" en la ingle.\n",
                      AN+" te muerde en la ingle.\n"
                   })
   ]);
}
