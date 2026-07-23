// gf_busy

#include <ansi.h>

int update_condition(object me, int duration)
{
        if (duration < 1) return 0;
        me->apply_condition("marks_bed", duration - 1);
        return 1;
}
string query_type(object me)
{
	return "marks_bed";
}