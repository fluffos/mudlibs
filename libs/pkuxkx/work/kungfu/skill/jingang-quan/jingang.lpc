//大金刚拳：大金刚神通 perform jingang
//条件：  只能在战斗中使用，混元一气功 60， 金刚拳 90，
//内力 500 以上
//特点：  臂力增强十倍，一招击毙强敌于掌下
//缺点：  内力损耗极大

//jingang 大金刚神通

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
	string msg;
	object weapon;
	int str,dmg;
    mapping attack_val = ([
        "base" : ([ "no_weapon" : "cuff", ]),//基本功夫类型
        "skill" : ([ "no_weapon" : "jingang-quan", ]),//高级技能名称
        ]);

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
            return notify_fail("「大金刚神通」只能对战斗中的对手使用。\n");

    if ( objectp(me->query_temp("weapon")) )
            return notify_fail("「大金刚神通」只能空手使用！\n");

    if( (int)me->query_str() < 30)
		return notify_fail("你的臂力不够，无法施展「大金刚神通」。\n");

	if( (int)me->query_skill("jingang-quan", 1) < 90 )
		return notify_fail("你的金刚拳不够娴熟，不会使用「大金刚神通」。\n");

	if( (int)me->query_skill("hunyuan-yiqi", 1) < 60 )
		return notify_fail("你的混元一气功等级不够，不能使用「大金刚神通」。\n");

	if( (int)me->query("max_neili") < 500 || (int)me->query("neili") < 500 )
		return notify_fail("你的内力不足，无法使用「大金刚神通」。\n");

	msg = RED "\n$N使出大金刚神通，拳头陡然间大了一倍，一拳打向$n。" NOR;

	me->add("neili", - 500);
	if( F_KUNGFU->hit_rate(me->query("combat_exp"), target->query("combat_exp"), 9, me, target) )
	{
//		msg += "结果$p被$P一击击中。\n" NOR;
		str = me->query("str");
		dmg = me->query_skill("jingang-quan")/2;
		me->add_temp("apply/damage",dmg);
        me->set("str",str*5 + dmg);
        me->set_temp("attack_val", attack_val);
		COMBAT_D->do_attack(me, target, 0, TYPE_SPECIAL, msg);
		me->set("str",str);
		me->add_temp("apply/damage",-dmg);
	}
	else
	{
		msg += RED "\n可是$p看破了$P的企图，并没有上当。\n" NOR;
		me->start_busy(3);
		message_vision(msg, me, target);
	}
	return 1;
}
