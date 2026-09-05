// zhi.c 孤注一掷

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
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
    object obj, *inv, right_weapon, left_weapon; 
    string msg;
    int damage, throwing_wield = 0;

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() )
        return notify_fail("先搞清楚对手是谁再说吧。\n");

    right_weapon = me->query_temp("weapon");
    left_weapon = me->query_temp("secondary_weapon");

    if ( (objectp(right_weapon) && right_weapon->query("skill_type")=="dagger") ||
         (objectp(left_weapon) && left_weapon->query("skill_type")=="dagger") )
        throwing_wield = 1;

    if ( !throwing_wield && me->check_hand() >= 2 )
        return notify_fail("你必须空出一只手才能发射暗器。\n");

    if( (int)me->query_skill("shenlong-xinfa", 1) < 120 )
        return notify_fail("你的神龙心法还不够，无法使用「孤注一掷」！\n");

    if( (int)me->query_skill("dulong-bi", 1) < 120 )
        return notify_fail("你的毒龙匕法不够娴熟，无法使用「孤注一掷」！\n");

    inv=all_inventory(me);
    for(int i=0;i<sizeof(inv);i++)
    {
        if(inv[i]->query("skill_type")!="dagger") continue;
        if(inv[i] == right_weapon) continue;//不要用手上拿的兵器
        if(inv[i] == left_weapon) continue;//不要用手上拿的兵器
        obj=inv[i];
        break;//找到暗器，退出循环
    }
    if (!obj)
    {
        if ( objectp(left_weapon) && left_weapon->query("skill_type")=="dagger" )
            obj = left_weapon;
        else if( objectp(right_weapon) && right_weapon->query("skill_type")=="dagger" )
            obj = right_weapon;
        else
            return notify_fail("你身上没有匕首，你拿什么扔啊？\n");
    }

    if( (int)me->query("neili", 1) < 200 )
        return notify_fail("你现在内力太弱，恐怕掷不出去！\n");
    msg = HIY "$N阴笑一声，大袖一挥，晃过了$n的双眼，一道寒光电也似的冲$n直射而来。\n等$n发觉时，"+obj->name() +HIY"已经飞到了$n的胸前。\n"NOR;

    me->add("neili", -100);
//命中率C+    
    if( F_KUNGFU->hit_rate(me->query("combat_exp"), target->query("combat_exp"), 7, me, target ) ) 
    {
        msg += HIR "只听见$n“啊”的一声惨叫！"+obj->name()+HIR"已经穿透了$n的胸口！\n" NOR;
        message_vision(msg, me, target);
        damage=(int)me->query_skill("shenlong-xinfa",1)+(int)me->query_skill("dulong-bi",1)+random((int)me->query("dex")*50);
        F_KUNGFU->hit_wound("qi", damage, damage/3, me, target);
        COMBAT_D->report_status(target);
        me->start_busy(1+random(2));
        obj->unequip();
        destruct(obj);
        if( !target->is_killing(me->query("id")) ) target->kill_ob(me);
    } else {
        msg += HIW"恍惚中，$n十分艰难的扭动身躯，"+obj->name()+HIW"贴着$n的肋骨擦身而过。\n" NOR;
        message_vision(msg, me, target);
        me->start_busy(2+random(2));
        obj->unequip();
        obj->move(environment(me));
    }
    if (!target->is_busy()) target->start_busy(1);

    return 1;
}
