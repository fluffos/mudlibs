// cuijin.c  九阴白骨爪「摧筋破骨」
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;
    if( !target ) target = offensive_target(me);
    if( !target || !target->is_character() || !me->is_fighting(target) )         return notify_fail("「摧筋破骨」只能对战斗中的对手使用。\n");
    if( (int)me->query_skill("jiuyin-zhua", 1) < 180 )
    return notify_fail(WHT"你的九阴白骨爪不够娴熟，还使不出「摧筋破骨」。\n"NOR);
    if( (int)me->query_skill("force", 1) < 180 )
    return notify_fail(RED"你的内功心法火候不够，使用「摧筋破骨」会震伤自己的经脉。\n"NOR);
    if( (int)me->query("neili") < 800 )
    return notify_fail("你内力不够了。\n");
    msg = HIC "$N一声怪啸，绕着$n急转数圈，而后施展出「摧筋破骨」，双爪齐出，直插$n前胸。\n"NOR;
    if (random(me->query("combat_exp")) > target->query("combat_exp"))
{
    if (me->query("neili") > target->query("neili"))
{
    me->start_busy(3);
    damage = target->query("max_qi");
    target->receive_damage("qi", damage/2);
    target->receive_wound("qi", damage/2);                         
    me->add("neili", -400);
    msg += HIR"$N已在$n前胸留下了五个整整齐齐的指洞！$n只觉胸口巨痛，鲜血狂喷而出！！！\n"NOR;
} 
else 
{
    me->start_busy(3);
    damage = target->query("max_qi");
    target->receive_damage("qi", damage/20);
    target->receive_wound("qi", damage/20);                         
    me->add("neili", -400);
    msg += HIY"$N只觉$n内力浑厚！双爪竟不能惯胸而入,只在$n胸前留下了一道血痕！！！\n"NOR;
} 
} 
    else
{
    me->start_busy(3);
    me->add("neili", -300);
    msg += HIY"可是$p早有防备，不慌不忙,卸开了$P的双爪。\n"NOR;
}
    message_combatd(msg, me, target);
    if(userp(target))
me->fight_ob(target);
    else if( !target->is_killing(me) )
me->kill_ob(target);
    return 1;
}