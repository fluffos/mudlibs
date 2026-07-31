// Updated by Lonely

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        string msg, pmsg;
        int damage, ap, dp;
        
        if (! target) target = offensive_target(me);

        if (! target
        ||      ! target->is_character()
        ||      ! me->is_fighting(target))
                return notify_fail("牵制攻击只能对战斗中的对手使用。\n");

        if ((int)me->query_str() < 30)
                return notify_fail("你臂力不够,不能使用这一绝技!\n");

        if ((int)me->query_skill("yinyun-ziqi", 1) < 100)
                return notify_fail("你氤氲紫气的功力不够不能使用倚天屠龙绝技!\n");

        if ((int)me->query("neili") < 800)
                return notify_fail("你内力现在不够, 不能使用倚天屠龙! \n");

        msg = HIY "$N长啸一声：" + YEL "武林至尊、宝刀屠龙。号令天下，莫敢不从。倚天不出，谁与争锋？\n" + 
              HIY "手中两般武器发出无穷罡气，或如灵蛇盘腾，或如猛兽屹立，须臾间二十四字一齐写毕。\n"NOR;

        ap = me->query_skill("yitian-tulong", 1) * 3 / 2 + me->query("level") * 20 +  
             me->query_skill("martial-cognize", 1); 

        dp = target->query_skill("force") + target->query("level") * 20 +
             target->query_skill("martial-cognize", 1); 

        if (ap / 2 + random(ap) > dp) 
        {
                damage = (int)me->query_skill("yitian-tulong", 1);
                
                damage = damage/2 + random(damage/2);
        
                me->add("neili", -500);
                
                if (damage < 20)
                        pmsg = HIY"结果$n受到$N的内力反震，闷哼一声。\n"NOR;
                else if (damage < 40)
                        pmsg = HIY"结果$n被$N以内力反震，「嘿」地一声退了两步。\n"NOR;
                else if (damage < 80)
                        pmsg = RED"结果$n被$N以内力一震，胸口有如受到一记重锤，连退了五六步！\n"NOR;
                else
                        pmsg = HIR"结果$n被$N的内力一震，眼前一黑，象一捆稻草一样飞出去好几丈远！\n"NOR;
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 35, pmsg);
                        
                me->start_busy(1);
                target->start_busy(random(3));          
                
        }
        else 
        {
                me->start_busy(2);
                me->add("neili", -200);
                msg += CYN"可是$p看破了$P的企图，并没有上当，轻轻一闪便躲开了。\n"NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}

