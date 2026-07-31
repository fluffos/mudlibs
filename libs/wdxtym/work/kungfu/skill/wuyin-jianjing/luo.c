#include <ansi.h>
#include <combat.h>

#define LUO "「" HIW "群仙陨落" NOR "」"
string query_name() { return "群仙陨落"; }
string name() { return HIR "群仙陨落" NOR; }
inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg, wn;
        object weapon;
        int ap, dp;

        me = this_player();

       /*  if( userp(me) && !me->query("can_perform/wuyin-jianjing/luo") )
                return notify_fail("你所使用的外功中没有这种功能。\n"); */

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(LUO "只能在战斗中对对手使用。\n");

        if( !objectp(weapon=me->query_temp("weapon") )
            || weapon->query("skill_type") != "sword" )
                return notify_fail("你所使用的武器不对，难以施展" LUO "。\n");

        if ((int)me->query_skill("wuyin-jianjing", 1) < 200)
                return notify_fail("你无垠剑经不够娴熟，难以施展" LUO "。\n");

        if (me->query_skill_mapped("sword") != "wuyin-jianjing")
                return notify_fail("你没有激发无垠剑经，难以施展" LUO "。\n");

        if ((int)me->query_skill("force") < 600)
                return notify_fail("你的内功火候不够，难以施展" LUO "。\n");

        if( me->query("neili")<2000 )
                return notify_fail("你现在的真气不够，难以施展" LUO "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        wn = weapon->name();

        msg = HIW "\n$N" HIW "将" + wn + HIW "斜指长空，猛地飞身跃起，"
              + wn + HIW "长响一声，寒光闪闪，犹如一道闪电劈空而下，一招"
              "「" HIG "群仙陨落" HIW "」已使出，以千军不可挡之势袭向$n" HIW
              "。" NOR;

        message_sort(msg, me, target);

        ap = me->query_skill("sword")*8;
        dp = target->query_skill("sword");

        if (ap * 7 / 2 + random(ap) > dp)
        {
                damage = ap + random(ap * 9 / 2);
                 msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 350,
                                          HIR "$n" HIR "只见一道电光从半空袭来，"
                                          "心中惊骇不已，但鲜血已从$n胸口喷出。\n"
                                          NOR);
                 me->start_busy(2 + random(4));
                 me->add("neili", -2000);
        } else
        {
                 msg = CYN "然而$n" CYN "眼明手快，侧身一跳"
                      "躲过$N" CYN "这一剑。\n" NOR;

                 me->start_busy(2);
				 me->add("qi", -10000);
                 me->add("neili", -10000);
        }
        message_combatd(msg, me, target);

        return 1;
}

