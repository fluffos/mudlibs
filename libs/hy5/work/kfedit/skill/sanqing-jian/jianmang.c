#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int  myexp, yourexp,i,num,damage;
        object weapon;
        
        int enhance;
        string str;     

        object ob;
        int skill, skill2, ap, dp,kee_wound;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("灵幻剑芒只能在战斗中使用。\n");

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "kongdong-xinfa")
                return notify_fail("请使用崆峒心法!\n");

        if((int)me->query_skill("kongdong-xinfa",1) < 100)
                return notify_fail("你的崆峒心法还不够。。。\n"); 

        if((int)me->query_skill("sanqing-jian",1) < 80)
                return notify_fail("你的三清剑法等级还不够！\n");
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);
        if( (int)me->query("max_neili") < 800)
                return notify_fail("你的内力太弱,不能吐出剑芒！\n");
        if( (int)me->query("neili") < 400)
                return notify_fail("你的内力不够了！\n");

        if(me->query_temp("jianmang_busy"))
                return notify_fail("糟了，剑芒没有发出！\n");
        myexp = (int)me->query("combat_exp");
        yourexp = (int)target->query("combat_exp");
        msg = HIC
        "\n$N一声朗笑，手中长剑斜指向天，剑尖吐出一团尺余的银芒，似有灵性般吞缩不定！\n"
        "$n正诧异间，那团剑芒却猛得暴涨，朝着$n的面门直射而来！\n\n" NOR;       
        message_combatd(msg, me, target, "");
        damage=me->query_temp("apply/damage")+me->query("force_factor");
        num=0;
        for (i=1;i<=7;i++) 
        {
                if( random(myexp)>random(yourexp))
                num++;
        }   
        if(num>0)         
        {
                damage=damage*num;
                

                
                msg = HIR
                "\n只听$n一声惨嚎,剑芒从$n的额头掠过,带出一缕血光！\n" NOR;

                msg += HIW
                "\n剑芒长虹经天般自天际处转得一转,又飞回$N的身边。\n" NOR;
                message_combatd(msg, me, target, "");
if (damage > 32000) damage=32000;
                target->receive_damage("qi",damage);
                target->receive_wound("qi",damage);
/*
                //if (random(damage)>target->query_temp("apply/armor"))
                if (damage>target->query_temp("apply/armor"))
                target->receive_wound("kee",damage-target->query_temp("apply/armor"),me,"pfm");
*/
                COMBAT_D->report_status(target,1);
                if(!target->is_busy()) 
                        target->start_busy(1+random(2));
                //target->kill_ob(me);
  	me->add_temp("apply/attack", 100);	
	me->add_temp("apply/damage", 2200);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
  	me->add_temp("apply/attack", -100);	
	me->add_temp("apply/damage", -2200);


        }
        else 
        {
                msg = HIY
                "\n$n却识得那团剑芒的厉害,早已远远避在一边。\n" NOR;
                message_combatd(msg, me, target, "");
                me->start_busy(2);
        }
        
        me->start_busy(2);
        
        me->add("neili",-150);
        me->set_temp("jianmang_busy",1);

if (me->query_skill("sanqing-jian",1) >= 300 || !userp(me))
{        
         message_combatd(HIC"\n$N运起神功，没等招式用老，脚踏八卦，身形一下转过一边，紧接着收剑出掌。\n"NOR,me,0,"");
        weapon->unequip();
        me->add_temp("apply/attack", 200);  
        me->add_temp("apply/damage",3800);        
        COMBAT_D->do_attack(me, target);
        COMBAT_D->do_attack(me, target);
        COMBAT_D->do_attack(me, target);
        me->add_temp("apply/attack",-200);
        me->add_temp("apply/damage",-3800);
        weapon->wield();
        me->reset_action();
     me->add("neili",-20);
me->start_busy(2);
}        

