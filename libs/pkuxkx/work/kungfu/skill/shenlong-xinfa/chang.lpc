// chang.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount, int chang);

int exert(object me, object target)
{
        int skill;
        int amount;//每次唱仙法的时候增加的攻防
        int cc;   //当前唱的次数
        string msg;

  //    if( target != me ) return notify_fail("你在对着谁唱仙法呢？\n");
        if( (int)me->query_skill("shenlong-xinfa") < 100)
                return notify_fail("你的神龙心法不够，不能唱仙法！\n");

        if( (int)me->query("neili") < 300)
                return notify_fail("你已经唱得精疲力竭,内力不够了。\n");
                
        if( (int)me->query_temp("chang") >3 
         || (int)me->query_temp("chang") > (int)me->query_skill("shenlong-xinfa",1)/100 )
                return notify_fail("你已经唱得太久了,不能再唱了。\n");

        skill = me->query_skill("force");
        cc=(int)me->query_temp("chang")+1;
        amount=(int)skill/(8*cc);

        me->add("neili", -200);

        message_combatd(HIR "只听$N口中念念有词，顷刻之间武功大进！\n" NOR, me);

        me->add_temp("apply/attack", amount);
        me->add_temp("apply/dodge", -amount);
        me->add_temp("apply/parry", -amount);
        me->add_temp("chang", 1);
        
        me->set_temp("active_force_buffer/shenlong-xinfa.chang"+me->query_temp("chang")+"/name", "唱仙法"+me->query_temp("chang"));                                  //buff名称
        me->set_temp("active_force_buffer/shenlong-xinfa.chang"+me->query_temp("chang")+"/last_time", time() + skill );              //持续时间
        me->set_temp("active_force_buffer/shenlong-xinfa.chang"+me->query_temp("chang")+"/effect1", "攻击命中+"+amount+"级");       //效果描述1   
        me->set_temp("active_force_buffer/shenlong-xinfa.chang"+me->query_temp("chang")+"/effect2", "轻功技能-"+amount+"级");       //效果描述2
        me->set_temp("active_force_buffer/shenlong-xinfa.chang"+me->query_temp("chang")+"/effect3", "招架技能-"+amount+"级");       //效果描述2

        me->start_call_out(__FILE__, "remove_effect", skill, me, amount, me->query_temp("chang") );

        return 1;
}

void remove_effect(object me, int amount, int chang)
{
        if ( (int)me->query_temp("chang") ) {
                me->add_temp("apply/attack", -amount);
                me->add_temp("apply/dodge", amount);
                me->add_temp("apply/parry", amount);
                me->delete_temp("active_force_buffer/shenlong-xinfa.chang"+chang);
                me->add_temp("chang", -1);
                if (me->query_temp("chang")<0) me->delete_temp("chang");
                tell_object(me, "你突然感觉力气全无，似乎仙法的功效已过！\n");
        }
        me->start_busy(2);
}

