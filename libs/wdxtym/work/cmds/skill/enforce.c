// enforce.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int pts;

	if( !arg || (arg!="none" && arg!="max" && !sscanf(arg, "%d", pts)) ) 
		return notify_fail(INPUTTXT("你要用多少内力伤敌？","enforce $txt#")+"\n"
					ZJOBACTS2+ZJMENUF(3,3,8,30)+"最大:enforce max"ZJSEP"取消加力:enforce none\n");

	if( !me->query_skill_mapped("force") )
		return notify_fail("你必须先 enable 一种内功。\n");

	if( arg=="none" )
	{
		me->delete("jiali");
		write("Ok，你现在取消了附加内力伤敌。\n");
	}
	else if( arg=="max" )
	{
		if( (pts=(int)me->query_skill("force")/2)<=0 )
			return notify_fail("你内功等级太低了。\n");
		me->set("jiali", pts);
		write("Ok，你现在使用"+pts+"附加点内力伤敌。\n");
	}
	else {
		if( pts < 0 || pts > (int)me->query_skill("force") / 2 )
			return notify_fail("你只能用 none 表示不运内力，或数字表示每一击用几点内力。\n");
		me->set("jiali", pts);
		write("Ok，你现在使用"+arg+"附加点内力伤敌。\n");
	}

	return 1;
}

int help (object me)
{
	write(@HELP
指令格式: enforce|jiali <使出几点内力伤敌>|none
 
这个指令让你指定每次击中敌人时，要发出几点内力伤敌。

enforce none 则表示你不使用内力。 

See Also: enable
HELP );
	return 1;
}
