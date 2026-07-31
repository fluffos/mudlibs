// imbue.c

#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string item, imbue;
	object obj, dest;

	if (! arg)
		return notify_fail("你要往什么道具上浸入其他物品？\n");

	//if (!wizardp(me)) return notify_fail("功能更新测试中，稍后开放！\n");

	if (me->is_busy())
		return notify_fail("先忙完了你的事情再做这件事情吧！\n");

	if (me->is_fighting())
		return notify_fail("你现在正在打架，没时间做这些事情。\n");

	if (! objectp(obj = present(arg, me)))
		return notify_fail("你身上没有这样东西可以用来浸入。\n");

	notify_fail(obj->name() + "无法浸透！\n");
	return obj->do_imbue(me);
}

int help(object me)
{
write(@HELP
指令格式 : imbue <道具>

这个指令可以让你将某样特殊物品浸入另外一种道具中，以锻炼那种
道具或是发挥它的威力。
HELP
    );
    return 1;
}
