// Code of ShenZhou
// killer.c

#include <ansi.h>

int update_condition(object me, int duration)
{
    if (me->query("family/family_name")=="朝廷" && me->query("pin")>=1 && me->query("pin")<3)
    {
        me->apply_condition("cakiller", 0);
        tell_object(me,HIY"鉴于你为朝廷做出的汗马功劳，特赦免罪过一次，以示皇恩浩荡。\n"NOR);
        return 0;
    }
	if (duration < 1) {
                tell_object(me, "长安城的金吾卫停止了对你的追杀！\n");
		return 0;
	}
        me->apply_condition("cakiller", duration - 1);
	return 1;
}
