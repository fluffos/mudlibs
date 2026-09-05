//tan.c
// notme 2004-05-25 
// 修改了暗器类perform使得可以使用各种暗器
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
    object obj, right_weapon, left_weapon; 
	string anqi;

    if( !target ) target = offensive_target(me);
    if( !objectp(target) || !target->is_character() )
        return notify_fail("暗器射敌只能对同地方的对手使用。\n");

    right_weapon = me->query_temp("weapon");
    left_weapon = me->query_temp("secondary_weapon");

    if ( (objectp(right_weapon) && right_weapon->query("skill_type")=="throwing") ||
         (objectp(left_weapon) && left_weapon->query("skill_type")=="throwing") )
        throwing_wield = 1;

    if ( !throwing_wield && me->check_hand() >= 2 )
        return notify_fail("你必须空出一只手才能发射暗器。\n");

    if( skilllevel = (int)me->query_skill("qianmie-shou", 1) < 80 )
        return notify_fail("你的千灭银针手不够娴熟，不会使用「满天花雨」。\n");

    if( (int)me->query_skill("yunu-xinfa", 1) < 30 )
        return notify_fail("你的玉女心法不够高，不能用内力发射暗器。\n");

    if( (int)me->query("neili", 1) < 100 )
        return notify_fail("你现在内力太弱，不能发射暗器。\n");

	if (!anqi = me->query_temp("perform_use_anqi"))
		anqi="yufeng zhen";
    obj=F_KUNGFU->find_throwing(me, anqi);
    if (!obj) return notify_fail("你身上没有暗器，怎能使出暗器绝技？\n");
    
    tell_object(me, HIG "只见你手一甩，" + obj->name() + HIG "激射而出，扑向" + target->name() + "！\n" NOR);
    message("vision", HIG "你只见眼前一闪，似乎有什么东西向" + target->name() + "直射过去！\n" NOR, environment(me), ({ me }));
    sp = me->query_skill("force", "yunu-xinfa") + me->query_skill("throwing");
    dp = target->query_skill("dodge");

    me->start_busy(2);
    me->add("neili", -100);
    if( F_KUNGFU->hit_rate(sp, dp, 9, me, target) )
    {
        obj->move(target);
        damage = (int)(me->query_skill("throwing") * 3/2);
        damage += obj->query("weapon_prop/damage") * 5;
        F_KUNGFU->hit_wound("qi", damage, damage/3, me, target);
        if(obj->query("id")=="yufeng zhen")
        {
            //target->set_temp("death_cond_origin/yf_condition", me);
			F_POISON->poison_attack(me,target,"yf_condition",skilllevel/10 + target->query_condition("yf_condition"));
            F_KUNGFU->hit_wound("qi", 0, 250, me, target);
            tell_object(target, HIR"\n你仔细一看，竟然是古墓派得绝门暗器" + HIG"玉蜂针  !!\n" NOR);
            message("vision", HIR "\n结果" + target->name() + 
                "被玉蜂针扎得浑身上下体无完肤，狂嚎起来！！\n" NOR, environment(me), target);
        } 
        COMBAT_D->report_status(target);
        tell_object(target, HIR "\n你眼见暗器射到身上，偏偏无法避开，不由惨叫一声，身子一歪，退后丈许！！\n" NOR);
    }
    else
    {
        destruct(obj);
        me->start_busy(2);     
        message_vision( HIC "\n可是$N身子急退，躲开了扑面而来得暗器攻击。\n" NOR, target);
    }                                    
    if(random(me->query("combat_exp"))>(int)target->query("combat_exp")/2)
    { 
        tell_object(target, HIC "\n你没有发现暗器的来源！\n" NOR);
    }                                                 
    else
    { 
        tell_object(target, HIR "\n你发现了射暗器的人了！\n" NOR);
        target->kill_ob(me);
    }
    return 1;
}

