#include <ansi.h>
#include <combat.h>

string name() { return HIR "威慑拳" NOR; }
string query_name() { return "威慑拳"; }
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;        
        int level, b;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(name() + "只能对战斗中的对手使用。\n");

        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail(name() + "只能空手施展。\n");

        if (target->is_busy())
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");

        if ((level = (int)me->query_skill("tiandaoquan", 1)) < 100)
                return notify_fail("你天道拳法火候不够，难以施展" + name() + "。\n");

        if (me->query_skill_mapped("unarmed") != "tiandaoquan")
                return notify_fail("你没有激发天道拳法，难以施展" + name() + "。\n");

        if (me->query_skill_prepared("unarmed") != "tiandaoquan")
                return notify_fail("你没有准备天道拳法，难以施展" + name() + "。\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("你的内功修为不够，难以施展" + name() + "。\n");

        if( me->query("max_neili")<100 )
                return notify_fail("你的内力修为不够，难以施展" + name() + "。\n");

        if( me->query("neili")<100 )
                return notify_fail("你现在的真气不足，难以施展" + name() + "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = WHT "$N" WHT "双拳交错，施出天道拳绝技「" HIR "威慑拳" NOR +
              WHT "」，旋起层层残影，笼罩$n" WHT "四方。\n" NOR;

        me->add("neili", -100);
        if (level + random(level)  > (int)target->query_skill("parry", 1))
        {
                msg += HIR "残影晃动间$n" HIR "招式陡然一紧，竟被$N"
                       HIR "的拳招牵引得手忙脚乱！\n" NOR;
                b = level / 20;
                target->start_busy(b);
                me->start_busy(1);
        } else

        {
                msg += CYN "可是$n" CYN "看破了$N"
                       CYN "的企图，镇定解招，一丝不乱。\n" NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);

        return 1;
}