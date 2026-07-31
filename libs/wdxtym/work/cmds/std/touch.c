// touch.c

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object obj;
	string obj_id;
	object *obj_list;

	if (! arg)
		return notify_fail("你要触摸什么物品？\n");
	if (! wizardp(me)) return notify_fail("你灵感一现，却又抓不住是什么！\n");
	if (sscanf(arg, "my %s", obj_id))
	{
		obj_list = all_inventory(me);

		if (! obj_list)
			obj_list = all_inventory(environment(me));
		else obj_list += all_inventory(environment(me));
		
		foreach (obj in obj_list)
		{
			if (obj->query("id") == obj_id &&
			    obj->query("owner/" + me->query("id")))
			{
				if (obj->is_character())
					return notify_fail("你别乱动" + obj->name() + "了。\n");
	
				notify_fail("你摸了一下" + obj->name() + "。\n");
				return obj->do_touch(me);
			}
		}
		return notify_fail("这里没有你的东西。\n");
	}

	if (! objectp(obj = present(arg, me)) &&
	    ! objectp(obj = present(arg, environment(me))))
		return notify_fail("你身上没有这样东西，附近也没有。\n");

	if (obj->is_character())
		return notify_fail("你别乱动" + obj->name() + "了。\n");

	notify_fail("你摸了一下" + obj->name() + "。\n");
	return obj->do_touch(me);
}

int help(object me)
{
	write(@HELP
指令格式 : touch [my] <物品名称>
 
这个指令可以让你抚摸某样东西，尝试发挥它的特殊能力。
如果增加了 my 选项，则将在你所在的房间和你身上搜索
你自己的物品。
 
HELP );
	return 1;
}
