#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon = me->query_temp("weapon");
        int i = me->query_skill("xuangong-quan", 1)/2;
        int j = me->query("jiali")/2 + 100;
        
        if( !target ) target = offensive_target(me);

        if( !target
        ||  !target->is_character()
        ||  !me->is_fighting(target) 
        || !living(target))
                return notify_fail("「无敌三连击」只能对战斗中的对手使用。\n");

        if( (int)me->query_skill("xuangong-quan", 1) < 250 )
                return notify_fail("你的无极玄功拳功力太浅，练练再说吧！\n");

        if( (int)me->query_skill("cuff", 1) < 250 )
                return notify_fail("你的基本拳法功力太浅，赶紧去领悟吧！\n");
        if( (int)me->query_skill("yinyun-ziqi", 1) < 250 )
                return notify_fail("你的内功功力太浅，还需多多修行。\n");
                
        if( (int)me->query("max_neili") < 1500 )
                return notify_fail("你的内力太少，打坐去。\n");
        if( (int)me->query("neili") < 500 )
                return notify_fail("你的真气不够，无法使出无敌三连击。\n");
        if (me->query_skill_mapped("force") != "yinyun-ziqi")
                return notify_fail("您现在内功是「氤氲紫气」吗！？\n");
        if(weapon)
                return notify_fail("你手中拿着剑，如何使得「无敌三连击」？\n");
                 
        message_vision(YEL"
只见$N脸色微微一沉，拳掌翻飞，手中招式骤然变快！\n"NOR,me);

        me->add("neili", -200);
        me->add("jingli", -30);
        me->add_temp("apply/attack", i*5);
        me->add_temp("apply/damage", j);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
//        if(me->is_fighting(target))
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
//        if(me->is_fighting(target))
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);        
        me->add_temp("apply/attack", -(i*5));
        me->add_temp("apply/damage", -j);   
        me->start_busy(2);
        target->start_busy(1+random(2));
        return 1;
}