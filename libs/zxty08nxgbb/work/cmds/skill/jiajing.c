
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int pts;

	if( !arg || (arg!="none" && !sscanf(arg, "%d", pts)) ) 
		return notify_fail("指令格式：enchant <每次使用几成精力>|none");

	if( !me->query_skill_mapped("taoism") )
		return notify_fail("你必须先 enable 一种神通。\n");

	if( arg=="none" )
		me->delete("jiajing");
	else {
		if( pts < 0 || pts > (int)me->query_skill("force") / 2 )
			return notify_fail("你只能用 none 表示不用精力，或数字表示每一击用几点精力。\n");
		me->set("jiajing", pts);
	}

	write("Ok.\n");
	return 1;
}

int help (object me)
{
        write(@HELP
指令格式: enchant <使用几点精力>|none
 
enchant none 则表示你不使用精力。 

See Also: enable
HELP
        );
        return 1;
}
