#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int i,lvl;
        
        if( !target ) target = offensive_target(me);

        if( !target
        ||  !target->is_character()
        ||  !me->is_fighting(target) 
        || !living(target))
                return notify_fail("「云龙三现」只能对战斗中的对手使用。\n");

        if( (int)me->query_skill("yunlong-jian", 1) < 120 )
                return notify_fail("你的云龙剑法功力太浅，别做梦了。\n");

        if( (int)me->query_skill("sword", 1) < 120 )
                return notify_fail("你的基本剑法功力太浅，别做梦了。\n");
                        
        if( (int)me->query("max_neili") < 1200 )
                return notify_fail("你的内力太浅，别做梦了。\n");
                
        if( (int)me->query("neili") < 500 )
                return notify_fail("你的真气不够，别做梦了。\n");
                
        if( me->query_skill_mapped("force") != "yunlong-shengong" &&
            me->query_skill_mapped("force") != "jiuyang-shengong") 
            
                return notify_fail("你用什么为基础来使云龙剑绝技么?\n");
        if( !(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "sword"
            || me->query_skill_mapped("sword") != "yunlong-jian")
                return notify_fail("你使得了云龙剑绝技么?\n");
                
        lvl = ( (int)me->query_skill("yunlong-jian", 1) + (int)me->query_skill("force", 1) ) /8;
        
        me->add("neili", -300);
        message_combatd(HIR "\n$N长笑一声，随手一抖，" + weapon->name() + HIR"竟嗡嗡作响，宛若龙吟一般。\n"
                "突然间剑光一闪，旁人只听“哧哧”几声轻响， $N已在一瞬间向$n刺了三剑，快的异乎寻常！\n"NOR, 
                me, target);
                
        me->add_temp("apply/dex", lvl); 
        me->add_temp("apply/damage", lvl);
        me->add_temp("apply/str", lvl);
        me->add_temp("apply/attack", lvl); 
        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        
        me->add_temp("apply/damage", -lvl);
        me->add_temp("apply/str", -lvl);
        me->add_temp("apply/dex", -lvl); 
        me->add_temp("apply/attack", -lvl); 
        
        me->start_busy(3);
        return 1;
}


