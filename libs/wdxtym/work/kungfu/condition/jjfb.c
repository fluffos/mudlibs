// mj_tasting.c

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
	if (duration < 1)
	{
		tell_object(me, HIY "副本空间已摧毁,请您及时返回安全区。\n" NOR);
//        me->move("d/city/guangchang");
        return 0;
	}

	if (!duration) return 0;
	me->apply_condition("jjfb", duration - 1);
	return 1;
}

string query_type(object me)
{
	return "job";
}
