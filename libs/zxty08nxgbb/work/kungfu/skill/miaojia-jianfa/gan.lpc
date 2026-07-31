// By KinGSo@舞林 2006年4月25日 

#include <ansi.h> 
#include <combat.h>
inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";

#define GAN "「" HIY "流星赶月" NOR "」"



int perform(object me, object target)
{
        int damage, p;

        string msg;
        object weapon;
        int ap, dp, wn;

       

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(GAN "只能在战斗中对对手使用。\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对，难以施展" GAN "。\n");

        if ((int)me->query_skill("miaojia-jianfa", 1) < 150)
                return notify_fail("你苗家剑法不够娴熟，难以施展" GAN "。\n");

        if ((int)me->query_skill("force") < 150 )
                return notify_fail("你的内功火候不够，难以施展" GAN "。\n");

        if ((int)me->query("max_neili") < 2000)
                return notify_fail("你的内力修为不够，难以施展" GAN "。\n");

        if ((int)me->query("neili") < 600)
                return notify_fail("你现在真气不够，难以施展" GAN "。\n");

      if (me->query_skill_mapped("sword") != "miaojia-jianfa")
                return notify_fail("你没有激发苗家剑法，难以施展" GAN "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        wn = weapon->name();

        msg = HIY "$N" HIY "凝聚内力，手中" + wn + HIY "迸出万道光华，蓦然间破空"
              "声骤响，" + wn + HIY "竟离手射出，流星般向$n" HIY "奔去！\n" NOR;

        ap = me->query_skill("sword");
        dp = target->query_skill("dodge");
        if (ap / 2 + random(ap) > dp)
        {
               damage = ap *6 + random(ap * 8);
                me->add("neili", -150);
             

                if (damage > 7000) damage = 7000 + random(1000);  

                 target->receive_damage("qi", damage, me);
                target->receive_wound("qi", damage/2, me);
                me->add("neili", -500);
                if (me->query("neili") < 0)
                      me->set("neili",0);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");

                msg += HIR "$n" HIR "顿时大惊失色，只觉胸口处一凉，那柄" + wn + HIR "竟然已经穿胸透过，带出一蓬血雨！\n" NOR;
                me->add("neili", -500);
          msg += "( $n"+eff_status_msg(p)+" )\n"; 
             me->start_busy(1 + random(1));

        } else
        {
                me->start_busy(4);
                msg += HIC "$n" HIC "见" + wn + HIC "来势汹涌，心知绝"
                       "不可挡，当即向后横移数尺，终于躲闪开来。\n" NOR;
                me->add("neili", -500);
        }

        if (userp(me) && (int)me->query_skill("miaojia-jianfa", 1) < 260)
        {
                msg += HIY "只见" + wn + HIY "余势不尽，又向前飞出数"
                       "丈，方才没入土中。\n" NOR;
        	weapon->move(environment(me));
	} else
                msg += HIY "然而$N" HIY "身形一展，登时跃出数丈，掌"
                       "出如风，将射出的" + wn + HIY "又抄回手中。\n" NOR;

        message_vision(msg, me, target);
    me->start_perform(4,"「流星赶月」");
        return 1;
}
