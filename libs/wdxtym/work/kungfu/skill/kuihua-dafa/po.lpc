#include <ansi.h>
#include <combat.h>

#define PO "「" HIW "破元剑闪" NOR "」"
string query_name() { return "破元"ZJBR"剑闪"; }
inherit F_SSERVER;

string final(object me, object target, int damage);

string *finger_name = ({ "左手中指", "左手无名指", "左手食指",
                         "右手中指", "右手无名指", "右手食指", });

int perform(object me, object target)
{
        int damage;
        string msg, name;
        object weapon;
        int lvl, ap, dp;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(PO "只能对战斗中的对手使用。\n");

        weapon = me->query_temp("weapon");

        if (weapon && weapon->query("skill_type") != "sword"
           && weapon->query("skill_type") != "pin")
                return notify_fail("你使用的武器不对，难以施展" PO "。\n");

        if ((int)me->query_skill("kuihua-dafa", 1) < 180)
                return notify_fail("你的葵花神功不够娴熟，难以施展" PO "。\n");

        if ((int)me->query("max_neili") < 2600)
                return notify_fail("你的内力修为不足，难以施展" PO "。\n");

        if (me->query("neili") < 300)
                return notify_fail("你现在的真气不足，难以施展" PO "。\n");

        if (weapon && me->query_skill_mapped("sword") != "kuihua-dafa")
                return notify_fail("你没有准备使用葵花神功，难以施展" PO "。\n");


        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");


        if (me->query_temp("weapon"))
                name = "手中" + weapon->name();
        else
                name = finger_name[random(sizeof(finger_name))];

        msg = HIW "$N" HIW "一声冷哼，双眸间透出一丝寒气，" + name +
              HIW "化作千百根相似，幻出死亡的色彩！\n" NOR;

        ap = me->query_skill("sword") +
             me->query_skill("dodge");

        dp = target->query_skill("parry") +
             target->query_skill("dodge");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap + random(ap)+600;
                target->add("qi",-damage);
		target->add("eff_qi",-damage);
                target->set("neili", target->query("neili")/2);
                msg +=HIR "$n" HIR "只觉眼前寒芒一闪而过，随即全身一阵"
               "刺痛，几股血柱自身上射出。\n$p陡然间一提真气，"
               "竟发现周身力道竟似涣散一般，全然无法控制。\n" NOR;
                me->start_busy(3);
                me->add("neili", -200);
        } else
        {
                msg += CYN "$n" CYN "大惊之下全然无法招架，急忙"
                       "抽身急退数尺，躲开了这一招。\n" NOR;
                me->start_busy(3);
                me->add("neili", -150);
        }
        message_combatd(msg, me, target);
        return 1;
}

