// Pajarraco Aokromes'99
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
   set_long("Es hermoso pajaro, que vuela a lo largo y ancho de la calle "
   "dando vueltas por los arboles, comiendo polen de las flores y tratando "
   "de que los gatos no les cazen.\n");
   set_random_stats(6, 11);
   set_cha(8);
   set_ac(-10); // Un pajaro es dificil de darle
   set_level(1+random(2)); // Nivel 1 o 2  :)
   add_move_zone("anduar");
} /* setup() */

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
