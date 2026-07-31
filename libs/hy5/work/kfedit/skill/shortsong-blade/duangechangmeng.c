// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	extra = me->query_skill("shortsong-blade",1);
	if ( extra < 90) return notify_fail("你的短歌刀法还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［短歌长梦］只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "blade")
                        return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("neili") < 500  ) 
		return notify_fail("你的内力不够。\n");
        me->add("neili",-100);

	weapon = me->query_temp("weapon");
	msg = HIY  "$N使出短歌刀法中的［短歌长梦］，一招连环三式，手中的"+ weapon->name()+  "闪电般向$n攻出第一刀！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIY  "第二刀！" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/damage",extra*5);
       msg = HIY  "第三刀！" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/damage",-extra*5);
	me->start_busy(2);
	return 1;
}
