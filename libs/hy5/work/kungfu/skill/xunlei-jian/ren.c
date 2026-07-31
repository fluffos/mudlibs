// ren.c  两仪剑法「天地同仁」

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    int damage,extra;
    string msg;
    object weapon;

    if (!target ) target = offensive_target(me);
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail("开什么玩笑，没装备剑就想使「天地同仁」？\n");
    if (!target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「天地同仁」只能对战斗中的对手使用。\n");
    if ((int)me->query_skill("xunlei-jian", 1) < 20 )
        return notify_fail("你迅雷剑不够娴熟，使不出「天地同仁」。\n");
    if ((int)me->query_skill("xuantian-wuji", 1) < 20 )
        return notify_fail("你玄天无极功火候不够，使不出「天地同仁」。\n");
    if ((int)me->query("max_neili")<200)
        return notify_fail("你内力修为不足，无法运足内力。\n");
    if ((int)me->query("neili")<200)
    {
        return notify_fail("你现在内力不够，没能将「天地同仁」使完！\n");
    }
	extra = me->query_skill("xunlei-jian",1) / 20;
	extra += me->query_skill("xunlei-jian",1) /20;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
if (random(2)==0) target->start_busy(2);
    msg = HIC "$N手中长剑剑芒跃动，剑光暴长，剑尖颤动似乎分左右刺向$n，\n"NOR;
    msg += HIC"$n看到剑光偏左，疾侧身右转，但只这一刹，剑光刹时袭向右首！"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIG"$n看到剑光偏右，疾侧身右转，但只这一刹，剑光刹时袭向左首！"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIR"$n看到剑光偏上，疾侧身下行，但只这一刹，剑光刹时袭向上身！"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);

      if(!target->is_fighting(me)) target->fight_ob(me);
	me->start_busy(2);
        me->add("neili", -100);
    return 1;
}
