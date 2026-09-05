// Code of ShenZhou
// dlkiller.c

//#include <ansi.h>

int update_condition(object me, int duration)
{
	if (duration < 1) {
                tell_object(me, "大理放弃了对你的追杀！\n");
		return 0;
	}
        me->apply_condition("dlkiller", duration - 1);
	return 1;
}

