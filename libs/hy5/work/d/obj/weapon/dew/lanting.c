//兰亭四夜
//by dewbaby@sk

#include <weapon.h>

inherit WHIP;
#include <ansi.h>

void create()
{
       set_name(HIB"兰亭四夜"NOR, ({"lanting whip","lanting","whip"}));
       set_weight(20000);
if( clonep() )
       set_default_object(__FILE__);
       else {
set("long",HIC"这就是传说中红霞仙子驰骋天下时所用的宝物之一。仔细闻去，它隐约散发着淡淡兰花的清香。\n"NOR);
              set("unit","副");
              set("value", 1200);
              set("wield_msg",HIB"$N淡淡一笑，飘然一个转身间$n"HIB"已经被缠绕在$N手腕上。"MAG"一阵兰花香朝你铺面而来。\n"NOR);
             set("unwield_msg",MAG"一阵浓郁的兰花香将你笼罩。"HIB"只见$N微微垂首，神情落寂地凝视着已缠绕在手腕上的$n。\n"NOR); 
              set("no_sell","这东西你也敢卖?你脑筋有毛病吧! \n");
              set("no_drop","扔到垃圾堆里去吧,乱扔会污染环境! \n");
             set("weapon_prop/courage", 20); 
      }
    init_whip(830);
    setup();
}
/*
 mixed hit_ob(object me, object victim) 
{
    int damage_bonus = 0; 

    if( (string)me->query("family/family_name") == "盘丝洞" 
                 && me->query_skill("yinsuo-jinling",1) > 1) 
    damage_bonus = me->query_skill("yinsuo-jinling",1); 
    damage_bonus = (damage_bonus+random(damage_bonus))/2; 

    victim->receive_wound("qi",damage_bonus); 
    return MAG"兰亭四夜上隐约显现出兰花之形!\n" NOR; 
  }
*/
