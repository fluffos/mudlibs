// unset.c

inherit F_CLEAN_UP;

int help();

int main(object me, string arg)
{
	object ob;
	object obj;
		int value;

	if (! (ob = present(arg, me)))
	{
		write("你身上没有这种东西啊！\n");
		return 1;
	}

	//if(me->query("combat_exp")<300000)
			//return notify_fail("江湖险恶，等你行走江湖一段时间有了一定能力再炫耀你的东西吧，不然小心被人盯上！\n");

	if (time() - me->query_temp("last_use_channel") < 10)
	{
		return notify_fail("不要在短期内频繁使用展示频道发布信息。\n");
	} else
	{
		me->set_temp("last_use_channel", time());
	}

	if( !arg||!objectp(obj = present(arg,me)) )
			return notify_fail("你要展示什么？\n");

		value = ob->query("value");
	//if (value < 2)
		//	return notify_fail("这件物品不值钱，展示什么？\n");

	message("channel:bill", "【展示】"+me->query("name")+"：物品展示->"+ZJURL("cmds:look "+arg)+ZJSIZE(22)+filter_color(obj->query("name"))+NOR"。\n", users());
	return 1;
}

int help()
{
	write(@TEXT
指令格式：showitem <物品>
物品展示和查看。

TEXT
	);
	return 1;
}
