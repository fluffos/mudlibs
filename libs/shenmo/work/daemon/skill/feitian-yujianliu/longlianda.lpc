// 飞天御剑流.龙连打.风,旋 岚
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon, ob;
        string msg, string1;
        int extra;
        int count;
  if( !target ) target = offensive_target(me);

	if( !me->is_fighting() )
		return notify_fail("「飞天御剑流.龙连打」只能在战斗中使用。\n");
 	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("「龙连打」只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("「龙连打」开始时必须拿着一把剑！\n");
    if ((int)me->query_skill("shayi-xinfa", 1) < 50)
   return notify_fail("你的杀意心法火候不够。\n");

	if( (int)me->query("neili") < 100 )
		return notify_fail("你的真气不够！\n");


	if((int)me->query_skill("feitian-yujianliu",1) < 90)
		return notify_fail("你的飞天御剑流的修为不够, 不能使用这一绝技 !\n");
	if((int)me->query_skill("blade") < 90)
		return notify_fail("你的刀法修为不够， 目前不能使用! \n");

	if( (int)me->query("neili") < 400  ) 
		return notify_fail("你的内力不够。\n");
	extra = me->query_skill("feitian-yujianliu",1) / 10;
	extra += me->query_skill("feitian-yujianliu",1) /10;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);

	msg = HIR "$N先由上方发动龙椎翔闪,然后由下方发动了龙卷闪！" NOR;
        message_combatd(msg, me, target);
	 msg =  YEL  "「 龙椎闪! 」！ " NOR;	
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  YEL  "「 龙翔闪! 」！ " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  HIY  "「 龙卷闪，风! 」！ " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  HIY  "「 龙卷闪，旋! 」！ " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  HIY  "「 龙卷闪.岚! 」！ " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->add("neili", -200);
	me->start_busy(2);
	return 1;
}
