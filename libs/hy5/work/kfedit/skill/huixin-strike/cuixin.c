#include <ansi.h>
#include <combat.h>
 
inherit F_SSERVER;
 
int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp;
        int damage, lvl;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail("夺命催心只能对战斗中的对手使用。\n");

        if (me->query_temp("weapon"))
                return notify_fail("你必须是空手才能使用夺命催心！\n");
 
        lvl = me->query_skill("huixin-strike", 1);

        if (lvl < 120)
                return notify_fail("你的峨嵋催心掌还不够纯熟！\n");

        if (me->query_skill("force") < 120)
                return notify_fail("你的内功火候太低，无法使出夺命催心。\n");

        if (me->query("neili") < 800)
                return notify_fail("你的内力不够，无法使出夺命催心。\n");
 
        msg = HIR "$N" HIR "聚气于掌，仰天一声狂啸，刹那间双掌交错，一招"
                  "「夺命催心」带着阴毒内劲直贯$n" HIR "！\n"NOR;

        ap = me->query_skill("strike") + lvl;
        dp = target->query_skill("parry");

        if (dp < 1) dp = 1;

        if ( ap / 2 + random(ap) > dp + random(dp) )
        {
        me->add("neili", -300);
        damage = lvl * 4 + random(lvl);
target->apply_condition("cuixin_zhang",35 );
   target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg += HIR "只听$n" HIR "惨叫一声，只感两耳轰"
               "鸣，目不视物，喷出一大口鲜血，软软瘫倒。\n" NOR;

        me->start_busy(2);
        }
    else
        {
        msg += HIY "$p见$P来势汹涌，急忙纵身一跃而起，躲开了这致命的一击！\n" NOR;
        me->add("neili", -300);
        me->start_busy(3);
        }
        message_combatd(msg, me, target);
if( (int)me->query_skill("huixin-strike", 1) >200 )
{
  msg = HIY "$N" HIY "运起全身功力，顿时真气迸发，全身骨骼噼啪作"
              "响，猛然一掌向$n" HIY "\n全力拍出，力求一击毙敌，正是一"
              "招「佛光普照」。\n" NOR;
         
        ap = me->query_skill("hand") +
             me->query_skill("force") +
             me->query("str") * 10;

        dp = target->query_skill("dodge") +
             target->query_skill("force") +
             me->query("con") * 10;

        damage = me->query_skill("hand")*2;

        if (target->query_skill_mapped("force") == "jiuyang-shengong")
        {
                me->add("neili", -200);
                me->start_busy(5);
                msg += HIW "只听轰然一声巨响，$n" HIW "已被一招正中，可$N"
                       HIW "只觉全身内力犹如江河入\n海，又如水乳交融，登"
                       "时消失得无影无踪。\n" NOR; 
        } else
        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili", -200);
                me->start_busy(3);
   target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                msg += HIR "只听轰然一声巨响，$n" HIR "被$N"
                                           HIR "一招正中，身子便如稻草般平平飞出"
                                           "，重\n重摔在地下，呕出一大口鲜血，动"
                                           "也不动。\n" NOR;

        } else 
        { 
                me->add("neili", -200);
                me->start_busy(3);
                msg += CYN "可是$p" CYN "内力深厚，及时摆脱了" 
                       CYN "$P" CYN "内力的牵扯，躲开了这一击！\n" NOR; 
        }
        message_combatd(msg, me, target);
}	
        return 1;
}

