// heal.c

#include <ansi.h>

int exert(object me, object target)
{
	if( !target ) target = me;	
        if( (int)me->query("force") < 60 )
                return notify_fail("你的真气不够。\n");
	if( me->query_level()<5 )
		return notify_fail("你的人物等级不够。\n");
        if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 5+1 )
                return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

        write( HIW "你全身放松，就地坐下，开始运功疗伤。\n" NOR);
        message("vision",HIW + me->name() +"坐下来运功疗伤，脸上一阵红一阵白，不久，吐出一口瘀血，脸色看起来好多了。\n"NOR,environment(me), me);
        me->receive_curing("kee", 20 + (int)me->query_skill("force")/8 );
        me->add("force", -50);
	if( me->is_fighting() )        
		me->start_busy(3);
        return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        内功名称：疗伤诀
        内功所属：冷泉神功
        内功效果：治疗并增加自身气血
                  战斗中使用自身busy3秒
        内功条件：
        	  人物等级 5 级
                  内力60点，消耗50点
STR;
        me->start_more(str);
        return 1;
}