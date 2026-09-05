//  jile 往登极乐

#include <ansi.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
    int damage;
    object weapon = me->query_temp("weapon");

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("你只能在战斗中使用『往登极乐』。\n");

    if( (int)me->query_skill("xiangfu-lun", 1) < 150 )
        return notify_fail("你的金刚降伏轮不够娴熟，不会使用往登极乐。\n");

    if( (int)me->query_skill("longxiang-boruo", 1) < 150 )
        return notify_fail("你的龙象般若功的基础不够，不能使用往登极乐。\n");

    if( (int)me->query_dex() < 26 )
        return notify_fail("你的身法太低，不能使用往登极乐。\n");

    if( (int)me->query("neili", 1) < 500 )
        return notify_fail("你现在内力不足！\n");     

    if( (int)me->query("eff_qi") > (int)me->query("max_qi") / 2 )
        return notify_fail("往登极乐是拼命的招数，怎可以随便使用？！\n");    

    if ( !objectp(weapon) || (weapon->query("skill_type") != "hammer") )
/*    || me->query_skill_mapped("hammer") != "xiangfu-lun"
    || me->query_skill_mapped("parry") != "xiangfu-lun") */
        return notify_fail("你现在无法使往登极乐。\n");

    message_vision(RED"\n$N放下法轮，双手合十，默默颂起往生极乐咒：\n"BBLU+HIC"天魔降服，往生极乐，生亦何欢，死亦何苦。\n"HIM"$N逆运龙象般若功，将自己全身静脉振断。"
    "意图和$n拼个玉石俱焚。\n\n"NOR, me, target);
    //命中率B+  
    if((me->query("combat_exp")) > (int)target->query("combat_exp")/2 &&
    F_KUNGFU->hit_rate( me->query_str(), (int)target->query_str(), 4, me, target) ) 
    {
        message_vision(HIR"\n$n被如此凶悍的招数吓的全身冰凉，呆立不动，但见$N振断静脉的真气袭向"
        "$n！\n$n感觉骇怖到了极点，但却有一丝隐隐的超脱之感！\n"NOR, me, target);
        me->start_busy(2);
        if ( !target->is_busy() ) target->start_busy(2);
        me->add("neili", -300);
        damage = (int)target->query("max_qi");
        damage = damage/10;
        damage = damage*9;
        me->query_temp("weapon")->move(target);
        target->kill_ob(me);
        me->receive_damage("qi", damage, "使用往登极乐和"+target->name()+"同归于尽");
        target->receive_damage("qi",damage, "被"+me->name()+"使用往登极乐杀");
        me->add("max_neili",-150);
        me->die();
        target->die();
    }
    else 
    {
        if ( !target->is_busy() ) target->start_busy(5);
        message_vision(HIY"\n$n在千钧一发之际，急忙推开$N，向上飞起，勉强避开这招，但已被吓的目瞪口呆。\n"NOR, me, target);
        me->add("max_neili",-50);
        me->receive_damage("qi", 0, "使用往登极乐自杀");
        me->die();
    }

    return 1;
}
int help(object me)
{
        write(HIB"\n降伏轮之「往登极乐」：\n\n"NOR);
        write(@HELP
        当年密宗金轮法王横扫西域，威镇草原，一手藏密金刚降伏轮使得出神入化！
        此「往登极乐」绝技乃前人所传，一旦使出，多半玉石俱焚！

        要求：  当前内力 500 以上；
                金刚降伏轮等级 150 以上；
                龙象般若功等级 160 以上；
                后天身法 26 以上；
                激发内功为龙象般若功；
                激发锤法为金刚降伏轮；
                激发招架为金刚降伏轮；
                且装备兵器。
HELP
        );
        return 1;
}
