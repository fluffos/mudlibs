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
   set_short("Oso Grizzly");
   set_name("Oso Grizzly");
   add_alias("oso grizzly");
   add_alias("oso");
   set_main_plural("Osos Grizzly");
   add_plural("osos grizzly");
   add_plural("osos");
   set_long("Este es un animal grande y poderoso.  "
      "Su denso pelaje marron lo protege de los elementos, y sus "
      "poderosas garras lo protegen de otros animales.\n");
   set_level(18);
   set_gender(random(2)+1);
   msgin="@Oso Grizzly llega andando pesadamente de $F.";
   msgout="@Oso Grizzly se va andando pesadamente hacia $T.";
   add_timed_property("just_summoned",1,10);
   set_heart_beat(1);
}
int unarmed_attack(object target, object me)
{
   int i;
   object *att;
   att=(object *)me->query_attacker_list();
      monster::unarmed_attack(att[random(sizeof(att))],me);
      set_damage_dice(1,8);
      monster::unarmed_attack(att[random(sizeof(att))],me);
      set_damage_dice(1,8);
      monster::unarmed_attack(att[random(sizeof(att))],me);
      set_damage_dice(1,12);
}
valid_attack()
{
   int two, four;
   two=random(2);
   four=random(4);
   return([
      "punch"  :({AN+" "+({"swats","slaps",})[two]+" "+DN+
                  " on the "+({"arm","leg","head","chest",})[four]+
                  ".\n",
                  "You "+({"swat","slap",})[two]+" "+DN+
                  " on the "+({"arm","leg","head","chest",})[four]+
                  ".\n",
                  AN+" "+({"swats","slaps",})[two]+" you on the "+
                  ({"arm","leg","head","chest",})[four]+".\n"}),
      "kick"   :({AN+" "+({"slashes","rends",})[two]+" "+DN+
                  " on the "+({"arm","leg","head","chest",})[four]+
                  ".\n",
                  "You "+({"slash","rend",})[two]+" "+DN+
                  " on the "+({"arm","leg","head","chest",})[four]+
                  ".\n",
                  AN+" "+({"slashes","rends",})[two]+" you on the "+
                  ({"arm","leg","head","chest",})[four]+".\n"}),
      "knee"   :({AN+" "+({"bites","mangles",})[two]+" "+DN+"'s "+
                  ({"arm","leg","head","chest",})[four]+".\n",
                  "You "+({"bite","mangle",})[two]+" "+DN+"'s "+
                  ({"arm","leg","head","chest",})[four]+".\n",
                  AN+" "+({"bites","mangles",})[two]+" your "+
                  ({"arm","leg","head","chest",})[four]+".\n"})
      ]);
}
