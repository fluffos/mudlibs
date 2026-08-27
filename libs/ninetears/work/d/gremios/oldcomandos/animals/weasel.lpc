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
   set_short("Comadreja");
   set_name("Comadreja");
   add_alias("comadreja");
   set_main_plural("Comadrejas");
   add_plural("comadrejas");
   set_long("This is a small thin animal with grey-brown fur.  "
      "It's keen eyes, long nose and whiskers, and darting movements "
      "give it a mischevious appearance.\n");
   set_level(3);
   set_gender(random(2)+1);
   msgin="@Comadreja llega deslizandose de $F.";
   msgout="@Comadreja se va deslizandose hacia $T.";
   add_timed_property("just_summoned",1,10);
   set_heart_beat(1);
   set_damage_dice(1,2);
}
valid_attack()
{
   int two, four;
   two=random(2);
   four=random(4);
   return([
      "punch"  :({AN+" "+({"scratches","nicks"})[two]+" "+DN+"'s "+
                  ({"arm","leg","head","chest",})[four]+".\n",
                  "You "+({"scratch","nick",})[two]+" "+DN+"'s "+
                  ({"arm","leg","head","chest",})[four]+".\n",
                  AN+" "+({"scratches","nicks",})[two]+" your "+
                  ({"arm","leg","head","chest",})[four]+".\n"}),
      "kick"   :({AN+" "+({"paws at","tweaks",})[two]+" "+DN+"'s "+
                  ({"arm","leg","head","chest",})[four]+".\n",
                  "You "+({"paw at","tweak",})[two]+" "+DN+"'s "+
                  ({"arm","leg","head","chest",})[four]+".\n",
                  AN+" "+({"paws at","tweaks",})[two]+" your "+
                  ({"arm","leg","head","chest",})[four]+".\n"}),
      "knee"   :({AN+" "+({"bites","nips",})[two]+" "+DN+"'s "+
                  ({"arm","leg","head","chest",})[four]+".\n",
                  "You "+({"bite","nip",})[two]+" "+DN+"'s "+
                  ({"arm","leg","head","chest",})[four]+".\n",
                  AN+" "+({"bites","nips",})[two]+" your "+
                  ({"arm","leg","head","chest",})[four]+".\n"})
      ]);
}
