// wait_mr_job.c

#include <ansi.h>

int update_condition(object me, int duration)
{
        if (duration < 1) return 0;
        me->apply_condition("wait_mr_job", duration - 1);
        return 1;
}
