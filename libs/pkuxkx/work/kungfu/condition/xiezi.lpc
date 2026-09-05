// xiezi

#include <ansi.h>

int update_condition(object me, int duration)
{
	if (duration < 1) {
		if (me->query("title")==me->query("xiezititle"))
        {
            me->set("title",me->query("old_title"));
            tell_object(me,HIC"你脸上被判官笔写上的墨迹终于变淡。\n"NOR);
        }
		return 0;
	}
	me->apply_condition("xiezi", duration - 1);
	return 1;
}
