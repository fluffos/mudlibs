// counterattack.c

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
object weapon;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("[31m小李飞刀[37m只能对战斗中的对手使用。\n");
	if((int) me->query_skill("feidao",1) <= 300)
		return notify_fail("你的飞刀绝技还不够精纯，不能发出小李飞刀。\n");
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "throwing")
                        return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("neili") < 500  ) 
		return notify_fail("你的内力不够。\n");
        me->add("neili",-200);
       if(userp(me) && !((int)(me->query("max_qi")/me->query("qi"))>=3))
             return notify_fail("你还没受重伤，体会不到生与死的那种境界。\n");

        if( (int)me->query("neili") < 300  ) 
                return notify_fail("你的内力不够。\n");

        me->add("neili",-200);
	message_vision(RED"$N目不转睛地盯着$n，准备发出致命一击。\n"NOR,me,target);
        me->start_call_out( (: call_other, __FILE__, "kill_him", me, 
target :), random(5)+5);
	me->start_busy(5);
	return 1;
}
void kill_him(object me, object target)
{
	string msg;
	if(me->is_fighting() && target->is_fighting() &&
	environment(me) == environment(target))
	{
msg = HIY "$N使出飞刀绝技中例无虚发的" + HIR "小李飞刀" +HIY "，$n只觉得眼前一花，咽喉已被对穿而过！！！" ;
msg +=  "\n一股血箭喷涌而出．．$n的眼睛死鱼般的突了出来．．\n" NOR;

	message_vision(msg, me, target);
if (target->query("qi") > 30000)
{
target->add("qi",-25000);
target->add("eff_qi",-25000);
}else target->unconcious();
	}
	return ;
}
