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

	if( (int)me->query("neili") < 200 )
		return notify_fail("你的真气不够！\n");

	if( (int)me->query_skill("blade",1) < 60 )
		return notify_fail("你的「五虎断门刀」还不到家，无法使用「断」字决！\n");

	if( (int)me->query_skill("wuhu-duanmendao",1) < 60 )
		return notify_fail("你的「五虎断门刀」还不到家，无法使用「断」字决！\n");

	msg = HIY "$N猛然伏地，使出「五虎断门刀」断字诀，顿时一片蓝光直向前滚去！" NOR;
	message_vision(msg,me,target);
	j = random(3)+1;
	for(i=1;i<=j;i++)
	{
	msg =  BLU "第"+chinese_number(i)+"刀" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	}

	me->add("neili", - (j * 50 + 50));
	me->start_busy(4);
	return 1;
}
