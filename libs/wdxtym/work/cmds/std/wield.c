// wield.c

inherit F_CLEAN_UP;

int do_wield(object me, object ob);

int main(object me, string arg)
{
	string name,name1;
	object ob,ob2, *inv;
	int i, count;
name=me->query("weapon/id");
name1="my ";
	if (! arg) return notify_fail("你要装备什么武器？\n");
	if (userp(me) && me->is_busy() )
		return notify_fail("你正忙着呢。\n");

	if (arg == "all")
	{
		inv = all_inventory(me);
		for (count = 0, i = 0; i<sizeof(inv); i++)
		{
			if (inv[i]->query("equipped")) continue;
			if (inv[i]->is_item_make()&&inv[i]->item_owner()!=me->query("id")) continue;
			if (do_wield(me, inv[i])) count ++;
		}
		write("Ok.\n");
		return 1;
	}

	if (! objectp(ob = present(arg, me)))
		return notify_fail("你身上没有这样东西。\n");

//	if (ob->query("id")!=name1+name)
//		return notify_fail("这别人的私有装备装备，你不能使用。\n");

	if (ob->query("equipped"))
	{
		inv = all_inventory(me) - ({ ob });
		for (count = 0, i = 0; i < sizeof(inv); i++)
		{
			if (! inv[i]->id(arg)) continue;
			if (inv[i]->query("equipped")) continue;
			if (do_wield(me, inv[i]))
			{
				count++;
				break;
			}
		}
		if (! count)
			return notify_fail("你已经装备着了。\n");
		return 1;
	}

	if(ob2=me->query_temp("weapon"))
		me->force_me("unwield "+file_name(ob2));
	return do_wield(me, ob);
}

int do_wield(object me, object ob)
{
	string str;
	switch (ob->wield())
	{
	case 0:
		return 0;

	case -1:
		return 1;

	default:
		if (! stringp(str = ob->query("wield_msg")))
			str = "$N装备$n作武器。\n";
//		if (userp(me) && me->is_fighting()) me->start_busy(1);
		message_vision(str, me, ob);
		return 1;
	}
}

int help(object me)
{
	write(@HELP
指令格式：wield <装备名称>
 
这个指令让你装备某件物品作武器, 你必需要拥有这样物品.
 
HELP );
    return 1;
}
