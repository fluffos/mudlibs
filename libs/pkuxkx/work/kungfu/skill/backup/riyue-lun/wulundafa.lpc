// jianzhang.c  
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
		return notify_fail("「五轮大法」只能在战斗中使用。\n");
 
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "hammer")
		return notify_fail("「五轮大法」用的兵器不是这个！\n");

	if( (int)me->query("neili") < 300 )
		return notify_fail("你的真气不够！\n");

	if( (int)me->query_skill("riyue-lun",1) < 150 )
		return notify_fail("你的日月轮法不够！\n");


	extra = me->query_skill("riyue-lun",1) / 10;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	msg = HIY "$N纵跃退後，立时呜呜、嗡嗡、轰轰之声大作，金光闪闪，银光烁烁，五只轮子从五个不同方位飞袭出来！" NOR;
	
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  HIC  "银轮大法！ " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  HIR  "铁轮大法！ " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  YEL  "铜轮大法！ " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  BLU  "锡轮大法！ " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->add("neili", -50);
	me->start_busy(3);
	return 1;
}
