// This program is a part of NITAN MudLIB

#include <command.h>
#include <ansi.h>
inherit F_SSERVER;

string query_name() { return HIR"绝情"ZJBR"绝世"NOR; }
int perform(object me, object target)
{
        string msg;
        int ski_value, max_lv,ap,dp,aa;
       aa=me->query_skill("jueqing-xinjing", 1) / 10;
        ski_value = random(me->query_skill("mingyu-gong", 1));
        max_lv = me->query_skill("mingyu-gong", 1);

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("『绝情绝世』只能对战斗中的对手使用。\n");
  
        if( me->query_skill("mingyu-gong", 1) < 450 )
                return notify_fail("你的明玉功功力(450)不足。 \n");

        if( me->query_skill("force", 1) < 450 )
                return notify_fail("你的内功(450)不够好。 \n");
        
        if (me->query_skill_mapped("force") != "mingyu-gong") 
                return notify_fail("你现在没有激发明玉功为内功，难以施展『绝情绝世』。\n"); 
                
        if (me->query_skill_mapped("unarmed") != "mingyu-gong" && 
        		me->query_skill_mapped("sword") != "mingyu-gong") 
                return notify_fail("你现在没有激发明玉功为拳脚或剑法，难以施展『绝情绝世』。\n");
                
        if(me->query("neili") < 3000)
                return notify_fail("你的内力不够。\n");
   
        if( target->is_busy() )
                return notify_fail(target->name() + "为了躲避你的杀气，目前正自顾不暇！\n");
        
        msg = HIC"$N眼中寒芒一闪，运起全身功力进入丹田,运转周天，欲将全身的气血激发。\n \n" NOR;

        ap = me->query_skill("force") + me->query_skill("martial-cognize") ; 
        dp = target->query_skill("force") + target->query_skill("martial-cognize");
        
        if (ap / 2 + random(ap) > dp)  
        {
                msg += BLK HBWHT "$N全身气血翻涌，血雾环绕，使出明玉神功的最终杀招 『绝 情 绝 世』，将周身的血雾化为血箭，激射向$n"BLK HBWHT"的全身大穴，将$n重创！！\n \n \n" NOR;

                target->start_busy( random((int)me->query_skill("mingyu-gong") / 100 + 3) );
                target->receive_wound("jing", random(target->query("jing")/100), me);
                target->receive_wound("qi", random(target->query("qi")/100), me);
                me->receive_damage("qi", random(me->query("max_qi")/100));
                me->add("neili",-5000);  
        }
        else
        if( ski_value < 20 ){
                msg +="$N所激发的气血并不强大，竟让对方轻松躲过。\n";
                me->receive_damage("qi", me->query("qi")*1/100);
                me->add("neili", -500); 
        }
        else if( ski_value <  70 )
        {
                msg += HIM "第一招 『魔气无常』\n\n$n受到伤害,动弹不得！\n" NOR;
                if (! target->is_busy())
                target->start_busy( (int)me->query_skill("mingyu-gong") /120 + 1);
       					me->start_busy(3 + random(2));
                me->add("neili",-1000);    
        }
        else if( ski_value <  90 )
        {
                msg += HIG "第二招 『火魔煞神』\n\n$n受到伤害,动弹不得！\n" NOR;
                if (! target->is_busy())
                target->start_busy( (int)me->query_skill("mingyu-gong") /110 + 1);
       					me->start_busy(3 + random(2));
 
                me->add("neili",-1000);    
        }
        else  if( ski_value < 100 )
        {
                msg += HIC "第三招 『商魂魔身』\n\n$n受到伤害,动弹不得。\n" NOR;
                if (! target->is_busy())
                target->start_busy( (int)me->query_skill("mingyu-gong") /100 + 1);
       					me->start_busy(3 + random(2));

                me->add("neili",-1000);    
        }
        else if( ski_value <  120 )
        {
                msg += HIB "第四招 『剑魔灭世』\n\n$n受到伤害,动弹不得！\n" NOR;
                if (! target->is_busy())
                target->start_busy( (int)me->query_skill("mingyu-gong") /95 + 1);
       					me->start_busy(3 + random(2));

                me->add("neili",-1000);    
        }
        else if( ski_value <  140 )
        {
                msg += HIW "第五招 『狂魔破空』\n\n$n受到伤害,动弹不得！\n" NOR;
                if (! target->is_busy())
                target->start_busy( (int)me->query_skill("mingyu-gong") /90 + 2);
       					me->start_busy(3 + random(2));

                me->add("neili",-1000);    
        }
        else if( ski_value <  160 )
        {
                msg += CYN "第六招 『群魔乱舞』\n\n$n受到伤害,动弹不得！\n" NOR;
                if (! target->is_busy())
                target->start_busy( (int)me->query_skill("mingyu-gong") /85 + 2);
       					me->start_busy(3 + random(2));

                me->add("neili",-1000);    
        }
        else if( ski_value <  180 )
        {
                msg +=  YEL "第七招 『天极魔杀』\n\n$n受到伤害,动弹不得！\n" NOR;
                if (! target->is_busy())
                target->start_busy( (int)me->query_skill("mingyu-gong") /80 + 2);
       					me->start_busy(3 + random(2));

                me->add("neili",-1000);    
        }
        else if( ski_value <  200 )
        {
                msg += BLU "第八招 『斗魔无生魂』\n\n$n受到伤害,动弹不得！\n" NOR;
                if (! target->is_busy())
                target->start_busy( (int)me->query_skill("mingyu-gong") /75 + 2);
       					me->start_busy(3 + random(2));

                me->add("neili",-1000);    
        }
        else                    
        {
                msg += RED "第九招 『风魔狂转业』\n\n$n受到伤害,动弹不得。\n" NOR;
                if (! target->is_busy())
                target->start_busy( (int)me->query_skill("mingyu-gong") /70 + 2);
       					me->start_busy(3 + random(2));
 
                me->add("neili",-1000);    
        }

        message_vision(msg, me, target);
        return 1;
}

