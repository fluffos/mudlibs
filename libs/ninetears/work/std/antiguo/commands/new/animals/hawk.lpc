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
   set_name("halcon");
   add_alias("halcon");
   set_main_plural("Halcones");
   add_plural("halcones");
   set_long("Este es un pajaro de rapinya, tiene unas grandes zarpas,  "
      "su plumaje es marronaceo a motas blancas.  "
      "Este halcon en particular tiene las patas "+
      ({"marrones","grises","oscuras",})[random(3)]+
      ".\n");
   set_level(6);
   set_gender(random(2)+1);
   msgin="@Halcon vuela hacia $F.";
   msgout="@Halcon llega volando $T.";
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
      "punch"  :({AN+" "+({"pica a","aranya con sus garras a",})[two]+" "+DN+" rasgando su "+
                  ({"brazo","cara","pecho","cuello",})[four]+".\n",
                  "Golpeas "+({"con un derechazo a","con un upercut a",})[two]+" "+DN+" en "+
                  ({"un ala","la pata","la cabeza","el pico",})[four]+".\n",
                  AN+" "+({"te clava sus garras","te picotea",})[two]+" en "+
                  ({"un brazo","una pierna","la cabeza","la nariz",})[four]+".\n"}),
      "kick"   :({AN+" "+({"clava sus unyas a","aranya a",})[two]+" "+DN+" en "+
                  ({"las piernas","la cabeza","el estomago","la boca",})[four]+".\n",
                   "Golpeas "+({"varias veces a","escupiendo a",})[two]+" "+DN+" en "+
                  ({"un brazo","la cabeza","la cara","la ingle",})[four]+".\n",
                  AN+" "+({"te pica","te clava sus garras",})[two]+" en "+
                  ({"un brazo","la pierna","la cabeza","la espalda",})[four]+".\n"}),
        "kick"   :({AN+" "+({"pica a","golpea a",})[two]+" "+DN+" en "+
                    ({"un brazo","una pierna","la cabeza","el cuello",})[four]+".\n",
                     "Pateas "+({"con tu talon a","con la rodilla a",})[two]+" "+DN+" en "+
                    ({"un brazo","la pierna","la cabeza","la boca",})[four]+".\n",
                    AN+" "+({"revolotea picandote ","se avalanza aranyandote",})[two]+" en "+
                    ({"la cara","un huevo","la boca","la nariz",})[four]+".\n"}),
      ]);
}
