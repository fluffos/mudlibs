// tisha.c

#include <ansi.h>
#include <char.h>
inherit F_SSERVER;

string* valid_weapon()
{
    return ({ "all" });
}

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

int perform(object me, object target)
{
    string msg;

    if ( !target ) target = offensive_target(me);

    if ( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("万里黄沙只能对战斗中的对手使用。\n");

    if (target->is_busy())
        return notify_fail(target->name() + "双目难睁，无法攻击。\n");

    if ((int)me->query_skill("datengnuo-bufa", 1) < 80)
        return notify_fail("你的大腾挪步法不够娴熟，不会使用万里黄沙。\n");

    if ( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FAMILY) && 
         me->query("family/family_name") != "明教" && me->query("chushi/last_family") != "明教" )
        return notify_fail("你现在不是明教弟子，对手不怕你这一招。\n");

    if ((int)me->query("neili") < 400)
        return notify_fail("你的内力不够。\n");

    msg = WHT"$N在打斗中忽然捶胸顿足大声号哭其声可哀,其情可怖.$n心中纳闷欲上前察看,
    熟料$N右腿在地上一卷,扬起"+HIY+"万里黄沙"+NOR+WHT+"把$n全部罩住了!\n\n" NOR;

    me->start_busy(1+me->query("betrayer"));
    if (random(me->query("combat_exp")) > (target->query("combat_exp") / 2))
    {
        msg +=HIY "$p在黄沙漫天中什么也看不见,只能静观启动,身上也不知道收到多少攻击
        却不敢出声,闭紧双眼运起"+NOR+MAG+"铁屁股"+HIY+"神功,假装是一块石头一动不动!\n\n" NOR;
//           target->start_busy(2+(int)me->query_skill("datengnuo-bufa") /40 );
             F_KUNGFU->hit_busy( "confuse", 2+(int)me->query_skill("datengnuo-bufa") / 40, target );
    } 
    else
    {
        msg += HIC"$p只见到眼前尘沙满天，心中一怒运起内力注到双眼之上喝一声“开”！
        $P奇怪对方为什么能够躲过自己的攻击，抬头望去心中一凛:$p在"+HIY+"黄沙烟尘"+HIC+"中\n" +WHT+"神目如电"+HIC+"来去悠闲，根本没有受到影响.\n\n" NOR;
        me->start_busy(2+me->query("betrayer"));
    }
    message_vision(msg, me, target);

    return 1;
}

