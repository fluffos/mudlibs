// ren.c  两仪剑法「漫天花雨」

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
       || (string)weapon->query("skill_type") != "throwing")
               return notify_fail("你使用的武器不对。\n");
    if (!target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「漫天花雨」只能对战斗中的对手使用。\n");
    if ((int)me->query_skill("mantian-huayu", 1) < 80 )
        return notify_fail("你漫天花雨不够娴熟，使不出「漫天花雨」。\n");
    if ((int)me->query_skill("xuantian-wuji", 1) < 40 )
        return notify_fail("你玄天无极功火候不够，使不出「漫天花雨」。\n");

    if ((int)me->query("max_neili")<400)
        return notify_fail("你内力修为不足，无法运足内力。\n");
    if ((int)me->query("neili")<200)
    {
        return notify_fail("你现在内力不够，没能将「漫天花雨」使完！\n");
    }
	extra = me->query_skill("mantian-huayu",1) / 20;
	extra += me->query_skill("mantian-huayu",1) /20;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", 400);
if (random(2)==0) target->start_busy(3);
    msg = HIW "$N左右手各抓三枚暗器，似乎分左右射向$n，\n"NOR;
    msg += HIC"一点黑光射向$n的头部！"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg =  HIB"一点黑光向$n的胁下射去！"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIY"一点黑光从下方突然甩出，直射向$n！"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIG"一点黑光从高处疾射，直向$n射去！"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIR"最后二枚，一左一中绕向$n的左右！"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -400);

      if(!target->is_fighting(me)) target->fight_ob(me);
	me->start_busy(3);
        me->add("neili", -200);
    return 1;
}
