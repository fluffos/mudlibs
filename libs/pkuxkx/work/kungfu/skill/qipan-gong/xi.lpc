//xi 玄铁棋盘功 － 吸兵器

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
	object weapon;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「吸兵器」只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("id") != "qi cheng")
        if (!objectp(weapon = me->query_temp("secondary_weapon"))
        || (string)weapon->query("id") != "qi cheng")
	        return notify_fail("你手里没拿玄铁棋秤，没法吸别人兵器。\n");


        if (!objectp(weapon = target->query_temp("weapon")))
	{
		if (!objectp(weapon = target->query_temp("secondary_weapon")))
	        return notify_fail(target->query("name")+"手里没兵器，你吸什么啊？\n");
	}
	if ((weapon->query("material") != "steel") && (weapon->query("material") != "iron"))
	{
		target->set_temp("second",1);
		if(objectp(weapon = target->query_temp("secondary_weapon")))
			{
				if ((weapon->query("material") != "steel") && (weapon->query("material") != "iron"))
				return notify_fail(target->query("name")+"手里的兵器可不是玄铁能吸的。\n");
			}
		else return notify_fail(target->query("name")+"手里的兵器可不是玄铁能吸的。\n");
	}
	
	if( me->is_busy())
		return notify_fail("你正忙着呢！\n");
        msg = HIR "突然间$p手中"+weapon->query("name")+"正被一股大力所拉扯，似欲脱手而去，大惊失色，赶忙运劲回夺。\n";
	
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) 
	{
		if (target->query_temp("second"))
			{	target->delete_temp("secondary_weapon"); }
		else	target->delete_temp("weapon");
                msg += "但为时已晚，只见"+weapon->query("name")+"如同活了一般从$p手中飞出，笔直地飞向了$N手里的棋盘，紧紧的贴在了上面。\n" NOR;
		weapon->move(me);
        } else {
                msg += HIG ""+weapon->query("name")+"被$p抓得紧紧的，没有脱手。\n" NOR;
        }
        message_vision(msg, me, target);
	me->start_busy(3);
	return 1;
}




