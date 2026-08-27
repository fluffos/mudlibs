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
   set_short("Halcon");
   set_name("Halcon");
   add_alias("halcon");
   set_main_plural("Halcones");
   add_plural("halcones");
   set_long("This is a large bird of prey, with a five foot wing span.  "
      "It has keen eyes, a sharp beak, and long talons.  "
      "This particular hawk has "+
      ({"redish-brown","brown","dark brown",})[random(3)]+
      " feathers.\n");
   set_level(6);
   set_gender(random(2)+1);
   msgin="@Halcon llega volando de $F.";
   msgout="@Halcon se va volando hacia $T.";
   add_timed_property("just_summoned",1,10);
   set_heart_beat(1);
}
int unarmed_attack(object target, object me)
{
   int i;
   object *att;
   att=(object *)me->query_attacker_list();
      monster::unarmed_attack(att[random(sizeof(att))],me);
      set_damage_dice(1,2);
      monster::unarmed_attack(att[random(sizeof(att))],me);
      set_damage_dice(1,2);
      monster::unarmed_attack(att[random(sizeof(att))],me);
      set_damage_dice(1,1);
}
valid_attack()
{
   int two, four;
   two=random(2);
   four=random(4);
   return([
      "punch"  :({AN+" "+({"claws","pierces",})[two]+" "+DN+"'s "+
                  ({"arm","leg","head","chest",})[four]+".\n",
                  "You "+({"claw","pierce",})[two]+" "+DN+"'s "+
                  ({"arm","leg","head","chest",})[four]+".\n",
                  AN+" "+({"claws","pierces",})[two]+" your "+
                  ({"arm","leg","head","chest",})[four]+".\n"}),
      "kick"   :({AN+" "+({"scratches","slashes",})[two]+" "+DN+"'s "+
                  ({"arm","leg","head","chest",})[four]+".\n",
                   "You "+({"scratch","slash",})[two]+" "+DN+"'s "+
                  ({"arm","leg","head","chest",})[four]+".\n",
                  AN+" "+({"scratches","slashes",})[two]+" your "+
                  ({"arm","leg","head","chest",})[four]+".\n"}),
        "kick"   :({AN+" "+({"bites","cuts",})[two]+" "+DN+"'s "+
                    ({"arm","leg","head","chest",})[four]+".\n",
                     "You "+({"bite","cut",})[two]+" "+DN+"'s "+
                    ({"arm","leg","head","chest",})[four]+".\n",
                    AN+" "+({"bites","cuts",})[two]+" your "+
                    ({"arm","leg","head","chest",})[four]+".\n"}),
      ]);
}
