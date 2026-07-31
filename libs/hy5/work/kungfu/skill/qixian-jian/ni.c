#include <ansi.h>
#include <combat.h>

#define NI "「" HIW "逆转乾坤" NOR "」"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;
int skill;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(NI "只能对战斗中的对手使用。\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对，难以施展" NI "。\n");

        if (me->query_skill("force") < 300)
                return notify_fail("你的内功的修为不够，难以施展" NI "。\n");



        if (me->query("neili") < 400)
                return notify_fail("你的真气不够，难以施展" NI "。\n");

skill=me->query_skill("qixian-jian",1);
        if (skill < 180)
                return notify_fail("你的七弦无形剑修为有限，现在无法使用" NI "。\n");

        if (me->query("neili") < 500)
                return notify_fail("你的真气不够，无法运用" NI "。\n");

        weapon = me->query_temp("weapon");

        if (weapon && weapon->query("skill_type") != "sword")
                return notify_fail("你不能使用这种兵器施展" NI "。\n");

        if (weapon && me->query_skill_mapped("sword") != "qixian-jian")
                return notify_fail("你现在没有准备使用七弦无形剑，无法施展" NI "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIW "$N" HIW "一声清啸，手中" + weapon->name() +
              HIW "一振，将乾坤剑法逆行施展，顿时剑影重重，万"
              "道光华直追$n" + HIW "而去！\n" NOR;

        ap = me->query_skill("sword") + me->query_skill("force");
        dp = target->query_skill("dodge") + target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap / 3 + random(ap / 3);
                me->add("neili", -200);
                me->start_busy(2);
                        target->add("qi",-damage+100);
                        target->add("qi",-damage+100);
if (random(3)==0) target->start_bus(5);
                        msg +=HIR "$n" HIR "完全无法看清招中虚实，微"
                                           "微一楞间，发现" + weapon->name() + HIR
                                           "竟已没入自己胸口数寸。\n" NOR;
        } else
        {
                me->add("neili", -80);
                me->start_busy(2);
                msg += CYN "可是$n" CYN "看破" CYN "$N" CYN
                       "的招数，飞身一跃，闪开了这神鬼莫测"
                       "的一击。\n"NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
