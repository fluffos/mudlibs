#include "animals.h"
#include "unarmed_combat.h"
inherit "/obj/monster";
object my_player;
#include "ranger.h"
void set_my_player(object ranger)
{
   my_player=ranger;
}
void setup()
{
   set_short("Lobo");
   set_name("lobo");
   add_alias("lobo");
   set_main_plural("Lobos");
   add_plural("lobos");
   set_long("Este es un perro - lobo con poderosos colmillos. "
      "y un gran pelaje "+({"blanco","gris","blanco y gris",})[random(3)]+
      "que le protege del frio.\n");
   set_level(9);
   set_gender(random(2)+1);
   add_timed_property("just_summoned",1,10);
   set_heart_beat(1);
   set_damage_dice(1,4);
   set_str(16);
}
valid_attack()
{
   int two, four;
   two=random(2);
   four=random(4);
   return([
      "punch"  :({AN+" "+({"da un zarpazo a","muerde a",})[two]+" "+DN+
                  " en el "+({"brazo","estomago","corazon","cuello",})[four]+
                  ".\n",
                  "Das "+({"un cabezazo a","una patada a",})[two]+" "+DN+
                  " en el "+({"brazo","estomago","corazon","cuello",})[four]+
                  ".\n",
                  AN+" "+({"te da un zarpaazo","te da un mordisco",})[two]+" en la "+
                  ({"barriga","pierna","cabeza","mano",})[four]+".\n"}),
      "kick"   :({AN+" "+({"aranya a","corta con sus garras a",})[two]+" "+DN+
                  " en la "+({"cara","cabeza","pierna","boca",})[four]+
                  ".\n",
                  "Golpeas "+({"repetidas veces a","sin cesar a",})[two]+" "+DN+
                  " en el "+({"brazo","estomago","culo","tobillo",})[four]+
                  ".\n",
                  AN+" "+({"te aranya","te muerde",})[two]+" en el "+
                  ({"brazo","cuerpo","estomago","cuello",})[four]+".\n"}),
      "knee"   :({AN+" "+({"muerde a","clava sus colmillos en",})[two]+" "+DN+" en la "+
                  ({"espinilla","pierna","cabeza","barriga",})[four]+".\n",
                  "Das un rodillazo "+({"volador a","perfecto a",})[two]+" "+DN+" en la "+
                  ({"cadera","pierna","cabeza","entrepierna",})[four]+".\n",
                  AN+" "+({"te aranya","te clava sus colmillos",})[two]+" en la "+
                  ({"cabeza","pierna","entrepierna","barriga",})[four]+".\n"})
      ]);
}
