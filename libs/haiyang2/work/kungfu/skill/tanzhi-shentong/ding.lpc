#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";

#define DING "「" HIC "定昆仑" NOR "」"

inherit F_SSERVER;


int perform(object me, object target)
{
        string msg;
        int ap, dp;
object weapon,weapon2;
int damage,p;
        string pmsg;
        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(DING "只能对战斗中的对手使用。\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(DING "只能空手施展。\n");

        if (target->is_busy())
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");

        if ((int)me->query_skill("tanzhi-shentong", 1) < 120)
                return notify_fail("你的弹指神通不够娴熟，难以施展" DING "。\n");

        if (me->query_skill_mapped("finger") != "tanzhi-shentong")
                return notify_fail("你没有激发弹指神通，难以施展" DING "。\n");

        if (me->query_skill_prepared("finger") != "tanzhi-shentong")
                return notify_fail("你没有准备弹指神通，难以施展" DING "。\n");

        if (me->query("max_neili") < 1500)
                return notify_fail("你的内力修为不足，难以施展" DING "。\n");

        if (me->query("neili") < 600)
                return notify_fail("你现在的真气不够，难以施展" DING "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");
        if ((int)me->query_skill("bibo-shengong", 1) < 120)
                return notify_fail("你的碧波神功火候太浅。\n");
        if ((int)me->query_skill("anying-fuxiang", 1) < 120)
                return notify_fail("你的暗影浮香火候太浅。\n");
        if ((int)me->query_skill("lanhua-shou", 1) < 120)
                return notify_fail("你的兰花拂穴手火候太浅。\n");
        if ((int)me->query_skill("luoying-shenjian", 1) < 120)
                return notify_fail("你的落英神剑火候太浅。\n");
        if ((int)me->query_skill("luoying-zhang", 1) < 120)
                return notify_fail("你的落英神剑掌火候太浅。\n");
        if ((int)me->query_skill("tanzhi-shentong", 1) < 120)
                return notify_fail("你的弹指神通火候太浅。\n");
        if ((int)me->query_skill("xuanfeng-leg", 1) < 120)
                return notify_fail("你的旋风扫叶腿火候太浅。\n");
        if ((int)me->query_skill("yuxiao-jian", 1) < 120)
                return notify_fail("你的玉箫剑法火候太浅。\n");
       if ((int)me->query_skill("count", 1) < 120)
                return notify_fail("你的阴阳八卦火候太浅。\n");
       if ((int)me->query_skill("qimen-wuxing", 1) < 120)
                return notify_fail("你的奇门五行火候太浅。\n");
        msg = HIC "$N" HIC "合指轻弹，顿时只听“飕”的一声，一缕若有若无的"
              "罡气已朝$n" HIC "电射而去。\n" NOR;

        ap = me->query_skill("finger");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                msg +=  HIR "$n" HIR "只觉胁下一麻，已被$P"
                        HIR "指气射中，全身酸软无力，呆立当场。\n" NOR;
                target->start_busy(6);
                me->start_busy(1);
                me->add("neili", -100);
        } else
        {
                msg += CYN "可是$p" CYN "看破了$P" CYN
                       "的企图，轻轻一跃，跳了开去。\n" NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);
     msg = HIW "陡见$N" HIW "双目精光四射，顿听破空声大作，一枚石子由指尖弹出，疾速射向$n" HIW "。\n" NOR;

        ap = me->query_skill("finger") + me->query_skill("force");
        dp = target->query_skill("dodge") + target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                me->start_busy(2);
                damage = me->query_skill("finger");

                msg += HIR "只见那石子来势迅猛之极，$n" HIR
                       "根本无暇闪避，被这招击个正中！\n" NOR;

                target->receive_damage("qi", damage*2);
                target->receive_wound("qi", damage*2);
                COMBAT_D->clear_ahinfo();

                if ((weapon2 = target->query_temp("weapon"))
                   && ap / 3 + random(ap) > dp)
                {
                        msg += HIW "$n" HIW "手腕一麻，手中" + weapon2->name() +
                               HIW "不由脱手而出！\n" NOR;
                        weapon2->move(environment(me));
                }

                p = (int)target->query("qi") * 100 / (int)target->query("max_qi");
                if (stringp(pmsg = COMBAT_D->query_ahinfo()))
                        msg += pmsg;
                        msg += "( $n" + eff_status_msg(p) + " )\n";
                message_combatd(msg, me, target);
        } else
        {
                me->start_busy(3);
                msg += CYN "可是$p" CYN "早料得$P" CYN "有此一着，急"
                       "忙飞身跃起，躲闪开来。\n" NOR;
                message_combatd(msg, me, target);
        }
        return 1;
}

