// tie@fengyun
string query_name() { return "葵花"ZJBR"神掌"; }
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int i,a;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("葵花神掌只能对战斗中的对手使用。\n");

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("「葵花神掌」只能空手使用。\n");

	if( (int)me->query("neili") < 400  )
		return notify_fail("你的内力不够。\n");

    if ( (string)me->query("gender")=="女性" )
        return notify_fail("女子不能用.\n");

   if ( (string)me->query("gender")=="男性" )
        return notify_fail("你必须先自宫,才能用.\n");
	if( (int)me->query_skill("kuihua-feiying", 1) < 50 )
		return notify_fail("你的葵花飞影术不够娴熟，不能用葵花神掌。\n");

	if( (int)me->query_skill("kuihua-xinfa", 1) < 60 )
		return notify_fail("你的葵花心法不够娴熟，不能使用葵花神掌。\n");

	extra = me->query_skill("kuihua-feiying",1) / 20;
	extra += me->query_skill("kuihua-xinfa",1) /20;
	me->add_temp("apply/attack", (extra*2));
	me->add_temp("apply/damage", (extra*2));
	msg = HIR  "$N运起［葵花心法］，同时使出［葵花神掌］死命的打向$n！" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  HIW "$N的人影变成了几个，．．．．\n" NOR;
        message_vision(msg, me, target);
a=extra/3;
if (a> 10) a=10;
me->set_temp("action_flag", 1);
	for(i=0;i<a;i++)
	{
	msg = HIC "在$n的身旁出现一个人影，一掌向$n打了过去！\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}
me->delete_temp("action_flag");
i = extra/4;
	me->add_temp("apply/attack", -(extra*2));
	me->add_temp("apply/damage", -(extra*2));
me->add("neili", - 40 * i);
	me->start_busy(2);
	return 1;
}
