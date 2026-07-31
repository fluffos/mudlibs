// hostage_busy.c
// Created by Numa 19991102

#include <ansi.h>

int update_condition(object me, int duration)
{
        if (duration <= 1){
                me->clear_condition("hostage_busy");
                return 0;
                }
        me->apply_condition("hostage_busy", duration - 1);
        return 1;
}

