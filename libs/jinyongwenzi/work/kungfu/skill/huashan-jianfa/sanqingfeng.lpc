// sanqingfeng.c 太岳三青峰

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon = me->query_temp("weapon");  

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("太岳三青峰只能对战斗中的对手使用。\n");

        if( me->query_dex() < 30 )
                return notify_fail("你在身法上先天禀赋不足，不能使用太岳三青峰！\n");
        
        if( me->query_skill("zixia-gong", 1) < 60 )
                return notify_fail("你的紫霞神功火候未到，无法施展太岳三青峰！\n");

        if( me->query_skill("dodge") < 80 )
                return notify_fail("太岳三青峰需要超绝的轻功配合，方能有效施展！\n");

        if( me->query_skill("sword") < 80 )
                return notify_fail("你剑法未到炉火纯青之境，还不会使用太岳三青峰！\n");

        if( me->query("neili") <= 500 )
                return notify_fail("你的内力不够使用太岳三青峰！\n");

        if( me->query("jingli") <= 300 )
                return notify_fail("你的精力不够使用太岳三青峰！\n");

        if (!weapon 
         || weapon->query("skill_type") != "sword"
         || me->query_skill_mapped("sword") != "huashan-jianfa")
                return notify_fail("你手中无剑怎能使用太岳三青峰？！\n");

// 42          weapon = (me->query_temp("weapon"))->query("name");

        message_vision(HIR "\n突然间$N大吼一声，聚集全身功力，" + weapon->name() +HIR "直指苍天，蓄势待发！\n" +
        "只听天空中克喇喇几声巨响，剑光挟着风雷之声，$N嗤嗤嗤向$n连攻三剑！剑光将$n的上盘尽数笼罩住了……\n\n" NOR, me, target);

        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),1);
	if (me->is_fighting(target)) COMBAT_D->do_attack(me, target, me->query_temp("weapon"),2);
	if (me->is_fighting(target)) COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);

        me->add("neili", -300);
        me->add("jingli", -100);
        me->start_busy(2);

        return 1;
}
