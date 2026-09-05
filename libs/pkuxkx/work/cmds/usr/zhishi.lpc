// 制作尸体，by Zine，尸体服饰变快后，对应星宿腐蚀毒或者其他一些特定需要尸体的任务
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me,string arg)
{
	object corpse;
	if (me->is_busy())
	return notify_fail("你正忙着呢。\n");
	if (!arg)
	return notify_fail("你要灌注内力进哪里？\n");
	if (!corpse=present(arg,environment(me)))
	return notify_fail("这里并没有"+arg+"。\n");
	if (!corpse->is_corpse())
	return notify_fail(corpse->query("name")+"并不是一具尸体。\n");
	if (corpse->query("re_maked"))
	return notify_fail(corpse->query("name")+"曾经被灌注过内力，再来一次毫无效果。\n");
	if (me->query("neili")<100||me->query("jingli")<100)
	return notify_fail("你此刻精力或者内力不济，无法灌注入尸体。\n");
	me->add("neili",-100);
	me->add("jingli",-100);
	me->add_busy(2);
	message_vision(BLU+"$N将自身精力内力灌注入$n，使其腐败的速度变得缓慢起来。\n"+NOR,me,corpse);
	corpse->re_make();
	return 1;
}
int help()
{
        write(@LONG
指令格式：zhishi corpse 

以内力精力灌注入尸体，使其腐败变慢。
LONG
        );
        return 1;
}
