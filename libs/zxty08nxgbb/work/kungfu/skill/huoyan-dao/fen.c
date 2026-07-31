// fen.c 焚心以火
#include <ansi.h>
 
inherit F_SSERVER;
 
int perform(object me)
{
    string msg;
    object weapon, target;
        int skill, ap, dp;
        
    me->clean_up_enemy();
    target = me->select_opponent();
        skill = me->query_skill("huoyan-dao",1);
    if( !(me->is_fighting() ))
                return notify_fail("「焚心以火」只能对战斗中的对手使用。\n");
 
if ( (string)me->query("family/family_name") != "雪山寺") 
    return notify_fail("「焚心以火」只有雪山弟子才能使用。\n");

    if (objectp(weapon = me->query_temp("weapon")))
                return notify_fail("你必须空手运功。\n");
    if( (int)me->query_skill("xiaowuxiang", 1) < 399 )
        return notify_fail("你的小无相功等级不够，不能使出「焚心以火」！\n");
    if( skill < 60)
                return notify_fail("你的「火焰刀」等级不够, 不能使出「焚心以火」！\n");
    if( me->query("neili") < 150 )
                return notify_fail("你的内力不够，无法运功！\n");
 
        msg = HIC "$N聚气于掌，忽然手掌变得猩红如血，一招「焚心以火」，向$n的胸口击去。\n"NOR;
    message_vision(msg, me, target);
    ap = skill + skill + skill;
   dp = target->query_skill("unarmed",1);
    if( dp < 1 )
        dp = 1;
    if( ap > dp )
    {
        if(userp(me))
            me->add("neili",-100);
                msg = HIG "$n只觉得精神恍忽，眼前一黑，“哇”的一声喷出一口鲜血！\n"NOR;
if (skill*2>target->query("max_qi")/500)
skill=target->query("max_qi")/1000;
       target->add("eff_jing",-skill/5);
target->receive_wound("qi", skill*2);
        target->start_busy(2);
		me->start_busy(2);
if (random(10)>8) me->start_busy(random(3));
    }
    else
    {
        msg = HIG "只见$n不慌不忙，轻轻一闪，躲过了$N的必杀一击！\n"NOR;
        if(userp(me))
            me->add("neili",-100);
        me->start_busy(2);
    }
    message_vision(msg, me, target);
    return 1;
}

