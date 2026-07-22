#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("特殊技法只能对战斗中的对手使用。\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "还没有从惊恐中镇静下来\n");

        if(me->query_skill("wave_steps") < 45 && me->query("force")<80){
                return notify_fail("显然你的武功火候不够!\n");}
        if( (int)me->query("gin") < 50 )
                return notify_fail("你的精神不能集中，找不准方位。\n");
        msg = HIW "$N使出了「风卷落花雨」,脚踏奇门方位身形流转，踪迹飘然不定，不可琢磨.\n";
        me->add("force",-80);
        me->start_busy(1);
        if( random(me->query("combat_exp")) > random(target->query("combat_exp")) ) {
                msg += "$p骤然失却目标不禁错愕, $P早已绕到$p的身后。\n" NOR;
                
                target->start_busy( (int)me->query_skill("tianfeng-xuan",1) / 100);
        } else {
                msg += "$p微微一呆但立刻镇静过来，一顿身形向$P追袭而去.\n" NOR;
                target->start_busy(1);
        }
        message_vision(msg, me, target);

        return 1;
}

