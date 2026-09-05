//from fy4..gamer@88
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER; 
int exert(object me, object target, int amount)
{
        int skill,skl, per, per1, ap,dp,ap1,dp1;
        int damage;
        if(me->query("family/family_name")!="神龙教")
                return  notify_fail("［摄心］是神龙教的绝技！\n");
        if( environment(me)->query("no_fight") )
                            return notify_fail("这里不能使用［摄心］！\n");
        if (me->query_skill("shenlong-xinfa",1)<100)
                return notify_fail ("你的[神龙心法]功力未够。\n");       
        if( (int)me->query("neili") < 300 )
                return notify_fail("你的内力不够。\n"); 
        if( (int)me->query("jing") < 100 )
                return notify_fail("自己都神不守舍了，怎么去媚惑他人！\n");        
        if( !target || target==me ) target = offensive_target(me);
        if (!target) return notify_fail("你要对谁施展［摄心］？\n");
        if(!target->is_character()) return notify_fail("你....脑子还好吧？\n");
        if(!living(target))     return notify_fail("对方已经没知觉了，怎么摄心啊？\n");

        me->add("neili", -300);
        me->receive_wound("jing",15+random(15));        
        
        skill = me->query_skill("shenlong-xinfa",1);
        skl= target->query_skill("force",1);
        per = me->query_per();
        if (per>=50) per=50;
        if (per<=10) per=10;

        per1=target->query_per(); 
        if (per1>=50) per1=50;
        if (per1<=10) per1=10;
     
        if (userp(target)) ap=(int)me->query("combat_exp")/24*per;
        else ap=(int)me->query("combat_exp")/15*per;
        dp=target->query("combat_exp")/32*per1;         
        ap1=skill*skill*skill/88;
        dp1=skl*skl*skl/108;
        ap+=ap1;
        dp+=dp1;        
        
        message_vision(MAG"\n$N用飘飘的眼光温柔地瞧着$n"+MAG"，媚眼如丝，巧笑盈盈 ...\n\n\n"NOR, me, target); 
      
        if( !F_KUNGFU->hit_rate( ap+dp, 2*dp, 9, me, target) ) {
                message_vision(HIY"$N心如止水，不为所动，避开了$n的目光！\n"NOR, target, me);
                me->start_busy(1+random(3));
                return 1;
        }
        
       if(random(2)){
                message_vision(WHT"$N缓缓将手前伸，这只手纤细、柔美，而毫无瑕疵，带着种凄秘的妖艳之气。\n\n\n" NOR,me,target);
                damage=skill*per/10+random(skill)+me->query_skill("force")/2;
             //   damage=damage*8/10;            
                message_vision(HIB"$N"+HIB"心中一荡，似已将窒息．眼勾勾地看着$n"+HIB"的纤纤手指拂过胸前。\n\n"NOR,target,me);
                message_vision(RED"$N"+RED"心头如针刺般剧痛，幽幽寒气渗入血脉，大脑顿觉一片空白。\n\n"NOR,target);        
       
                F_KUNGFU->hit_wound("qi", damage, damage/2+random(damage/2), me, target);
                target->add("neili",-damage/3- random(damage/3));
                if(target->query("neili")<0) target->set("neili",0);
                COMBAT_D->report_status(target);
       } else {        
                message_vision(WHT"$N樱唇微张，「☆бハξのㄊ★」，一缕魔音如针似箭直刺$n耳膜。\n\n\n" NOR,me,target);
                damage=skill*per/10+random(skill)+me->query_skill("spells")/2;
                damage=damage*8/10;
                
                message_vision(HIB"$N"+HIB"心中大骇，极力想捂住耳朵，全身却无一块肌肉听从自己的指挥。\n\n"NOR,target);
                message_vision(RED"$N"+RED"头嗡嗡直响，冷汗一滴一滴的从额头冒了出来，大脑顿觉一片空白。\n\n"NOR,target);                
       
                F_KUNGFU->hit_wound("jing", damage, damage/2+random(damage/2), me, target); 
                target->add("neili",-damage/3- random(damage/3));
                if(target->query("neili")<0) target->set("neili",0);
                COMBAT_D->report_status(target);
        }
        
        if (!target->is_busy()) target->start_busy(1+random(2));
        
        if(random(2)){
               if( !target->is_fighting(me) ) {
                       if( living(target) ) {
                               if( userp(target) ) target->fight_ob(me);
                               else target->kill_ob(me);
                        }
                        me->kill_ob(target);
                }                       
        }
        me->start_busy(2+random(2));
        return 1;
} 
