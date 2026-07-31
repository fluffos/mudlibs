// put.c
//星星lywin 2000/6/14日修正bug

inherit F_CLEAN_UP;

int do_put(object me, object obj, object dest);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string target, item;
	object obj, dest, *inv, obj2;
	int i, amount;

	if(!arg) return notify_fail("你要将什么东西放进哪里？\n");

	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成！\n");
		

	if( sscanf(arg, "%s in %s", item, target)!=2 )
		return notify_fail("你要给谁什么东西？\n");

	dest = present(target, me);
	if( !dest || living(dest) ) dest = present(target, environment(me));
	if( !dest || living(dest) )
		return notify_fail("这里没有这样东西。\n");

	if(sscanf(item, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )
			return notify_fail("你身上没有这样东西。\n");


	        if (obj==dest )
			return notify_fail("自己放进自己?\n");
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "不能被分开。\n");
         	if( obj->query("dynamic_quest") )
			return notify_fail("这个东西不能放?\n");
         	if( obj->query("no_put") )
			return notify_fail("这个东西不能放?\n");

                if( obj->query("weapon_prop") && me->is_exert() &&
                        obj == me->query_temp("weapon"))
                if( obj->query("weapon_prop") && me->is_perform() &&
                        obj == me->query_temp("weapon"))
                               return notify_fail("你正在使用"+me->query_perform()+"，无法给出"+obj->name()+"。\n");
		if( amount < 1 )
			return notify_fail("东西的数量至少是一个。\n");
		if( amount > obj->query_amount() )
			return notify_fail("你没有那么多的" + obj->name() + "。\n");
		else if( amount == (int)obj->query_amount() )
			return do_put(me, obj, dest);
		else {
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			return do_put(me, obj2, dest);
		}
	}

	if(item=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
			if( inv[i] != dest ) do_put(me, inv[i], dest);
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(item, me)))
		return notify_fail("你身上没有这样东西。\n");
if (!obj) 		return notify_fail("你身上没有这样东西。\n");
if (!me) 		return notify_fail("你身上没有这样东西。\n");
	        if (obj==dest )
			return notify_fail("自己放进自己?\n");

//	        if (obj->is_container() )
//			return notify_fail("容器不能再放进容器。\n");
//	        if (dest->is_container() )
//			return notify_fail("容器不能再放进容器。\n");

	return do_put(me, obj, dest);
}

int do_put(object me, object obj, object dest)
{
	if (!dest->is_container() )
	{
		tell_object(me, dest->name()+"不是容器。你不能把东西放进去。\n");
		return 1;
	}
        if (dest->is_character() &&
            sizeof(filter_array(all_inventory(dest), (: ! $1->query("equipped") :))) >= 30)
        {
                tell_object(me, dest->name() + "里面的东西实在"
                            "是太多了，你没法再放东西了。\n");
                return 1;
        } else
        if (dest->is_container() && sizeof(all_inventory(dest)) >= 30)
        {
                tell_object(me, dest->name() + "里面的东西实在"
                            "是太多了，你先好好整理整理吧。\n");
                return 1;
        }

        if( obj->query("winner") )
	{
		tell_object(me, "你不能把"+obj->name()+"放进去。\n");
		return 1;
	}
	if( obj->query("no_get") )
	{
		tell_object(me, "你不能把"+obj->name()+"放进去。\n");
		return 1;
	}

	if( obj->query("dynamic_quest") )
	{
		tell_object(me, "你不能把"+obj->name()+"放进去。\n");
		return 1;
	}

	if( obj->query("no_put") )
	{
		tell_object(me, "你不能把"+obj->name()+"放进去。\n");
		return 1;
	}
	if( obj->query("id") == "corpse" )
	{
		tell_object(me, "你不能把"+obj->name()+"塞进去。\n");
		return 1;
	}
        if(obj->is_character())
	{
		tell_object(me, "你不能把"+obj->name()+"塞进去。\n");
		return 1;
	}

	if( userp(obj) )
	{
		tell_object(me, "你不能把"+obj->name()+"塞进去。\n");
		return 1;
	}
        if( obj->query("weapon_prop") && me->is_exert() &&
            obj == me->query_temp("weapon"))
                 return notify_fail("你正在使用"+me->query_exert()+"，无法给出"+obj->name()+"。\n");
        if( obj->query("weapon_prop") && me->is_perform() &&
            obj == me->query_temp("weapon"))
                 return notify_fail("你正在使用"+me->query_perform()+"，无法给出"+obj->name()+"。\n");

	if( obj->move(dest) ) {
		message_vision( sprintf("$N将一%s%s放进%s。\n",
			obj->query("unit"), obj->name(), dest->name()),
			me );
		me->save();
		return 1;
	}
	else return 0;
}

int help(object me)
{
write(@HELP
指令格式 : put <物品名称> in <某容器>
 
这个指令可以让你将某样物品放进一个容器，当然，首先你要拥有这样物品。
 
HELP
    );
    return 1;
}
