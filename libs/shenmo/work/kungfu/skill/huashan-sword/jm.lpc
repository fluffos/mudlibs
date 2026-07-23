// jianmang.c 

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;                                        
void check_fight(object me, object target, int improve);
private int remove_effect(object me, int improve);

string *name1 = ({ "玉堂穴", "大横穴", "幽门穴", "章门穴", "晴明穴", "紫宫穴",
                   "风池穴", "太阳穴", "会阴穴", "长强穴", "灵台穴" });

int perform(object me)
{       
        string msg, name, name2;
        int damage;

        object target;
        object weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);
        if( me->is_busy())
                return notify_fail("你现在正忙着呢。\n"); 
        if( !me->is_fighting() )
                return notify_fail("「剑芒」只能在战斗中使用。\n");
        if( !target || !target->is_character() ||!me->is_fighting(target) )
                return notify_fail("「剑芒」只能在战斗中对对手使用。\n");
        if( target->query("qi") <= 50 && me->is_fighting(target) )
                return notify_fail("你现在没有必要用「剑芒」攻击敌人了。\n");

        if (!weapon || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "huashan-sword")
             return notify_fail("你现在无法使用「剑芒」攻击敌人。\n");

        if(  me->query_temp("perform") 
        ||   me->query_temp("perform2")
        ||   me->query_temp("perform3") )
             return notify_fail("你现在正用着「剑芒」呢。\n");

        if( (int)me->query_skill("huashan-sword", 1) < 90 ||
            (int)me->query_skill("sword", 1) < 90 ||
            (int)me->query_str() < 25   ||
            (int)me->query_dex() < 25)  
                return notify_fail("你有的功夫还不够娴熟，不会使用「剑芒」。\n");

         if((int)me->query_skill("zixia-shengong", 1) < 80)
            return notify_fail("你的紫霞功修为不够，无法领悟「剑芒」的精髓。\n");


        if( (int)me->query("max_neili") < 500 )
                return notify_fail("你的内力太弱，无法使用出「剑芒」！\n");
        
        if( (int)me->query("neili") < 200 )
                return notify_fail("你的真气不够！\n");
                
        name = name1[random(sizeof(name1))];    
        name2 = weapon->query("name");
        msg =  HIC"\n$N右手剑锋一转，手中"+name2+"直斗，顿时使$N被一片剑辉所笼罩，其中一支剑芒奔向$n的"+name+"。\n" NOR;
        
        if (random(me->query_skill("dodge")) > target->query_skill("dodge") / 3)
        {                
                msg += HIR "结果一剑刺中，$n只觉得全身气脉通道阻塞，真气立受干挠！\n"NOR;   
                target->start_busy(2);
                me->add("neili", -200);
                me->set_temp("perform", 1);
                if( (int)me->query_skill("huashan-sword", 1) > 110
                &&  (int)me->query("neili") > 300
                  &&  me->is_fighting(target) 
                &&  me->query_skill_mapped("sword") == "huashan-sword"
                &&  (string)weapon->query("skill_type") == "sword" ) 
                {
                        call_out("perform2", 0, me);    
                }
                else 
                {
                        me->delete_temp("perform");
                }
        } 
        else 
        {
                me->start_busy(2);
                me->add("neili", -100);
                me->delete_temp("perform");
                target->add("neili", -50);
                target->start_busy(1);
                msg += HIY"\n$p大叫一声不好，全身用力一纵，顺势跳了开去。\n" NOR;
        }
        message_vision(msg, me, target);
        return 1;
}                   
                                       
int perform2(object me)
{
        string msg, name, name2;
        int damage;   
        object target;
        object weapon = me->query_temp("weapon");
if (!me)  return notify_fail("你已经不在了。\n");
        if (!weapon)
{
      me->delete_temp("perform");                                                    
      me->delete_temp("perform2");                                                    
      me->delete_temp("perform3");                                                    
 return notify_fail("你没有武器。\n");
}

        name2 = weapon->query("name");
        
        if( !target ) target = offensive_target(me);   
        name = name1[random(sizeof(name1))];
        if (!target)
{
      me->delete_temp("perform");                                                    
      me->delete_temp("perform2");                                                    
      me->delete_temp("perform3");                                                    
 return notify_fail("敌人已经不在了。\n");
}
       
        msg = MAG"\n接着$N踏前一步，"+name2+"发出的第二支剑芒隔空点向$n的"+name+"，认穴竟无厘毫之差！\n"NOR;        
        
        if (me->query("combat_exp")> target->query("combat_exp")/3 )
        {
                me->start_busy(1);
                target->start_busy(1);
                me->delete_temp("perform");
                damage = (int)me->query_skill("huashan-sword", 1);
                damage = (int)me->query_skill("sword", 1) +damage;
                damage = (int)me->query_skill("zixia-shengong", 1) +damage;
                damage = damage + random(damage/2);
                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/3);
                me->add("neili", -300);
                me->set_temp("perform2", 1);
                if( damage < 300 ) msg += HIY"结果「噗」地一声刺入了$n"+name+"寸许！\n"NOR;
                else if( damage < 400 ) msg += HIY"结果「噗」地一声刺进$n的"+name+"，使$p不由自主地退了几步！\n"NOR;
                else if( damage < 500 ) msg += HIY"结果「噗嗤」地一声，"+name2+"已在$n"+name+"刺出一个血肉模糊的血窟窿！\n"NOR;
                else msg += HIR"结果只听见$n一声惨嚎，"+name2+"已在$p的"+name+"对穿而出，鲜血溅得满地！！\n"NOR;

                if(  (int)me->query_skill("huashan-sword", 1) > 135
                && (int)me->query("neili", 1) > 300
                &&  me->is_fighting(target) 
                &&  me->query_skill_mapped("sword") == "huashan-sword"
                &&  (string)weapon->query("skill_type") == "sword")                
                {
                        call_out("perform3", 0, me);                                  
                }
                else 
                {
                        me->delete_temp("perform"); 
                        me->delete_temp("perform2");
                }
        } 
        else 
        {       me->start_busy(2);
                me->add("neili", -150);                
                me->delete_temp("perform");
                me->delete_temp("perform2");                          
                target->start_busy(1);
                msg += HIY"可是$p一个巧云翻身，远远的躲了开去。\n"NOR;
        }
        message_vision(msg, me, target);
        return 1;
}                                                       

