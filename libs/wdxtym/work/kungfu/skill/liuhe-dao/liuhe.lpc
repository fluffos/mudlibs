// liuhe.c六合兴旺
// bye jfeng
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon, ob;

	if (!target ) target = offensive_target(me);
	if (!target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「六合兴旺」只能在战斗中使用。\n");
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");
		if (me->is_busy()) 
		return notify_fail("你现在正忙着呢！\n");
	if((int)me->query_str() < 40)
		return notify_fail("你的臂力不够, 还不能使用这项绝技! \n");
	if((int)me->query_skill("huntian-qigong",1) < 150)
		return notify_fail("你的基本刀法的火候还不到家, 不能使用这一绝技 !\n");
	if((int)me->query_skill("liuhe-dao",1) < 350)
		return notify_fail("你的六合刀法的火候还不到家, 不能使用这一绝技 !\n");
	if ( !wizardp(me) && me->query_skill_mapped("force") != "huntian-qigong")
		return notify_fail("不使用本门内功，如何使用本门绝学!\n");	
		if (me->query_skill_mapped("blade") != "liuhe-dao")
		return notify_fail("你没正确激发该技能 。\n");
	if( (int)me->query("neili") < 2000 )
		return notify_fail("你的真气不够！\n");
	if( (int)me->query("max_neili") < 5000 )
		return notify_fail("你的内力修为不够！\n");
	message_vision(HIY "\n$N长期与牛、马、羊、猪、鸡、狗接触，领悟出「六合兴旺」！刷...刷...刷...六刀从不同地方斩来！！！\n" NOR, me, target);

	me->clean_up_enemy();
	ob = me->select_opponent();
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

	me->add("neili",-random(2000));
	me->start_busy(3);
	return 1;
}
