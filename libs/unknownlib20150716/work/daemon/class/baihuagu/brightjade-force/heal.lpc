// heal.c
#include <ansi.h>

int exert(object me, object target)
{
	if( !target ) target = me;
	if( me->is_fighting() )
        	return notify_fail("战斗中运功疗伤？找死吗？\n");
        if( (int)me->query("force") < 50 )
                return notify_fail("你的真气不够。\n");
	if( me->query_level()<5 )
		return notify_fail("你的人物等级不够。\n");
        if( (int)me->query("eff_kee") < (int)me->query_maxkee() / 2 )
                return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");
	if( me->query("eff_kee")>=me->query_maxkee() )
		return notify_fail("没有这个必要。\n");                

        write( HIG "你全身放松，坐下来开始运功疗伤。\n" NOR);
        message("vision",HIG + me->name() +"坐下来运功疗伤，脸上一阵红一阵白，不久，吐出一口瘀血，脸色看起来好多了。\n"NOR,environment(me), me);
        me->receive_curing("kee", 15 + (int)me->query_skill("force")/5 );
        me->add("force", -50);
        return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        内功名称：疗伤诀
        内功所属：明玉心法
        内功效果：治疗自身气血
        内功条件：
        	  人物等级 5 级
                  内力50点，消耗50点
STR;
        me->start_more(str);
        return 1;
}