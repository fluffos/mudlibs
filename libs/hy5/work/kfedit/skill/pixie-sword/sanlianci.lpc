// jianzhang.c  三连刺

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
		return notify_fail("「三连刺」只能在战斗中使用。\n");
        if ((int)me->query_skill("kuihua-xinfa", 1) < 80 )
        return notify_fail(RED"你葵花心法火候不够。\n"NOR);
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("「三连刺」开始时必须拿着一把剑！\n");

	if( (int)me->query("neili") < 100 )
		return notify_fail("你的真气不够！\n");

	if((int) me->query_skill("pixie-jian",1) < 100)
		return notify_fail("你的辟邪剑法还不到家，无法使用三连刺！\n");

	msg = RED "$N嫣然一笑，诡异之极，身法陡然加快！" NOR;
	message_vision(msg, me);
msg = 	RED"先刺双目！"NOR;
if (!me)
return notify_fail("「三连刺」只能在战斗中使用。\n");
if (!target)
return notify_fail("「三连刺」只能在战斗中使用。\n");
if (!me->query_temp("weapon"))
return notify_fail("「三连刺」只能在战斗中使用。\n");
 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg = 	RED"后刺双足！"NOR;
 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg = 	RED"最后刺心！"NOR;
 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	me->add("neili", -150);
	me->start_busy(2);

	return 1;
}