// condition hostage_1.c
// Created by Numa 19991027

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
        if (duration < 1)
        {
                me->delete_temp("hostage");
                me->set_temp("hostage/failed_1");
                me->clear_condition("hostage1");
                tell_object(me,"你的营救人质任务失败了。\n");
                return 0;
        }
        
        if (!duration) return 0;
        
        me->apply_condition("hostage1", duration - 1);
        return 1;
}

