// tan.c  霹雳弹 「弹字诀」
//create bye cuer
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
    int sp, dp;      
    int damage,skilllevel;
    object obj, *inv; 

    if( !target ) target = offensive_target(me);
    if( !target || !target->is_character() )
        return notify_fail("暗器射敌只能对同地方的对手使用。\n");
    if( skilllevel = (int)me->query_skill("pili-dan", 1) < 80 )
        return notify_fail("你的霹雳弹不够娴熟，不会使用「弹字诀」。\n");
    if( (int)me->query_skill("linji-zhuang", 1) < 30 )
        return notify_fail("你的临济十二庄不够高，不能用内力发射暗器。\n");
    if( (int)me->query("neili", 1) < 100 )
        return notify_fail("你现在内力太弱，不能发射暗器。\n");
	inv=all_inventory(me);
	for(int i=0;i<sizeof(inv);i++)
	{
		if(inv[i]->query("skill_type")!="throwing") continue;
		if(inv[i]==me->query_temp("weapon")) continue;//不要用手上拿的兵器
		obj=inv[i];
        break;//找到暗器，退出循环
    }
	if (!obj) return notify_fail("你身上没有暗器，怎能使出暗器绝技？\n");
    tell_object(me, HIG "你手一甩，" + obj->name() + HIG "激射而出，直射向" + target->name() + "！\n" NOR);
    message("vision", HIG "你只见眼前一闪，似乎有什么东西向" + target->name() + "直射过去！\n" NOR, environment(me), ({ me }));
    sp = me->query_skill("force") + me->query_skill("throwing");
    dp = target->query_skill("dodge");

//    destruct(obj);
    me->start_busy(2);
    me->add("neili", -100);
    if( random(sp) > random(dp) )
    {
        damage = (int)(me->query_skill("throwing") * 3/2);
        //damage += obj->query("weapon_prop/damage") * 5;
        target->receive_damage("qi", damage, me);
        target->receive_wound("qi", damage/3, me);
        tell_object(target, HIR "\n你眼见暗器射到身上，偏偏无法避开，不由惨叫一声，身子一歪，退后丈许！！\n" NOR);
        message("vision", HIR "\n结果" + target->name() + 
                "被暗器射中，惨叫一声，身子一歪，退后丈许！！\n" NOR, environment(me), target);
        if(obj->query("id")=="pili dan")
        {
            target->receive_wound("qi", 100 + random(800), me);
            tell_object(target, HIG"\n你仔细一看，竟然是峨嵋派的绝门暗器" + HIR"霹雳弹  !!\n" NOR);
            message("vision", HIR "\n霹雳弹轰的一声炸开!" + target->name() + 
                "被炸得浑身上下体无完肤，狂喊起来！！\n" NOR, environment(me), target);
        }
    }
    else
    {
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
    destruct(obj);
    return 1;
}
