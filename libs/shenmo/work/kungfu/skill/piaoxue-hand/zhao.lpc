#include <ansi.h>
#include <combat.h>

#define ZHAO "「" HIY "佛光普照" NOR "」"

inherit F_SSERVER;

         
int perform(object me, object target) 
{ 
        object weapon; 
        string msg; 
        int ap, dp; 
        int damage; 


        if (! target) target = offensive_target(me); 
        
        if (! target || ! me->is_fighting(target)) 
                return notify_fail(ZHAO "只能在战斗中对对手使用。\n"); 
         
        if (me->query_temp("weapon") || 
            me->query_temp("secondary_weapon")) 
                return notify_fail("你必须空手才能施展" ZHAO "。\n"); 
         
        if (me->query_skill("force") < 300) 
                return notify_fail("你的内功的修为不够，无法施展" ZHAO "。\n"); 
        
        if (me->query_skill("piaoxue-hand", 1) < 180) 
                return notify_fail("你的飘雪穿云手修为不够，无法施展" ZHAO "。\n"); 
         
        if (me->query("neili") < 1000 || me->query("max_neili") < 3500) 
                return notify_fail("你的真气不够，无法施展" ZHAO "。\n"); 



        if (me->query_skill_mapped("hand") != "piaoxue-hand") 
                return notify_fail("你没有激发飘雪穿云手，无法施展" ZHAO "。\n"); 


       

        if (! living(target))
               return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIY "$N" HIY "运起全身功力，顿时真气迸发，全身骨骼噼啪作"
              "响，猛然一掌向$n" HIY "\n全力拍出，力求一击毙敌，正是一"
              "招「佛光普照」。\n" NOR;
         
        ap = me->query_skill("hand") +
             me->query_skill("force") +
             me->query("str") * 10;

        dp = target->query_skill("dodge") +
             target->query_skill("force") +
             me->query("con") * 10;

        damage = me->query_skill("hand");

        if (target->query_skill_mapped("force") == "jiuyang-shengong")
        {
                me->add("neili", -800);
                me->start_busy(5);
                msg += HIW "只听轰然一声巨响，$n" HIW "已被一招正中，可$N"
                       HIW "只觉全身内力犹如江河入\n海，又如水乳交融，登"
                       "时消失得无影无踪。\n" NOR; 
        } else
        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili", -800);
                me->start_busy(3);
   target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                msg += HIR "只听轰然一声巨响，$n" HIR "被$N"
                                           HIR "一招正中，身子便如稻草般平平飞出"
                                           "，重\n重摔在地下，呕出一大口鲜血，动"
                                           "也不动。\n" NOR;

        } else 
        { 
                me->add("neili", -500);
                me->start_busy(4);
                msg += CYN "可是$p" CYN "内力深厚，及时摆脱了" 
                       CYN "$P" CYN "内力的牵扯，躲开了这一击！\n" NOR; 
        }
        message_combatd(msg, me, target);
       
        return 1; 
}

