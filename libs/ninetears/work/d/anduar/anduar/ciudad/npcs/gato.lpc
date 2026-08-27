// Me parecio ver un lindo gatiiiito.
// Gestur'98
#include "unarmed_combat.h"

inherit "/obj/monster";

void setup()
{
   set_name("gato");
   set_short("gato callejero");
   add_alias("callejero");
   set_main_plural("gatos callejeros");
   add_plural("gatos");
   add_plural("callejeros");
   set_long("Ante ti tienes un bonito y simpatico gato callejero. A pesar de "
   "estar abandonado su aspecto es bastante bueno. Es de color pardo "
   "brillante y tiene pinta de estar limpio. Es de tamanyo medio y parece "
   "bastante agil.\n");
   set_wimpy(20);
      set_al(random(161)-random(161));
   set_gender(1);
   set_random_stats(6,16);
   set_dex(19);
   set_cha(6+random(10));
   set_level(2+random(2));
   load_chat(50,
   ({ 1, "@Miiiiaaauuuuu.",
      1, ":empieza a lamerse el pelo.",
      1, ":ronronea al arrimarte.", 
   }));
   load_a_chat(80,
   ({ 1, "@Bffffffffffffffffffhhhhhhhhhhhhhhhhhh!!!!!!!!!!!!!!!!",
      1, "@Marramiauuuuuuuuuuuuuuu!!!!!!!!",
      1, ":se le erizan los pelos.",
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
