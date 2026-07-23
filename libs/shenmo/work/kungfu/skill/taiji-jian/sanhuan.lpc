#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int i = me->query_skill("taiji-jian", 1)/5;
        int j = me->query("jiali")/4 + 10;
        
        if( !target ) target = offensive_target(me);

        if( !target
        ||  !target->is_character()
        ||  !me->is_fighting(target) 
        || !living(target))
                return notify_fail("「三环套月」只能对战斗中的对手使用。\n");
        if( (int)me->query_skill("taiji-jian", 1) < 120 )
                return notify_fail("你的太极剑法功力太浅，别做梦了。\n");

        if( (int)me->query_skill("sword", 1) < 120 )
                return notify_fail("你的基本剑法功力太浅，别做梦了。\n");

        if( (int)me->query_skill("taiji-shengong", 1) < 120 )
                return notify_fail("你的内功功力太浅，别做梦了。\n");
                
        if( (int)me->query("max_neili") < 1500 )
                return notify_fail("你的内力太浅，别做梦了。\n");
        if( (int)me->query("neili") < 500 )
                return notify_fail("你的真气不够，别做梦了。\n");
        if (me->query_skill_mapped("force") != "taiji-shengong")
                return notify_fail("你用什么为内功基础来使「三环套月」?\n");
        if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "sword"
            || me->query_skill_mapped("sword") != "taiji-jian")
                return notify_fail("你使得了「三环套月」么?\n");
                 
        me->add("neili", -100);
        me->add("jing", -40);
        me->set_temp("tjj/sanhuan", 4); 
        me->add_temp("apply/attack", i);
        me->add_temp("apply/damage", j);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        if(me->is_fighting(target))
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        if(me->is_fighting(target))
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);        
if( me->is_fighting() ) me->start_busy(2);
        me->add_temp("apply/attack", -i);
        me->add_temp("apply/damage", -j);   
        me->start_busy(2);
           me->delete_temp("tjj/sanhuan"); 
//        me->start_perform(4, "「三环套月」");
        return 1;
}
