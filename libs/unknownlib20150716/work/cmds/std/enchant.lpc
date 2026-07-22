// enchant.c
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int pts;
	if( !arg || ( !sscanf(arg, "%d", pts) && arg!="max" && arg!="none" ) )
		return notify_fail("指令格式：enchant <法力点数>|max|none\n");
	if( arg=="max" )
        	pts = ((int)me->query_maxmana()/20+1);        
	if( arg=="none" )
        	pts = 0;        
	if( pts >((int)me->query_maxmana()/20+1) )
        	return notify_fail("你的法力不足，发不出那么强的威力。\n");
	if( pts < 0 ) return notify_fail("法力点数必须是正数。\n"); 
	if( me->query("mana_factor")==pts )
		return notify_fail("你目前法术加力已经是这么多了。\n");  
	me->set("mana_factor", pts);
	write("Ok.\n");
	return 1;
}

int help (object me)
{
write(@HELP
指令格式: enchant <法力点数|max>
 
这个指令让你设定使用法术武器时要用来导引武器法力所用的法力强度。
法力点数越高，法术武器的杀伤力也越强。
当设定为max时，法力强度为你所能发出的最大威力。
当设定为none时，法力强度为0。
HELP
);
return 1;
}

