// zhaichu.c

#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object obj, item;

	if (! arg)
		return notify_fail("你要摘除什么道具上的镶嵌物品？\n");

	if (me->is_busy())
		return notify_fail("先忙完了你的事情再做这件事情吧！\n");

	if (me->is_fighting())
		return notify_fail("你现在正在打架，没时间做这些事情！\n");

	if (sscanf(arg,"%s yes",arg)!=1)
	{
		if (! objectp(obj = present(arg, me)))
			return notify_fail("你身上没有这件装备。\n");

		if (! obj->is_item_make() || !obj->query("magic/tessera"))
			return notify_fail("你要摘除什么东西？\n");

		write(ZJOBLONG"你确定要摘除"+obj->short()+"上镶嵌的"+obj->query("magic/tessera")+"吗？"ZJBR
			"摘除宝石需要消耗"+obj->query("magic/power")+"金币存款，宝石摘除后会碎掉不可恢复，请慎重操作！\n"
			ZJOBACTS2+ZJMENUF(3,3,10,30)+"确定:zhaichu "+arg+" yes"ZJSEP"取消:shake\n");
		return 1;
	}

	if (! objectp(obj = present(arg, me)))
		return notify_fail("你身上没有这件装备。\n");

	if (! obj->is_item_make() || !obj->query("magic/tessera"))
		return notify_fail("你要摘除什么东西？\n");

	if (me->query("balance") < obj->query("magic/power")*10000)
		return notify_fail("你钱庄存款不足，不能进行宝石摘除！\n");

	me->add("balance",-obj->query("magic/power")*10000);
	write("你将"+obj->short()+"上镶嵌的"+obj->query("magic/tessera")+"摘除了下来。\n"+obj->query("magic/tessera")+"化作了粉末被风吹散了。\n");
	obj->delete("magic/power");
	obj->delete("magic/type");
	obj->delete("magic/tessera");
	obj->save();
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : zhaichu <道具>

这个指令可以让你将某样装备上镶嵌的宝石摘除下来，以便重新镶嵌。
HELP
    );
    return 1;
}
