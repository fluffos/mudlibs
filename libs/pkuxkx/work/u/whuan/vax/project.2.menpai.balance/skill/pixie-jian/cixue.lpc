// cixue.c 辟邪剑刺穴
//added by bing

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    string msg;
    int pp,damage,mm,tt;
    if( !target ) target = offensive_target(me);
    if( !present("xiuhua zhen",me))
        return notify_fail("你身上没有绣花针，怎么刺别人穴道？\n");
    if( !present("flower shoes",me))
        return notify_fail("你没穿绣花小鞋，使不出刺穴一式。\n");
    if( !present("pink cloth",me))
        return notify_fail("你没穿粉红绸衫，使不出刺穴一式。\n");
    if( !present("golden ring",me))
        return notify_fail("你没戴金戒指，使不出刺穴一式。\n");
    if( !present("golden necklace",me))
        return notify_fail("你没戴金项链，使不出刺穴一式。\n");

    if( !target ||  !target->is_character() ||  !me->is_fighting(target) )
        return notify_fail("刺目只能对战斗中的对手使用。\n");

    if(me->query_skill("pixie-jian",1)<200)
        return notify_fail("你辟邪剑法不太熟练，不能刺人穴道。\n");
    if(me->query("neili")<200)
        return notify_fail("你内力不够，不能使出「刺穴」一式。\n");

    if ( target->query("luding_monster"))
    return notify_fail(HIC"对方不吃这一招，看来要另想办法！\n"NOR);
    msg = HIR "$n只觉眼前有一团粉红色的物事一闪，似乎$N的身子动了一动。\n";
    me->start_busy(3);
    target->kill_ob(me);
    if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/10 )
    {
        msg += "听得铛的一声响，$p的眉心、左右太阳穴、鼻下人中四处大穴上，都是有一个细小红点，微微
            有血渗出，显是$P用手中的绣花针所刺。$p张大了口，忽然身子向前直扑下去，俯伏在地，\n" NOR;
        target->set_temp("last_damage_from", me);
        message_vision(msg, me, target);
        target->unconcious();
	 me->start_busy(2+random(2))
        return 1;
    }
    else    
        msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
    message_vision(msg, me, target);
    me->add("neili",-300);
	me->start_busy(4+random(4))
    return 1;
}
