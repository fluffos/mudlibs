// 雨激梅花半瓣香 五展梅特殊技
// by hem
// yumei.c perform wuzhan-mei
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{      
       int damage;
       object weapon;
       object obj;
       string msg;
        if( !target ) target = offensive_target(me);
weapon = me->query_temp("weapon");
	if( !target || !target->is_character() )
	return notify_fail("「"HIC"雨激梅花半瓣香"NOR"」只能对对手使用。\n");
	if( (int)me->query_skill("bahuang-gong", 1) < 100 )
                return notify_fail("你的八荒功不够高，不能运用「"HIC"雨激梅花半瓣香"NOR"」。\n");

        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("你现在内力太弱，不能使用「"HIC"雨激梅花半瓣香"NOR"」。\n");
         if(!weapon || weapon->query("skill_type") != "sword")
                 return notify_fail("你必须使用武器才能使用「闪电惊虹」！\n");   

	if(me->query_skill("tianyu-qijian")<100)
	return notify_fail("你的天羽奇剑不够娴熟，不能运用「"HIC"雨激梅花半瓣香"NOR"」。\n");
	if (!objectp(weapon = target->query_temp("weapon")))
	return notify_fail("对手并没有使用武器。\n");
	msg = HIM"$N手中剑斜斜一带，施展出「"HIC"雨激梅花半瓣香"HIM"」，轻飘飘压住$n的兵器！\n"NOR;
	me->start_busy(2);
//	if (random(me->query_skill("force")) > target->query_skill("force")/2 )
	if( random( (int)me->query("combat_exp",1))>random(target->query("combat_exp")/2 ) )
	{
	msg +=HIY"只听得一阵金铁之声，$p的兵刃竟被$P震碎，碎屑如暴雨般反击向$p！\n" NOR;
	obj=target->query_temp("weapon");
	destruct(obj);
	damage = (int)me->query_skill("bahuang-gong", 1);
                
                damage = damage + random(damage/2)+200;
                
if (target->query("qi") >damage)
{
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/1);
}
                me->add("neili", -damage);
	if( damage < 120 )
                        msg += HIY"结果$n被激飞的兵器碎屑击中，受了点儿伤。\n"NOR;
       else if( damage < 140 )
                        msg += HIY"结果$n被激飞的兵器碎屑击中，受了些伤。\n"NOR;
        else if( damage < 180 )
                        msg += RED"结果$n被激飞的兵器碎屑击中，划出满身伤痕，其状甚惨！\n"NOR;
                else
                        msg += HIR"结果$n被激飞的兵器碎屑击中，浑身上下就如刺猬一般！\n"NOR;
                
	target->start_busy(5);
        } 
	else {
	msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
	me->start_busy(3);
}
message_vision(msg, me, target);
return 1;
}