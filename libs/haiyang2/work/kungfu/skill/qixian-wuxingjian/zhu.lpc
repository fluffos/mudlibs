#include <ansi.h>
#include <combat.h>

#define ZHU "「" HIW "七弦连环诛" NOR "」"

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        object weapon;
        int i;
        int skill;
        int ap, an, dn;
        int count;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }


        if (! me->is_fighting(target))
                return notify_fail(ZHU "只能对战斗中的对手使用。\n");

        skill = me->query_skill("qixian-wuxingjian", 1);

        if (me->query_skill("force") < 300)
                return notify_fail("你的内功的修为不够，现在无法使用" ZHU "。\n");

        if (skill < 180)
                return notify_fail("你的七弦无形剑修为有限，现在无法使用" ZHU "。\n");

        if (me->query("neili") < 500)
                return notify_fail("你的真气不够，无法运用" ZHU "。\n");

        weapon = me->query_temp("weapon");

        if (weapon && weapon->query("skill_type") != "sword")
                return notify_fail("你不能使用这种兵器施展" ZHU "。\n");

        if (weapon && me->query_skill_mapped("sword") != "qixian-wuxingjian")
                return notify_fail("你现在没有准备使用七弦无形剑，无法施展" ZHU "。\n");

        if (me->query_skill_mapped("force") != "hamagong")
                return notify_fail("你没有激发蛤蟆功为内功，无法施展。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        if (weapon)
        {
                msg = HIW "只见$N" HIW "双目微闭，单手在" + weapon->name() +
                      HIW "上轻轻拨动，顿时只听“啵啵啵”破空之声连续不断"
                      "，数股破\n体无形剑气激射而出，直奔$n" HIW "而去。\n" NOR;
        } else
        {
                msg = HIW "只见$N" HIW "双目微闭，双手轻轻舞弄，陡然间十指一"
                      "并箕张，顿时只听“啵啵啵”破空之声连续不\n断，数股破"
                      "体无形剑气激射而出，直奔$n" HIW "而去。\n" NOR;
        }

        ap = me->query_skill("force");
        an = me->query("max_neili");
        dn = target->query("max_neili");

        if (an > dn)
        {
                msg += HIR "$p" HIR "只感到$P" HIR "内力澎湃，汹涌而至，霎"
                       "时心神惧碎，呆立当场！\n" NOR;
                count = ap / 8;
        } else
        {
                msg += HIC "$n" HIC "只感到$P" HIC "内力澎湃，汹涌而至，急"
                       "忙凝神聚气，小心应付。\n" NOR;
                count = ap / 15;
        }

        message_combatd(msg, me, target);
        me->add("neili", -250);
me->add_temp("apply/attack", count);
me->add_temp("apply/damage", 500);
        for (i = 0; i < 7; i++)
        {
                if (! me->is_fighting(target))
                        break;

                if (random(3) == 0 && ! target->is_busy())
                        target->start_busy(2);

                COMBAT_D->do_attack(me, target, weapon, 0);
        }
me->add_temp("apply/damage", -500);
        me->start_busy(2);
        me->add_temp("apply/attack", -count);
if (random(3)==0 && (int)me->query_skill("qixian-wuxingjian",1) > 300
&& (int)me->query_skill("zhaosheshu",1) > 200
&& (int)me->query_skill("yangsheshu",1) > 200)
{
	message_combatd(
        HIW "$N用蛤蟆功射出白蛇山独门怪蛇粉，射中了$n的全身！
$n被一团蛇雾笼罩，$n心口一阵巨痛！\n" NOR, me, target);
target->apply_condition("baituo_poison",50);
}
        return 1;
}
