// sanjue.c  缚龙斩鲛刀。九头龙闪
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon, ob;
	string msg;
        int extra;
        extra = me->query_skill("longjiao-blade",1);

	 if( !target ) target = offensive_target(me);
if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("「九头龙闪」只能在战斗中使用。\n");
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "blade")
			return notify_fail("你使用的武器不对。\n");
	if((int)me->query_skill("longjiao-blade",1) < 250)
		return notify_fail("你的缚龙斩鲛刀的修为不够, 不能使用这一绝技 !\n");

   

	if((int)me->query_skill("blade") < 250)
		return notify_fail("你的刀法修为不够， 目前不能使用! \n");
	weapon = me->query_temp("weapon");
	if( (int)me->query("neili") < 900 )
		return notify_fail("你的真气不够！\n");

	
	extra = me->query_skill("longjiao-blade",1) / 15;
	extra += me->query_skill("longjiao-blade",1) /15;
	me->add_temp("apply/attack", 100);	
me->add_temp("apply/damage", 900);
	msg = HIR "$N速度突然加快!向九个方使出了九种不同的招术! $n尽然感到无法防御和躲避！！\n" NOR;     
message_vision(msg, me, target);
	msg = HIG "壹！唐竹！" NOR;     
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIC "贰！袈裟斩！" NOR;     
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIB "叁！逆袈裟！" NOR;     
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIY "肆！左刺！" NOR;     
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIR "伍！右刺！" NOR;     
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIM "陆！左切上！" NOR;     
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIW "柒！右切上！" NOR;     
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = CYN "捌！逆风！" NOR;     
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = BLU "玖！刺突剑！" NOR;     
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	me->add_temp("apply/attack", -100);
me->add_temp("apply/damage", -900);
	me->add("neili", -200);
	me->start_busy(2);
	return 1;
}
