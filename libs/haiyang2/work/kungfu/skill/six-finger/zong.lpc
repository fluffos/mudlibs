#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;


#define ZONG "「" HIM "纵横天下" NOR "」"

int perform(object me, object target)
{
        string msg;
        int ap, dp;
        int damage, skill;

        if (! target) target = offensive_target(me);
        

        
        if (! target || ! me->is_fighting(target))
                return notify_fail(ZONG "只能对战斗中的对手使用。\n");

        if (me->query_skill_prepared("finger") != "six-finger")
                return notify_fail("你没有准备使用六脉神剑，无法施展" ZONG "。\n");



        skill = me->query_skill("six-finger", 1);

        if (skill < 320)
                return notify_fail("你的六脉神剑修为有限，无法使用" ZONG "！\n");

        if (me->query_skill("force") < 280)
                return notify_fail("你的内功火候不够，难以施展" ZONG "！\n");

        if (me->query("max_neili") < 6500)
                return notify_fail("你的内力修为不够,无法施展" ZONG "！\n");

        if (me->query("neili") < 1250)
                return notify_fail("你的真气不够，现在无法施展" ZONG "！\n");

        if (me->query_temp("weapon"))
                return notify_fail("你必须是空手才能施展" ZONG "！\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        if ((int)me->query_skill("kurong-changong",1) < 180)
            return notify_fail("你的枯荣禅功太低。\n");
        if ((int)me->query_skill("duanjia-sword", 1) < 180)
		return notify_fail("你的段家剑火候太浅。\n");    
        if ((int)me->query_skill("jinyu-quan", 1) < 180)
		return notify_fail("你的金玉拳火候太浅。\n");
        if ((int)me->query_skill("wuluo-zhang", 1) < 180)
		return notify_fail("你的五罗轻烟掌火候太浅。\n");
        if ((int)me->query_skill("feifeng-whip", 1) < 180)
		return notify_fail("你的飞凤鞭火候太浅。\n");
        if ((int)me->query_skill("sun-finger", 1) < 180)
		return notify_fail("你的一阳指火候太浅。\n");
        if ((int)me->query_skill("yiyang-zhi", 1) < 180)
		return notify_fail("你的段氏一阳指火候太浅。\n");
				
        msg = HIM "$N" HIM "一声清啸，十指纷弹，顿觉六脉剑谱已涌上心头，此起"
              "彼伏、连绵不绝。霎时剑气如奔，连绵无尽的万道剑气豁然贯向$n" HIM 
              "！\n" NOR;

        ap = me->query_skill("six-finger", 1) +
             me->query_skill("force", 1) / 2;
        dp = target->query_skill("force");

        if (target->query_skill("martial-cognize", 1) >= 200
            && random (10) == 1 )
        {
                me->add("neili", -500);
                me->start_busy(3);
                msg += HIY "但见$n" HIY "会心一笑，轻拂衣袖，轻易的躲过这一招！\n"NOR;
        } else
        if (ap * 11 / 20 + random(ap) > dp)
        { 
                damage = me->query_skill("finger");
                me->add("neili", -500);
target->add("qi",-damage);
target->add("eff_qi",-damage);
target->apply_condition("yyz_damage",30);

                        msg +=HIR "只听$n" HIR "一声惨叫，万道剑气已"
                                           "透体而过，伤口处鲜血顿时狂涌，痛苦难当！\n" NOR;

                me->start_busy(2);
        } else
        {
                me->add("neili", -400);
                me->start_busy(3);
                msg += CYN "$n" CYN "见$N" CYN "来势汹涌，不敢轻易"
                       "招架，急忙提气跃开。\n" NOR;
        }
       message_combatd(msg, me, target); 
        msg = HIY "$N" HIY "摊开双手，手指连弹，霎时间空气炙热，几"
              "欲沸腾，六道剑气分自六穴，一起杀向$n" HIY "！\n" NOR;
        ap = me->query_skill("six-finger", 1) ;
        dp = target->query_skill("dodge"),1;
 if (random(ap)+10  > dp)
        {
                msg += HIM "$n久闯江湖，六脉神剑也识得二三，但何曾见过如此神妙之用法，一愣神之间先机已失，只得任人宰割。霎时无数剑气穿身而出，全身上下无数血洞，鲜血狂喷不止，真气涣散之下，奄奄一息。" + "\n" NOR;
target->start_busy(2);
        } else
        {
                msg += NOR + CYN "$p哪曾见过六脉神剑如此用法，心道必死无疑，当即双眼一闭，仰头便倒，昏倒在地，却恰好避过来招。" + "\n" NOR;
        }
        message_combatd(msg, me, target); 

      msg = HIR  "$N凌空跃起，使出了六脉神剑的最高绝技［六脉归宗］！！！\n$N杀红了眼，拼尽所有功力！！六道金光疾射而出，射向$n！" NOR;
        message_vision(msg,me,target);
        msg = HIG  "━━━━「少泽剑」！\n$N右手小指连点，剑气到处，所向无敌。" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg
);
        msg = HIY  "━━━━━━「商阳剑」！\n$N食指伸处，商阳剑法随之展动。" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg
);
        msg = HIB  "━━━━━━━━━「少冲剑」！\n$N左手小指一伸，一路剑气从少冲穴中激射而出。" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg
);
        msg = HIM  "━━━━━━━━━━━━「中冲剑」！\n$N中指一竖，中冲剑猛的向前刺出。" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg
);
        msg = HIC  "━━━━━━━━━━━━━━━「少商剑」！\n$N拇指急出，虚虚实实的指向$n。 " NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg
);
        msg = HIW  "━━━━━━━━━━━━━━━━━「关冲剑」！\n$N无名指回收，随之一甩，一道极光刺向$n的$l。
" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg
);
        msg = RED  "$N潜运神功，六脉和一，又是六道剑光！！\n一阴一阳，一奇一正，一上一下地射向$n的$l。" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg
);
me->add("neili", -300);
me->start_busy(5);
        return 1;
}


