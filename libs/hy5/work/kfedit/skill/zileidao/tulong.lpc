// tulong.c 天打雷辟屠真龙

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int skill, ap, dp;
        int force_wound, kee_wound ;
         string msg;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「天打雷辟屠真龙」？\n");

  if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("只能在战斗中使用。\n");

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "lengyue-shengong")
                return notify_fail("请使用冷月神功!\n");

        if((int)me->query_skill("lengyue-shengong",1) < 200)
                return notify_fail("你的冷月神功还不够。。。\n"); 
        if((int)me->query("neili") < 500 )
                return notify_fail(WHT"你的内力不足。\n"NOR);

        if(!me->is_fighting())
                return notify_fail("「天打雷辟屠真龙」只能在战斗中使用！\n");

        if((int)me->query("max_neili") < 500 )
                return notify_fail("你的内力不够！\n");

	if((int)me->query("neili") < 500 )
		return notify_fail("你的内力不足！\n");

        if((int)me->query("jing") < 500 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

        if((int)me->query_skill("zileidao", 1) < 200)
                return notify_fail("你的紫雷刀法级别还不够，使用这一招会有困难！\n");

 
        me->delete("env/brief_message");
	target->delete("env/brief_message");

	message_vision(HIC"\n$N运足精神，身形一转，霹雳间连续向$n攻出了七招！\n"NOR,me,target);
        me->add_temp("apply/attack", 100);
        me->add_temp("apply/damage", 800);
            target->start_busy(1);
        message_vision(HIC"\n$N第一招——春雷暴极！"NOR,me,target);
        me->set_temp("QJB_perform", 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        message_vision(HIC"\n$N第二招——沉雷地狱！"NOR,me,target);
        me->set_temp("QJB_perform", 2);  
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

        message_vision(HIC"\n$N第三招——天旋雷轰！"NOR,me,target);
        me->set_temp("QJB_perform", 3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        message_vision(HIC"\n$N第四招——冬雷霹雳！"NOR,me,target);
        me->set_temp("QJB_perform", 4);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        message_vision(HIC"\n$N第五招——狂雷震九宵！"NOR,me,target);
        me->set_temp("QJB_perform", 5);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        message_vision(HIC"\n$N第六招——惊雷爆五岳！"NOR,me,target);
        me->set_temp("QJB_perform", 6);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        message_vision(HIC"\n$N第七招——怒雷撕天裂地！"NOR,me,target);
        me->set_temp("QJB_perform", 7);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->delete_temp("QJB_perform");

        me->add_temp("apply/attack", -100);
        me->add_temp("apply/damage", -800);
        me->add("qi", -100);



me->start_busy(3);

if ((int)me->query_skill("zileidao",1)>= 380)
	{
  msg = HIC "$N聚气于掌，使出一招「雷火必杀」，向$n的胸口击去。\n"NOR;

        message_vision(msg, me, target);

        ap = me->query("combat_exp") + skill * 800;
        dp = target->query("combat_exp") ;

        if( dp < 1 )
                dp = 1;
        if( random(ap+dp) > (dp*3/7) )
        {
                if(userp(me))
                        me->add("neili",-100);

                msg = HIG "$n只觉得眼前一黑，“哇”的一声喷出一口鲜血！\n"NOR;

                force_wound = 200 + random(skill)*3;
                if(force_wound > target->query("neili"))
                        force_wound = target->query("neili");


                    kee_wound = force_wound /2;
                              
                if(kee_wound > target->query("eff_qi"))
                        kee_wound = target->query("eff_qi");
        if (kee_wound < 0) kee_wound=100;
if (kee_wound> 38000) kee_wound=38000;
                target->receive_damage("qi", kee_wound);
                target->receive_wound("qi", kee_wound/3);
                me->start_busy(2);
                target->start_busy(2);
             

       }
        else
        {
                msg = HIG "只见$n不慌不忙，轻轻一闪，躲过了$N的必杀一击！\n"NOR;
                if(userp(me))
                        me->add("neili",-100);
                me->start_busy(2);
        }
        message_vision(msg, me, target);
}
  
        return 1;
}

