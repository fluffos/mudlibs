// enforce.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int pts;

	if( !arg || (arg!="none" && !sscanf(arg, "%d", pts) && arg!="max") )
        	return notify_fail("指令格式：enforce <使出几成内力伤敌>|none|max\n");
	if( !me->query_skill_mapped("force") )
        	return notify_fail("你必须先 enable 一种内功。\n");
	if( arg=="none" )
        	pts = 0;
        if ( arg=="max" )
                pts = ((int)me->query_maxforce()/20+1);   
	if( pts < 0 || pts > ((int)me->query_maxforce()/20+1) )
		return notify_fail("你只能用 none 表示不运内力，或数字表示每一击用几点内力。\n");
	if( me->query("force_factor")==pts )
		return notify_fail("你目前内术加力已经是这么多了。\n");  
        me->set("force_factor", pts);
	write("Ok.\n");
	return 1;
}

int help (object me)
{
        write(@HELP
指令格式: enforce|jiali <使出几点内力伤敌>|none|max
 
这个指令让你指定每次击中敌人时，要发出几点内力伤敌。
enforce none 则表示你不使用内力。 
enforce max  则表示你发出所能的最大值。

相关指令: enable, enchant
HELP
        );
return 1;
}

