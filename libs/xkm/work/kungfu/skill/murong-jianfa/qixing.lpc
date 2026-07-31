// 七星连环剑
// qixing.c
#include <ansi.h>
#include <skill.h>
#include <combat.h>
#include <weapon.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon, ob;
        string msg, string1;
        int count;
        if( !me->is_fighting() )
                 return notify_fail("「七星连环剑」只能在战斗中对敌人使用。\n");
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                 return notify_fail("[七星连环剑]必须用剑才能施展。\n");
        if (me->query("family/master_id") != "murong fu" && !wizardp(me) )
                 return notify_fail("你未经慕容复传授此剑义，怎能领悟起奥秘？\n");
         if( me->query_skill_mapped("force") != "douzhuan-xingyi" )
               return notify_fail("你没有配合本门内功，恐怕难以领悟[七星连环剑]之妙旨！\n");
        if( (int)me->query_skill("murong-jianfa", 1) < 200 )
               return notify_fail("你的慕容剑法练得不够熟练，不会使用此绝招。\n");
        if( (int)me->query_skill("douzhuan-xingyi", 1) < 100 )
               return notify_fail("你的内功心法不到家不能使用七星连环剑术！\n");
        if( (int)me->query_skill("dodge", 1) < 150 )
               return notify_fail("此绝技需同极高的身法才能使出。\n");
/*
        if (me->query("family/family_name") != "姑苏慕容")
               return notify_fail("你不是慕容弟子，无法领悟其奥妙。\n");               
*/
        if( (int)me->query("max_neili") < 1000 )
               return notify_fail("你的内力不足以发出此招！\n");
        if( (int)me->query("neili") < 400 )
               return notify_fail("你的内力不够，怎能发招？\n");

        msg = HIY "\n$N脚踏玄妙之七星步，倒悬至半空，使出慕容剑法绝技[七星连环剑]。\n"NOR;
        message_vision(msg, me, target);

        me->clean_up_enemy();
        ob = me->select_opponent();

        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

        msg = HIY "\n$N施展完[七星连环剑]，缓缓落地，动作极其潇洒。\n"NOR;
        message_vision(msg, me, target);

        me->add("neili", -400);
        me->add("jingli", -100);
        if( (int)me->query_skill("murong-jianfa", 1) > 100 ) 
        {
        if( me->is_fighting() ) me->start_busy(3+random(2));
        }
        if( (int)me->query_skill("murong-jianfa", 1) > 200 ) 
        {
        if( me->is_fighting() ) me->start_busy(2+random(2));
        }
        if( (int)me->query_skill("murong-jianfa", 1) > 300 ) 
        {
        if( me->is_fighting() ) me->start_busy(1+random(2));
        }

        return 1;
}
