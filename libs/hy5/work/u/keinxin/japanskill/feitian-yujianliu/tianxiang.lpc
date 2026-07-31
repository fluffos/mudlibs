// tianxiang.c  天翔龙闪

#include <ansi.h>


void remove_effect(object me, int a_amount, int d_amount);

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int skill;
        string msg;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("天翔龙闪只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "blade")
                        return notify_fail("你使用的武器不对。\n");

	if((int)me->query_skill("feitian-yujianliu",1) < 300)
		return notify_fail("你的飞天御剑流的修为不够, 不能使用这一绝技 !\n");
	if((int)me->query_skill("blade") < 300)
		return notify_fail("你的刀法修为不够， 目前不能使用! \n");
    if ((int)me->query_skill("shayi-xinfa", 1) < 200)
   return notify_fail("你的杀意心法火候不够。\n");

	weapon = me->query_temp("weapon");

	if( (int)me->query("neili") < 1000 )
		return notify_fail("你的真气不够！\n");

        
       if( !((int)(me->query("max_qi")/me->query("qi"))>=4))
             return notify_fail("你还没受重伤，体会不到生与死的那种境界。\n");

        if( (int)me->query("neili") < 300  ) 
                return notify_fail("你的内力不够。\n");

        if( (int)me->query_temp("tx_tong") ) 
                return notify_fail("你已经在使用天翔龙闪中了。\n");

message_vision(RED"$N本来死灰色的眼睛中突然出现了生的光彩$n。\n"NOR,me,target);
message_vision(HIR"$N把刀插回了刀鞘。超神速的拔刀术的准备动作,强烈的求生意志使$n感到发抖！  \n"NOR,me,target);
message_vision(RED"$N目不转睛地盯着$n，准备发出致命一击。同时$N超高速的身法，随时准备切入$n的攻击范围。  \n"NOR,me,target);
        me->start_call_out( (: call_other, __FILE__, "kill_him", me, 
target :), random(5)+5);
	me->start_busy(4);
	return 1;
	
        me->add_temp("apply/armor", (int)me->query("feitian-yujianliu")/2);
        me->add_temp("apply/dodge", (int)me->query_skill("feitian-yujianliu",1)/2);
        me->set_temp("tx_tong", 1);
        me->add("neili", -((int)me->query("neili")/2));

        return 1;
}


void kill_him(object me, object target)
{
	string msg;
        me->add_temp("apply/armor", - (int)me->query("feitian-yujianliu")/2);
        me->add_temp("apply/dodge", - (int)me->query_skill("feitian-yujianliu",1)/2);
        me->delete_temp("tx_tong");

	if(me->is_fighting() && target->is_fighting() &&
	environment(me) == environment(target))
	{
msg = HIW "$N使出飞天御剑流的最高剑决的" + HIR "天翔龙闪" +HIW "，$n只见$N身形一闪，咽喉已被对穿而过！ " ;
msg +=  HIY"\n一股血箭喷涌而出．．$n的眼睛死鱼般的突了出来．．\n" NOR;
	message_vision(msg, me, target);
target->unconcious();
	}
	return ;
}

