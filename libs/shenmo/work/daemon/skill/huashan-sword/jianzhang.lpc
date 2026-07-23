// jianzhang.c  剑掌五连环
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
		return notify_fail("「剑掌五连环」只能在战斗中使用。\n");
 	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("「剑掌五连环」只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("「剑掌五连环」开始时必须拿着一把剑！\n");

	if( (int)me->query("neili") < 100 )
		return notify_fail("你的真气不够！\n");

	if( (int)me->query_skill("zixia-shengong",1) < 50 )
		return notify_fail("你的紫霞神功不够！\n");

	if( (int)me->query_skill("sword",1) < 50 ||
	    me->query_skill_mapped("sword") != "huashan-sword")
		return notify_fail("你的华山剑法还不到家，无法使用剑掌五连环！\n");
	extra = me->query_skill("huashan-sword",1) / 10;
	extra += me->query_skill("huashan-sword",1) /10;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);

	msg = HIY "$N使出华山派绝技「剑掌五连环」，身法陡然加快。第一剑！" NOR;
	
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  YEL  "第二掌！ " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  YEL  "第三剑！ " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  YEL  "第四掌！ " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  YEL  "第五剑！ " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->add("neili", -200);
	me->start_busy(2);
	return 1;
}
