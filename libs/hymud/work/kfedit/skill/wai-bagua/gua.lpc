#include <ansi.h>
#include <combat.h>

#define GUA "「" HIM "劈卦八卦拳" NOR "」"

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp,level;



        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(GUA "只能对战斗中的对手使用。\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(GUA "只能空手施展。\n");

        if ((int)me->query_skill("wai-bagua", 1) < 70)
                return notify_fail("你的外八卦不够娴熟，难以施展" GUA "。\n");

        if (me->query_skill_mapped("cuff") != "wai-bagua") 
                return notify_fail("你没有激发外八卦，难以施展" GUA "。\n");

        if (me->query_skill_prepared("cuff") != "wai-bagua") 
                return notify_fail("你没有准备外八卦，难以施展" GUA "。\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("你现在真气不够，难以施展" GUA "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

         level = me->query_skill("wai-bagua", 1);

        msg = HIG "$N" HIG "脚下步伐加快，使出八卦掌「罩」字诀，双掌"
              "舞出漫天掌影，将$n" HIG "笼罩在当中。\n" NOR;

        me->add("neili", -30);
        if (random(level) > (int)target->query_skill("parry", 1) / 2)
        {
                msg += HIR "$p" HIR "只觉无数掌影向自己袭来，手忙脚乱，"
                       "呆在当地，不知该如何应对！\n" NOR;
                target->start_busy(7);
        } else
        {
                msg += CYN "然而$p" CYN "看破了$P" CYN "的企图，纵身一跃，"
                       "已跳出了$P" CYN "的掌势。\n" NOR;
                me->start_busy(1);
        }
        message_combatd(msg, me, target);

        msg = HIM "$N" HIM "紧接着 突然身体一侧，双掌向下一沉，忽又向上一翻，朝着$n"
              HIM "的双肩斜斜地劈去！\n" NOR;

        ap = me->query_skill("cuff");
        dp = target->query_skill("parry");
        if (ap / 2 + random(ap) > dp)
        {
                damage = me->query_skill("cuff")*2+300;
                me->add("neili", -100);

                msg += HIR "只因这招实在太过巧妙，$n" HIR "被"
                                           "$N" HIR "攻了个措手不及，大叫一声，吐"
                                           "出一口鲜血！\n" NOR;
                me->add("neili", -50);

                target->add("qi",-damage);
		target->add("eff_qi",-damage);
		
                //message_combatd(msg, me, target);
                

                me->start_busy(2);
        } else 
        {
                msg += CYN "可是$n" CYN "看破了$N" CYN
                       "的这一招，镇定解招，一丝不乱。"
                       "\n" NOR;
                me->add("neili", -50);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}
