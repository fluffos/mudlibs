#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	extra = me->query_skill("zhong-qiang",1);
    	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "club")
			return notify_fail("你使用的武器不对。\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［反转流星］只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	msg = HIY  "$N使出中平枪法中的［反转流星］，假意抽身急退，蓦地反身抖手一枪！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "$N紧跟一招，另一枪反身又是一枪！！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "$N竟然还不回头，两臂一振，再来一枪！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	me->start_busy(3);
	return 1;
}
