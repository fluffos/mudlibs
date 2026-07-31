//wd_job.c

#include <login.h>
#include <ansi.h>
int update_condition(object me, int duration)
{
        if (duration < 1) {               
me->clear_condition("xs_job");
                }
        if (!duration) return 0;
 me->apply_condition("xs_job", duration - 1);
        return 1;
}

string query_type(object me)
{
        return "job";
}


