// put.c

#include <config.h>

inherit F_CLEAN_UP;

int do_put(object me, object obj, object dest);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string target, item, where, tmp;
	object obj, dest, *inv, obj2;
	int i, amount;

	if (! arg) return notify_fail("你要将什么东西放进哪里？\n");

	if (! wizardp(me)) return notify_fail("命令已被屏蔽！\n");

	if (sscanf(arg, "%s in %s", item, target) != 2)
		return notify_fail("你要放什么东西？\n");
	 if (sscanf(target,"%s of %s",tmp,where) == 2)
	 {
		target = tmp;
	 }
	 else
	{
		where = "all";
	}
	 if(where != "me" && where != "here")
	 {
		dest = present(target, me);
	       if (! dest || living(dest)) dest = present(target, environment(me));
	 }else
	 if(where == "me")
	{
		dest = present(target, me);
	       if (! dest || living(dest))
			return notify_fail("你身上没有" + target + "这样东西？\n");		
	}else
	     dest = present(target, environment(me));

	 if(dest == me) return notify_fail("不是已经在你身上了吗？\n");

	if (! dest || living(dest))
		return notify_fail("这里没有" + target + "这样东西。\n");

	if (dest->query("no_get_from"))
		return notify_fail("还是不要打扰人家了。\n");

	if (sscanf(item, "%d %s", amount, item) == 2)
	{
		if (! objectp(obj = present(item, me)))
			return notify_fail("你身上没有这样东西。\n");

		if (! obj->query_amount())
			return notify_fail( obj->name() + "不能被分开。\n");

		if (amount < 1)
			return notify_fail("东西的数量至少是一个。\n");

		if (amount > obj->query_amount())
			return notify_fail("你没有那么多的" + obj->name() + "。\n");
		else
		if (amount == (int) obj->query_amount())
			return do_put(me, obj, dest);
		else
		{
			obj->set_amount((int) obj->query_amount() - amount);
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			if (do_put(me, obj2, dest))
				return 1;
			if (obj2)
			{
				obj->add_amount(amount);
				destruct(obj2);
			}
			return 0;
		}
	}

	if (item == "all")
	{
		inv = all_inventory(me);
		for (i = 0; i < sizeof(inv); i++)
			if (inv[i] != dest)
				do_put(me, inv[i], dest);
		write("Ok.\n");
		return 1;
	}

	if (! objectp(obj = present(item, me)))
		return notify_fail("你身上没有这样东西。\n");
	return do_put(me, obj, dest);
}

int do_put(object me, object obj, object dest)
{
	mixed msg;

	if (! dest->is_container() && ! dest->is_character())
		return notify_fail(dest->name() + "不是容器。你不能把东西放进去。\n");

	if (dest->is_character() &&
	    sizeof(filter_array(all_inventory(dest), (: ! $1->query("equipped") :))) >= MAX_ITEM_CARRIED)
	{
		return notify_fail(dest->name() + "里面的东西实在"
			    "是太多了，你没法再放东西了。\n");
	} else
	if (dest->is_container() && sizeof(all_inventory(dest)) >= MAX_ITEM_CARRIED)
		return notify_fail(dest->name() + "里面的东西实在"
			    "是太多了，你先好好整理整理吧。\n");

	if (! undefinedp(msg = obj->query("no_put")))
	{
		if (! stringp(msg))
			msg = "这个东西不要乱放。\n";
		return notify_fail(msg);
	}
	if (obj->query("yuanbao"))
		return notify_fail("对不起，这个道具无法放进容器。\n");
	if (obj->is_corpse())
		return notify_fail("你无法把" + obj->name() + "塞进去。\n");

	if (playerp(obj))
		return notify_fail("你无法把" + obj->name() + "塞进去。\n");

	if (obj == dest)
		return notify_fail("嗯... 自己套自己，你的想法比较有趣。\n");

	if (obj->move(dest))
	{
		message_vision(sprintf("$N将一%s%s放进%s。\n",
			       obj->query("unit"), obj->name(),
			       dest->name()), me);
		return 1;
	}

	return 0;
}

int help(object me)
{
	write(@HELP
指令格式 : put <物品名称> in <某容器>
 
这个指令可以让你将某样物品放进一个容器，当然，首先你要拥有这样物品。
 
HELP );
	return 1;
}
