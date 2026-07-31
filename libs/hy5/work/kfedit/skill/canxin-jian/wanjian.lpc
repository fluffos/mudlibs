#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int i,j,k,u,damage;
        string str; 
                object ob;
        string msg;
        int f_time;
        int myexp,yourexp,lvl;    
        
        weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || target->is_corpse() || target==me)
                return notify_fail("你要攻击谁？\n");

        if(!me->is_fighting())
                return notify_fail("你们没有在打架！\n");

        if((int)me->query("max_neili") < 1000 )
                return notify_fail("你的内功太差。\n");
        if((int)me->query("neili") < 900 )
                return notify_fail("你的内力不足！\n");
        if((int)me->query("jing") < 200 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("只能在战斗中使用。\n");

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "baiyun-xinfa")
                return notify_fail("请使用白云心法!\n");

        if((int)me->query_skill("baiyun-xinfa",1) < 200)
                return notify_fail("你的白云心法还不够。。。\n"); 


        k=50+(int)me->query_skill("canxin-jian",1);
        j=(int)target->query_skill("dodge");
        if(k<150)        
                return notify_fail("你的剑法级别还不够，使用这一招会有困难！\n");
        u=1+k/50;
        if (u>6) u=6;
        me->delete("env/brief_message");
        target->delete("env/brief_message");
        message_vision(HIB"\n$N仰天大喝了一声："NOR,me,target);
        message_vision(HIW"\n助我克敌者赏神剑一柄！"NOR,me,target);
        message_vision(HIB"\n一刹那间千万剑光破空而来，劈面罩向$n"NOR,me,target);
        for (i=0;i<u;i++)
        {
                //if (random(k+j)>j/2) 
                if (random(k+j)>j/3) 
                {
                        message_vision(HIY"\n$n一个不慎，中了一剑"NOR,me,target);
                        damage=k+random(100)+100;
                        target->receive_damage("qi",damage,me);
                        target->receive_wound("qi",damage/2,me);
                        COMBAT_D->report_status(target);
                        me->receive_damage("qi", 10);
                        me->add("neili", -30);
                }
                else 
                {
                        message_vision(HIY"\n$n左跳右闪，好不容易避开了一轮剑雨"NOR,me,target);
                        //me->receive_damage("jing", 10);
                        me->add("neili", -30);
                }
        }
if (!random(4))
        {
                target->start_busy(2);
        }          
 
if ((int)me->query_skill("canxin-jian",1)> 360)
{ 
	 myexp = (int) me->query("combat_exp");
        yourexp = (int) target->query("combat_exp");
        lvl = (int)me->query_skill("canxin-jian",1)/40;
        
        msg = HIC
"\n$N神色潇潇,手中剑芒幻出五彩光芒，将剑身向$n极速圈去，好一招“晓风三月”\n" NOR;
		        		       me->add_temp("apply/attack", 150);    
        me->add_temp("apply/damage", 2500);
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

		        		       me->add_temp("apply/attack", -150);    
        me->add_temp("apply/damage", -2500);
        me->add("neili", -50);
	
        
   }     

if ((int)me->query_skill("canxin-jian",1)> 880)
{ 
	if (random(2)==0) target->start_busy(2);
   me->add_temp("apply/attack", 200);
        me->add_temp("apply/damage", 3800);
        message_vision(HIW"\n$N集中精神，施展心剑的「心动三剑」，向$n发动会心攻击！\n"NOR,me,target);
        msg=HIR"心动心动，我心疯狂！"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg=HIR"心动心动，花心怒放！"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg=HIR"心动心动，心剑合一！"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -200);
        me->add_temp("apply/damage", -3800);

                if( living(target)) 
                        target->receive_damage("qi",2*((int)me->query_skill("canxin-jian",1)));
                        message_vision(HIR"\n$N突然使出心剑最终密招，暴喝而至！\n$n受到了严重的伤害！\n"NOR,me,target);

        //me->receive_damage("qi", 100);
        me->add("neili", -50);

   }   
            
        me->start_busy(3);
        return 1;
}

