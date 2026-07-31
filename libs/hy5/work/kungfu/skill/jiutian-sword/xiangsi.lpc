//xiangxi.c  
//created by DHXY-EVIL 2000.7.7
//Modified by vikee for xlqy-zq station 2000-12-5 9:05 .The CopyRight was keeped by DHXY-evil.

#include <ansi.h>
#include <combat.h>
#include <condition.h>
inherit F_SSERVER;

int perform(object me, object target)
{       
        string msg="";
        int damage,wound;
        int i,j;
        int success, ap, dp;        
        object weapon=me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展「相思三剑」？\n");

        if(!me->is_fighting())
                return notify_fail("「相思三剑」只能在战斗中使用！\n");
        
   if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("只能在战斗中使用。\n");

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "huiyan-xinfa")
                return notify_fail("请使用回雁心法!\n");

        if((int)me->query_skill("huiyan-xinfa",1) < 200)
                return notify_fail("你的回雁心法还不够。。。\n"); 
        
        if(environment(me)!=environment(target))
                return notify_fail("你要攻击的人不在这里。\n");
                
        if((int)me->query("max_neili") < 1800 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("neili") < 500 )
                return notify_fail("你的内力不足！\n");
        if((int)me->query("jing") < 300 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

        if((int)me->query_skill("jiutian-sword", 1) < 80)
                return notify_fail("你的九天黄泉剑修为还不够，使用这一招会有困难！\n");

        message_vision(HIM"$N集思凝神，猛地施出残心剑的绝招「相思三剑」，向$n"+HIM"连续发动进攻！\n"NOR,me,target);
        me->set("xiangsi", 8);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        switch (random(4))
        {
         case 0:
              {
               message_vision(HIC"$n被剑意中的相思之苦感染，身中情毒！\n"NOR,me,target);
               target->apply_condition("ill_shanghan",20);
               target->apply_condition("ill_zhongshu",20);
               target->apply_condition("ill_dongshang",20);
               target->apply_condition("ill_fashao",20);
               target->apply_condition("ill_keshou",20);
               break;
               }
         case 1:
              {

               message_vision(HIB"一股酒气冲向$n，$n似乎有了点酒意！\n"NOR,me,target);
               target->apply_condition("drunk",20);
               break;
              } 
         case 2:
              {
               message_vision(HIB"问世间情为何物？\n"NOR,me,target);
               message_vision(HIM"梦无痕，随风逝，仙灵如月长伴君．\n"NOR,me,target);  
               target->apply_condition("flower_poison",20);
               break;
              }
         case 3:
              {
               break;
              }
        }
        me->set("xiangsi", 9);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        switch (random(4))
        {
         case 0:
              {
               message_vision(HIR"$n被剑意中的相思之苦感染，身中情毒！\n"NOR,me,target);
               target->apply_condition("flower_poison",20);
               break;
              }
         case 1:
              {
               message_vision(HIC"一股酒气冲向$n，$n似乎有了点酒意！\n"NOR,me,target);
               target->apply_condition("drunk",20);
               break;
              }
         case 2:
              {
               message_vision(HIW"问世间情为何物？\n"NOR,me,target);
               message_vision(HIB"梦无痕，随风逝，仙灵如月长伴君．\n"NOR,me,target);
                target->apply_condition("ill_dongshang",20);
               target->apply_condition("ill_fashao",20);
               target->apply_condition("ill_keshou",20);
               target->apply_condition("ill_shanghan",20);
               target->apply_condition("ill_zhongshu",20);               
               break;
              }
         case 3:
              {
         break;
              }
        }
        me->set("xiangsi", 10);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        switch (random(4))
        {
         case 0:
              {
               message_vision(HIR"$n被剑意中的相思之苦感染，身中情毒！\n"NOR,me,target);
                             target->apply_condition("flower_poison",20);
               break;
              }
         case 1:
              {
               message_vision(HIG"一股酒气冲向$n，$n似乎有了点酒意！\n"NOR,me,target);
               target->apply_condition("drunk",20);
               break;
              }
         case 2:
              {
               message_vision(HIW"问世间情为何物？\n"NOR,me,target);
               message_vision(HIM"梦无痕，随风逝，仙灵如月长伴君．\n"NOR,me,target);  
                target->apply_condition("ill_dongshang",20);
               target->apply_condition("ill_fashao",20);
               target->apply_condition("ill_shanghan",20);
               target->apply_condition("ill_zhongshu",20);               
               target->apply_condition("ill_keshou",20);
               break;
              }
         case 3:
              {
               break;
               }
        }
        me->delete("xiangsi");



if ((int)me->query_skill("jiutian-sword",1)> 360)
{
	if (!target->is_busy()) target->start_busy(2);
       message_vision(HIW"
你剑势越舞越快，剑气四射，寒光逼人，突然一声长啸，剑光如
滑落的泪滴般洒下来，在天际中划出一道优美的弧线，思念了眼
泪化作无边的剑气
"NOR, me);
       me->add("neili", -50);
        me->add_temp("apply/attack",200	);
        me->add_temp("apply/damage",3800);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
msg=HIW""NOR; 
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);      
msg=HIW"☆凝☆"NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg=HIW"☆泪☆"NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg=HIW"☆决☆"NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg=HIW""NOR; 
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	
        me->add_temp("apply/attack",-200);
        me->add_temp("apply/damage",-3800);

}	

if ((int)me->query_skill("jiutian-sword",1)> 880)
{
 msg = HIW"$N剑势越来越慢，回想去和自己爱人的过去种种，不由觉得伤痛欲绝
"+HIM"“如果还有来生，你愿意和我在续前缘么？”
"+HIW"$N想起和爱人花前月下缠绵绯策时的话语，不由得痴了…………

"+HIR"$N又想到了至爱离你而去时依依不舍感情，无奈中含恨闭上双眼的情景……
"+HIR"突然间$N觉得全身的血液在沸腾……
"+HIW"$N喃喃自语道：“今生没有你，我活着还有什么意义？”
就在这个时候，$N仿佛看到至爱的人在对自己微笑……
"HIW"$N仰天长啸，身形陡转，背对$n飞了过来，手中长剑倒转“噗”的一声刺入自己的胸膛！\n" NOR;
	
        success = 1;
        ap = me->query_skill("jiutian-sword");
        ap = ap * ap * ap /10 ;
        ap += (int)me->query("combat_exp");
        ap = 4*ap; //this is for 拼命 so easier.
        dp = target->query("combat_exp");
        if( random(ap + dp) < dp ) success = 0;

        ap = (int)me->query("max_neili");
        dp = (int)target->query("max_neili");
        if( ap < random(dp) ) success = 0;

        if(success == 1 ){//now both die.
                msg +=  HIR "$n被$N的举动吓呆了，一个没注意被$N透体而出的剑尖刺中胸口，顿时发出一声惨叫！\n而$N也身子一瘫，倒在地上。\n" NOR;
                message_vision(msg, me, target);

       me->add("neili", -50);
       me->add("max_neili", -2);
damage=target->query("max_jing")/2;
if (damage > 9999) damage=9999;
     target->receive_damage("jing",damage);
                target->receive_wound("jing", damage);

damage=target->query("max_qi")/2;
if (damage > 9999) damage=9999;
target->start_busy(3);
     target->receive_damage("qi",damage);
                target->receive_wound("qi", damage);
                COMBAT_D->report_status(target);

                COMBAT_D->report_status(me);
  
                //attacker die here.

        }
            
        else {
                msg +=  HIR "$n见次情景，顾不得什么别的了，就地一滚躲开了着致命的一击！\n$N长叹一声，身子一瘫，倒在地上。嘴角带着一丝微笑……\n" NOR;
                message_vision(msg, me, target);

                                
       me->add("neili", -50);
       me->add("max_neili", -2);

              
                COMBAT_D->report_status(me);

                //attacker die here.
        } 
	
}	
        message_vision(HIY"$N的「相思三剑」用功完毕，气回丹田,缓缓收功.\n"NOR,me,target);

        me->start_busy(3);
        //me->add("qi", -100);
        me->add("neili", -50);
        //me->add("jing",-100);
        
        return 1;
}


