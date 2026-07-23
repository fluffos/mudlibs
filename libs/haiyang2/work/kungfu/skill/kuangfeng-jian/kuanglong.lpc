// feilong.c  狂风快剑「天外狂龙」

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;
    object weapon;

    if (!target ) target = offensive_target(me);
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail("装备剑才能使用「天外狂龙」\n");
    if (!target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「天外狂龙」只能对战斗中的对手使用。\n");
    if ((int)me->query_skill("kuangfeng-jian", 1) < 150 )
        return notify_fail("你狂风快剑不够娴熟，使不出「天外狂龙」。\n");
    if ((int)me->query_skill("huashan-neigong", 1) < 120 )
        return notify_fail("你华山内功火候不够，使不出「天外狂龙」。\n");
    if ((int)me->query("max_neili") < 600)
        return notify_fail("你内力修为不足，无法运足内力。\n");
    if ((int)me->query("neili") < 400)
    {
        return notify_fail("你现在内力不够，没能将「天外狂龙」使完！\n");
    }
    weapon = me->query_temp("weapon");
msg = HIC "$N心念电闪，一提内力，勒手仗剑，运劲于臂，呼的一声向$n掷了出去！"NOR;
   COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
   COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
   COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
   COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
   COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
//    weapon->move(environment(me));
       me->start_busy(2);
    return 1;
}
