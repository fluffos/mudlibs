// enchase.c

#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string msg, item, tessera;
	object *baoshi,obj, dest;
	int i;

	if (! arg)
		return notify_fail("你要往什么道具上镶嵌物品？\n");

	if (me->is_busy())
		return notify_fail("先忙完了你的事情再做这件事情吧！\n");

	if (me->is_fighting())
		return notify_fail("你现在正在打架，没时间做这些事情。\n");

	if (sscanf(arg, "%s with %s", item, tessera) != 2)
	{
		baoshi = filter_array(all_inventory(me),(:$1->query("can_be_enchased"):));
		if(sizeof(baoshi))
		{
			msg = ZJOBLONG"请选择你要镶嵌的宝石(镶嵌宝石需要消耗与宝石能量对应的金币)：\n"ZJOBACTS2+ZJMENUF(3,3,10,30);
			for(i=0;i<sizeof(baoshi);i++)
			{
				msg += baoshi[i]->query("name")+"("+baoshi[i]->query("magic/power")+"):enchase "+arg+" with "+file_name(baoshi[i]);
				if(i<(sizeof(baoshi)-1)) msg += ZJSEP;
			}
		}
		else
		{
			msg = ZJOBLONG"你身上现在没有宝石，不能进行镶嵌！";
		}
		tell_object(me,msg+"\n");
		return 1;
	}

	if (! objectp(obj = present(tessera, me)))
		return notify_fail("你身上没有这样东西可以用来镶嵌。\n");

	if (! objectp(dest = present(item, me)))
		return notify_fail("你身上没有这样道具。\n");

	notify_fail("你无法把" + obj->name() + "镶嵌到" + dest->name() + "上。\n");
	return dest->do_enchase(me, obj);
}

int help(object me)
{
write(@HELP
指令格式 : enchase <道具> with <特殊物品>

这个指令可以让你将某样特殊物品镶嵌到另外一种道具上，使得道具
具有特殊的能力。
HELP
    );
    return 1;
}
