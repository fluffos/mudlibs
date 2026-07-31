// chan.c 余地鞭 缠字诀
#include <ansi.h>
string query_name() { return "缠字诀"; }
inherit F_SSERVER;
int perform(object me, object target)
{
    string msg;

if( me->query("family/family_name") != "血河派" ) 
            return notify_fail("你不理解血河派的信念，怎么用的出他们的武功。\n"); 

    if( !target ) target = offensive_target(me);
    if( !me->is_fighting() )
        return notify_fail("缠字诀只能对战斗中的对手使用。\n");
    if( (int)me->query_skill("yudi-bian",1) < 150)
        return notify_fail("你的「余地鞭」功力太浅，使不了「缠」字诀！\n");
    if( target->is_busy() )
        return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧!\n");
    msg = HIB "$N使出余地鞭中的「缠」字诀，连挥长鞭企图把$n的全身缠住。\n";
    if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
        msg += "结果$p被$P攻了个措手不及!\n" NOR;
        target->start_busy( (int)me->query_skill("yudi-bian") / 30 + 1);
        me->start_busy(1+ random(1));
    } else {
        msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
        me->start_busy(3);
    }
    message_vision(msg, me, target);
    return 1;
}

