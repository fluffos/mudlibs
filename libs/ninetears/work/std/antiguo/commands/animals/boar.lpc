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
   set_short("Jabali Salvaje");
   set_name("Jabali Salvaje");
   add_alias("jabali salvaje");
   add_alias("jabali");
   set_main_plural("Jabalies Salvajes");
   add_plural("jabalies salvajes");
   add_plural("jabalies");
   set_long("Este animal se parece a un cerdo domesticado, pero obviamente "
      "no es tan docil.  Tiene un hocico algo mas corto, "
      "pelo duro y oscuro, una cola estrecha, y colmillos cortos.\n");
   set_level(12);
   set_gender(random(2)+1);
   msgin="@Wild Boar llega corriendo de $F.";
   msgout="@Wild Boar se va corriendo hacia $T.";
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
      "punch"  :({AN+" "+({"head butts","tripps",})[two]+" "+DN+
                  " on the "+({"arm","leg","head","chest",})[four]+
                  ".\n",
                  "You "+({"trounce","trip",})[two]+" "+DN+
                  " on the "+({"arm","leg","head","chest",})[four]+
                  ".\n",
                  AN+" "+({"trounces","tripps",})[two]+" you on the "+
                  ({"arm","leg","head","chest",})[four]+".\n"}),
      "kick"   :({AN+" "+({"slashes","tramples",})[two]+" "+DN+
                  " on the "+({"arm","leg","head","chest",})[four]+
                  ".\n",
                  "You "+({"slash","trample",})[two]+" "+DN+
                  " on the "+({"arm","leg","head","chest",})[four]+
                  ".\n",
                  AN+" "+({"slashes","tramples",})[two]+" you on the "+
                  ({"arm","leg","head","chest",})[four]+".\n"}),
      "knee"   :({AN+" "+({"bites","kicks",})[two]+" "+DN+"'s "+
                  ({"arm","leg","head","chest",})[four]+".\n",
                  "You "+({"bite","kick",})[two]+" "+DN+"'s "+
                  ({"arm","leg","head","chest",})[four]+".\n",
                  AN+" "+({"bites","kicks",})[two]+" your "+
                  ({"arm","leg","head","chest",})[four]+".\n"})
      ]);
}
