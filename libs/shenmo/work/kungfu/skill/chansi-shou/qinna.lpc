#include <ansi.h>
#include <combat.h>
 
inherit F_SSERVER;


int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, damage;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail("缠丝擒拿手只能在战斗中对对手使用。\n");

        skill = me->query_skill("chansi-shou", 1);

        if (skill < 120)
                return notify_fail("你的缠丝擒拿手等级不够，不会使用绝技！\n");

        if (me->query("neili") < 100)
                return notify_fail("你的真气不够，无法运用绝技！\n");
 
        if (me->query_skill_mapped("hand") != "chansi-shou") 
                return notify_fail("你没有激发缠丝擒拿手，无法使用绝技！\n");

        msg = HIC "$N" HIC "悄然贴近$n" HIC "，猛然使出缠丝擒拿手，只见$P"
              "双手忽折忽扭，或抓或甩，直琐$n" HIC "各处要脉！\n" NOR;
 
        ap = me->query_skill("hand");
        dp = target->query_skill("parry");
        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili", -80);
                damage = me->query_skill("hand");
target->add("qi",-damage*2);
target->add("eff_qi",-damage*2);

                        msg +=HIR "$p" HIR "奋力抵抗，终究不敌$P"
                                           HIR "，连中数招后还是被压制得无法"
                                           "反击！\n" NOR;
                me->start_busy(1);
                if (ap / 3 + random(ap) > dp && ! target->is_busy())
                        target->start_busy(5);
        } else
        {
                msg += CYN "可是$p" CYN "的看破了$P" CYN
                       "的招式，巧妙的一一拆解，没露半点破绽！\n" NOR;
                me->add("neili",-20);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}

