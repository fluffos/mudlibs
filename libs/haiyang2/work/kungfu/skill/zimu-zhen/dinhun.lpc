// 定魂 子母针特殊技

#include <ansi.h>
#include <combat.h> 
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	string msg;
int extra;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("「定魂」只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "throwing")
			return notify_fail("你使用的武器不对。\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "已经神志恍惚，放胆攻击吧.\n");
		
	if( (int)me->query_skill("zimu-zhen", 1) < 30 )
		return notify_fail("你的子母针法不够娴熟，不会使用「定魂」。\n");

	if( (int)me->query_skill("biyun-xinfa", 1) < 60 )
                return notify_fail("你的碧云心法不够高。\n");

        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("你现在内力太弱。\n");

 extra = me->query_skill("zimu-zhen",1) / 3;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra*5);
msg = RED "$N左手一扬，唐门独门暗器----一朵令人闻风丧胆的唐花朝$n发了出去。\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra*5);
        me->add("neili",-50);
        
	msg = HIG "$N双目突然泛过怪异绿光,中指在不易察觉间微微一动,一点银星悄无声息打向$n眉心。\n"NOR;

	me->start_busy(1);
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
		msg += HIR " 结果$p被$P的「定魂」打个正着，瞬间神志开始迷糊起来！\n" NOR;
                target->start_busy( (int)me->query_skill("zimu-zhen") / 50+2 );
        target->apply_condition("tmzhuihun_poison", 60);
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
        target->apply_condition("tmqidu_poison", 60);
	} 
	} else {
		msg += "可是$p在千钧一发之间闪身躲过了这一击。\n" NOR;
	}
	message_vision(msg, me, target);

	return 1;
}
