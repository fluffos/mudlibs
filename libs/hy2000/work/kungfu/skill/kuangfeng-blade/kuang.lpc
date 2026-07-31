//kuang.c -「狂风二十一式」
// Modified by Venus Oct.1997
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    int extra;
	object weapon;
    string msg;
	extra=me->query_skill("kuangfeng-blade",1);
    if( !target ) target = offensive_target(me);
    if( !target||!target->is_character()||!me->is_fighting(target) )
    return notify_fail("你只能对战斗中的对手使用「狂风二十一式」。\n");
    if( (int)me->query_skill("kuangfeng-blade",1) < 70)
    return notify_fail("你目前功力还使不出「狂风二十一式」。\n");
    	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "blade")
			return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("neili") < 200 )
    return notify_fail("你的内力不够。\n");
    me->add("neili", -60);
    msg = HIC"$N淡然一笑，本就快捷绝伦的刀法骤然变得更加凌厉！就在这一瞬之间，"+
    "$N已劈出二十一刀！刀夹杂着风，风里含着刀影！$n只觉得心跳都停止了！"NOR;
   me->add_temp("apply/attack",extra*2);
	me->add_temp("apply/damage",extra*2);
     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
 me->start_busy(2);
me->add_temp("apply/attack",-extra*2);
	me->add_temp("apply/damage",-extra*2);

    return 1;
}

