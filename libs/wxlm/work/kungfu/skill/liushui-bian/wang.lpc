// wang.c 望断秋水


#include <combat.h>

inherit F_SSERVER;
string query_name() { return "望断秋水"; }

int perform(object me)
{
        string msg;
        object weapon, target;
        int ap, dp, damage;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (userp(me) && ! me->query("can_perform/liushui-bian/wang"))
                return notify_fail("你还不会使用「望断秋水」这一绝技。\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail("「望断秋水」只能对战斗中的对手使用。\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "whip")
                return notify_fail("你使用的武器不对。\n");

        ap = me->query_skill("liushui-bian",1);

        if (userp(me) && ap < 120)
                return notify_fail("你的流水鞭法等级不够, 不能使用「望断秋水」！\n");

        if (me->query("neili") < 200)
                return notify_fail("你的真气不够，无法运用「望断秋水」！\n");

        msg = HIC "$N" HIC "一抖手中的" + weapon->name() + HIC
              "，挽出一朵鞭花，随即运气于臂，如气贯长虹般直向$n" HIC
              "击出。\n" NOR;

        dp = target->query_skill("dodge", 1);
        if (dp < 1)  dp = 1;
        if (ap / 2 + random(ap) > dp || ! living(target))
        {
                me->add("neili", -150);
                damage = ap + (int)me->query_skill("force", 1);
                damage = damage / 2 + random(damage / 2);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 70,
                                           HIR "$n" HIR "见来招凶猛，躲闪不及，登时被击"
                                           "个正中，不由一阵火辣辣的疼痛！\n" NOR);
                me->start_busy(1 + random(3));
        } else
        {
                me->add("neili", -40);
                msg += CYN "可是$n" CYN "看清来势，侧身避过$N"
                       CYN "这一招。\n"NOR;
                me->start_busy(3);
        }
        message_combatd(msg, me, target);
        return 1;
}

