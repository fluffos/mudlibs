#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;


int perform(object me, object target)
{
        object weapon, ob;
        string msg;
        int myexp,yourexp,lvl;    
        int myskill, myskill1, tparryb, tparryh, myforce, tforce,  texp, damage;
        object tweapon;
        weapon = me->query_temp("weapon");
        myskill= (int)me->query_skill("sword",1);
        myskill1= (int)me->query_skill("jiutian-sword",1);
                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展“ 晓风三月 ”?\n");
         
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
        
        if( !me->is_fighting() )
                return notify_fail("“ 晓风三月 ”只能在战斗中使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");



        if( (int)me->query_skill("jiutian-sword", 1) < 120)
                return notify_fail("你的九天黄泉剑等级不够，你怎么能使出“ 晓风三月 ”。\n");

        if( (int)me->query("combat_exp",1) < 150000 )
                return notify_fail("你的经验不足，不能使出“ 晓风三月 ”。\n");

        if (me->query("neili") < 650)
                return notify_fail("你内力不继，难以使出“ 晓风三月 ”。\n");

        me->clean_up_enemy();
        ob = me->select_opponent();
        myexp = (int) me->query("combat_exp");
        yourexp = (int) target->query("combat_exp");
        lvl = (int)me->query_skill("jiutian-sword",1)/40;
        
        msg = HIC
"\n$N神色潇潇,手中剑芒幻出五彩光芒，将剑身向$n极速圈去，好一招“晓风三月”\n" NOR;
        me->add_temp("apply/attack",200	);
        me->add_temp("apply/damage",3800);
                message_combatd(msg + "\n", me, target, "");
                msg = HIM "$n只觉三股剑气罩住自己,登时全身一麻,动弹不得!!\n" NOR;
                
                message_combatd(msg, me, target, "");
                target->start_busy(2);
                msg=HIM"第一股五彩剑气一出，早春三月的寒露为之融化，让$n惊叹！"NOR;
                 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

                msg=HIC"第二股五彩剑气一出，万物生灵争妖艳，让$n感慨！"NOR;
                 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

                msg=HIW"第三股五彩剑气一出，似口含蜜露的雀儿，飞舞、疾驰，让$n无奈！"NOR;
                 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

                msg=HIW"第四股五彩剑气一出，醉看风落帽，舞爱月流人。让$n心痛！"NOR;
                 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                 
                msg=HIW"第五股五彩剑气一出，红颜弃轩冕，白首卧松云。让$n心慌！"NOR;
                 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);                 

        me->add_temp("apply/attack",-200	);
        me->add_temp("apply/damage",-3800);
 
        

if ((int)me->query_skill("jiutian-sword",1)> 360)
{
	    message_vision(HIW"$N攻势渐缓，运剑成圆，一股股剑气在三尺青锋吞吐！\n\n" NOR,me,target);        
      message_vision(HIG"柔而不断的『绕指剑气』围绕在$N身边！\n"NOR,me);
if(random(myexp)>(int)(yourexp/2) || random(3)==0)
{msg = HIR"$n躲闪不及，一股柔和的剑气透体而过！\n"NOR;
damage=800+(myskill*3);
if(damage<1800)damage = 1800;
target->receive_damage("qi", damage,me);
target->receive_wound("qi", damage,me);
target->start_busy(4);
     message_vision(msg, me, target);
     COMBAT_D->report_status(target);
     }
else{
         msg = HIW"$n自知不敌，身形一低,贴着剑锋平平的飞了出去！\n\n"NOR;
            message_vision(msg, me, target);
        COMBAT_D->do_attack(target, me, tweapon);
        }
}        
        
        me->add("neili", -150);
        me->start_busy(2);
        return 1;  

}

