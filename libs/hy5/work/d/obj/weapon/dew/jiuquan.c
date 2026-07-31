    //含笑九泉
    //by dewbaby@sk


#include <weapon.h>
#include <ansi.h>
//  inherit F_UNIQUE;

inherit WHIP;
void create()
{
    set_name(HIR"含笑九泉"NOR,({"death whip","death","whip"}));
    set_weight(20000);
if( clonep() )
       set_default_object(__FILE__);
    else{
    set("long",HIR"一根长而细的鬼神之鞭，上面沾满鲜血，散发出一丝丝杀气!\n"NOR);
    set("unit","条");
    set("value", 1200);
    set("wield_msg",HIR"$N鬼魅一笑，神情中夹杂着丝丝杀气。\n"NOR);
    set("unwield_msg",HIR"$N神情傲然不可侵犯，手中$n"HIR"已悄然消失!\n"NOR);
    set("no_sell","你大脑有问题吧? 这东西你也敢卖? \n");
    set("no_drop","去垃圾堆丢吧，乱扔会污染环境!\n");
    }
      init_whip(830);
      setup();

}
/*
    mixed hit_ob(object me, object victim)
{
    int damage_bonus = 0; 

    if( (string)me->query("family/family_name") == "阎罗地府" 
              && me->query_skill("hellfire-whip",1) > 1) 
    damage_bonus = me->query_skill("hellfire-whip",1); 
    damage_bonus = (damage_bonus+random(damage_bonus))/2; 

    victim->receive_wound("qi",damage_bonus); 
    return HIB"含笑九泉上燃起阵阵鬼火!\n" NOR; 

}
*/
