#include <ansi.h>
#include <combat.h>

#define ZHUI "「" HIR "夺命" NOR "」"

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;

        if (me->query("family/family_name")!="红花会"
                &&me->query("chushi/last_family")!="红花会")
                return notify_fail("你所使用的外功中没有这种功能。\n");
        if (! target) target = offensive_target(me);
        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHUI "只能对战斗中的对手使用。\n");
        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对，难以施展" ZHUI "。\n");
        if (me->query_skill_mapped("sword") != "zhuihun-jian") 
                return notify_fail("你没有激发追魂夺命剑，难以施展" ZHUI "。\n");
        if ((int)me->query_skill("zhuihun-jian", 1) < 100)
                return notify_fail("你的追魂夺命剑还不够娴熟，难以施展" ZHUI "。\n");
        if (me->query("neili") < 200)
                return notify_fail("你现在真气不够，难以施展" ZHUI "。\n");
        if (! living(target))
               return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIR "$N" HIR "一声冷哼，手中" + weapon->name() +
              HIR "一式「夺命」，剑身顿时漾起一道血光，直射$n"
              HIR "！\n" NOR; 
        me->add("neili", -200);
        ap = me->query_skill("sword");
        dp = target->query_skill("dodge");

        me->start_busy(3);
        if (ap/2 + random(ap) > dp)
        {
                damage = ap/2 + random(ap/2);
                msg +=HIR "只听$n" HIR "一声惨叫，被这一剑穿胸而入，顿时鲜血四处飞溅。\n" NOR;
                message_vision(msg, me, target);
                target->receive_damage("qi",damage,me);
                target->receive_wound("qi",damage/3,me); 
                COMBAT_D->report_status(target);
        } else
        {
                msg += CYN "可$n" CYN "却是镇定逾恒，一丝不乱，"
                       "全神将此招化解开来。\n" NOR;
                message_vision(msg, me, target);
        }        

        return 1;
}

