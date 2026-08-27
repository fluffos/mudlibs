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
   set_short("Tigre de Bengala");
   set_name("tigre");
   add_alias("tigre");
   add_alias("bengala");
   set_main_plural("Tigres de Bengala");
   add_plural("tigres");
   add_plural("bengala");
   set_long("Este el mas grande y mas fiero de los gatos salvajes.  "
      "El tigre de Bengala es el rey de los animales en cuanto a predadores "
      "se refiere.  Tiene unos grandes colmillos, y un pelaje sagrado "
      "marronaceo moteado, sus grandes ojos negros le permiten divisar "
      "a su alrededor sus presas.  Su hocico huele la comida y sangre "
      "de otros animales para anticiparse por sorpresa, sin duda es un excelente "
      "cazador y luchador.\n");
   set_level(15);
   set_gender(random(2)+1);
   msgin="@Tigre de Bengala llega sigilante $F.";
   msgout="@Tigre de Bengala se mueve con rapidez al $T.";
   add_timed_property("just_summoned",1,10);
   set_heart_beat(1);
}
int unarmed_attack(object target, object me)
{
   int i;
   object *att;
   att=(object *)me->query_attacker_list();
      monster::unarmed_attack(att[random(sizeof(att))],me);
      set_damage_dice(1,4);
      monster::unarmed_attack(att[random(sizeof(att))],me);
      set_damage_dice(1,4);
      monster::unarmed_attack(att[random(sizeof(att))],me);
      set_damage_dice(1,10);
      monster::unarmed_attack(att[random(sizeof(att))],me);
      set_damage_dice(1,4);
      monster::unarmed_attack(att[random(sizeof(att))],me);
      set_damage_dice(1,4);
}
valid_attack()
{
   int two, four;
   two=random(2);
   four=random(4);
   return([
      "punch"  :({AN+" "+({"da un zarpazo a","clava sus colmillos en",})[two]+" "+DN+
                  " en el "+({"brazo","estomago","corazon","cuello",})[four]+
                  ".\n",
                  "Das "+({"un cabezazo a","una patada a",})[two]+" "+DN+
                  " en el "+({"brazo","estomago","corazon","cuello",})[four]+
                  ".\n",
                  AN+" "+({"te da un zarpazo","te clava sus colmillos",})[two]+" en la "+
                  ({"barriga","pierna","cabeza","mano",})[four]+".\n"}),
      "kick"   :({AN+" "+({"mordisquea a","corta con sus garras a",})[two]+" "+DN+
                  " en la "+({"cara","cabeza","pierna","boca",})[four]+
                  ".\n",
                  "Golpeas "+({"repetidas veces a","sin cesar a",})[two]+" "+DN+
                  " en el "+({"brazo","estomago","culo","tobillo",})[four]+
                  ".\n",
                  AN+" "+({"te mordisquea","te corta con sus garras",})[two]+" en el "+
                  ({"brazo","cuerpo","estomago","cuello",})[four]+".\n"}),
      "knee"   :({AN+" "+({"muerde a","da un tremendo zarpazo a",})[two]+" "+DN+" en la "+
                  ({"espinilla","pierna","cabeza","barriga",})[four]+".\n",
                  "Das un rodillazo "+({"volador a","perfecto a",})[two]+" "+DN+" en la "+
                  ({"cadera","pierna","cabeza","entrepierna",})[four]+".\n",
                  AN+" "+({"te muerde","te da un tremendo zarpazo",})[two]+" en la "+
                  ({"cabeza","pierna","entrepierna","barriga",})[four]+".\n"})
      ]);
}
