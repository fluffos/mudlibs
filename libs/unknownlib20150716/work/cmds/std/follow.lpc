// follow.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;

	if( !arg ) 
		return notify_fail("指令格式：follow <某人>|none。\n");
	if( arg=="none")
	{
		if( me->query_follow() ) 
		{
			if( me->set_follow(0) );
				return 1;
			return notify_fail("取消跟随失败。\n");	
		} 
		else 	return notify_fail("你现在并没有跟随任何人。\n");
	}	
	if( !objectp(ob = present(arg, environment(me))) )
		return notify_fail("这里没有 " + arg + "。\n");
	if( !ob->is_character() )
		return notify_fail("什么？跟随...." + ob->name() + "？\n");
	if( ob==me )
		return notify_fail("跟随自己？\n");
	if( me->set_follow(ob) )
		return 1;
	return notify_fail("跟随失败。\n");
}

int help (object me)
{
        write(@HELP
指令格式 : follow|gen [<生物>|none]
 
这个指令让你能跟随某人或生物。
如果输入 follow none 则停止跟随。
 
HELP
);
        return 1;
}
