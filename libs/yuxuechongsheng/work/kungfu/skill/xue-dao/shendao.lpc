// shendao.c  血刀「祭血神刀」

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
    int extra;
    string msg;
    object weapon;
	extra = me->query_skill("xue-dao",1);
    if (!target ) target = offensive_target(me);
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
        return notify_fail(RED"装备刀才能使用「祭血神刀」？\n"NOR);
    if (!target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「祭血神刀」只能对战斗中的对手使用。\n");
    if ((int)me->query_skill("xue-dao", 1) < 100 )
        return notify_fail(WHT"你血刀刀法不够娴熟，使不出「祭血神刀」。\n"NOR);
    if ((int)me->query_skill("longxiang", 1) < 60 )
        return notify_fail(RED"你龙象般若功火候不够，使不出「祭血神刀」。\n"NOR);
    if ((int)me->query("max_neili") < 600)
        return notify_fail(RED"你内力修为不足，无法运足内力。\n"NOR);
    if ((int)me->query("neili") < 600)
    {
        return notify_fail(HIC"你现在内力不够，没能将「祭血神刀」使完！\n"NOR);
    }
    me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
msg = YEL "$N右手持刀向左肩一勒，一阵血珠溅满刀面，紧接着右臂抡出，一片血光
裹住刀影向$n当头劈落，\n"NOR;
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);	
	me->add_temp("apply/damage", -extra);
me->start_busy(2);
    return 1;
}
