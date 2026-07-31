#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string str,nb,*text,short_name,*dk, name;
	int i, index;
	object *inv,store;
/*
	if (!wizardp(me))
	{
		write("暂时封闭储物袋功能。请大家提供BUG原因。管理测试多次未发现问题。\n");
		return 1;
	} */
	if(!objectp(store=present("chuwu dai",me)))
	{
		store = new("/clone/misc/baibao");
		store->move(me);
	}
	if (store->query("owner_id") != me->query("id"))
		store->set("owner_id", me->query("id"));
	if (!arg)
	{
		str = ZJOBLONG+sprintf("请选择查看的类型："+"\n");
		str += ZJOBACTS2+ZJMENUF(3,3,9,30);
		str += "所有物品:mystore 全部 1";
		str += ZJSEP+ "武器类:mystore 武器 1";
		str += ZJSEP+"防具类:mystore 防具 1";
		str += ZJSEP+"其它类:mystore 杂货 1";
		str += ZJSEP+"搜  索:mystore 搜索";
		
		write(str+"\n");
		return 1;
	}
	if (arg == "搜索")
	{
		write(INPUTTXT("请输入搜索的关键字","mystore 名称 $txt# 1")+"\n");
		return 1;
	} else
	if (arg == "全部 1"  || arg == "武器 1" || arg == "防具 1" || arg == "杂货 1")
	{
		store->query_item(arg);
		return 1;
	} else	
	if (arg=="put")
	{
		inv = all_inventory(me);
		if (! sizeof(inv))
		{
			write(ZJOBLONG+HIY"目前你身上没有任何东西。""\n");
			return 1;
		}
		dk = ({});
		for (i = 0; i < sizeof(inv); i++)
		{
			if (inv[i]->query("equipped") ||inv[i]->query("no_put")||inv[i]->query("money_id") || inv[i]->query("id") == "chuwu dai") continue;

			short_name = inv[i]->query("name");
			if(inv[i]->query_amount())
				short_name = inv[i]->query_amount() + inv[i]->query("base_unit") + short_name;

			dk += ({ short_name + ":mystore put " + file_name(inv[i]) });
		}
		text = sort_array(dk, 1);

		str = ZJOBLONG"你想往仓库中存什么东西？"+"\n";
		str += ZJOBACTS2+ZJMENUF(3,3,9,30);
		if (! sizeof(text))
		{
			write(ZJOBLONG+HIY"目前你身上没需要存入仓库的东西。"NOR+"\n");
			return 1;
		}
		str += implode(text, ZJSEP);
		write(str+"\n");
		return 1;
	} else if (sscanf(arg,"名称 %s %d", name, index) == 2)
	{
		store->query_item(arg);
		return 1;
	} else	if (sscanf(arg,"get %s %d", nb, index)==2)
	{
		store->get_item(nb, index);
		return 1;
	} else	if (sscanf(arg,"put %s %d", nb, index)==2)
	{
		store->do_store(nb, index);
		return 1;
	} else if (sscanf(arg,"全部 %d", index) == 1)
	{
		store->query_item(arg);
		return 1;
	} else if (sscanf(arg,"武器 %d", index) == 1)
	{
		store->query_item(arg);
		return 1;
	} else if (sscanf(arg,"防具 %d", index) == 1)
	{
		store->query_item(arg);
		return 1;
	} else if (sscanf(arg,"杂货 %d", index) == 1)
	{
		store->query_item(arg);
		return 1;
	} else if (sscanf(arg,"get %s",nb)==1)
	{
		store->get_item(nb);
		return 1;
	} else if (sscanf(arg,"put %s",nb)==1)
	{
		store->do_store(nb);
		return 1;
	}
	else
		return notify_fail(HIM"你想干什么？？"NOR"\n");

	return 1;
}

int help(object me)
{
     write(@HELP

仓库操作。

HELP
    );
    return 1;
}
