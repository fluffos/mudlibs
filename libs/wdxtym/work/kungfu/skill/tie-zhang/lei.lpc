#include <ansi.h>
#include <combat.h>

string name() { return HIR "掌心雷" NOR; }
string query_name() { return "掌心雷"; }
inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int ap, dp;
        int damage;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(name() + "只能对战斗中的对手使用。\n");

        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail(name() + "只能空手施展。\n");
			
			if(me->query("family/family_name")!="绝情谷")
                return notify_fail("不是绝情谷的不能用使用！\n");

        if ((int)me->query_skill("tie-zhang", 1) < 160)
                return notify_fail("你铁掌掌法火候不够，难以施展" + name() + "。\n");

        if (me->query_skill_mapped("strike") != "tie-zhang")
                return notify_fail("你没有激发铁掌掌法，难以施展" + name() + "。\n");

        if (me->query_skill_prepared("strike") != "tie-zhang")
                return notify_fail("你没有准备铁掌掌法，难以施展" + name() + "。\n");

        if ((int)me->query_skill("force") < 240)
                return notify_fail("你的内功修为不够，难以施展" + name() + "。\n");

        if( me->query("max_neili")<2500 )
                return notify_fail("你的内力修为不够，难以施展" + name() + "。\n");

        if( me->query("neili")<300 )
                return notify_fail("你现在的真气不足，难以施展" + name() + "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = WHT "$N" WHT "运转真气施出「" HIR "掌心雷" NOR +
              WHT "」绝技，双掌翻红，有如火烧，朝$n" WHT "猛"
              "然拍出。\n" NOR;

        ap=me->query_skill("strike")+me->query_str()*10;
        dp=target->query_skill("parry")+target->query_con()*10;

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap;
                damage+= me->query("jiali");
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 85,
                                           HIR "结果只听$n" HIR "一声闷哼，被$N"
                                           HIR "一掌劈个正着，口中鲜血狂喷而出。"
                                           "\n" NOR);
                me->add("neili", -250);
                me->start_busy(2);
        } else
        {
                msg += CYN "$n" CYN "眼见$N" CYN "来势汹涌，丝毫"
                       "不敢小觑，急忙闪在了一旁。\n" NOR;
                me->add("neili", -100);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}