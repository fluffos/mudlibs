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
   set_short("Oso pardo");
   set_name("oso pardo");
   add_alias("oso");
   add_alias("pardo");
   set_main_plural("Osos pardos");
   add_plural("osos");
   add_plural("pardos");
   set_long("Este es un gran y poderoso animal.  "
      "Es un gran oso protector de los elementos, y "
      "sus poderos colmillos le hacen respetar del resto de animales.\n");
   set_level(18);
   set_gender(random(2)+1);
   msgin="@Oso pardo llega grunyendo $F.";
   msgout="@Oso pardo se mueve rapido al $T.";
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

  return([
          "knee"  :({AN+" salta sobre "+DN+" mordisceandole la cara.\n",
                     "Un tremendo zarpazo a "+DN+" le deja grogi.\n",
                     AN+" salta sobre ti mordisceandote la cara.\n"}),
          "punch"  :({AN+" se cuelga del cuello de "+DN+" aogandolo.\n",
                      "Te cuelgas del cuello de "+DN+" aogandolo.\n",
                      AN+" te rodea con sus patas por el cuello aogandote.\n"}),
          "kick"  :({AN+" hace saltarle las lagrimas a "+DN+" al golpear su corazon.\n",
                     "Haces saltar las lagrimas a "+DN+" al golpear su corazon.\n",
                      AN+" te hace saltar las lagrimas al golpearte en el corazon.\n"})]);
}
