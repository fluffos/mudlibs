#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string dodskill,msg;
        int extra;
        int tmp;
        int basic;
        int i, flag;
        object weapon;
        
         extra = me->query_skill("music",1);
        if ( extra < 30) return notify_fail("你的琴道还不够纯熟！\n");
                
        dodskill = (string) me->query_skill_mapped("dodge");

    if( (int)me->query_skill("xuantian-wuji", 1) < 50 )
	return notify_fail("你的本门内功还未练成，不能使用！\n");

    if( (int)me->query("neili") < 600 )
    return notify_fail("你的内力不够。\n");
        
                
        basic = extra/40 + tmp/40;
        if (basic>7)
                basic=7;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［瑶琴七弦］只能对战斗中的对手使用。\n");
                
        weapon = me->query_temp("weapon");
        msg = HIR"$N 仰天长啸 一弦为黄钟，三弦为宫调。五调为慢角！啸声震天！\n"NOR;
        message_vision(msg, me, target);
        if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp"))
   {
                message_vision("结果$N目瞪口呆，不知如何招架！\n",target);
				if (!target->is_busy()) 
                            target->start_busy(5);

                        msg = HIY"长啸声中，$N凌空下击，接着又借力上跃！\n"NOR;
                        message_vision(msg, me, target);
                me->add_temp("apply/attack",100);
                me->add_temp("apply/damage",2000);
                for(i=0;i<basic;i++)
                {
                        if (me->is_busy()) continue;
              msg=HIG"瑶琴七弦 第"+(i+1)+"式"NOR;
              COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

 me->add("neili",-50);
                }
				me->add_temp("apply/attack",-100);
                me->add_temp("apply/damage",-2000);
                        me->start_busy(3);

        }
        else{
                message_vision("但是$N已经看破$n的攻式，$n处处受制！\n",target,me);
                me->start_busy(2);
              
                
        }
       
        return 1;
}      
