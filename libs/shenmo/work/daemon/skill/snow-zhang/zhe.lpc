#include <ansi.h>
#include <combat.h>

#define ZHE "「" HIG "只手遮天" NOR "」"

inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";

string final(object me, object target, int lvl);

int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp;
        int lvl, p;
        int count;
	int i, attack_time;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHE "只能对战斗中的对手使用。\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(ZHE "只能空手施展。\n");

   if( (int)me->query_skill("bingxue-xinfa", 1) < 170 )
   return notify_fail("你的冰雪心法火候不够，使不出「"+HIW"烟雪春梅"NOR+"」。\n");

    if( (int)me->query_skill("snow-zhang", 1) < 100 )
   return notify_fail("你的飞雪映梅掌不够熟练，不会使用「"+HIW"烟雪春梅"NOR+"」。\n");


        if ((int)me->query("max_neili") < 2000)
                return notify_fail("你的内力修为不足，无法施展" ZHE "。\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("你的真气不够，无法施展" ZHE "。\n");

       if (! living(target))
              return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIW "\n$N" HIW "运起玄冥神功，全身浮现出一层紫气，猛然间双掌翻腾不息，施"
                  "展出绝招「" HIG "只手遮天" HIW "」，携带着万古至毒至寒之气的掌劲"
                  "攻向$n" HIW "！\n"NOR;  

        lvl = me->query_skill("snow-zhang", 1);

        ap = me->query_skill("strike") + me->query_skill("force");
        dp = target->query_skill("dodge") + target->query_skill("force");

        me->start_busy(4);

        if (ap / 2 + random(ap) > dp)
        { 
                damage = ap + random(ap / 2);
                me->add("neili", -300);
     
                // 玄冥寒毒反噬
                if (target->query("max_neili") * 3 / 5 > me->query("max_neili"))
                {
                        message_vision(msg, me, target);
                        message_vision(HIM "$N" HIM "一掌打在$n" HIM "身上，猛然间气血翻腾，一股阴寒之气竟"
                                     "反噬回来，$N" HIM "抵御不住，寒毒侵入体内。$N" HIM "闷哼一声，一"
                                     "口淤血吐出，脸色顿时发紫。" NOR, me, target);

                        me->receive_wound("qi", me->query("jiali") + random(me->query("jiali") / 2));

                        p = (int)me->query("qi") * 100 / (int)me->query("max_qi");
                        msg = "( $N" + eff_status_msg(p) + " )\n\n";
                        message_vision(msg, me, target);

                        me->apply_condition("xuanming_poison",10);

                        return 1;
                        
                } 
        

        target->apply_condition("ice_poison",50);
        target->apply_condition("xuantian_han",50);
        target->apply_condition("xuanming_poison",50);
                msg += HIR "$n" HIR "只见眼前紫影晃动，突然间胸口一震，已知大势"
               "不妙，只感胸口处一股寒气升起，尽损三焦六脉。\n" NOR;
                                           
        } else
        {
                msg += HIY "$n" HIY "看见$N" HIY "来势汹涌，急忙提气跃开。\n" NOR;
                me->add("neili", -180);
        }
        message_vision(msg, me, target);
attack_time=(int)me->query_skill("snow-zhang", 1) /40;
        if (attack_time > 7)
                attack_time = 7;
        me->add_temp("apply/attack", 50);
        me->add_temp("apply/damage", 200);
        me->add("neili", -attack_time * 30);


	for (i = 0; i < attack_time; i++)
	{
                if (! target->is_busy() && random(5) == 1)
                       target->start_busy(2);
 
         msg = HIG "$N双掌连环，推出第"+(i+1)+"掌！\n"NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	}
        me->add_temp("apply/attack", -50);
        me->add_temp("apply/damage", -200);
        return 1;
}

