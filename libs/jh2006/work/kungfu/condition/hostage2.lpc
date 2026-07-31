// condition hostage_3.c
// Created By Numa@Sj 2000.2.18

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
        if (duration < 1)
        {
                me->delete_temp("hostage");
                me->set_temp("hostage/failed_3");
                me->clear_condition("hostage2");
                tell_object(me,"你的营救人质任务失败了。\n");
                return 0;
        }
        
        if (!duration) return 0;
        
        me->apply_condition("hostage2", duration - 1);
        return 1;
}

