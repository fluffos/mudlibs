/*  File upgrade by Grimbrand 2-11-96                                   */

#include "unarmed_combat.h"
inherit "/obj/monster";

void setup() {
   set_name("umber hulk");
   set_short("Viejo Umber Hulk");
   set_long("   Una criatura que obviamente ha visto pasar muchas "
            "estaciones. En un tiempo debio ser temible verle ,con "
            "cerca de 8 pies de altura, ahora apenas levanta unos "
            "6 pies y esta encorvado. Tambien ha perdido una de sus "
            "mandibulas, haciendole mucho menos letal,pero no es un "
            "enemigo indefenso ni mucho menos."
	    "\n\n");
   set_kill_xp(431);
   add_alias("umber hulk");
   add_alias("umber");
   add_alias("hulk");
   set_main_plural("umber hulks");
   add_plural("umber hulks");
   add_plural("hulks");
   add_plural("umbers");
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
      "punch": ({AN+" raja a "+DN+" con su garra.\n",
                 "Rajas a "+DN+" con tu garra.\n",
                 AN+" te raja con sus garras.\n"}),
      "kick":  ({AN+" rasga la cara a "+DN+" con su garra.\n",
                 "Rasgas la cara a "+DN+" con tu garra.\n",
                 AN+" te rasga la cara con su garra.\n"}),
      "knee":  ({AN+" arranca a "+DN+"un trozo de carne con sus mandibulas.\n",
                 "Arrancas a "+DN+" un trozo de carne con sus mandibulas.\n",
                 AN+" te arranca un trozo de carne con sus mandibulas.\n"})
      ]);
}
