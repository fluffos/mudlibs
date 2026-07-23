// wuji.c 混元无极
 
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

 
inherit F_SSERVER;
 
int perform(object me)
{
	string msg;
	object weapon, target;
	int skill,extra;

	me->clean_up_enemy();
	target = me->select_opponent();

	skill = me->query_skill("hunyuan-zhang",1);
	extra = me->query_skill("poyu-quan",1);
	if( !(me->is_fighting() ))
		return notify_fail("「混元无极」只能对战斗中的对手使用。\n");
 
	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("你使用了武器。\n");

	if( skill < 60)
		return notify_fail("你的「混元掌」等级不够, 不能使用「混元无极」！\n");

	if( extra < 60)
		return notify_fail("你的「破玉拳」等级不够, 不能使用「混元无极」！\n");
	
	if( me->query("neili") < 150 )
		return notify_fail("你的内力不够，无法运用「混元无极」！\n");
 	me->add_temp("apply/attack",extra);
	me->add_temp("apply/damage",skill);

	msg = YEL "$N潜运「混元掌」，双掌挟着隐隐的风雷之声向$n击去。"NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = CYN "$N暗使「破玉拳」，双拳挟着幽幽的呼啸之声向$n击去。"NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->start_busy(1);
	me->add_temp("apply/attack",-extra);
	me->add_temp("apply/damage",-skill);
	return 1;
}
