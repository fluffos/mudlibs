// Mosco. Gestur'98
#include "unarmed_combat.h"

inherit "/obj/monster";

void setup()
{
   set_name("rata");
   set_short("rata");
   set_race_ob("roedor");
   set_wimpy(0);
   add_alias("roedor");
   set_main_plural("ratas");
   add_plural("ratas");
   add_plural("roedores");
   set_gender(0);
   set_long("Es una fea y gorda rata de color marron amarillento. Su rabo "
   "es largo y desagradable. Parece que este royendo algo. Quizas tenga algo "
   "que ver este animal con el estado de las paredes.\n");
   set_random_stats(4, 10);
   set_cha(2);
   set_level(3+random(3)); // Nivel 3 - 5
} /* setup() */

valid_attack()
{
   return
   ([
      "punch"    : ({ AN+" muerde a "+DN+" en la pierna.\n",
                      "Muerdes a "+DN+" en la pierna.\n",
                      AN+" te muerde en la pierna.\n"
                   }),
      "kick"     : ({ AN+" muerde a "+DN+" en el pie.\n",
                      "Muerdes a "+DN+" en el pie.\n",
                      AN+" te muerde en el pie.\n"
                   }),
      "knee"     : ({ AN+" muerde a "+DN+" en la mano.\n",
                      "Muerdes a "+DN+" en la mano.\n",
                      AN+" te pica en la mano.\n"
                   }),
      "headbutt" : ({ AN+" muerde a "+DN+" en el brazo.\n",
                      " muerde "+DN+" en el brazo.\n",
                      AN+" te muerde en el brazo.\n"
                   })
   ]);
}
