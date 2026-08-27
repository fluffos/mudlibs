/* By Shimmer */

#define CREATOR "shimmer";

#include "unarmed_combat.h"

inherit "/obj/monster";

void setup()
{
   set_name("perro");
   set_short("perro");
   set_main_plural("perros");
   add_plural("perros");
   set_long("Es un perro callejero que vive en la calle buscando desperdicios con los "
   "que alimentarse, su aspecto es repugnante, esta lleno de pulgas y garrapatas.\n");
   set_wimpy(0);
   set_gender(1);
  set_al(random(50));
   
   set_random_stats(6,16);
   set_dex(16);
   set_str(17);
   set_cha(12);
   set_level(4+random(4));
   load_chat(50,
   ({ 1, "@Guau, worf, arf arf.",
      1, ":se rasca las pulgas.",
      1, "@Guau, guau, grrrrrrrr.", 
      1, ":te ensenya los colmillos.",
   }));
   add_move_zone("brethem");
   set_move_after(30, 60);
}

void event_enter(object ob, string mess, object from)
{
   if (ob->query_name()=="gato")
   {
      attack_ob(ob);
   }
   ::event_enter(ob, mess, from);
}

void event_person_say(object ob)
{
   if (ob->query_name()=="gato")
   {
      attack_ob(ob);
   }
}

valid_attack()
{
   return
   ([
      "punch"    : ({ AN+" le muerde la pantorrilla a "+DN+".\n",
                      "Le muerdes la pantorrilla a "+DN+".\n",
                      AN+" te muerde la pantorrila.\n"
                   }),
      "kick"     : ({ AN+" muerde a "+DN+" en la pierna.\n",
                      "Muerdes a "+DN+" en la pierna.\n",
                      AN+" te muerde en la pierna.\n"
                   }),
      "knee"     : ({ AN+" muerde a "+DN+" en la mano.\n",
                      "Muerdes a "+DN+" en la mano.\n",
                      AN+" te muerde en la mano.\n"
                   }),
      "headbutt" : ({ AN+" muerde a "+DN+" en la cara.\n",
                      " Muerdes "+DN+" en la cara.\n",
                      AN+" te muerde en la cara.\n"
                   })
   ]);
}
