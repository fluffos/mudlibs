// sanshen.c 华岳三神峰

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
	object weapon, ob;
	string msg, string1;
	int count;
 	if( !target ) target = offensive_target(me);

	if( !me->is_fighting() )
		return notify_fail("「华岳三神峰」只能在战斗中使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");

	if( (int)me->query("neili") < 100 )
		return notify_fail("你的真气不够！\n");

	if( (int)me->query_skill("zixia-shengong",1) < 80 )
		return notify_fail("你的紫霞神功功力不足！\n");

	if( (int)me->query_skill("blade") < 50 ||
	    me->query_skill_mapped("blade") != "fanliangyi-dao")
		return notify_fail("你的「反两仪刀法」还不到家，无法使用「华岳三神峰」！\n");

	msg = RED "$N使出华山派绝技「华岳三神峰」，身法突地变得异常灵动飘忽！" NOR;
	message_vision(msg, me, target);          

	msg =  YEL  "玉女峰！ " NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	msg =  YEL  "朝阳峰！ " NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	msg =  YEL  "莲花峰！ " NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	me->add("neili", -50);
	me->start_busy(2);
	
	return 1;
}
