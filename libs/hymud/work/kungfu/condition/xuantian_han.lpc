// ill_fashao.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

string name() { return "xuantian_han"; }

int min_qi_needed() { return 10; }

int update_condition(object me, int duration)
{
        if( duration < 1 ) return 0;

 message("vision", me->name() + "痛苦的呻吟了一声，脸上竟笼罩了一股薄薄的寒霜。。\n"NOR, environment(me), me);
                tell_object(me, HIB "忽然一阵寒气自丹田的而起，逐步渗透到四"
               "肢白赅，透出阵阵寒意。。\n" NOR );

if ((int)me->query("qi") < 100000)
{
        me->receive_wound("qi", me->query("qi")/8);
        me->receive_damage("qi", me->query("qi")/9);
}else    me->receive_wound("qi", 2000);
        if (!me->is_busy())
        me->start_busy(3);
        me->apply_condition(name(), duration - 1);

        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}
