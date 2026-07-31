#include <ansi.h>

#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string str;
        int snowsword,f,bufa,ini_damage_apply,times,damage;
        string desc_msg="";
        int sword_level;
        string msg;
        int ap, dp,qixue,eff_qi,max_qi,qi_pcg,dmg;

                        
        snowsword = (int)me->query_skill("snowsword", 1);
        f = (int)me->query_skill("bitao-shengong", 1);
        bufa = (int)me->query_skill("qiongya-bufa", 1);
       
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展「漫天飞雪」？\n");

        if(!me->is_fighting())
                return notify_fail("「漫天飞雪」只能在战斗中使用！\n");


     if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("只能在战斗中使用。\n");
        
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "bitao-shengong")
                return notify_fail("请使用碧涛心法!\n");

   

        if((int)me->query_skill("bitao-shengong",1) < 100)
                return notify_fail("你的碧涛心法还不够。。。\n"); 
                
                
        sword_level=(int)(snowsword/50);
        if( snowsword < 50)
                return notify_fail("你的风回雪舞剑法级别还不够，使用这一招会有困难！\n");


        if((int)me->query("neili") < 500 )
                return notify_fail("你的内力不足！\n");


        
        if( bufa < 50)
                return notify_fail("你的本门步法级别还不够，使用这一招会有困难！\n");
                

        
  //      if( time()-(int)me->query_temp("wuxue_end") < 3 )
  //              return notify_fail("绝招用多就不灵了！\n");
                
        if ( sword_level <= 1 ) desc_msg = "" ; 
        else desc_msg = chinese_number(sword_level);
        if ( sword_level > 9 ) desc_msg = "百";
   



        ini_damage_apply = me->query_temp("apply/damage");
        me->add_temp("apply/attack", 200);	
        me->add_temp("apply/damage", 2200);
        message_vision(HIW"\n$N轻叱一声，脚尖一点，身体急速上旋，在半空中一个折腰。
同时手腕轻抖，剑光闪动幻作漫天飞雪卷向$n。\n"NOR,me,target);
        target->start_busy(2);
        damage=1;
        //前三剑
        message_vision(HIC"\n$N同时使出风回雪舞剑的前三招，在半空中压向$n。\n"NOR,me,target);
        
        me->set_temp("WX_perform", 5);
        damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));


        damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        

        me->set_temp("WX_perform", 6);
        damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        //再两剑
        if( snowsword > 99 && f > 99 && bufa > 99 )
           {
                message_vision(HIC"\n$N身体斜斜向上飘出，也不回头，反手就刺出了两招。\n"NOR,me);
                
                
                
                me->set_temp("WX_perform", 7);
                damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
             

                me->set_temp("WX_perform", 8);
                damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        }
      
        //最后三剑
        if( snowsword > 149 && f > 149 && bufa > 149 )
        {
                message_vision(HIC"\n$N斜斜一再个翻身，长剑幻作千百支冰箭，夹着一股寒风扑向$n。\n"NOR,me,target);
                    

                me->set_temp("WX_perform", 9);
                damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
   

                me->set_temp("WX_perform", 10);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
            
                    
        }
        me->add_temp("apply/attack", -200);	               
        me->delete_temp("WX_perform");
        me->add_temp("apply/damage",-2200);


if (snowsword> 600)
{
         message_vision(HIY"\n$N双手合十，轻念佛偈：\n" NOR,me,target);
message_vision(HIC"\n“一切恩爱会，无常难得久。\n"NOR,me,target);
message_vision(HIC"\n  生世多畏惧，命危于晨露。\n"NOR,me,target);
message_vision(HIC"\n  由爱故生忧，由爱故生怖。\n"NOR,me,target);
message_vision(HIC"\n  若离于爱者，无忧亦无怖。”\n"NOR,me,target);
message_vision(HIB"\n $N叹道:是耶?非耶?化作蝴蝶......
忽然招式一变舞起一片剑花,似彩蝶翻飞般罩向$n\n\n"NOR,me,target);
   

                 
        ap = me->query_skill("snowsword", 1);
        ap = ap * ap * ap /10;
        ap = ap + (int)me->query("combat_exp");
        dp = target->query_skill("parry");
        dp = dp * dp * dp /20;   
        dp = dp + target->query("combat_exp");
        dp = dp*qi_pcg/50;  
        if( random(ap + dp) <  dp ) {
                            message_vision(HIW"$n一见情势不妙，一个鱼跃,跳出圈外。\n"NOR, me, target);
         } else {
dmg=target->query("qi")/2;
if (dmg > 50000) dmg=50000;
                  target->receive_damage("qi",dmg,me);

                   message_vision(HIM "$n躲闪不及,剑花中但见一只彩蝶穿身而过！\n"NOR, me, target);
                   COMBAT_D->report_status(target); 
           }
        
}       
        

if (snowsword> 800)
   

{
            msg = HIW"\n$N银牙一咬，突然高高纵起，凝聚全身功力，人剑合一，"
                 +"化做一道白光，疾风般扑向$n！\n" NOR;
        ap = me->query_skill("snowsword", 1);
        ap = ap * ap * ap /10;
        ap = ap + (int)me->query("combat_exp");
        dp = target->query_skill("parry");
        dp = dp * dp * dp /10;   
        dp = dp + target->query("combat_exp");
        dp = dp*qi_pcg/50;  //more badly you're hurt, more chance you will succeed
        if( random(ap + dp) <  dp ) {
                msg += HIW "$n一见情势不妙，连忙就地一滚，虽于千钧一发之际躲过雷霆一击，却也狼狈不堪，吓得魂飞魄散，一时间动弹不得。\n"NOR;
                message_vision(msg, me, target);
         } 
         else {
dmg=target->query("qi")/2;
if (dmg > 50000) dmg=50000;
                target->receive_wound("qi",dmg);
                msg += HIW "$n不料$N如此决绝，为此气势所慑，竟然楞在当地，忘了招架。\n
说时迟，那时快，这道白光已在$n身上当胸穿过！\n"NOR;
                message_vision(msg, me, target);



                COMBAT_D->report_status(target); 
         }
    
}       


me->add("neili", -100);
me->start_busy(2);
        //me->set_temp("wuxue_end",time());
        return 1;
}
