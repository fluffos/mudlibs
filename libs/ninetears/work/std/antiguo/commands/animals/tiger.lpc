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
   set_name("Tigre de Bengala");
   add_alias("tigre de bengala");
   add_alias("bengala");
   add_alias("tigre");
   set_main_plural("Tigres de Bengala");
   add_plural("tigres de bengala");
   add_plural("bengalas");
   add_plural("tigres");
   set_long("This is the largest and most feared of the great cats.  "
      "The bengal tiger is the most efficient preditor of the animal "
      "kingdom.  It has long claws and fang, and its redish-brown fur "
      "and verticle, black stipes allow it to blend perfectly with its "
      "natural surroundings.  It's keen eyes and ears not only make it "
      "difficult to surprise, but also make it an expert at hunting "
      "and stalking.\n");
   set_level(15);
   set_gender(random(2)+1);
   msgin="@Tigre de Bengala llega acechando sigilosamente de $F.";
   msgout="@Tigre de Bengala se va acechando sigilosamente hacia $T.";
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
      "punch"  :({AN+" "+({"swats","claws",})[two]+" "+DN+
                  " on the "+({"arm","leg","head","chest",})[four]+
                  ".\n",
                  "You "+({"swat","claw",})[two]+" "+DN+
                  " on the "+({"arm","leg","head","chest",})[four]+
                  ".\n",
                  AN+" "+({"swats","claws",})[two]+" you on the "+
                  ({"arm","leg","head","chest",})[four]+".\n"}),
      "kick"   :({AN+" "+({"slashes","rends",})[two]+" "+DN+
                  " on the "+({"arm","leg","head","chest",})[four]+
                  ".\n",
                  "You "+({"slash","rend",})[two]+" "+DN+
                  " on the "+({"arm","leg","head","chest",})[four]+
                  ".\n",
                  AN+" "+({"slashes","rends",})[two]+" you on the "+
                  ({"arm","leg","head","chest",})[four]+".\n"}),
      "knee"   :({AN+" "+({"bites","rips",})[two]+" "+DN+"'s "+
                  ({"arm","leg","head","chest",})[four]+".\n",
                  "You "+({"bite","rip",})[two]+" "+DN+"'s "+
                  ({"arm","leg","head","chest",})[four]+".\n",
                  AN+" "+({"bites","rips",})[two]+" your "+
                  ({"arm","leg","head","chest",})[four]+".\n"})
      ]);
}
