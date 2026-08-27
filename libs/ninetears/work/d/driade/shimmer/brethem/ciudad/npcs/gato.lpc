/* By Shimmer */

#define CREATOR "shimmer";

#include "unarmed_combat.h"

inherit "/obj/monster";

void setup()
{
   set_name("gato");
   set_short("gato");
   set_main_plural("gatos");
   add_plural("gatos");
   set_long("Es un pequenyo gato abandnado que recorre las calles e busca de algo de comida.\n");
   set_wimpy(20);
   set_al(10);
   set_gender(1);
   set_random_stats(6,16);
   set_dex(19);
   set_cha(6+random(10));
   set_level(2+random(2));
   load_chat(50,
   ({ 1, "@Miiiiaaauuuuu.",
      1, ":empieza a lamerse el pelo.",
      1, ":ronronea al arrimarse a tu pierna.", 
   }));
}

valid_attack()
{
   return
   ([
      "punch"    : ({ AN+" le aranya la pierna a "+DN+".\n",
                      "Le aranyas la pierna a "+DN+".\n",
                      AN+" te aranya la pierna.\n"
                   }),
      "kick"     : ({ AN+" muerde a "+DN+" en la pierna.\n",
                      "Muerdes a "+DN+" en la pierna.\n",
                      AN+" te muerde en la pierna.\n"
                   }),
      "knee"     : ({ AN+" muerde a "+DN+" en la mano.\n",
                      "Muerdes a "+DN+" en la mano.\n",
                      AN+" te muerde en la mano.\n"
                   }),
      "headbutt" : ({ AN+" aranya a "+DN+" en la cara.\n",
                      " Aranyas "+DN+" en la cara.\n",
                      AN+" te aranya en la cara.\n"
                   })
   ]);
}
