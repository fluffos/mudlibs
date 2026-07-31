// yufeng_poison.c 玉蜂针毒
// By Kayin @ CuteRabbit Studio 1999/3/23 new

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        int dam_kee,dam_gin,dam_sen;
        string msg;
        dam_kee = (int) me->query("max_qi")/10;
        dam_gin = (int) me->query("max_jing")/10;
        dam_sen = (int) me->query("max_jing")/10;
    if( duration < 1 )
        {
                tell_object(me, HIR "你终于受不了" HIY "阴阳合和散" HIR "的催情作用，全身爆裂而死！\n" NOR );
                message("vision", me->name() + "全身经脉爆裂。\n", environment(me), me); 
if (userp(me))
{
                me->unconcious();
if (random(8)==0)
{
me->die();
}
	
}


        }
   if( !living(me) ) {
      message("vision", me->name() + "痛苦地哼了一声。\n", environment(me), me);
   }
   else {
 tell_object( me, HIR "你中的" HIY "阴阳合和散" HIR  "发作了，你觉得全身燥热不已！\n" NOR );
                msg = me->query("gender") == "男性" ? 
                        "头颈赤红发热，赤红的一双眼睛充满了欲望，那眼光象要把你扒光。\n" 
                        : "娇喘微微，面上泛出一层桃花般淡淡的红色，春情难禁，眼中媚波流动，似乎要滴出水来。\n" ;
                message("vision", "只见" + me->name() + msg, environment(me), me);
   }
        me->receive_wound("qi", dam_kee);
    me->receive_wound("jing", dam_gin);
    me->receive_wound("jing", dam_sen);
        me->apply_condition("hehe", duration - 1);

      me->start_busy(2);
   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}
