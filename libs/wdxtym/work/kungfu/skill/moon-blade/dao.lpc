// 刀至上，至上刀   By Gold
#include <ansi.h> 
#include <combat.h> 
        
inherit F_SSERVER; 
      
#define DAO "「" HIW "刀至上，至上刀" NOR "」" 
  string query_name() { return "刀至上"ZJBR"至上刀"; }
int can_not_hubo() { return 1;} 
    
int perform(object me) 
{ 
    string msg; 
    object weapon, target; 
    int ap, dp, count; 
    int i, damage; 
    
    if( me->query("family/family_name") != "魔教" ) 
            return notify_fail("你不是魔教弟子，无法使用" DAO "。\n"); 
                      
    if (! target) target = offensive_target(me); 
       
    if (! target || ! me->is_fighting(target)) 
            return notify_fail(DAO "只能对战斗中的对手使用。\n"); 

    if (! objectp(weapon = me->query_temp("weapon")) || 
       (string)weapon->query("skill_type") != "blade") 
            return notify_fail("你使用的武器不对，难以施展" DAO "。\n"); 
      
    if ((int)me->query_skill("moon-blade", 1) < 300) 
            return notify_fail("你圆月弯刀火候不够，难以施展" DAO "。\n"); 
      
    if ((int)me->query("max_neili") < 5000) 
            return notify_fail("你的内力修为不够，难以施展" DAO "。\n"); 
       
    if ((int)me->query("neili") < 1000) 
            return notify_fail("你现在的真气不足，难以施展" DAO "。\n"); 
       
    if (! living(target)) 
            return notify_fail("对方都已经这样了，用不着这么费力吧？\n"); 
     
    if (objectp(weapon = target->query_temp("weapon"))) 
    {         
            msg = HBYEL "$N" HBYEL "双手持刀，一跃而起，劲运刀身，划出一道完美的弧线，一股刀劲" 
                  HBYEL "如一轮新月袭向$n。\n" NOR; 
       
            ap = me->query_skill("blade");
                        
            if (ap / 2 + random(ap) > dp)
            { 
               me->add("neili", -500); 
               msg += HIR "$n" HIR "暗叫不好，连忙举起手中兵器抵挡，却不想虎口剧痛，手中" + weapon->name() + 
                               HIR "捏不住，脱手而出。\n" NOR; 
                               
               weapon->move(environment(me)); 
             } else 
               { 
                     me->add("neili", -500); 
                     msg += CYN "$n" CYN "提升十成功力，头上青筋暴出，紧握手中" + weapon->name() +  
                                     CYN "硬是将$N" CYN "的劲气抵挡化解了。\n" NOR;                         
                } 
                message_combatd(msg, me, target); 
             }  
               
             msg = HBBLU "霎时间$N" HBBLU "身法变得飘忽，不知何时已闪至$n的身前，一招" HIY "「刀至上」" NOR +
                   HBBLU "刀尖由下至上划出一个形如满月的气劲飞向$n，誓要把$n一分两半" HBBLU "。\n"NOR;   
       
             ap = me->query_skill("blade");
             dp = target->query_skill("dodge");
             damage = me->query_skill("blade");
               
             if (ap / 2 + random(ap * 2) > dp) 
            {       
                   damage = damage * 4;          
                   target->receive_damage("jing", damage / 8);
                   target->receive_wound("jing", damage / 10);
                   msg += COMBAT_D->do_damage(me, target, REMOTE_ATTACK, damage, 200, 
                                              HIR "$n" HIR "只觉呼吸紧迫，一股劲风扑面" 
                                             "而来，根本避无所避，被$N" HIR "的劲气袭中"
                                             "全身，各大穴道血气翻腾，血入箭般喷出。\n" NOR); 
                   target->set_status_xuruo(5); 
                   me->add("neili", -400);                 
             } else 
              { 
                   msg += CYN "$n" CYN "眼见$N" CYN "来势汹涌，丝毫不" 
                              "敢小觑，急忙闪在了一旁。\n" NOR; 
                   me->add("neili", -200); 
              } 
               
             message_combatd(msg, me, target);     
              
             msg = HBMAG "紧跟着$N" HBMAG "跃向空中，另一杀招" HIB "「至上刀」" NOR +
                   HBMAG "手中刀狂舞，一瞬间天空中多出了无数个满月，一起向$n" HBMAG "飞去。\n" NOR;                       
      
             ap = me->query_skill("blade");
             dp = target->query_skill("parry");
              
             if (ap / 2 + random(ap * 2) > dp) 
             { 
                     msg += HIR "$n" HIR "面对$N" HIR "这排山倒海般的攻" 
                            "势，完全无法抵挡，招架散乱，连连退后。\n" NOR; 
                     count = ap / 5; 
             } else 
             { 
                     msg += HIC "$n" HIC "心底微微一惊，心知不妙，急忙" 
                            "凝聚心神，竭尽所能化解$N" HIC "数道刀劲。\n" NOR; 
                     count = 0; 
             } 
              
             message_combatd(msg, me, target); 
      
             me->add_temp("apply/attack", count); 
             me->add_temp("apply/damage", count / 2); 
   if(me->query_skill("moon-blade")>=300)
   {
             for (i = 0; i < 16; i++) 
             { 
                     if (! me->is_fighting(target)) 
                             break; 
      
                     if (! target->is_busy()) 
                             target->start_busy(3); 
      
                     if (! objectp(weapon = me->query_temp("weapon")) )
                     COMBAT_D->do_attack(me, target, 0, 120);
                     else
                     COMBAT_D->do_attack(me, target, weapon, 120); 
             } 
   }else
   {
             for (i = 0; i < 12; i++) 
             { 
                     if (! me->is_fighting(target)) 
                             break; 
      
                     if (! target->is_busy()) 
                             target->start_busy(3); 
      
                     if (! objectp(weapon = me->query_temp("weapon")) )
                     COMBAT_D->do_attack(me, target, 0, 120);
                     else
                     COMBAT_D->do_attack(me, target, weapon, 120); 
             } 
   }
             me->add("neili", -2000); 
             me->add_temp("apply/attack", -count); 
             me->add_temp("apply/damage", -count / 2); 
      
             me->start_busy(3 + random(4)); 
             me->add("neili", -400 - random(600)); 
             return 1;         
     } 

