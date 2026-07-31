
#include <combat.h>
int help(object me);

int main(object me, string arg)
{
	int pot;
        if( !arg)		pot=30;
	else	if(!sscanf(arg, "%d", pot))			return help(me);

//    if (1==1)
//return notify_fail("此命令已经停用！\n");

	if (pot<30)	return notify_fail("至少需要30点潜能！\n");

//    if ( me->query("zhuanshen"))
//return notify_fail("转生后不允许转换！\n");



	//if (me->query("jing")*10 < pot )	return notify_fail("你的精神状态不足以转化这么多潜能！\n");

    if( ((int)me->query("potential")-(int)me->query("learned_points")) >= pot ){
		//me->add("jing",-pot/10);
		me->add("potential",-pot);
		me->add("combat_exp",pot/10);
       	write("OK!\n");
	} else 	write ( "你没有这么多潜能来转移！\n" );

   return 1;
}

int help(object me)
{
	write(@HELP
指令格式 :transfer <潜能点>

      把潜能转成经验。10点潜能转1点经验
see also : hp

HELP
    );
    return 1;
}
