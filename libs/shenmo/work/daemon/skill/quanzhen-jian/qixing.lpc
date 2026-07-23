// qixing. 七星绝命剑

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
	object weapon = me->query_temp("weapon");
	int damage;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("七星绝命剑只能对战斗中的对手使用。\n");

    if( (int)me->query_skill("quanzhen-jian", 1) < 150 )
		return notify_fail("你的全真剑法不够熟练，使不出七星绝命剑。\n");
  
    if (!weapon || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "quanzhen-jian")
		return notify_fail("你现在无法使用七星绝命剑。\n");

    if ( (int)me->query("neili") < 200)
		return notify_fail("你的内力不够，无法使用七星绝命剑。\n");

 	msg = MAG "$N一声长啸，一抖手中剑，顿时形成一道剑幕，狂风暴雨般压向$n。就在
$n慌乱之间，剑幕中飞出七朵寒星，如流星般射向$n。\n";

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) {
		msg += "$n躲闪不及，已然中剑！\n";
		damage = 4*(int)me->query_skill("quanzhen-jian", 1);
		damage = damage / 2 + random(damage / 2);
		if (damage > target->query("neili") / 10)
			damage -= target->query("neili") / 15;
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage/4);
	 	if( damage < 40 ) msg += HIY"$n已身中数剑，身上到处是血。\n"NOR;
         	else if( damage < 80 ) msg += HIR"$n身中七剑，鲜血狂喷而出！\n"NOR;
         	else msg += RED"$n“哇”的狂叫一声，身上喷出七道血剑！\n"NOR;
		message_vision(msg, me, target);
	} 
	else {
	me->start_busy(2);
	 	msg += HIW"$n情急之中向后激飞，随机趴下，堪堪躲过了这致命一击。\n" NOR;
		message_vision(msg, me, target);
	}
        if (me->query_skill("qixing-array",1)>80)
{
        msg = HIC "随后$N脚走七星，使出一招 天玑离枢！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
}
        if (me->query_skill("qixing-array",1)>150)
{
        msg = HIG "紧跟着$N，随着阵法，使出一招天璇乱步！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
}
        if (me->query_skill("qixing-array",1)>250)
{
        msg = HIG "紧跟着$N，随着阵法，使出一招七星移位！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
}
	me->add("neili", -300);
	me->start_busy(2);

	return 1;
}
