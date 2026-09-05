//tan.c 弹金花

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
    int sp, dp;
    int damage, skilllevel;
    int throwing_wield = 0;
    object obj, *inv, right_weapon, left_weapon;
	string anqi;

    if (!target) target = offensive_target(me);

    if ( !objectp(target) || !target->is_character() ) 
        return notify_fail("暗器射敌只能对同地方的对手使用。\n");

    right_weapon = me->query_temp("weapon");
    left_weapon = me->query_temp("secondary_weapon");

    if ( (objectp(right_weapon) && right_weapon->query("skill_type")=="throwing") ||
         (objectp(left_weapon) && left_weapon->query("skill_type")=="throwing") )
        throwing_wield = 1;

    if ( !throwing_wield && me->check_hand() >= 2 )
        return notify_fail("你必须空出一只手才能发射暗器。\n");

    if (skilllevel = (int)me->query_skill("feihua-shou", 1) < 80)
        return notify_fail("你的飞花摘叶手不够娴熟，不会使用「漫天金花」。\n");

    if ((int)me->query_skill("guangming-shenghuogong", 1) < 30)
        return notify_fail("你的光明圣火功不够高，不能用内力发射暗器。\n");

    if ((int)me->query("neili", 1) < 100)
        return notify_fail("你现在内力太弱，不能发射暗器。\n");

	if (!anqi = me->query_temp("perform_use_anqi"))
		anqi="jin hua";
    obj = F_KUNGFU->find_throwing(me, anqi);
    if (!obj) return notify_fail("你身上没有暗器，怎能使出暗器绝技？\n");

    tell_object(me, HIY "\n你手指一弹，" + obj->name() + HIY"激射而出，击向" + target->name() + HIY"。" NOR);
    message_vision(HIY "\n$N只见眼前金光一闪，似乎有什么暗器打了过来。" NOR, target);
    sp = me->query_skill("force", "guangming-shenghuogong") + me->query_skill("throwing", "feihua-shou");
    dp = target->query_skill("dodge");

    me->start_busy(2);
    me->add("neili", -100);
    if (F_KUNGFU->hit_rate(sp, dp, 9, me, target))
    {
        obj->move(target);
        damage = (int)(me->query_skill("throwing", "feihua-shou") * 3 / 2);
        damage += obj->query("weapon_prop/damage") * 5;
        F_KUNGFU->hit_wound("qi", damage, damage / 3, me, target);
        tell_object(target, HIR "\n你眼见暗器射到身上，偏偏无法避开，不由惨叫一声，身子一歪，退后丈许！！\n" NOR);
        message("vision", HIR "\n结果" + target->name() +
                HIR"被暗器射中，惨叫一声，身子一歪，退后丈许！！\n" NOR, environment(me), target);
        if (obj->query("id") == "jin hua")
        {
            tell_object(target, HIR"\n你仔细一看，竟然是一枚亮闪闪的" + HIW"金花 !!\n" NOR);
            F_KUNGFU->hit_wound("qi", 500, 0, me, target);
        }
        COMBAT_D->report_status(target);
    }
    else
    {
        destruct(obj);
        me->start_busy(2);
        message_vision(HIC "\n可是$N"HIC"看到了暗器，身子急退，躲开了。\n" NOR, target);
    }

    if (F_KUNGFU->hit_rate(me->query("combat_exp"), (int)target->query("combat_exp"), 9, me, target))
    {
        tell_object(target, HIC "\n你没有发现暗器的来源！\n" NOR);
    }
    else
    {
        tell_object(target, HIR "\n你发现了原来是" + me->query("name") + "在发射暗器偷袭你！\n" NOR);
        target->kill_ob(me);
    }
    return 1;
}

