// ding.c 全真剑-定阳针

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
int perform(object me, object target)
{
        object weapon;
        int damage,time;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("狂草只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "dagger")
                return notify_fail("你使用的武器不对。\n");

        if( (int)me->query_skill("ziwu-daxuefa", 1) < 140 )
                return notify_fail("你的子午打穴法不够娴熟，不能使用狂草。\n");

        if (me->query_skill_mapped("force") != "bluesea-force")
                return notify_fail("你使用的内功必须是南海玄功。\n");

        if( (int)me->query("neili", 1) < 950 )
                return notify_fail("你现在内力太弱，不能使用狂草。\n");
        
   
           if( (int)me->query_temp("nokc"))
                return notify_fail("你现在正在使用狂草。\n");
       
        msg = HIM "$N使出《裴将军诗》笔法，口中念道：：“裴将军！大君制六合，猛将清九垓。战马若龙虎，腾陵何壮哉！”。\n"NOR;

        //if( !target->is_killing(me) ) target->kill_ob(me);

        if (random(me->query_skill("dagger")) > target->query_skill("dodge")/3 )
        {
                me->start_busy(1);

                damage = (int)me->query_skill("dagger", 1) + (int)me->query_skill("force",1);
                //(全真剑法级别+基本内功)

                damage = damage/2 + random(damage/2);

                target->receive_damage("qi", damage);
                target->start_busy(4);
                me->add("neili", -100);
               time=8-((int)me->query_skill("ziwu-daxuefa",1)/40);
              if(me->query_skill("ziwu-daxuefa", 1) > 200)
                call_out("perform2", 0, me, target);    
me->set_temp("nokc",1);
                msg += HIR"$n不知$N写的是什么，被攻了个措手不及！\n"NOR;


        }
        else
        {
                me->start_busy(3);
                msg += GRN"$N这路狂草每一招只使出半招,立刻被$n封住。\n"NOR;
        }
        message_vision(msg, me, target);
        me->start_busy(1);
        return 1;
}
int perform2(object me, object target)
{
 object weapon, ob;
        string msg, string1;
        int count,time;
        
    weapon = me->query_temp("weapon");  
if (!me || !target) 
return 0;              
        if(!living(target)) 
          {
 me->delete_temp("nokc");
          return notify_fail("对手已经不能再战斗了。\n");
}
        if( (int)me->query("neili", 1) < 300 )
          {
 me->delete_temp("nokc");
                return notify_fail("你待要再出第二击，却发现自己的内力不够了！\n");     
}
        if(!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "dagger")
    return notify_fail("你现在没有使剑，无法进一步攻击。\n");
             msg = HIY+"$N大喝一声，笔法登变，不再如适才那么恣肆流动，而是劲贯中锋，笔致凝重，但锋芒角出，剑拔弩张，大有磊落波磔意态！\n" NOR;
        
        message_vision(msg, me,target);
        me->clean_up_enemy();
        ob = me->select_opponent();   
        if (!ob->is_busy() && random(2)==0)ob->start_busy(2);
        	                                me->add_temp("apply/attack", 100);
                me->add_temp("apply/damage", 1200);
        	
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);  
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
                                        me->add_temp("apply/attack", -100);
                me->add_temp("apply/damage", -1200);
        
        me->add("neili", -100);
    time= 1+((int)me->query_skill("dagger",1)/50);
        if(me->query_skill("ziwu-daxuefa", 1) > 300)
               call_out("perform3", 0, me, target);    
               //me->start_busy(2);
        return 1;
}

int perform3(object me, object target)
{
 object weapon, ob;
        string msg, string1;
        int count,time,i,damage;
        ob=target;
if (!me || !target) 
return 0;    
    weapon = me->query_temp("weapon");  
              
        if(!living(target)) 
           {
 me->delete_temp("nokc");
          return notify_fail("对手已经不能再战斗了。\n");
}
        if( (int)me->query("neili", 1) < 400 )
          {
 me->delete_temp("nokc");
                return notify_fail("你待要再出第三击，却发现自己的内力不够了！\n");     
}
        if(!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "dagger")
    return notify_fail("你现在没有使剑，无法进一步攻击。\n");
        me->add("neili", -100);
        //me->add("jing", -100);
        message_vision(BLU "\n$N笔法又变，大书《怀素自叙帖》中的草书，纵横飘忽，流转无方，草中加草,劲力充沛，令人眼花缭乱！\n" NOR,me, target);

                                me->add_temp("apply/attack", 100);
                me->add_temp("apply/damage", 1200);
        if (!ob->is_busy() && random(2)==0)ob->start_busy(2);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);  
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);  
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        me->delete_temp("nokc");

                                me->add_temp("apply/attack", -100);
                me->add_temp("apply/damage", -1200);
        //me->set_temp("mr_sanhua", 1); 
        i = (int)me->query_skill("dagger")/30;
        if( 15 - i <= 4) i = 4;
        //call_out("remove_effect", i, me);

                me->start_busy(2);
        return 1;
}
