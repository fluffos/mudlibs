// use.c

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	int count;
	string from;
	object from_ob;
	object ob;
	object *guard;
	int search_flag;
	string prefix;
	int k,need_busy;

	if (! arg)
		return notify_fail("你要使用什么东西？\n");

	prefix = "";
	need_busy = 0;
	if (sscanf(arg, "%s in %s", arg, from) == 2)
	{
		// 检查容容具
		if (sscanf(from, "all %s", from))
		{
			if (me->is_busy())
				return notify_fail("你忙着呢，没有功夫找东西。\n");

			search_flag = 0;
			foreach (from_ob in all_inventory(me))
			{
				if (! from_ob->id(from))
					continue;

				if (from_ob->is_character())
					continue;

				if (! present(arg, from_ob))
					continue;

				search_flag = 1;
				break;
			}

			if (! search_flag)
			{
				me->start_busy(2);
				return notify_fail("你翻遍了身上带的东西，也没找到想要的。\n");
			} else
				need_busy = 3;
		} else
		if (! objectp(from_ob = present(from, me)))
		{
			from_ob = present(from, environment(me));
			if (me->query("env/careful"))
			{
				if (! objectp(from_ob))
					return notify_fail("你身上没有这个容具。\n");
				else
					return notify_fail("你身上没有这样容具，附近的" +
							   from_ob->name() + "你又不敢动。\n");
			}
	
			if (! objectp(from_ob))
				return notify_fail("你身上没有这样容具，附近也没有。\n");
		}

		if (from_ob->is_character() && from_ob != me)
			return notify_fail("你要抢劫啊？\n");
		else
		if (sizeof(all_inventory(from_ob)) < 1)
			return notify_fail(from_ob->name() + "里面什么都没有啊。\n");

		prefix = "从" + from_ob->name() + "中";
	} else
		from_ob = me;

	if (! objectp(ob = present(arg, from_ob)))
	{
		ob = present(arg, environment(me));
		if (me->query("env/careful"))
		{
			if (! objectp(ob))
				return notify_fail("你身上没有这样东西。\n");
			else
				return notify_fail("你身上没有这样东西，附近的" +
						   ob->name() + "你又不敢动。\n");
		}

		if (! objectp(ob))
			return notify_fail("你身上没有这样东西，附近也没有。\n");
	}

	if (! undefinedp(count = ob->query_amount()) && count < 1)
		return notify_fail(ob->name() + "已经用完了。\n");

	if (me->is_busy())
	{
		write("你上一个动作还没有完成。\n");
		return 1;
	}

	if (guard = ob->query_temp("guarded"))
	{
		guard = filter_array(guard, (:
			objectp($1) && present($1, environment($(me))) &&
			living($1) && ($1 != $(me)) :));
		if (sizeof(guard))
			return notify_fail(guard[0]->name()
				+ "正守在" + ob->name() + "一旁，防止任何人拿走。\n");
	}

	if (ob->query("only_do_effect"))
	{
		k = ob->do_effect(me);
		if(ob)
			write("你可以继续使用"+ZJURL("cmds:use "+ob->query("id"))+ob->name()+NOR+"。"NOR"\n");
		return k;
	} else
	{
		return notify_fail(ob->name() + "不能这样使用。\n");

	}

	if (! me->is_busy() && need_busy)
		me->start_busy(need_busy);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : use <道具> | <道具> [in [all] <包裹>]
 
这个指令可以让你使用道具。如果你没有设置环境变量 careful，并且
你身上没有带这种食物就会自动在周围的环境寻找你指定的食物。

如果你指明了 in， 那么你将从包裹取出道具使用。倘若你身上没有
指明的包裹并且没有设置环境变量 careful 的话， 就会自动在附近
的环境寻找。

如果你指明了 all，那么你将在身上所有指定的包裹中寻找想要的道具，这需要花费你一些时间。

see also : eat,drink
 
HELP );
	return 1;
}
