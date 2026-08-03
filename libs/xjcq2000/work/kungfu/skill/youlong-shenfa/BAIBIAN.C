// baibian.c 神行百变
// 19990815001

#include <ansi.h>

void remo(object me,int count);

int perform(object me)
{
        string msg;
        int improve;

        if( !me->is_fighting() )
                return notify_fail("「神行百变」只能在战斗时使用！\n");

        if((int)me->query_skill("dodge")< 200 )
                return notify_fail("你的游龙身法还不够熟练，不能使用「神行百变」！\n");

        if (me->query_skill_mapped("dodge") != "youlong-shenfa")
                return notify_fail("只有施展游龙身法时才能使用「神行百变」！\n");

        if( (int)me->query_skill("dulong-dafa", 1) < 120 )
                return notify_fail("你的毒龙大法功力不足，不能用「神行百变」。\n");

        if((int)me->query("jingli", 1)<150)
                return notify_fail("你现在精力不足，不能使用「神行百变」！\n");       

        if((int)me->query("neili", 1) < 600) 
                return notify_fail("你现在内力不足，不能再次使用「神行百变」！\n");      

            if( me->query_temp("sxbb",1))
                return notify_fail("你正在使用「神行百变」呢！\n");

        msg = HIY "\n$N忽然猛一提气，身法立刻迅捷了数倍！\n"NOR; 
        message_vision(msg, me);
        me->add("jingli",-100);
        me->add("neili",-( 200+random(200)));
        improve = (int)me->query_dex();
        me->add_temp("apply/dodge", improve);
        me->set_temp("sxbb", improve);
        call_out("remo",1, me, me->query("neili")/200+2);
        me->start_perform(2,"神行百变");
        return 1;       
}

void remo(object me,int count)
{
        int i;
        if( !me ) return;
        if(!me->is_fighting()
         || count < 1){
          i = me->query_temp("sxbb");
          me->add_temp("apply/dodge", - i);
          me->delete_temp("sxbb");
          tell_object(me, HIW"你身形一顿，身法慢慢地缓慢了下来。\n"NOR);
          tell_room(environment(me), HIW + me->name()+"身形一顿，身法慢慢地缓慢了下来。\n"NOR,  ({ me })); 
          return;
        }
        call_out("remo", 1 , me ,count -1);
}
