/* By Shimmer */

#define CREATOR "shimmer";

#include "unarmed_combat.h"

inherit "/obj/monster";

void setup()
{
   set_name("pajaro");
   set_short("pajaro");
   set_wimpy(0);
   add_alias("ave");
   set_main_plural("pajaros");
   add_plural("pajaros");
   add_plural("aves");
   set_gender(0);
   set_long("Es hermoso pajaro, que sobrevuela la calle picoteando de vez en"
   "cuando algunas migajas que encuentra, tratando de esquivar a los gatos callejeros.\n");
   set_random_stats(6, 11);
   set_cha(8);
   set_ac(-10);
   set_level(1+random(2));
   add_move_zone("brethem");
}

valid_attack()
{
   return
   ([
      "punch"    : ({ AN+" se mete por el oido de "+DN+".\n",
                      "Te metes por el oido de "+DN+".\n",
                      AN+" se te mete por el oido.\n"
                   }),
      "kick"     : ({ AN+" pica a "+DN+" en la pierna.\n",
                      "Picas a "+DN+" en la pierna.\n",
                      AN+" te pica en la pierna.\n"
                   }),
      "knee"     : ({ AN+" pica a "+DN+" en la mano.\n",
                      "Picas a "+DN+" en la mano.\n",
                      AN+" te pica en la mano.\n"
                   }),
      "headbutt" : ({ AN+" pica a "+DN+" en la cara.\n",
                      " pica "+DN+" en la cara.\n",
                      AN+" te pica en la cara.\n"
                   })
   ]);
}
