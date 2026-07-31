// by Lonely

#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        if (duration < 1) return 0;
        
        me->add("snake_poison/remain", 20);

        me->apply_condition("poison-supply", duration - 1);

        if (duration < 1) return 0;
        return CND_CONTINUE;
}

