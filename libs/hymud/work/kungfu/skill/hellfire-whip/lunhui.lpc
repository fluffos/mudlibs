//Cracked by Roath

//六道轮回

#include <ansi.h>
 
inherit F_DBASE;
inherit F_SSERVER;
 
void delay_effect(object me, object target, object weapon,int power);
 
int perform(object me, object target)
{
        int delay,skill;
        object weapon=me->query_temp("weapon");
        
        if( !target ) target = offensive_target(me);
        if( !target 
        ||      !target->is_character() 
        ||      target->is_corpse() 
        ||      target==me) 
                return notify_fail("你要对谁施展「炼狱」？\n"); 
        if (!target) return notify_fail("打谁？\n");
        if(environment(me)!=environment(target))
                return notify_fail("你要攻击的人不在这里。\n");
        if (!me->is_fighting(target))
                return notify_fail("你们不在打架。\n");

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("这门绝学只能对战斗中的对手使用。\n");
		
        skill=me->query_skill("buddhism",1);        
        if (skill<160) return notify_fail("你的禅宗心法不够纯熟。\n");

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "whip")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "zhanzhuang-gong")
                return notify_fail("请使用四平大马站桩功!\n");
                if((int)me->query_skill("yijinjing", 1) < 150)
                return notify_fail("你的易筋经级别还不够，使用这一招会有困难！\n");
        if((int)me->query("neili") < 1000 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("qi") < 300 )
                return notify_fail("你的气血不足，没法子施用外功！\n");

        if((int)me->query_skill("hellfire-whip", 1) < 100)
                return notify_fail("你的六道烈火鞭级别还不够，使用这一招会有困难！\n");
                
        skill=me->query_skill("whip");
        if (skill<100) 
                return notify_fail("你的鞭法太差劲了。\n"); 
        if( (int)me->query("neili") < 300 )      
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("lunhui_delay") )
                return notify_fail("你已经在施展炼狱了。\n");
        
        me->add("neili", -200);
        delay=random(2)+1;
        message_vision(HIB"$N阴恻恻地一笑，手中"+weapon->name()+
             HIB"突然慢了下来，$n一见大喜，抓住机会，上前就是一轮疾攻！\n"NOR, me,target);
        me->start_busy(delay);
        //tell_object(me,delay+"\n");
        me->set_temp("lunhui_delay", 1);
        me->start_call_out( (: call_other, __FILE__, "delay_effect", 
me, target,weapon,delay:), delay);
 
        return 1;
}
 
void delay_effect(object me,object target,object weapon,int power)
{
        mapping action;
        mapping new_act=([]);
        int attack,damage;
        
        me->delete_temp("lunhui_delay");
        if (!target) return;
        if (environment(me)!=environment(target)) return;
        if (me->query_temp("weapon")!=weapon) return;

        message_vision(HIR"$N鞭势突然一变，手中"+weapon->name()+
            HIR"幻做漫天鞭影，将$n的退路全部封死。\n"NOR,me,target);
        message_vision(HIR"$N觉得有如置身炼狱，四周都是熊熊鬼火，深受轮回之苦，连气都透不过来。\n"NOR,target);

        me->set("actions", (: call_other, SKILL_D("hellfire-whip"), "query_pfm_action" :) );

        attack=me->query_temp("apply/attack");
        damage=me->query_temp("apply/damage");
        me->add_temp("apply/attack",me->query_skill("hellfire-whip",1));
        me->add_temp("apply/damage",1200);
        COMBAT_D->do_attack(me, target, weapon);
        COMBAT_D->do_attack(me, target, weapon);
        COMBAT_D->do_attack(me, target, weapon);
        COMBAT_D->do_attack(me, target, weapon);
        COMBAT_D->do_attack(me, target, weapon); 
        COMBAT_D->do_attack(me, target, weapon); 
        me->add_temp("apply/attack",-me->query_skill("hellfire-whip",1));
        me->add_temp("apply/damage",-1200);
        message_vision(HIR"\n$N鞭势渐缓，$n四周的鬼火渐渐消失，压力减轻不少！\n"NOR,me,target);
        me->reset_action();
        me->start_busy(1);
        target->start_busy(2);
}

