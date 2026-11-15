// give.c


#include <config.h>

inherit F_CLEAN_UP;

int do_give(object me, object obj, object who);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string str,target, item;
	object obj, who, *inv, obj2;
      string no_accept;
      
	int i, amount;

	if (! arg) return notify_fail("你要给谁什么东西？\n");

	if(who=present(arg,environment(me)))
	{
		inv = all_inventory(me);
		if (!sizeof(inv))
		{
			write(ZJOBLONG"你身上什么都没有，哪来东西给人家？\n");
			return 1;
		}
		write(ZJOBLONG"请选择你要给予"+who->short()+"的物品：\n");
		str = ZJOBACTS2+ZJMENUF(2,2,8,30);
		for (i = 0; i < sizeof(inv); i++)
		{
			if (!inv[i]->query("equipped"))
			{
				if(inv[i]->query_amount())
					str += inv[i]->query_amount()+inv[i]->query("base_unit")+inv[i]->query("name")+ZJBR+inv[i]->query("id")+":give "+ inv[i]->query("id")+" to "+arg + ZJSEP;
				else
					str += inv[i]->query("name")+ZJBR+inv[i]->query("id")+":give "+ inv[i]->query("id")+" to "+arg + ZJSEP;
			}
		}
		write(str+"\n");
		return 1;
	}
	else if (sscanf(arg, "%s to %s", item, target) == 2 || sscanf(arg, "%s %s", target, item) == 2 );
	else return notify_fail("你要给谁什么东西？\n");

	if (! objectp(who = present(target, environment(me))))
	{
		string ext;

		if (sscanf(arg, "%s %s %s", ext, target, item) != 3 || ! objectp(who = present(ext + " " + target, environment(me))))
			return notify_fail("这里没有这个人。\n");
	}

	if (me == who) return notify_fail("毛病！你自己给自己东西干吗？\n");
	if (! living(who))
		return notify_fail("你还是得等人家醒了再说吧。\n");

	if (playerp(me) && wiz_level(me) < wiz_level("(wizard)") && stringp(no_accept = who->query("env/no_accept")))
	{
		if ((no_accept == "all" || no_accept == "ALL" ||  is_sub(me->query("id"), no_accept)) && ! is_sub(me->query("id"), who->query("env/can_accept")))
		{
			return notify_fail("人家现在不想要什么东西。\n");
		}
	}

	if (sscanf(item, "%d %s", amount, item) == 2)
	{
		if (! objectp(obj = present(item, me)))
			return notify_fail("你身上没有这样东西。\n");

		if (me->query_temp("is_riding") == obj)
			return notify_fail("你正骑着它呢。\n");

		if (! obj->query_amount())
			return notify_fail( obj->name() + "不能被分开给人。\n");

		if (amount < 1)
			return notify_fail("东西的数量至少是一个。\n");

		if (amount > obj->query_amount() )
			return notify_fail("你没有那么多的" + obj->name() + "。\n");

		else if (amount == (int)obj->query_amount())
		{
			do_give(me, obj, who);
			return 1;
		} else
		{
			obj->set_amount((int)obj->query_amount() - amount);
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			if (do_give(me, obj2, who))
				return 1;
			else
			if (obj2)
			{
				obj->set_amount((int)obj->query_amount() + amount);
				destruct(obj2);
				return 1;
			}
		}
	}

	if (item == "all")
	{
		inv = all_inventory(me);
		for (amount = 0, i = 0; i < sizeof(inv); i++)
		{
			if (! living(me)) break;
			if (environment(me) != environment(who)) break;
			if (objectp(inv[i]) &&
			    me->query_temp("is_riding") != inv[i])
				amount += do_give(me, inv[i], who);
		}
		if (! amount)
		{
			write("你什么都没有给出去。\n");
			return 1;
		}

		write("给完了。\n");
		return 1;
	}

	if (! objectp(obj = present(item, me)))
		return notify_fail("你身上没有这样东西。\n");

	if(obj->query_amount())
	{
		write(INPUTTXT("你共有"+obj->short()+"，你想给"+who->query("name")+"多少？","give $txt# "+obj->query("id")+" to "+who->query("id"))+"\n");
		return 1;
	}
	if (me->query_temp("is_riding") == obj)
		return notify_fail("你正骑着它呢。\n");

	do_give(me, obj, who);
	return 1;
}

int do_give(object me, object obj, object who)
{

	if (me->query("id") !="mo ye" && who->query("id") != "mo ye")
	{
		if (wiz_level(me) < 3 && obj->query("no_drop"))
		{
			tell_object(me, "这样东西不能随便给人。\n");
			return 0;
		}
		if (wiz_level(me) < 3 && obj->query("no_give"))
		{
			tell_object(me, "这样东西不能随便给人。\n");
			return 0;
		}
	}
	else
	{
		if (playerp(me))
		{
			tell_object(me, "莫邪允许接收绑定的材料。\n");
		}

		if (playerp(who))
		{
			tell_object(me, "莫邪返回了你的材料。\n");
			return 0;
		}
	}

	if (living(obj))
	{
		tell_object(me, "天哪！你怎么连活人生意也做？\n");
		return 0;
	}


	if (playerp(who) &&
	    sizeof(filter_array(all_inventory(who), (: ! $1->query("equipped") :))) >= MAX_ITEM_CARRIED &&
	    ! obj->can_combine_to(who))
	{
		tell_object(me, "人家身上的东西实在是太多了，没法再拿东西了。\n");
		return 0;
	}

	switch ((string)obj->query("equipped"))
	{
	case "worn":
		tell_object(me, obj->name() + "必须脱下来才能给别人。\n");
		return 0;

	case "wielded":
		tell_object(me, obj->name() + "必须解除装备才能给别人。\n");
		return 0;
	}
		
	message_vision("$N拿出" + obj->short() + "给$n。\n", me, who);
	
	if (playerp(who))
		log_file("action/give", sprintf("%s，%s(%s)给%s(%s)%s。\n",ctime(time()),me->query("name"),me->query("id"),who->query("name"),who->query("id"),obj->short()));
	
	if (! playerp(who))
	{
		function f;
		int r;

		// 接受物品的时候首先判断是否有重载的接收函数
		f = who->query_temp("override/accept_object", 1);
		if (functionp(f))
			r = (*f)(who, me, obj);
		else
			r = 0;

		if (! r)
			// 重载的函数不接受，也不处理(返回-1)
			// 那么就调用accept_object进行处理
			r = who->accept_object(me, obj);

		if (! objectp(who)) return 0;
		switch (r)
		{
		case 0:
			message_vision("$n不肯要$N的" + obj->name() + "。\n", me, who);
			return 0;
		case -1:
			// The receiver will handle all the things
			if (! obj || environment(obj) == who)
				return 1;
			return 0;
		default:
			break;
		}
		if (! objectp(obj))
			// The receive has destructted the object
			return 1;
	}

	if (! playerp(who) && obj->value())
	{
		message_vision("$n接过了$N的" + obj->short() + "。\n", me, who);
		destruct(obj);
		return 1;
	}

	if (! obj->move(who))
	{
		message_vision("然而$n没能拿住$N的" + obj->name() + "。\n", me, who);
		return 0;
	}

	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : give <物品名称> | all to <某人>
      或 : give <某人> <物品名称> | all
 
这个指令可以让你将某样物品给别人，当然，首先你要拥有这样物品。
 
HELP );
	return 1;
}