// 掌刀
#include <ansi.h>

inherit F_SSERVER;

void remove_effect(object me, int amount);

int perform(object me, object target)
{
        int skill;

        if(!target ) target = offensive_target(me);
        if(!target || !me->is_fighting(target) )
                return notify_fail("只能在战斗中使用。\n"); 
        if( objectp(me->query_temp("weapon")) )
                return notify_fail("你必须空手才能使用「掌刀」！\n");       
        if((int)me->query("neili") < 500  ) 
                return notify_fail("你的内力不够。\n");
        if((int)me->query_temp("tzzf") ) 
                return notify_fail("你已经在掌刀的运功中。\n");
        if((int)me->query_skill("tiezhang-zhangfa", 1) < 120 )
                return notify_fail("你的铁掌掌法还不够娴熟，使不出「掌刀」来。\n");
        if((int)me->query_skill("force") < 140 )
                return notify_fail("你的内功等级不够，使不出「掌刀」来。\n");
        if((int)me->query_str() < 30 )
                return notify_fail("你的膂力还不够强劲，使不出「掌刀」来。\n");
        if( (int)me->query_skill("guiyuan-tunafa", 1) < 120 )
                return notify_fail("你的归元土吐纳法等级还不够，使不出「掌刀」绝技。\n");
        if (me->query_skill_mapped("force") != "guiyuan-tunafa")
                return notify_fail("你所使用的内功不对。\n");
        if (me->query_skill_prepared("strike") != "tiezhang-zhangfa"
        || me->query_skill_mapped("strike") != "tiezhang-zhangfa"
        || me->query_skill_mapped("parry") != "tiezhang-zhangfa")
                return notify_fail("你现在无法使用「掌刀」！\n");

        skill = me->query_skill("tiezhang-zhangfa") / 2;
        skill = skill + me->query_skill("strike");
        skill = skill / 4;
        me->add("neili", -(me->query_skill("strike")+100));
        me->add("jingli", -100);
        message_vision(YEL "$N突然面色苍白，双手颤抖，随即两眼神光一闪，一双手掌颜色变的雪白，发出一种奇怪的光芒！\n" NOR, me, target);
        me->set_temp("tzzf", 1);
		me->add_temp("apply/attack", skill);
        me->add_temp("apply/damage", skill);
        //me->start_call_out( (: call_other, this_object(), "remove_effect", me, skill :), skill/2);
        me->start_call_out(__FILE__, "remove_effect", skill/2, me, skill);
        if( me->is_fighting() ) me->start_busy(1);
        return 1;

}

void remove_effect(object me, int amount)
{        
        int skill;
        skill = me->query_skill("tiezhang-zhangfa") / 2;
        skill = skill + me->query_skill("strike");
        skill = skill / 4;
		me->delete_temp("tzzf");
		me->add_temp("apply/attack", -skill);
        me->add_temp("apply/damage", -skill);
        message_vision(YEL "\n$N掌刀运功完毕，双手逐渐恢复了原状。\n" NOR, me);        
}
