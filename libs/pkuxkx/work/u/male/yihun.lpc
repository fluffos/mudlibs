//yihun.c 移魂大法

#include <ansi.h>

int exert(object me, object target)
{
	int sp, dp;

        if( !objectp(target) || target->query("id") == "mu ren" || !target->is_character())
		return notify_fail("你要对谁施加移魂大法？\n");

//	if ( me->query_temp("yihuned") )
//		return notify_fail("你刚刚用过移魂大法！\n");

	if( (int)me->query_skill("jiuyin-shengong",1) <80 )
		return notify_fail("你的九阴神功功力不够，不能施加移魂大法。\n");
        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("只能对战斗中的对手使用。\n");

	if( (int)me->query("neili",1) < 50 )
		return notify_fail("你的内力不够，不能使用移魂大法。\n");

	if( target->is_busy() )
		return notify_fail("你的移魂大法还在" + target->name() + "身上发挥着效力，放胆攻击吧！\n");

	message_vision(
		HIR "$N突然神秘的一笑，双眼紧叮着$n，象要把$n的魂摄下来。\n\n" NOR,
		me, target );

	sp = me->query("combat_exp")+ me->query_skill("force")*1000 + me->query_skill("dodge")*500 + me->query("con")*1000;
	dp = target->query("combat_exp")+ target->query_skill("force")*1000 + target->query_skill("dodge")*500 + me->query("con")*1000;

//	me->set_temp("yihuned", 1);		

       if( random(sp) > random(dp)/2 )
	{
		tell_object(target, HIR "你恍恍忽忽，乱蹦乱舞，不知道自己在做什么。\n" NOR);
		tell_object(me, HIG "只见" + target->name() + "乱蹦乱舞，象一只无头苍蝇一样地到处转。\n" NOR);
	

		me->start_busy(random(3));
		target->start_busy(3+(int)me->query_skill("jiuyin-shengong") / 20);
		me->add("neili", -50);

//		call_out("del_yihuned", 2, me);
	}
	else
	{	
		message_vision(HIY "可是$p看破了$P的企图，继续功击。\n" NOR, me, target);

		me->start_busy(2);
//		call_out("del_yihuned", 4, me);
	}

	return 1;
}

//void del_sucked(object me)
//{
//	if ( me->query_temp("yihuned") )
//	me->delete_temp("yihuned");
//}
