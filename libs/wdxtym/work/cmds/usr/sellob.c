#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	object nob;
	string my_id;
	int amount;
	int value;
	int res;
	int max_count;
	mixed ns;

	if (! arg)
		return notify_fail("你要卖什么？\n");

	if (sscanf(arg, "%d %s", amount, arg) != 2)
		amount = 1;

	if (amount < 1)
		return notify_fail("你想干啥？\n");

	if (! (ob = present(arg, me)))
	{
		write("你身上没有这种东西啊！\n");
		return 1;
	}

	max_count = ob->query_amount();
	if (! max_count)
	{
		if (amount > 1)
		{
			write(ob->name() + "这种东西不能拆开来卖。\n");
			return 1;
		}
		max_count = 1;
	} else
	{
		if (amount > max_count)
		{
			write("你身上没有这么多" + ob->name() + "。\n");
			return 1;
		}
	}

	if (ob->query("money_id"))
	{
		write(CYN + "你想卖「钱」？？"NOR"\n");
		return 1;
	}

	if (ob->is_character())
	{
		write(CYN + "这你也要卖？？"NOR"\n");
		return 1;
	}
/*
	if (ob->query("no_drop") || (ns = ob->query("no_sell")))
	{
		if (stringp(ns))
		{
			write(CYN + "系统大神无奈道：" + ns + NOR"\n");
			return 1;
		}
		write(CYN + "这东西不能卖！！"NOR"\n");
		return 1;
	}
*/
	if (ns = ob->query("no_sell"))
	{
		if (stringp(ns))
		{
			write(CYN + "系统大神无奈道：" + ns + NOR"\n");
			return 1;
		}
		write(CYN + "这东西不能卖！！"NOR"\n");
		return 1;
	}
	if (ob->query("food_supply"))
	{
		write(CYN + "剩菜剩饭还是留着自己用吧！！"NOR"\n");
		return 1;
	}
	
	if (ob->query("shaolin"))
	{
		write(CYN + "这是少林庙产，怎么能随便卖？？"NOR"\n"); 
		return 1;
	}

	if (ob->query("mingjiao"))
	{
		write(CYN + "魔教的东西可不能随便卖，很危险的！！"NOR"\n");
		return 1;
	}

	if (max_count > 1)
		value = ob->query("base_value") * amount;
	else
		value = ob->query("value");

	if (ob->query("consistence"))
		value = value * ob->query("consistence") / 100;

	if (value < 2)
		write(CYN + ob->query("name") + "一文不值，直接丢掉吧！！"NOR"\n");
	else
	{
		write("你卖掉了一" + ob->query("unit") +  ob->query("name") + "得到" + MONEY_D->money_str(value*50/100) + "。\n");
	      log_file("pay/sellob", sprintf("%s："+me->query("id")+"卖掉%s获得%s。\n",ctime(time()),ob->query("name"),MONEY_D->money_str(value*50/100) ));
		if (max_count == amount)
			destruct(ob);
		else
			ob->add_amount(-amount);
		MONEY_D->pay_player(me, value * 50 / 100);
	}
	return 1;
}

int help(object me)
{
     write(@HELP
指令格式: sellob <物品id>

随身卖东西。

HELP
    );
    return 1;
}
