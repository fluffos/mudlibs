// lingxiao.c 天罡指穴法 「凌空指穴」

#include <ansi.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
    string msg;

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「凌空指穴」只能对战斗中的对手使用。\n");

    if((int)me->query_str() < 25)
        return notify_fail("你臂力不够,不能使用这一绝技!\n");

    if((int)me->query_skill("linji-zhuang",1) < 100)
        return notify_fail("你临济十二庄的功力不够不能使用「凌空指穴」!\n");

    if((int)me->query_skill("finger", "tiangang-zhi") < 100)
        return notify_fail("你的指法修为不够,目前还不能使用「凌空指穴」绝技!\n");

    if((int)me->query("neili") < 300)
        return notify_fail("你内力现在不够, 不能使用「凌空指穴」! \n");

    if( target->is_busy() )
        return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧ⅵ\n");

    msg = YEL "$N使出天罡指穴法绝技「凌空指穴」，回过身来，背后竟似生了眼睛一般，左
        手食中二指向$n接连戳去，一连七指，全是对向$n的头脸与前胸重穴。\n";

    me->add("neili", -200);
//  所有busy类的perform命中不能高于3倍。
    if( F_KUNGFU->hit_rate(me->query("combat_exp"), (int)target->query("combat_exp"), 6, me, target) ) 
    {
        msg +=  NOR "结果$p被$P指力点中几处穴道! \n" ;
        F_KUNGFU->hit_busy( "dianxue", (int)me->query_skill("tiangang-zhi",1) / 50 + 2, target );
    }
    else
    {
        msg += NOR "$p情急智生，狠力一跃，退出老远。\n";
    }
    message_combatd(msg, me, target);
    me->start_busy(2);

    return 1;
}
