//神驼夺魄 add by jpei

#include <ansi.h> 
#include <combat.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
    int damage, unarmed, strike;
    string msg;

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「神驼夺魄」只能对战斗中的对手使用。\n");

    if( !target->is_busy()) 
        return notify_fail("「神驼夺魄」只能对忙乱中的对手使用。\n");

    if( me->check_hand() >= 1)
        return notify_fail("你双手不空，怎能发招！\n");

    if( (int)me->query_skill("shentuo-zhang",1) < 180 )
        return notify_fail("你的掌法修为不足，使不出神驼夺魄。\n");

    if ((int)me->query_skill("hamagong", 1) < 180)
        return notify_fail("你的蛤蟆功修为还不够。\n");

    if( (int)me->query("neili") < 500 )
        return notify_fail("你现在内力太弱，不能打出神驼夺魄。\n");

    if( (int)me->query("jiali") < 100 )
        return notify_fail("你现在加力太弱，不能打出神驼夺魄。\n");

/*
    if (me->query_skill_prepared("strike") != "shentuo-zhang"
     || me->query_skill_mapped("strike") != "shentuo-zhang")
        return notify_fail("你现在无法使用神驼夺魄！\n");
*/
            
    me->start_perform(4,"神驼夺魄");
    me->start_busy(2);
    msg = HIR"$N趁着$n手忙脚乱之时，使出“神驼夺魄”！\n"NOR;
    //命中率级别C- 
    if( F_KUNGFU->hit_rate( me->query("combat_exp"), target->query("combat_exp"), 9, me, target) )
    {
        me->add("neili", -200);
        strike = me->query_skill("strike", "shentuo-zhang");
        unarmed = me->query_skill("unarmed", "shentuo-zhang");
        damage = ( strike>unarmed ? strike:unarmed ) + me->query_skill("hamagong", 1);
        damage += random(me->query("jiali")*4);
        if (damage>3000) damage = 3000+random(me->query("jiali"));
        F_KUNGFU->hit_wound("qi", damage, damage/2, me, target); 
        msg += HIG"$N偷袭得手，重重的打在$n的胸口，$n登时鲜血狂喷！ \n"NOR; 
        message_vision(msg, me, target);
        COMBAT_D->report_status(target);
    }else{
        msg += HIG"$N心中窃喜，那知偷袭未成，反而内力外泄！\n"NOR;
        message_vision(msg, me, target);
        me->add("neili", -100);       
    }
    if (me->query("neili") < 0) me->set("neili", 0);

    return 1;
}

