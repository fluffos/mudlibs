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
   set_short("Comadreja salvaje");
   set_name("comadreja");
   add_alias("comadreja");
   add_alias("salvaje");
   set_main_plural("Comadrejas salvajes");
   add_plural("comadrejas");
   add_plural("boars");
   set_long("Este animal se parece a un castor acuatico, pero "
      "obviamente no es docil.  Tiene una alargada cola puntiaguda, "
      "su pelo es oscuro y sus patas son mas bien cortas.\n");
   set_level(12);
   set_gender(random(2)+1);
   msgin="@Comadreja salvaje llega sigilosa del $F.";
   msgout="@Comadreja salvaje se arrastra al $T.";
   add_timed_property("just_summoned",1,10);
   set_heart_beat(1);
   set_damage_dice(3,4);
}
valid_attack()
{
   int two, four;
   two=random(2);
   four=random(4);
   return([
      "punch"  :({AN+" "+({"da un cabezazo a","patea a",})[two]+" "+DN+
                  " en el "+({"brazo","estomago","corazon","cuello",})[four]+
                  ".\n",
                  "Das "+({"un cabezazo a","una patada a",})[two]+" "+DN+
                  " en el "+({"brazo","estomago","corazon","cuello",})[four]+
                  ".\n",
                  AN+" "+({"te da un cabezazo","te da un zarpazo",})[two]+" en la "+
                  ({"barriga","pierna","cabeza","mano",})[four]+".\n"}),
      "kick"   :({AN+" "+({"aranya a","corta con sus garras a",})[two]+" "+DN+
                  " en la "+({"cara","cabeza","pierna","boca",})[four]+
                  ".\n",
                  "Golpeas "+({"repetidas veces a","sin cesar a",})[two]+" "+DN+
                  " en el "+({"brazo","estomago","culo","tobillo",})[four]+
                  ".\n",
                  AN+" "+({"te aranya","te muerde",})[two]+" en el "+
                  ({"brazo","cuerpo","estomago","cuello",})[four]+".\n"}),
      "knee"   :({AN+" "+({"muerde a","da un rodillazo a",})[two]+" "+DN+" en la "+
                  ({"espinilla","pierna","cabeza","barriga",})[four]+".\n",
                  "Das un rodillazo "+({"volador a","perfecto a",})[two]+" "+DN+" en la "+
                  ({"cadera","pierna","cabeza","entrepierna",})[four]+".\n",
                  AN+" "+({"te aranya","te mordisquea",})[two]+" en la "+
                  ({"cabeza","pierna","entrepierna","barriga",})[four]+".\n"})
      ]); 
}