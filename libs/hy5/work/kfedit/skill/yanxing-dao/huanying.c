// huanying.c  雁行刀法「无形幻影」

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
    int extra;
    int damage;
    string msg;
    object weapon;

    if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［无形幻影］只能对战斗中的对手使用。\n");
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
        return notify_fail("开什么玩笑，没装备刀怎么使「无形幻影」？\n");
    if ((int)me->query_skill("yanxing-dao", 1) < 150 )
        return notify_fail("你雁行刀法不够娴熟，使不出「无形幻影」。\n");
    if ((int)me->query_skill("linji-zhuang", 1) < 90 )
        return notify_fail("你临济庄火候不够，「无形幻影」不成招式。\n");
    if ((int)me->query("max_neili")<300)
        return notify_fail("你的内力修为不足，无法运足「无形幻影」的内力。\n");
    if ((int)me->query("neili")<200)
    {
        return notify_fail("你现在内力不够，没能将「无形幻影」使完！\n");
    }
	extra = me->query_skill("yanxing-dao",1) / 15;
	extra += me->query_skill("linji-zhuang",1) /15;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
    msg = HIC "$N大喝一声，全场四处游动，$n只看到$N化做数团身影，漫天刀光席卷而来！"NOR;
	   COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL  "$n奋力一架，但$N刀分数路，$n只架住一刀！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL  "$N的刀横劈向$n！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL  "$N无形的身影朝$n飞来，刀法成幻影令$n捉摸不清！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL  "$N身法飘忽不定，不时的砍向$n，犹如无形，犹如幻影！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
    me->add("neili", -200);
    me->start_busy(2);
    return 1;
}
