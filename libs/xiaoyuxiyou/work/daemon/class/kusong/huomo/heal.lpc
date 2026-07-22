// heal.c

#include <ansi.h>

int exert(object me, object target)
{
        if( (int)me->query("force") < 50 )
                return notify_fail("你的真气不够。\n");
	if( me->query_level()<5 )
		return notify_fail("你的人物等级不够。\n");
        if( (int)me->query("eff_kee") < (int)me->query_maxkee() / 3 )
                return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");
	if( me->query("eff_kee")>=me->query_maxkee() )
		return notify_fail("你又没受伤。\n");
	if(me->query("family/family_name")!="火云洞")
		return 0;
        write( HIW "你全身放松，坐下来开始运功疗伤。\n" NOR);
        message("vision",HIR + me->name() +HIR"坐下来运功疗伤，脸上一阵红一阵白，不久，吐出一口瘀血，脸色看起来好多了。\n"NOR,environment(me), me);
        me->receive_curing("kee", 15 + (int)me->query_skill("force")/5 );
        me->add("force", -40);
        if( me->is_fighting() )
        	me->start_busy(2);
        return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        内功名称：疗伤诀
        内功所属：火魔心法
        内功效果：治疗自身气血
                  战斗中使用自身busy 2 秒 
        内功条件：
                  火云洞弟子
        	  人物等级 5 级
                  内力50点，消耗40点
STR;
        me->start_more(str);
        return 1;
}

