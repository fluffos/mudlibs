// Planta asesina Aokromes 99
#include "unarmed_combat.h"

inherit "/obj/monster";

void setup()
{
   set_name("planta negra");
   set_short("planta negra");
   set_main_plural("plantas negras");
   add_plural("plantas");
   add_alias("planta");
   add_alias("negra");
   set_long("Una planta negra indudablemente venenosa, parece ser que esta "
   "tierra le ha dado una especie de vida y ataca a todo lo que pasa por "
   "aqui, sea lo que sea no te inspira nada de confianza, tal vez sea mejor "
   "alejarse rapidamente de ella.\n");
   set_wimpy(0);
   set_gender(0);
   set_al(1000);
   set_random_stats(16,18);
   set_str(20);
   set_cha(18);
   set_level(20+random(4));
   set_aggressive(3);
}

void event_enter(object ob, string mess, object from)
{
      attack_ob(ob);
   ::event_enter(ob, mess, from);
}

valid_attack()
{
   return
   ([
      "punch"    : ({ AN+" le apresa la pantorrilla a "+DN+" con una raiz.\n",
                      "Le apresas la pantorrilla a "+DN+" con una raiz.\n",
                      AN+" te apresa la pantorrila con una raiz.\n"
                   }),
      "kick"     : ({ AN+" apresa a "+DN+" la pierna con una raiz.\n",
                      "Apresas a "+DN+" la pierna con una raiz.\n",
                      AN+" te apresa la pierna con una raiz.\n"
                   }),
      "knee"     : ({ AN+" apresa a "+DN+" en la mano con una hoja.\n",
                      "Apresas a "+DN+" en la mano con una hoja.\n",
                      AN+" te apresa en la mano con una hoja.\n"
                   }),
      "headbutt" : ({ AN+" apresa a "+DN+" en la cara con la flor.\n",
                      "Apresas "+DN+" en la cara con la flor.\n",
                      AN+" te apresa en la cara con la flor.\n"
                   })
   ]);
}
