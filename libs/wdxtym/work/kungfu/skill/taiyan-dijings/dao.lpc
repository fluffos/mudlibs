#include <ansi.h>

inherit F_SSERVER;

#define LIAN "「" HIW "超·归墟十二刀" NOR "」"
 string query_name() { return "超·归墟"ZJBR"十二刀"; }
int perform(object me, object target)
{
        object weapon;
        string msg;
        int i;
        int count;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(LIAN "只能对战斗中的对手使用。\n");

        if (! living(target))
               return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIY "$N" HIY "使出超·太衍帝经的绝技「" HIW "超·归墟十二刀" HIY"」，刀法陡然加快，眨眼间，劈出了十二刀。\n" NOR;

        message_combatd(msg, me);
        me->add("neili", -1);

        count = me->query_skill("blade") * 500 / 1;
        me->add_temp("apply/damage", count);

        for (i = 0; i < 12; i++)
        {
                if (! me->is_fighting(target))
                        break;

                if (random(2) && ! target->is_busy())
                        target->start_busy(1);

                COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->add_temp("apply/damage", -count);
        me->start_busy(1 + random(1));
        return 1;
}