// by sinb

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        int i;
        string msg;
        
        if (me->query_condition("killer") &&
            environment(me)->query("no_fight")) 
        {
                tell_object(me, HIR "你发现你的明玉功好象受到限制，气血未能自动恢复！\n" NOR );
        }
        else
        {
                tell_object(me, HIR "你的明玉功发挥了奇效，感觉损失的气血在慢慢恢复！\n" NOR );
                message_vision(HIW "$N眼睛中射出异样光芒，身上的伤口奇迹般地愈合了。\n" NOR, me);
        
                me->set("eff_qi", me->query("max_qi"));     
                me->set("qi", me->query("eff_qi"));
                me->add("neili", -100);     
        }
        
        me->apply_condition("mingyu_qizu", duration - 1);
        
        if( duration < 1 ) 
        {
                me->delete_temp("qizu");
                message_vision(HIC "$N的「气足」奇功运行完毕，脸色顿时一片苍白。\n" NOR, me);

                return 0;
        }
        return CND_CONTINUE;
}

