#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object obj;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() )
		return notify_fail(HIY"你要为谁使用复元术？\n"NOR);

//       if( !me->query("zhuanbest",1))
//        return notify_fail("你没有资格使用这项技能！\n");

       if( me->query_condition("tianrenheyi"))
        return notify_fail("你的念力不足！\n");

       if( !me->query("4zhuan") && !me->query("5zhuan"))
        return notify_fail("你没有资格使用这项技能！\n");

       if( me->query("zhuanfinal/1") !=1 )
        return notify_fail("你没有资格使用这项技能！\n");

	if( userp(target) && target!=me && query_ip_name(target)==query_ip_name(me) )
	return notify_fail("你不能对自己的人用这个技术。\n");

        if ( me->is_busy() )
        return notify_fail("你现在正忙，无法使用复元术");

	if((int)target->query("neili") > (int)target->query("max_neili")-(int)target->query("max_neili")/3)
	return notify_fail("目标现在不需要使用复元术！\n");

	msg = HIY "$N大喝一声，一股气流直冲而出!\n";
	msg += HIY "$N真气直透九重 身边斗气突然增强数倍!!！。\n";
	me->start_busy(2);

	if((int)target->query("neili") < (int)target->query("max_neili")+(int)target->query("max_neili")/3)
        {
        target->set("neili",target->query("max_neili"));
        }
        if (target==me)
        me->apply_condition("tianrenheyi",3);
else    me->apply_condition("tianrenheyi",6);
		message_combatd(msg, me, target);
	return 1;
}
