// lingxiao.c 天罡指穴法 「凌空指穴」

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
    string msg;

    if( !target ) target = offensive_target(me);
    if( !target
            ||  !target->is_character()
            ||  !me->is_fighting(target) )
        return notify_fail("［凌空指穴］只能对战斗中的对手使用。\n");

    if((int)me->query_str() < 25)
        return notify_fail("你臂力不够,不能使用这一绝技!\n");

    if((int)me->query_skill("linji-zhuang",1) < 100)
        return notify_fail("你临济十二庄的功力不够不能使用凌空指穴!\n");

    if((int)me->query_skill("finger") < 100)
        return notify_fail("你的指法修为不够,目前还不能使用凌空指穴绝技!\n");

    if((int)me->query("neili") < 300)
        return notify_fail("你内力现在不够, 不能使用凌空指穴! \n");

    if( target->is_busy() )
        return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧ⅵ\n");

    msg = YEL "$N使出天罡指穴法绝技「凌空指穴」，回过身来，背后竟似生了眼睛一般，左
        手食中二指向$n接连戳去，一连七指，全是对向$n的头脸与前胸重穴。\n";
    if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) 
    {
        msg +=  NOR "结果$p被$P指力点中几处穴道! \n" ;
        target->start_busy( (int)me->query_skill("tiangang-zhi",1) / 50 + 2);
        me->add("neili", -300);
		me->start_busy(2);
    }
    else
    {
        msg += NOR "$p情急智生，狠力一跃，退出老远。\n";
        me->start_busy(3+random(3));
    }
    message_combatd(msg, me, target);

    return 1;
}
