
#include <ansi.h>
#include <combat.h>
#include <command.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
	int lvl;
	if( !target ) target = me;
	if(!me->is_fighting() )
		return notify_fail("［抽身法］只能在战斗中使用。\n");
	if( target != me)
		return notify_fail("［抽身法］只能对自己使用。\n");
	if( (int)me->query("neili") < 500  ) 
		return notify_fail("你的内力不够。\n");
        me->add("neili",-140);
	msg = YEL "$N虚晃一招，纵身向外跳开，企图避开敌人的攻势，\n" NOR;
	lvl = (int)me->query_skill("dodge",1);
	me->add_temp("apply/attack",lvl);
        message_vision(msg, me);
	msg = HIR  "上一抽身！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIR  "下一抽身！" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIR  "最后再一抽身！" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	me->add_temp("apply/attack",-lvl);
	me->start_busy(2);
	return 1;
}
