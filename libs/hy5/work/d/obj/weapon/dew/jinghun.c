    //十面惊魂
    //by dewbaby@sk


#include <weapon.h>
//  inherit F_UNIQUE;

#include <ansi.h>
inherit BLADE;

void create()
{
    set_name(RED"十面惊魂"NOR,({"ghost blade","ghost","blade"}));
    set_weight(20000);
if( clonep() )
       set_default_object(__FILE__);
else {
    set("long",RED"你一碰触此宝刀，双手就不住地颤抖起来。据说它可以让拥有者获得惊人的力量!\n"NOR);
    set("unit","把");
    set("value",1200);
    set("wield_msg",RED"$N仰天长笑，仿佛到达了"HIW"悲喜空，无善念，以血伺刀"RED"的境界!\n"NOR);
    set("unwield_msg",HIB"$N突然神情黯淡，望着天空良久无语，悲喜之情又渐渐如潮水涨起...\n"NOR);
    set("no_sell",1);
    set("no_drop",1);

 }
   init_blade(830);
   setup();

}
/*
      mixed hit_ob(object me, object victim) 
{
          int damage_bonus = 0; 

         if( (string)me->query("family/family_name") == "陷空山无底洞" 
                    && me->query_skill("kugu-blade",1) > 1) 
          damage_bonus = me->query_skill("kugu-blade",1); 
         damage_bonus = (damage_bonus+random(damage_bonus))/2; 

         victim->receive_wound("qi",damage_bonus); 
         return HIW"十面惊魂上阴魂闪现!\n" NOR; 

}
*/
