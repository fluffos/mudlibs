// leidong 雷动九天
// by winder 98.12

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount, int amount1);

int perform(object me)
{
	int skill, count, count1;

	if( (int)me->query_temp("leidong") ) 
		return notify_fail("你已经在运功中了。\n");
      if( me->query_temp("wudui") )
      return notify_fail("你正在使用无双无对。\n");

	if( !me->is_fighting() )
		return notify_fail("雷动九天只能在战斗中使用。\n");
	if( (int)me->query("neili") < 500  ) 
		return notify_fail("你的内力不够。\n");

	count = me->query_str();
	skill = (int)me->query_skill("poyu-quan",1);
	if( skill < 200  ) 
		return notify_fail("你的破玉拳修为还不够。\n");

      if (me->query_skill("zixia-shengong", 1)<50)
                return notify_fail("你的本门内功火候未到，！\n");

	me->add("neili", -400);
	message_combatd( HIM "$N深深吸了一口气，脸上顿时紫气大盛，出手越来越重！\n" NOR, me);

	count = me->query("str") + (int)(skill/10);
	count1 = skill/12;

        me->start_busy(2);
        me->add_temp("apply/strength",skill/12);
        me->add_temp("apply/dexerity",skill/12);
//	me->add_temp("str", count);
//	me->add_temp("dex", count1);
	me->set_temp("leidong", 1);
	me->start_call_out( (: call_other,  __FILE__, "remove_effect", me, count, count1 :), skill/3 );

	return 1;
}

void remove_effect(object me, int amount, int amount1)
{
        int skill;
	skill = (int)me->query_skill("poyu-quan",1);
if ((int)me->query_skill("poyu-quan",1) <200)
{
        me->delete_temp("apply/strength");
        me->delete_temp("apply/dexerity");
}
	if ( (int)me->query_temp("leidong") ) 
	{
//		me->add_temp("str", -amount);
//		me->add_temp("dex", -amount1);
        me->add_temp("apply/strength",-amount1);
        me->add_temp("apply/dexerity",-amount1);
		me->delete_temp("leidong");
		tell_object(me, CYN"你的雷动九天运行完毕，将内力收回丹田。\n"NOR);
		me->start_busy(4);
	}
}
