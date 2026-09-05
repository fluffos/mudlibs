// feilong.c 华山剑法「天外飞龙」

#include <ansi.h>

inherit F_SSERVER;
int perform(object me,object target)
{
    string msg;

    if( !target ) target = offensive_target(me);

    if( !me->query("feilong"))
        return notify_fail("你的外功中没有这项技能。\n");

    if( !target ||      !target->is_character() ||      !me->is_fighting(target) )
        return notify_fail("「天外飞龙」只能对战斗中的对手使用。\n");


    if( (int)me->query_skill("huashan-jianfa",1) < 100 )
        return notify_fail("你的华山剑法不够娴熟，不会使用「天外飞龙」。\n");

    if( (int)me->query_skill("huashan-neigong",1) < 100 )
        return notify_fail("你的华山内功等级不够，无法使用「天外飞龙」这招。\n");

    if ( target->query("luding_monster"))
    return notify_fail(HIC"对方不吃这一招，看来要另想办法！\n"NOR);
    msg = HIC "$N忽地一声长啸，身形腾空跃起，竟然冲入天际!\n$n正震愕间，一道剑芒震彻四宇八荒如闪电惊虹激射而至!\n\n"NOR;

    me->start_busy(2);
    if( random(me->query("combat_exp")) > (int)target->query("combat_exp")*10) 
    {
        msg += HIR"$p已被这天马行空的一剑震慑得目瞪口呆，三尺青锋竟透胸而过直没至柄!\n$p脑中灵光一闪，突然回光返照，用尽全身力气拔出长剑，大声喝道\n\n\n"HIY + BNK +"【天 外 飞 龙】!!!\n\n\n" + NOR + HIR + "言毕再也支持不住，一头栽倒在地上。\n\n" NOR;
        message_vision(msg, me, target);
        target->set_temp("last_damage_from", me);
        target->set("eff_qi",10);
        target->unconcious();
    } 
    else 
    {
        if (random(2) == 0)
            msg += HIC"$p不惶多想，凭借身经百战的本能身形疾转，生生让开了来势，\n冰冷的剑锋划裂衣衫砭肤而过，只消少许迟缓\n便是开膛破肚之祸.$p不禁出了一身冷汗，心中暗道：\n莫非这就是传说中穆人清老爷子的天外飞龙?不想竟然霸道至斯!\n\n" NOR;
        else    msg += HIC"危急中$p已经想不起任何一招能够低挡，只得横心闭眼全力上格。\n“当”的一声，火花四溅，$p双臂发麻，全身乏力只想躺倒睡去。\n这一挡却也保住了自己性命，$p不由得暗自想到“侥幸侥幸!!”\n\n"NOR;

        message_vision(msg, me, target);
        me->start_busy(5);

    }

    return 1;
}
