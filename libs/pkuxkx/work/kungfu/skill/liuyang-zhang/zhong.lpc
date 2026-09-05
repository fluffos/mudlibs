// zhong.c 种生死符
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string* valid_weapon() 
{
    return ({ "all" });
}

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other";
}

int perform(object me, object target)
{
    object obj;
    string msg;
    int damage;

    if( !target ) target = offensive_target(me);

    if( !target || !target->is_character() )
        return notify_fail("生死符只能种在对手身上。\n");

    if( me->query_skill("bahuang-gong", 1) < 120 )
        return notify_fail("你的八荒六合功不够娴熟，不能种生死符。\n");

    if( (int)me->query_skill("liuyang-zhang", 1) < 150 )
        return notify_fail("你的天山六阳掌不够娴熟，不能种生死符。\n");

    if( (int)me->query_skill("throwing", 1) < 100 )
        return notify_fail("你的暗器功夫不够娴熟，不能种生死符。\n");

    if ( me->check_hand() >= 2 )
        return notify_fail("你必须空出一只手才能发射暗器。\n");

    if (!objectp(obj=present("jiudai", me)))
        return notify_fail("你身上没有酒袋，不能化水为冰。\n");

    if( (int)me->query("neili", 1) < 100 )
        return notify_fail("你现在内力太弱，不能发射暗器。\n");

    msg = CYN "$N从酒袋中倒出一些清水放在手掌中，倒运内力化水为冰，凝于掌中，轻飘飘地拍向$n。\n";

    me->add("neili", -100);
//命中率B-    
    if( F_KUNGFU->hit_rate( me->query("combat_exp"), (int)target->query("combat_exp"), 6, me, target) ) 
    {
        msg += HIW " 结果$n身子一晃,双肩之后两下针刺般的疼痛直如万蚁咬啮！\n" NOR;
        damage = (int)(me->query_skill("liuyang-zhang",1));
        damage += (int)(me->query_skill("bahuang-gong",1)*1/2);
        damage += (int)(me->query_skill("throwing",1)*1/2);
        F_KUNGFU->hit_wound("qi", damage, damage/3+random(800), me, target);
        target->receive_wound("jing", 10, me);
        //target->set_temp("death_cond_origin/ss_poison", me);
		F_POISON->poison_attack(me,target,"ss_poison", random(me->query_skill("liuyang-zhang",1)/10) + target->query_condition("ss_poison"));
        me->start_busy(2);
        if( !target->is_killing(me->query("id")) ) target->kill_ob(me);
    } else {
        msg += "可是$p急忙闪在一旁，躲了开去。\n" NOR;
        me->start_busy(4);
    }

    message_vision(msg, me, target);
    COMBAT_D->report_status(target);

    if ( !target->is_busy() ) target->start_busy(1 + random(2));

    destruct(obj);

    return 1;
}
