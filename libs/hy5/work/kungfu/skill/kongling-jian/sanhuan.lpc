#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int i = me->query_skill("kongling-jian", 1)/5;
        int j = me->query("jiali")/4 + 10;
        
        if( !target ) target = offensive_target(me);

        if( !target
        ||  !target->is_character()
        ||  !me->is_fighting(target) 
        || !living(target))
                return notify_fail("「三环套月」只能对战斗中的对手使用。\n");
        if( (int)me->query_skill("kongling-jian", 1) < 50 )
                return notify_fail("你的空灵剑法功力太浅，别做梦了。\n");

        if( (int)me->query_skill("sword", 1) < 120 )
                return notify_fail("你的基本剑法功力太浅，别做梦了。\n");

        if( (int)me->query_skill("kongdong-xinfa", 1) < 120 )
                return notify_fail("你的内功功力太浅，别做梦了。\n");
                
        if( (int)me->query("max_neili") < 500 )
                return notify_fail("你的内力太浅，别做梦了。\n");
        if( (int)me->query("neili") < 500 )
                return notify_fail("你的真气不够，别做梦了。\n");
        if( (int)me->query("jing") < 100 )
                return notify_fail("你的精不够，别做梦了。\n");
        if (me->query_skill_mapped("force") != "kongdong-xinfa")
                return notify_fail("你用什么为内功基础来使「三环套月」?\n");
        if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "sword"
            || me->query_skill_mapped("sword") != "kongling-jian")
                return notify_fail("你使得了「三环套月」么?\n");
                 
        me->add("neili", -100);
        //me->add("jing", -40);
        me->set_temp("tjj/sanhuan", 4); 
        me->add_temp("apply/attack", i);
        me->add_temp("apply/damage", 600);
if (random(2)==0) target->start_busy(2);
message_vision( HIW "$N使出「三环套月」，招式一变，左手抚剑把，右手托剑，剑尖青光闪动，以一个圆弧将剑锋向$n轻轻挑出！\n"NOR, me, target );
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        if(me->is_fighting(target))
message_vision( HIW "然后$N移进一步，右手左招，左手右招，同样一剑接着挥出，上下连续，不着一点停顿的痕迹！\n"NOR, me, target );
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
message_vision( HIW "剑光紧接，$N手中的长剑又一次挥出急点$n，这三剑剑势相联，剑气相叠，剑意相同，正合道家三清之属！\n"NOR, me, target );
       if(me->is_fighting(target))
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);        

if( me->is_fighting() ) me->start_busy(2);
        me->add_temp("apply/attack", -i);
        me->add_temp("apply/damage", -600);   
        me->start_busy(2);
           me->delete_temp("tjj/sanhuan"); 
//        me->start_perform(4, "「三环套月」");
        return 1;
}
