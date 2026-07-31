// combine.c

#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object obj,target,*obs;
	int i,num,need;
	string item;
	mapping *needs;

	if (!arg)
		return notify_fail("你要合并什么物品？\n");



	if(sscanf(arg,"%s %d",item,num)!=2)
	{
		if (!objectp(obj=present(arg,me)))
			return notify_fail("你要合并什么物品？\n");

		message_vision(HIM "$N" HIM "将一些"+obj->query("name")+"摆在一起，默运神通使它们变化。"NOR"\n", me);
		me->start_busy(1);

		if(obj->query("can_be_enchased")&&arrayp(needs=obj->query("enchased_need")))
		{
			obs = ({});
			for(i=0;i<sizeof(needs);i++)
			{
				if(!objectp(present(needs[i]["id"],me)))
					return notify_fail("你身上缺少合成更高级物品所必须的"+needs[i]["name"]+"。\n");
				obs += ({ present(needs[i]["id"],me) });
			}
			if (me->query("max_jingli") < 6000)
			{
				message_vision(HIG "过了半天，似乎没有任何变化，$N" HIG "一脸悻悻。\n", me);
	       			return notify_fail(HIR "你感觉你的精力修为还远远不够，无" HIR "法驾御这几种物品。\n");
			}

			for(i=0;i<sizeof(obs);i++)
			{
				obs[i]->add_amount(-1);
			}
			target = new(obj->query("can_be_enchased"));
			obj->add_amount(-1);
			target->move(me);
			write("恭喜：你获得了一个"+target->query("name")+"。\n");
			if(target->query("id") == "god eyes")
			{
				// 发布消息
   		    		CHANNEL_D->do_channel(this_object(), "rumor","听说" + me->name() + "创造了无上宝石" + target->name() + HIM + "。");
		     		me->add("max_jingli", -5000);
			}

			return 1;
		}

		if(!obj->query("can_be_enchased")||!(need=obj->query("enchased_need"))||!obj->query_amount())
			return notify_fail(obj->query("name")+"不能融合生成高级物品！\n");

		if(need>obj->query_amount())
			return notify_fail("至少要"+need+obj->query("base_unit")+obj->query("name")+"才能融合成一个高级物品！\n");

		write(INPUTTXT("你想生成多少个"+(obj->query("can_be_enchased"))->query("name")+"？"ZJBR
			"你最多可以输入："+obj->query_amount()/need,"combine "+arg+" $txt#\n"));
		return 1;
	}

	if (!objectp(obj=present(item,me)))
		return notify_fail("你要合并什么物品？\n");

	if(!obj->query("can_be_enchased")||!(need=obj->query("enchased_need"))||!obj->query_amount())
		return notify_fail(obj->query("name")+"不能融合生成高级物品！\n");

	if(need>obj->query_amount())
		return notify_fail("至少要"+need+obj->query("base_unit")+obj->query("name")+"才能融合成一个高级物品！\n");

	if(num<1||(num*need)>obj->query_amount())
		return notify_fail("你融合不出那么多的"+(obj->query("can_be_enchased"))->query("name")+"！\n");

	if (me->is_busy())
		return notify_fail("先忙完了你的事情再做这件事情吧！\n");

	if (me->is_fighting())
		return notify_fail("你现在正在打架，没时间做这些事情。\n");

	if (me->query("max_jingli") < (100*num+300))
		return notify_fail("你现在的精力修为有限，无法施展如此艰深的法力。\n");

	if (me->query("jingli") < (200*num+300))
		return notify_fail("你现在精力不济，无法施展法力。\n");

	//message_vision(HIM "$N" HIM "将一些"+obj->query("name")+"摆在一起，默运神通使它们变化。"NOR"\n", me);
	//me->start_busy(1);

	me->add("jingli", -200*num);
	me->add("max_jingli", -100*num);
	target = new(obj->query("can_be_enchased"));
	target->set_amount(num);
	obj->add_amount(-num*need);
	target->move(me);
	message_vision(HIW "数道光芒闪过，似乎发生了不同寻常的事情。"NOR"\n", me);   
	write("恭喜：你获得了"+num+"个"+target->query("name")+"。\n");

	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : combinue

这个指令可以让你将某些特殊物品合并成一种新的物品，哪些才能合
并？这就要靠你去发掘了。每次合并都会损失一些精力的上限。如果
要合并的几个物品名字相同，则需要指明他们的序号，比如有三个钻
石碎片，如果要合一，则需要输入：

HELP
    );
    return 1;
}
