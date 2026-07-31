// shout.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if( !wizardp(me) )
{
if (me->query("neili") <4000)
		return notify_fail("你的内力不足。\n");
if (me->query("combat_exp") < 2000000)
		return notify_fail("你的经验不足不足。\n");
if (me->query_condition("killer"))
 return notify_fail("你是通辑犯，不能如此。\n");
if (me->is_busy())
 return notify_fail("你正忙着呢。\n");
me->add("neili",-1000);
me->start_busy(12);
}

	if (!arg) return notify_fail("你想要大叫什么？\n");
        shout(HIW + me->name() + "纵声长啸：" + arg + "\n" + NOR);
        write(HIW +"你纵声长啸：" + arg + "\n" + NOR);
	return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : shout <讯息>
 
这个指令让你将 <讯息> 传送出去, 所有正在游戏中的人都
会听见你的话.
 
see also : tune
HELP
    );
    return 1;
}
 
