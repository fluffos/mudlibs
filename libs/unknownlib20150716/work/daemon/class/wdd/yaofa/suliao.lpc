// 妖法－－速疗
#include <ansi.h>

int cast(object me, object target)
{
	int cure,cost;
	string msg;

	if( me->query_level()<20 )
		return notify_fail("你的人物等级不够。\n");
	if(me->query("family/family_name")!="陷空山无底洞"
        && me->query("chushi/chushi_wdd")!="yes")
		return notify_fail("你不能使用这项技能！\n");
	if( me->query_skill("yaofa", 1)<200 )
		return notify_fail("你的妖法等级不够，无法承受速疗。\n");
	if( me->query("mana")<500 )
		return notify_fail("你的法力不够。\n");
	if( me->query("eff_kee")>=me->query_maxkee() )
		return notify_fail("你现在没有受伤。\n");		
	cost = 200;
        if( (int)me->query("eff_kee") < (int)me->query_maxkee() / 2 )
		cost=cost*2;
	cure = me->query_maxkee()-me->query("eff_kee");
	cure = cure/2;
	if( cure<50 )
		cure = 50;
	if(!me->is_fighting())
	{
		cost=cost/2;
		msg = HIR"$N"HIR"双手举在胸前，做个火焰状，念了几句咒。随即，$P将双手在全身上下擦了一遍，双手到处，伤口居然好了大半！\n"NOR;
		me->start_busy(2);
	}
	else
	{
		msg = HIR"百忙之中，$N"HIR"突然越出战圈，掐指念了段咒。一瞬间，$P面部黄气大盛。待黄气下去时，身上大半伤口居然已经收口了！\n"NOR;
		me->start_busy(1);
	}
	message_vision(msg, me);
        me->receive_curing("kee", cure);
        me->add("mana", -cost);
        return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        法术名称：速疗术
        法术所属：妖法
        法术效果：使用法力治疗自身的气血
        	  战斗中使用 busy 1 秒，否则busy 3 秒
        法术条件：
                  无底洞(出师)弟子
        	  人物等级20级
        	  妖法200级
                  法力500点，消耗200点
                  
STR;
        me->start_more(str);
        return 1;
}
