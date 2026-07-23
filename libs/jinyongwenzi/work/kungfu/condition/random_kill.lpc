// random_kill

#include <login.h>

int update_condition(object me, int duration)
{
	if (duration < 1) return 0;
	me->apply_condition("random_kill", duration - 1);
	return 1;
}

string query_type(object me)
{
	return "random_kill";
}
