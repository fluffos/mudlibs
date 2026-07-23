// san.c  天女散花

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;
        int extra;
        extra = me->query_skill("tianyu-qijian",1);


	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「天女散花」只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if( (int)me->query_skill("tianyu-qijian", 1) < 50 )
		return notify_fail("你的天羽奇剑不够娴熟，不会使用。\n");

	if(((int)me->query_skill("bahuang-gong", 1) < 50 ) &&
	   ((int)me->query_skill("beiming-shengong", 1) < 50 ))
		return notify_fail("你的本门内功实在太差，没法用「天女散花」。\n");

	if( (int)me->query("neili", 1) < 300 )
		return notify_fail("你现在内力太弱，不能使用「天女散花」。\n");
			
	msg = CYN "$N凝神息气，手腕疾抖，挽出千万个剑花，铺天盖地飞向$n。"NOR;
	extra = me->query_skill("tianyu-qijian",1) / 15;
	extra += me->query_skill("tianyu-qijian",1) /15;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);

        message_vision(HIR"上一朵剑花！\n" NOR,me,target);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIG"下一朵剑花！！\n" NOR,me,target);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIY"最后一朵剑花！！！\n" NOR,me,target);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);

	me->add("neili",-150);
		me->start_busy(2);
	return 1;
}