int perform3(object me)
{
        int skill;
        string msg, name, name2;
        object weapon = me->query_temp("weapon");
        object target;
if (!me)  return notify_fail("你已经不在了。\n");
        if (!weapon)
{
      me->delete_temp("perform");                                                    
      me->delete_temp("perform2");                                                    
      me->delete_temp("perform3");                                                    
 return notify_fail("你没有武器。\n");
}
        name2 = weapon->query("name");
        skill = (int)me->query_skill("huashan-sword", 1);                
        skill = skill/10;
        if( !target ) target = offensive_target(me);
        name = name1[random(sizeof(name1))];
        if (!target)
{
      me->delete_temp("perform");                                                    
      me->delete_temp("perform2");                                                    
      me->delete_temp("perform3");                                                    
 return notify_fail("敌人已经不在了。\n");
}
       
        msg = HIW "\n紧跟着$N手中"+name2+"发出第三支剑芒，只见一道光芒直奔$n，剑辉扫向$n的"+name+"！\n"NOR;        
        if (random(me->query_skill("force")) > target->query_skill("force") / 2)
        {                                                                       
                call_out("check_fight", 1, me, target);                                 
                me->add("neili", -300);
                me->delete_temp("perform2");              
                me->set_temp("perform3");
                msg += HIR "$n只觉体内奇经八脉中内息为之一怠，全身气力竟然提不起来了！\n" NOR;
                me->add_temp("apply/attack", skill);
                me->add_temp("apply/dodge",  skill);
                me->add_temp("apply/parry",  skill);  
                target->start_busy(1);
                me->start_busy(3);
                target->add("neili", -300);                 
        }
        else 
        {
                me->start_busy(2);
                me->add("neili", -250);
                me->delete_temp("perform2");        
                target->start_busy(2);
                msg += HIY"\n$p喘息未定，见$P手中发出的剑芒如狂风般点来，连忙又跃开数尺，狼狈地避开。\n" NOR;
        }
        message_vision(msg, me, target);
        return 1;
}

void check_fight(object me, object target, int improve) 
{ 
        object weapon;      


        if (!me)
{
 return notify_fail("你已经不在了。\n");
}

        if (!target)
{
      me->delete_temp("perform");                                                    
      me->delete_temp("perform2");                                                    
      me->delete_temp("perform3");                                                    
remove_effect(me, improve);
 return notify_fail("敌人已经不在了。\n");
}
        if( target->query("qi") <= 50 && me->is_fighting(target) )         
        { 
                remove_effect(me, improve); 
                tell_object(me, HIY"对方已经渐渐适应了你的套路，攻守自如多了。\n"NOR);                
        } 
        
        else if (!present(target->query("id"), environment(me)) 
        &&  me->is_fighting(target) ) 
        { 
                remove_effect(me, improve);
                tell_object(me, HIY"对方已经渐渐适应了你的套路，攻守自如多了。\n"NOR);                
        }                                                
        
        else if( !living(target) || !present(target->query("id"),environment(me)) ) 
        { 
                remove_effect(me, improve);                                           
                tell_object(me, HIY"对方已经渐渐适应了你的套路，攻守自如多了。\n"NOR);
        } 
        
        else if( !me->is_fighting() || !living(me) || me->is_ghost() ) 
        { 
                remove_effect(me, improve);                                                           
                tell_object(target, HIY"你已经渐渐适应了对方的套路，攻守自如多了。\n"NOR);                          
        } 
        
        else if( !objectp(weapon = me->query_temp("weapon")) 
        || me->query_skill_mapped("sword") != "huashan-sword"
        || (string)weapon->query("skill_type") != "sword" ) 
        { 
                remove_effect(me, improve);             
                tell_object(target, HIY"你已经渐渐适应了对方的套路，攻守自如多了。\n"NOR);                
                tell_object(me, HIY"对方已经渐渐适应了你的套路，攻守自如多了。\n"NOR);
        }

         else call_out("check_fight", 1, me, target, improve); 
         
}
private int remove_effect(object me, int skill)
{     
      skill = (int)me->query_skill("huashan-sword", 1)/10;                
      me->add_temp("apply/attack", -skill);
      me->add_temp("apply/dodge",  -skill);
      me->add_temp("apply/parry",  -skill);  
      me->delete_temp("perform3");                                                    
      tell_object(me, HIY"对方已经渐渐适应了你的套路，攻守自如多了。\n"NOR);      
      return 0;
}
