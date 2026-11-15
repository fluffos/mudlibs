// unset.c

inherit F_CLEAN_UP;

int help();

int main(object me, string arg)
{
	object obj;

	if(me->is_busy())
			return notify_fail("你现在正忙着呢！\n");

	if (time() - me->query_temp("last_use_channel") < 30)
	{
		return notify_fail("不要在短期内频繁使用展示频道发布信息。\n");
	} else
	{
		me->set_temp("last_use_channel", time());
	}

	if( !arg||!objectp(obj = present(arg,me)) )
			return notify_fail("你要展示什么？\n");

	me->start_busy(1);
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
