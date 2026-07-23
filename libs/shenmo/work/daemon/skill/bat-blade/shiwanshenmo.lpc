// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	extra = me->query_skill("bat-blade",1);
	if ( extra < 50) return notify_fail("你的[蝙蝠刀法]还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［十万神魔］只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "blade")
                        return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("neili") < 500  ) 
		return notify_fail("你的内力不够。\n");
        me->add("neili",-200);


	weapon = me->query_temp("weapon");
	msg = MAG  "$N凝聚起天地间十万妖魔的无边力量，一式－十－万－神－魔 －如急电般劈向$n！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIB  "$N手中"+ weapon->name()+  "幻出奇异的光华刺向$n！" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIR  "$N手中"+ weapon->name()+  "发出摄人心魄的呼啸向$n劈去！" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIW  "$N手中"+ weapon->name()+  "竟然发出妙不可言的奇香扑向$n！" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIC  "十万诸魔齐在云端隐现，$N手中"+ weapon->name()+  "鬼神莫测已然到了$n的眼前！"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       me->start_busy(3);
       target->apply_condition("bat",random(10)+10);

	return 1;
}
