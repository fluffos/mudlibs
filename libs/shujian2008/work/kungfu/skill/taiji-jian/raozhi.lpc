// 2005.7.4 by Lane@SJ

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	string msg, dodge_skill;
	object weapon;
	int ap, dp,i;

	if( !target ) target = offensive_target(me);

	if( !me->query("raozhi") )
		return notify_fail("你未得传授「绕指柔剑」。\n");

	if( !objectp(target)
	|| !target->is_character()
	|| !me->is_fighting(target)
	|| !living(target) )
		return notify_fail("「绕指柔剑」只能对战斗中的对手使用。\n");

	if( me->query_temp("tjj/lian") )
		return notify_fail("你正在使用「连」字诀。\n");

	if( me->query_temp("tjj/chan") )
		return notify_fail("你正在使用「缠」字诀。\n");

	if( (int)me->query_skill("taiji-jian", 1) < 200 )
		return notify_fail("你的太极剑法功力太浅了。\n");

	if( (int)me->query_skill("sword", 1) < 200 )
		return notify_fail("你的基本剑法功力太浅了。\n");

	if( (int)me->query_skill("yinyun-ziqi", 1) < 200 )
		return notify_fail("你的内功功力太浅了。\n");

	if( (int)me->query("max_neili") < 3000 )
		return notify_fail("你的内力太浅了。\n");

	if( (int)me->query("neili") < 1000 )
		return notify_fail("你的真气不够。\n");

	if( me->query_skill_mapped("force") != "yinyun-ziqi" )
		return notify_fail("你用什么为内功基础来使「绕指柔剑」？\n");

	if( !objectp(weapon = me->query_temp("weapon"))
	 || weapon->query("skill_type") != "sword"
	 || me->query_skill_mapped("sword") != "taiji-jian"
	 || me->query_skill_mapped("parry") != "taiji-jian" )
		return notify_fail("你使得了「绕指柔剑」么?\n");
	
	if( target->is_busy() )
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");
	//For npc Chan+Raozhi 流氓至极

	ap = COMBAT_D->skill_power(me, "sword", SKILL_USAGE_ATTACK) + me->query("combat_exp")/2;
	dp = COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE) + target->query("combat_exp")/2;

	ap += me->query_int(1) * me->query_dex(1) * 1000;
	dp += target->query_int(1) * target->query_con(1) * 1000;

	if( me->query_skill("taiji-jian", 1) > 550 )
		ap += random(ap/4);

	msg = HIW"\n$N施展出太极剑法中的绕指柔剑，手中"+weapon->name()+HIW"竟似了一条软蛇，弯曲自如，攻势奇诡！\n"NOR;

	if ( random( ap + dp ) > dp ) {
		msg += HIY"$n不由感到害怕，只感觉前后左右都似有$N攻来，一下子不知道如何是好！\n"NOR;
		i=random(2);
		target->add_busy(4+i+random(2));
		if( !userp(target) ) target->add_busy(random(2));
		if( target->query_temp("lost_attack") < 1 )
			target->add_temp("lost_attack", random(3));
		me->add("neili", -300);
		me->add("jingli", -100);
		me->start_perform(3 + i, "「绕指柔剑」");
	}
	else {
		dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
		me->add("neili", -100);
		me->add("jingli", -50);
		me->start_perform(1+random(2), "「绕指柔剑」");
	}
	me->start_busy(1);
	message_vision(msg, me, target);
	return 1;
}

string perform_name(){ return HIR"绕指柔剑"NOR; }

int help(object me)
{
        write(HIR"\n太极剑法之「绕指柔剑」："NOR"\n\n");
        write(@HELP
        要求：  当前内力 1000 以上;
                最大内力 3000 以上；
                太极剑法等级 200 以上；
                氤氲紫气等级 200 以上；
                基本剑法等级 200 以上；
                激发剑法为太极剑法；
                激发招架为太极剑法；
                激发内功为氤氲紫气；
                需得到传授「绕指柔剑」。

HELP
        );
        return 1;
}
