/*  File upgrade by Grimbrand 2-11-96                                   */

#include "unarmed_combat.h"
inherit "/obj/monster";

void setup() {
   set_name("umber hulk");
   set_short("Old Umber Hulk");
   set_long("   This creature has obviously seen many a season.  At one "
            "time it might have looked very strong standing nearly 8 "
            "feet tall, now it only stands at about 6 feet with a "
            "stoop.  It is also missing one of its large mandibles, "
            "making it far less dangerous, but not easy by any means."
            "\n\n");
   set_kill_xp(431);
   add_alias("umber hulk");
   add_alias("hulk");
   set_main_plural("umber hulks");
   add_plural("umber hulks");
   add_plural("hulks");
   set_guild("fighter");
   set_level(8);
   set_random_stats(12,18);
   set_max_hp(34);
   set_max_gp(10);
   adjust_money(5,"gold");
}

int unarmed_attack(object target, object me)
{
   int i;
   object *att;
   att=(object *)me->query_attacker_list();
      monster::unarmed_attack(att[random(sizeof(att))],me);
}
mapping valid_attack()
{
   return([
      "punch": ({AN+" rends "+DN+" with its claws.\n",
                 "You rend "+DN+" with your claws.\n",
                 AN+" rends you with its claws.\n"}),
      "kick":  ({AN+" rends "+DN+" with its claws.\n",
                 "You rend "+DN+" with your claws.\n",
                 AN+" rends you with its claws.\n"}),
      "knee":  ({AN+" rips "+DN+"'s flesh with it's mandibles.\n",
                 "You rip "+DN+"'s flesh with your mandibles.\n",
                 AN+" rips your flesh with its mandibles.\n"})
      ]);
}
