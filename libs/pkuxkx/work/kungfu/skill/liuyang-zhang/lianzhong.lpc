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
    object obj, right_weapon;
    string msg;
    int extra, weapon_changed_for_perform;
    mapping attack_val = ([
                           "base" : ([ "no_weapon" : "strike", ]), //基本功夫类型
                           "skill" : ([ "no_weapon" : "liuyang-zhang", ]), //高级技能名称
                           ]);

    if( !target ) target = offensive_target(me);

    if( !target || !target->is_character() )
        return notify_fail("连种生死符只能种在对手身上。\n");

    if( (me->query_skill("bahuang-gong", 1) < 200 ) )
        return notify_fail("你的本门内功不够娴熟，不能连种生死符。\n");

    if( (int)me->query_skill("liuyang-zhang", 1) < 200 )
        return notify_fail("你的天山六阳掌不够娴熟，不能连种生死符。\n");

    if( (int)me->query_skill("throwing", 1) < 200 )
        return notify_fail("你的暗器功夫不够娴熟，不能种生死符。\n");

    if ( me->check_hand() >= 2 )
        return notify_fail("你必须空出一只手才能发射暗器。\n");

    if (!objectp(obj=present("jiudai", me)))
        return notify_fail("你身上没有酒袋，不能化水为冰。\n");

    if( (int)me->query("neili", 1) < 300 )
        return notify_fail("你现在内力太弱，不能发射暗器。\n");

    right_weapon = me->query_temp("weapon");
    if (objectp(right_weapon))
    {
        weapon_changed_for_perform = 1;
        me->changewield();
    }

    extra = me->query_skill("liuyang-zhang",1);
    me->add_temp("apply/strength", extra/4);
    me->add_temp("apply/attack", extra);

    msg = BLU "$N化水为冰，凝于掌中，双指一弹，手上几道青光急速射向$n。\n";
    message_vision(msg, me, target);

    msg =  HIW  "$N左指一弹，"HIG"第一道生死符"HIW"向$n左边打来！" NOR;
    me->set_temp("attack_val", attack_val);
    COMBAT_D->do_attack(me,target, me->query_temp("weapon"), TYPE_SPECIAL, msg);

    msg = HIB  "$N右指一弹，"HIG"第二道生死符"HIB"向$n右边打来! " NOR;
    me->set_temp("attack_val", attack_val);
    COMBAT_D->do_attack(me,target, me->query_temp("weapon"), TYPE_SPECIAL, msg);

    msg = CYN  "$N凌空跃起,"HIG"第三道生死符"CYN"向$n上面打来!" NOR;
    me->set_temp("attack_val", attack_val);
    COMBAT_D->do_attack(me,target, me->query_temp("weapon"), TYPE_SPECIAL, msg);

    if (weapon_changed_for_perform == 1) me->changewield();

    me->add_temp("apply/strength", -extra/4);
    me->add_temp("apply/attack", -extra);

    me->add("neili", -200);

    //命中率C-    
    if( F_KUNGFU->hit_rate( (int)me->query_skill("liuyang-zhang"), target->query_skill("dodge")/3, 9, me, target) )
    {
        msg = HIG "\n又是一道生死符打向$n，$p被$P攻了个正着，身上又中了一道生死符！\n" NOR;
        F_KUNGFU->hit_wound("qi", (int)me->query_skill("bahuang-gong",1), 15 + random(50), me, target);
        target->receive_wound("jing", 10 + random(50), me);
        //target->set_temp("death_cond_origin/ss_poison", me);
		F_POISON->poison_attack(me,target,"ss_poison", random(me->query_skill("liuyang-zhang",1)/10) + 2 +
                target->query_condition("ss_poison"));
        me->start_busy(2);
        message_vision(msg, me, target);
        COMBAT_D->report_status(target);
    }
    else
    {
        msg = HIY"\n$N又是一道生死符打向$n，可是$p急忙闪在一旁，躲了开去。\n" NOR;
        me->start_busy(4);
        message_vision(msg, me, target);
    }
    if ( !target->is_busy() )
      target->start_busy(1 + random(2));
    target->kill_ob(me);
    destruct(obj);
    return 1;
}