if (me->query_skill("sanqing-jian",1) >= 600 || !userp(me))
{ 
	        skill = me->query_skill("sword");
        skill2 = me->query_skill("force");
                msg = HIY "$N忽然向后疾退两步，气沉丹田，力贯剑身，霎时剑身碎裂，犹如－－
                \n"HIC"『青霞漫天』
                \n"HIY"－－无数剑片铺天盖地向$n飞射而去。\n\n"NOR;
                message_vision(msg, me, target);
                ob = me->query_temp("weapon");
              

 
                ap = ((me->query("combat_exp"))*(me->query_str()));
                dp = ((target->query("combat_exp"))*(target->query_str()))/3;

                if( dp < 1 )
                        dp = 1;
                if( random(ap) > dp || random(3)==0)
                {
                        msg = HIR "$n面前仿佛涌起万丈青色霞光，惊愕之下，无数剑片已然嵌在了$n的身上，\n\n$n惨叫一声，脸上露出极为痛苦的表情。\n\n"NOR;
                        message_vision(msg, me, target);
                        kee_wound = 380 + skill + random(skill*2);

                        if(kee_wound > target->query("qi")) kee_wound = (target->query("qi") + 1);
                       
                        target->receive_damage("qi",kee_wound); 
                        target->receive_wound("qi", kee_wound);
                       
                        COMBAT_D->report_status(target, 0);

                        me->add("neili",-100);
                }
                else
                {
                        msg = HIG "只见$n不敢怠慢，脚一点地疾飞冲天，堪堪躲过了这满天的剑片。\n\n"NOR;
                        message_vision(msg, me, target);

                        me->add("neili",-50);
                }

                call_out("perform_qiao", 3, me);

                return 1;
        }
        else if(skill<180  )
        {
                msg = HIW "$N忽然向后疾退两步，手腕一振就要施展三清剑法无上绝技之一的“青霞漫天”，
                \n却不料功力不足，居然没有震化手中"+weapon->query("name")+HIW"。\n" NOR;
                msg += HIR "$n刚要躲闪，突然发现机会难得，立时又扑了上来。\n\n";
                message_vision(msg, me, target);
                me->add("neili",-50);

        }
        else
        {
                msg = HIW "$N突然向后疾退两步，力惯"+weapon->query("name")+HIW"，三寸剑芒吞吐，手腕一振，\n竟然使出了三清剑法密传绝技
\n"HIC"★★★★★青霞剑芒★★★★★
\n\n"HIW"万点剑芒云起风涌，如清风拂铃，如靡音过耳罩向$n。\n\n" NOR;
                message_vision(msg, me, target);

                ap = me->query("combat_exp");
                dp = target->query("combat_exp")/3;

                if( dp < 1 )
                        dp = 1;
                if( random(ap) > dp || random(3)==0)
                {
                        msg = HIR "$n对付这招显然束手无策，万道剑芒恰如无数剑片打在了$n的身上，\n\n$n惨叫一声，脸上露出极为痛苦的表情。\n\n"NOR;
                        message_vision(msg, me, target);
                        kee_wound = 380 + skill + random(skill*2);

                        if(kee_wound > target->query("kqi")) kee_wound = (target->query("qi") + 1);
                        target->receive_damage("kee",kee_wound); 
                        target->receive_wound("kee", kee_wound);
                        COMBAT_D->report_status(target, 0);

                        me->add("neili",-100);
                }
                else
                {
                        msg = HIG "$n显然老练至极，脚一点地疾飞冲天，堪堪躲过了这满天的剑芒。\n\n"NOR;
                        message_vision(msg, me, target);

                        me->add("neili",-150);
                }

 

}        
        call_out("jianmang_ok",3+random(2),me);
        return 1;
}

void jianmang_ok(object me) 
{
        if (!me) return;
        me->delete_temp("jianmang_busy");
}






int perform_qiao(object me)
{
        object weapon, target;
        if (!me) return 1;
        target = me->select_opponent();
        
if (me && target)
{
        me->delete_temp("jianmang_busy");
        if(me->is_fighting() && living(target) && living(me))
        {
                object qiao;
                string msg;
                int count;
                count = me->query_str();
                me->add_temp("apply/attack", 200); 
	me->add_temp("apply/damage", 2200);

                count = me->query_str();
                //me->add_temp("str", count * 2); 
                msg = HIY "\n$N突然从腰畔将剑鞘拿到手中，招式突然加速，闪电般攻出三招，这突然的变化令$n目瞪口呆！\n\n"NOR;
                message_vision(msg, me, target);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                me->delete_temp("apply/attack", 200);
	me->add_temp("apply/damage", -2200);

                //me->delete_temp("str", count * 2);
        }
}
        return 1;
}
