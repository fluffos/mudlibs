//heal.c

#include <ansi.h>

int exert(object me, object target)
{
	if( me->query_level()<5 )
		return notify_fail("你的人物等级不够。\n");
        if( (int)me->query("force") < 80 )
                return notify_fail("你的真气不够。\n");
        if( (int)me->query("eff_kee") < (int)me->query_maxkee() / 2 
         || (int)me->query("eff_sen") < (int)me->query_maxsen() / 2 )
                return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");
	if( me->query("eff_kee")>=me->query_maxkee()
	 && me->query("eff_sen")>=me->query_maxsen() )
	 	return notify_fail("没有这个必要。\n");
        write( HIW "你全身放松，坐下来开始运功疗伤。\n" NOR);
        message("vision",YEL + me->name()+YEL+"坐下来运功疗伤，头上冒出丝丝热气，不久，吐出一口瘀血，脸色看起来好多了。\n"NOR,environment(me), me);
        if( me->query("eff_kee")<me->query_maxkee() )
        	me->receive_curing("kee", 10 + (int)me->query_skill("force")/6 );
        if( me->query("eff_sen")<me->query_maxsen() )	
        	me->receive_curing("sen", 10 + (int)me->query_skill("force")/6 );
        me->add("force", -60);
        return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        内功名称：疗伤诀
        内功所属：混天气功
        内功效果：治疗自身气血、精神
                  战斗中不能使用
        内功条件：
        	  人物等级 5 级
                  内力80点，消耗60点
STR;
        me->start_more(str);
        return 1;
}


