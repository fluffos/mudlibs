// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <combat.h>

#define TIANYA "「" HIY "天涯"HIW"明月" NOR "」"
string query_name() { return "天涯"ZJBR"明月"; }
inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;
        int ap, dp, wn;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(TIANYA "只能在战斗中对对手使用。\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "blade")
                return notify_fail("你使用的武器不对，难以施展" TIANYA "。\n");

        if ((int)me->query_skill("mingyue-blade", 1) < 200)
                return notify_fail("你天涯明月刀不够娴熟，难以施展" TIANYA "。\n");

        if ((int)me->query_skill("force") < 280 )
                return notify_fail("你的内功火候不够，难以施展" TIANYA "。\n");

        if ((int)me->query("max_neili") < 3000)
                return notify_fail("你的内力修为不够，难以施展" TIANYA "。\n");

        if ((int)me->query("neili") < 600)
                return notify_fail("你现在真气不够，难以施展" TIANYA "。\n");

        if (me->query_skill_mapped("blade") != "mingyue-blade")
                return notify_fail("你没有激发天涯明月刀，难以施展" TIANYA "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        wn = weapon->name();

        msg = HIC "$N" HIC "手中的 " + weapon->name() +  HIC "悄然探出，变化中突然收劲，$n一时不查，身形顿时被$N的" + weapon->name() + HIC"吸住，\n"
                  "只听$N一声轻蔑的哼声，" + weapon->name() + HIC"从$n头顶位置闪电下劈！\n "NOR;


        ap =  me->query_skill("blade");
        dp = target->query_skill("dodge");

        if (ap / 2 + random(ap*2) > dp)
        {
                me->start_busy(2);
                damage = me->query_skill("blade")*2;
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 70,
                                           HIR "$n" HIR "顿时大惊失色，呆若木鸡,避无可避，"
                                           "顿时被砍得血肉模糊，鲜血崩流！\n" NOR);
                me->add("neili", -500);
                me->add("shen",-100);
        } else
        {
                me->start_busy(3);
                msg += HIC "$p" HIC "见$P来势汹涌，心知绝不可挡，当即向后横移数尺，终于躲闪开来。\n" NOR;
                me->add("neili", -400);
        }
        message_combatd(msg, me, target);
        return 1;
}

