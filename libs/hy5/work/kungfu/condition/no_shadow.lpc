// yufeng_poison.c 玉蜂针毒
// By Kayin @ CuteRabbit Studio 1999/3/23 new

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        me->receive_wound("qi", 7);
        me->receive_damage("jing", 10);
        me->apply_condition("no_shadow", duration - 1);
        if( duration < 1 )
        tell_object(me, HIW "你中的" HIC "无影毒" HIW "终于清除了！\n" NOR );
        else
        tell_object(me, HIW "你中的" HIC "无影毒" HIW "发作了！\n" NOR );
      me->receive_wound("qi",55 + random(100));
      me->receive_wound("jing", 50);
      me->apply_condition("no_shadow", duration - 1);
      me->start_busy(2);
   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}


