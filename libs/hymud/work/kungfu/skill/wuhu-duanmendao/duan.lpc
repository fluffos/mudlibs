#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
	object weapon, ob;
	string msg;
	int i,j;
 if( !target ) target = offensive_target(me);

	if( !me->is_fighting() )
		return notify_fail("五虎断门刀「断」字决只能在战斗中使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");

	if( (int)me->query("neili") < 250 )
		return notify_fail("你的真气不够！\n");

	if( (int)me->query_skill("blade") < 60 ||
	    me->query_skill_mapped("blade") != "wuhu-duanmendao")
		return notify_fail("你的「五虎断门刀」还不到家，无法使用「断」字决！\n");

	msg = HIY "$N猛然伏地，使出地堂刀断字决，顿时一片蓝光直向前滚去！" NOR;
	message_vision(msg,me,target);
	j = random(7)+1;
	for(i=1;i<=j;i++)
	{
	msg =  BLU "第"+chinese_number(i)+"刀" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	}

	me->add("neili", -200);
	me->start_busy(3);
	return 1;
}
