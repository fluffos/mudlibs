#include <ansi.h>

inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";
 
int perform(object me, object target)
{       
        string msg;
        int damage, p;

        if( !target ) target = offensive_target(me);
 
         if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail("「阳关三叠」只能在战斗中使用。\n");
        
        if( objectp( me->query_temp("weapon")) )
                return notify_fail("只有空手才能施展「阳关三叠」。\n");

        if( (int)me->query_skill("yiyang-zhi", 1) < 100 ||
            (int)me->query_skill("finger", 1) < 100 ||
            (int)me->query_str() < 25)
                return notify_fail("你有的功夫还不够娴熟，不会使用「阳关三叠」。\n");

        if(!me->query_skill("kurong-changong", 1))
           if(me->query_skill("kurong-changong", 1) <180)
                return notify_fail("以你现在的内功修为还使不出「阳关三叠」。\n");        
         
//           if (me->query_skill_mapped("force") != "kurong-changong" )
//            if (me->query_skill_mapped("force") != "qiantian-yiyang")
//                return notify_fail("你所使用的内功不对。\n");

        if ( me->query_skill_mapped("finger") != "yiyang-zhi" )
                return notify_fail("你现在无法使用「阳关三叠」进行攻击。\n");  
      
//            if (me->query_skill_mapped("parry") != "kurong-changong" )
            if (me->query_skill_mapped("parry") != "yiyang-zhi")
                return notify_fail("你所使用的招架不对。\n");
        if( (int)me->query("neili") < 1200 )
                return notify_fail("你的内力修为太弱，不能使用「阳关三叠」！\n");

        
        if( (int)me->query("neili") < 800 )
                return notify_fail("你的真气不够！\n");
  if( target->is_busy() )
                return notify_fail("对方已经手忙脚乱了！\n");

//modified by cool for hamagong
        if (me->query("yd_2") && (target->query_skill_mapped("force")=="hamagong" || 
            target->query_skill_mapped("strike") == "hamagong")){
            msg = YEL "\n$N背向$n，凝气于指，一式「阳关三叠」反手缓缓点出，纯阳指力直袭$n胸口！\n" NOR;

         if (random(me->query_skill("force",1)) > target->query_skill("force",1) /3 
         || random(me->query("combat_exp")) > target->query("combat_exp")/2 ){
                me->start_busy(1);
                if (!target->is_busy()) target->start_busy(2);
                damage = (int)me->query_skill("yiyang-zhi", 1);
//                damage = (int)me->query_skill("qiantian-yiyang", 1) +damage;
                damage = (int)me->query_skill("kurong-changong", 1) +damage;
                damage = random(damage)+150;
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage);               
target->apply_condition("yyz_damage",50);
                me->add("neili", -100);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += HIR "$n一见之下，大为失色，发现这似乎正是自己的克星！\n"NOR;   
                msg += damage_msg(damage, "内伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                } 
         else {       
                me->start_busy(random(2)+1);
                me->add("neili", -100);                
                msg += HIY"$p见这反手点穴似乎正是蛤蟆功的克星，识得厉害，危及之中一个铁板桥，上身向后一倒，艰难的躲过这一招。\n"NOR;
                }
         }
       else{
         msg = YEL "\n$N凝气于指，一式「阳关三叠」点出，但听得嗤嗤声响，一股纯阳的内力直袭$n胸口！\n" NOR;
          if (random(me->query_skill("parry")) > target->query_skill("parry") / 3)
             {
                me->start_busy(2);
                if (!target->is_busy()) target->start_busy(2);
target->apply_condition("yyz_damage",50);
                damage = (int)me->query_skill("yiyang-zhi", 1);
  //              damage = (int)me->query_skill("qiantian-yiyang", 1) +damage;
                damage = (int)me->query_skill("kurong-changong", 1) +damage;
       damage = damage + random(damage/2);
                target->receive_damage("qi", damage*2);
                target->receive_wound("qi", damage);               
             me->add("neili", -(damage/5));
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "内伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                if(me->query_skill("yiyang-zhi", 1) > 180)
                call_out("perform2", 0, me, target);    
              } 
         else {       
                me->start_busy(2);
                me->add("neili", -100);                
                msg += HIY"可是$p一个巧云翻身，远远的躲了开去。\n"NOR;

              }
         }         
        message_vision(msg, me, target);
        return 1;
}

int perform2(object me, object target)
{
        string msg;

        if (!me)
{
        me->delete_temp("yyz_hama");
 return notify_fail("你已经断线了。\n");
}

        if (!target)
{
        me->delete_temp("yyz_hama");
         return notify_fail("敌人已经不在了。\n");
}

        if(!living(target)) 
{
        me->delete_temp("yyz_hama");
          return notify_fail("对手已经不能再战斗了。\n");  
}
        if( (int)me->query("neili", 1) < 600 )
{
        me->delete_temp("yyz_hama");
                return notify_fail("你待要再出第二指，却发现自己的内力不够了！\n");     
}       
        msg = YEL "\n接着$N踏前一步，出第二指隔空点向$n胸前“玉堂穴”，认穴竟无厘毫之差！\n"NOR;
        if (random(me->query_skill("dodge")) > target->query_skill("dodge") / 3){                
                me->start_busy(2);
                
                msg += HIR "结果一指点中，$n只觉得全身气脉通道阻塞，真气立受干挠！\n"NOR;   
                target->start_busy(me->query_skill("force",1)/50+3);
                me->add("neili", -(me->query_skill("force",1)/4));
//else            msg += HIG "结果一指点中，但$n已经全身气脉通道阻塞，看来没有什么效果！\n"NOR;   
                if((int)me->query_skill("yiyang-zhi", 1) > 249)
                call_out("perform3", 0, me, target);    
                } 
        else {
           me->start_busy(2);
           me->add("neili", -150);
           target->add("neili", -50);
           msg += HIY"\n$p眼看逼无可逼，便也一指点去，两根指尖相碰，$p顺势跳了开去。\n" NOR;

           }
        message_vision(msg, me, target);
        return 1;
}

int perform3(object me, object target)
{
        int skill;
        string msg;
        if (!me)
{
        me->delete_temp("yyz_hama");
         return notify_fail("你已经断线了。\n");
}

        if (!target)
{
        me->delete_temp("yyz_hama");
         return notify_fail("敌人已经不在了。\n");
}
        skill = (int)me->query_skill("yiyang-zhi", 1);                
        skill = skill/10;
       
        if(!living(target)) 
{
        me->delete_temp("yyz_hama");
          return notify_fail("对手已经不能再战斗了。\n");
}
        if( (int)me->query("neili", 1) < 400 )
{
        me->delete_temp("yyz_hama");
                return notify_fail("你待要再出第三指，却发现自己的内力不够了！\n");     
}
        msg = YEL "\n紧跟着$N一阳指第三次点出，以纯阳内力，同时透入$n体内任脉紫宫穴、
阴维脉大横穴、冲脉幽门穴、带脉章门穴和阴跤脉晴明穴！\n"NOR;        
        if (random(me->query_skill("force")) > target->query_skill("force") / 3){                
                me->add("neili", -100);
                msg += HIR "$n只觉体内奇经八脉中内息为之一怠，全身气力竟然提不起来了！\n" NOR;
                target->add_temp("apply/attack", -100);
                target->add_temp("apply/dodge", -100);
                target->add_temp("apply/parry", -100);  
                target->add("neili", -500);                 
                call_out("back", 3 + skill, target);
                } 
        else {
//                me->start_busy(target->query_skill("force",1)/30);
                me->start_busy(2);
                me->add("neili", -200);
//                target->start_busy(2);
                msg += HIY"\n$p喘息未定，见$P指力如狂风般点来，连忙又跃开数尺，狼狈地避开。\n" NOR;
             }

        message_vision(msg, me, target);
        return 1;
}

void back(object target)
{
    if (!target) return;
        target->add_temp("apply/attack", 100);
        target->add_temp("apply/dodge", 100);
        target->add_temp("apply/parry", 100);
}
