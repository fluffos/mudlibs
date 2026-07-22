// heal.c

#include <ansi.h>

int exert(object me, object target)
{
	if( me->is_fighting() )
		return notify_fail("战斗中运功疗伤？找死吗？\n");

	if ((int)me->query_skill("pingfeng", 1)<100)
		return notify_fail("你的屏风大法修为还不够。\n");
	if( (int)me->query("force") < 50 )
		return notify_fail("你的真气不够。\n");
	if ((int)me->query("eff_kee") >= ((int)me->query_maxkee()) )
		return notify_fail("你不需要疗伤。\n");
	if( (int)me->query("eff_kee")<(int)me->query_maxkee()/8+1 )
		return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");
	write( HIW "你全身放松，坐下来运起屏风大法内功，开始疗伤。\n" NOR);
	message("vision",HIW + me->name() + "“哇”的一声吐出一口瘀血，脸色看起来好多了。\n" NOR,environment(me), me);
	me->receive_curing("kee", 10 + (int)me->query_skill("force")/5 );
	me->add("force", -50);
	me->set("force_factor", 0);
      	me->start_busy(1);
	return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        内功名称：疗伤诀
        内功所属：屏风四扇门
        内功效果：治疗气血
        内功条件：
                  内力50点，消耗50点
                  屏风四扇门 100 级
STR;
        me->start_more(str);
        return 1;
}