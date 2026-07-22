#include <ansi.h>
inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;

	if( target != me ) 
		return notify_fail("你只能用屏风四扇门来提升自己的战斗力。\n");
	if( (int)me->query_skill("pingfeng",1)<200 )
		return notify_fail("你的屏风四扇门还不够娴熟。\n");
	if( (int)me->query("force") < 100  ) 
		return notify_fail("你的内力不够。\n");
	if( (int)me->query("kee")<100 )
		return notify_fail("你现在体力不够。\n");	
	if( (int)me->query_temp("powerup") ) 
		return notify_fail("你已经在运功中了。\n");

	skill = me->query_skill("force");
	me->add("force", -100);
	me->receive_damage("kee",50);

	message_vision(HIY"$N"HIY"一声爆喝，运起屏风四扇门奇功，但见$P须发皆张，出招勇猛，宛若天神。\n" NOR, me);

	me->add_temp("apply/attack", skill/3);
	me->add_temp("apply/dodge", skill/3);
	me->set_temp("powerup", 1);
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill/4);
	if( me->is_fighting() ) 
		me->start_busy(2);
	return 1;
}

void remove_effect(object me, int amount)
{
   	if ( me && (int)me->query_temp("powerup") ) 
   	{
		me->add_temp("apply/attack", - amount);
		me->add_temp("apply/dodge", - amount);
		me->delete_temp("powerup");
		tell_object(me, "你的屏风四扇门奇功运行完毕，将内力收回丹田。\n");
	}
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        内功名称：屏风四门诀
        内功所属：屏风四扇门
        内功效果：一定时间内提升自身的命中与闪避基数
                  不可与其他增益类状态叠加
        内功条件：
                  内力100点，消耗100点
                  气血100点，消耗50点
                  屏风四扇门 200 级
STR;
        me->start_more(str);
        return 1;
}