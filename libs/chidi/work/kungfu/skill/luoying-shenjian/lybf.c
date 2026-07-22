// lybf.c 落英神剑之落英缤纷
// by victori
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int damage;
                int busy_time;
                int c,d;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「落英缤纷」只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if( (int)me->query_skill("luoying-shenjian", 1) < 200 )
                return notify_fail("你的落英神剑不够娴熟，不能使用「落英缤纷」。\n");

        if( (int)me->query_skill("qimen-wuxing", 1) < 100)
                return notify_fail("你的奇门五行修为太低，不能使用「落英缤纷」。\n");

        if( (int)me->query("neili", 1) < 150 )
                return notify_fail("你现在内力太弱，不能使用「落英缤纷」。\n");

        msg = HIM "$N配合奇门五行之奥妙阵法，使出桃花岛落英剑法之「落英缤纷」，剑锋直逼$n。\n"NOR;

        //if( !target->is_killing(me) ) target->kill_ob(me);

                c=me->query_skill("jing")+me->query_skill("qimen-wuxing");
                c+=me->query_skill("sword")+me->query_skill("dodge");
                d=target->query_skill("jing")+me->query_skill("qimen-wuxing");
                d+=target->query_skill("dodge");
        if (random(c) > d/2 )
                //双方的sword/dodge,qimen-wuxing与精神高低决定成功率
        {
                me->start_busy(3);

                damage = (int)me->query_skill("luoying-shenjian", 1) + (int)me->query_skill("qimen-wuxing");
                //(落英神剑级别+奇门五行)

                damage = damage/2 + random(damage/2);
                target->receive_damage("qi", damage);//气血减少

                                //令对手busy的时间=双方qimen-wuxing级别之差除10（小于4则按4秒计算）
                                if(((me->query_skill("qimen-wuxing")-target->query_skill("qimen-wuxing"))/10)<4)    
                                busy_time=4;
                                else busy_time=(int)((me->query_skill("qimen-wuxing")-target->query_skill("qimen-wuxing"))/10);
                                //>10则按10计算，削减威力，但会wound
                                if(busy_time>10) 
                                {
                                        target->receive_wound("qi", (busy_time-10)*10);
                                        busy_time=10;                                   
                                }

                target->start_busy(busy_time);

                me->add("neili", -150);
                                //损耗精神的写法
                                me->add("jing", -100);

                msg += HIR"$n无法识破奇门五行之精髓所在，身陷囹圄，面对$N的攻势，然不知所措！\n$N乘势又是刺出5剑...\n"NOR;
                                message_vision(msg, me, target);
                                //再出5招的写法
                                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                                me->set_temp("action_flag",1);
                                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                                me->set_temp("action_flag",0);
                  
                            
                               

        }
        else
        {
                me->start_busy(4);
                msg += CYN"可是$p看破了$P的企图，$N的招数尽被化解。\n"NOR;
                                message_vision(msg, me, target);
        }
        

        return 1;
}
