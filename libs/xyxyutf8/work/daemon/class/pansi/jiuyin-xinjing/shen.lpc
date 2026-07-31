// jingheal.c

#include <ansi.h>

int exert(object me, object target)
{
	if( me->is_fighting() )
        	return notify_fail("战斗中运功疗伤？找死吗？\n");
        if( (int)me->query("force") < 200 )
                return notify_fail("你的真气不够。\n");
	if( me->query_level()<20 )
		return notify_fail("你的人物等级不够。\n");
        if( (int)me->query("eff_sen")<(int)me->query_maxsen()-50 )
                return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");
	if( me->query("eff_sen")==me->query_maxsen() )
	 	return notify_fail("有这个必要吗？\n");

        write( HIW "你全身放松，坐下来开始运功疗伤。\n" NOR);
        message("vision",HIW + me->name() +"坐下来运功疗伤，脸上一阵红一阵白，不久，吐出一口瘀血，脸色看起来好多了。\n"NOR,environment(me), me);
       	me->receive_curing("sen", 30 + (int)me->query_skill("force")/3 );
        me->add("force", -150);
        return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        内功名称：疗神诀 
        内功所属：九阴心法
        内功效果：治疗自身精神
        内功条件：
        	  人物等级 20 级
                  内力200点，消耗150点
STR;
        me->start_more(str);
        return 1;
}