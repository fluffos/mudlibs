// zhuihun.c 追魂快剑
// by hubo 2008-4-27

#include <ansi.h> 
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        
        string str;
        string dodskill,msg;
        string level;
        int effect;
        int extra; 
        object weapon,ob; 

        extra = me->query_skill("zhuihun-jian",1)/2;
        extra = extra+me->query_skill("bingchuan-xinfa",1)/2;

        if( !target ) target = offensive_target(me);
        if( !target
         || !target->is_character()
         || !me->is_fighting(target) )
                return notify_fail("［追魂快剑］只能对战斗中的对手使用。\n");
        
        if(me->query("family/family_name")!="红花会" 
        	&& me->query("chushi/last_family")!="红花会")
                return notify_fail("你不是红花会弟子，不能出绝招！\n");
        if( !(ob = me->query_temp("weapon"))
         || (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才行。\n");                        
        if ( me->query_skill("zhuihun-jian",1) < 100 )
                return notify_fail("你的［基本剑法］还不够纯熟！\n");             
        if ( me->query_skill("zhuihun-jian",1) < 100) 
                return notify_fail("你的［追魂快剑夺命剑法］还不够纯熟！\n");
        if((int)me->query("max_neili") < extra )
                return notify_fail("你的内功太差。\n");        
        if((int)me->query("neili")< extra/2) 
                return notify_fail("你的内力不够了。\n");

        me->add("neili",-extra/2);
      
        weapon = me->query_temp("weapon");
        extra = extra/4;
        me->add_temp("apply/attack",extra);
        
        //显示perform具体情况
        //me->set_temp("combat_env",me->query("env/skip_combat"));
        //me->set("env/skip_combat",0);
        //target->set_temp("combat_env",target->query("env/skip_combat"));
        //target->set("env/skip_combat",0);

        if (me->query_skill("zhuihun-jian",1)>100)
        {   
                msg = BLINK""+HIR  "\n［无常抖索］$N手中"+weapon->query("name")+"直劈$n！\n" NOR;
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);        
                msg = BLINK""+HIY  "［煞神当道］$N手中"+weapon->query("name")+"斜刺$n！\n" NOR;
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);        
                msg = BLINK""+HIW  "［怨魂缠足］$N手中"+weapon->query("name")+"平削$n！\n" NOR;
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg); 
        }
    
        me->add_temp("apply/attack",extra/2); 
        me->add_temp("apply/damage",extra);
        if ( random(me->query_skill("zhuihun-jian",1)) > 120)
        {
                msg = BLINK""+HIG  "［庸医下药］$N手中"+weapon->query("name")+"横砍$n！\n" NOR;
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        } 
        if (random(me->query_skill("zhuihun-jian",1)) > 140)
        {
                msg = BLINK""+HIC  "［闯王掷笔］$N手中"+weapon->query("name")+"飞刺$n！\n" NOR;
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        }
        if (random(me->query_skill("zhuihun-jian",1)) > 160)
        {
                msg = BLINK""+HIR  "［勇者无惧］$N手中"+weapon->query("name")+"加紧，旋风般向$n杀去！\n" NOR;
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        }
     
        if (me->query_skill("zhuihun-jian",1)> 600 && !random(3))
        {
        
                me->add_temp("apply/damage",extra/4);
                msg = BLINK""+HIM  "［铁索横江］$N手中"+weapon->query("name")+"虚劈，拐弯向$n剁去！\n" NOR;
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_QUICK,msg);
                msg = BLINK""+HIY  "［杀人偿命］$N手中"+weapon->query("name")+"轻晃，写意般向$n挥去！\n" NOR;
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_QUICK,msg);
                msg = BLINK""+HIG  "［追魂夺命］$N手中"+weapon->query("name")+"排山倒海向$n舞去！\n" NOR;
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_QUICK,msg);  
                me->add_temp("apply/damage",-extra/4);
        }
    
        msg = "\n" NOR;
        message_vision(msg, me, target);
     
        me->add_temp("apply/attack",-extra/2); 
        me->add_temp("apply/attack",-extra); 
        me->add_temp("apply/damage",-extra);   

        //恢复combat设置                                                  
        //me->set("env/skip_combat",me->query_temp("combat_env"));        
        //target->set("env/skip_combat",target->query_temp("combat_env"));   
     
        me->start_busy(3 + random(2));
        return 1;
}

