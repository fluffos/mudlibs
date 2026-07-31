// enchase.c

#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string item, tessera;
	object obj, dest;

	if (! arg)
		return notify_fail("你要强化什么装备？\n");

	if (me->is_busy())
		return notify_fail("先忙完了你的事情再做这件事情吧！\n");

	if (me->is_fighting())
		return notify_fail("你现在正在打架，没时间做这些事情。\n");

	if (sscanf(arg, "%s with %s", item, tessera) != 2 && sscanf(arg, "%s in %s", tessera, item) != 2)
		return notify_fail("你要用什么东西强化什么装备？\n");

	if (! objectp(obj = present(tessera, me)))
		return notify_fail("你身上没有这样东西可以用来强化。\n");

	if (! obj->query("item_exp"))
		return notify_fail("你选用的道具不能用来强化装备。\n");

	if (! objectp(dest = present(item, me)))
		return notify_fail("你身上没有这样装备。\n");

	if (dest->query("equipped"))
		return notify_fail("先取下装备才能强化。\n");

	notify_fail("你无法用" + obj->name() + "强化" + dest->name() + "。\n");
	return dest->do_enhance(me, obj);
}

int help(object me)
{
write(@HELP
指令格式 : enhance <特殊物品> with <道具>

这个指令可以让你用某样特殊物品强化装备，使得装备成长。
HELP
    );
    return 1;
}
