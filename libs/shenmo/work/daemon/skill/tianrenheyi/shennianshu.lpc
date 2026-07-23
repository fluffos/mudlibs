#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object obj;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() )
		return notify_fail(HIY"你要为谁使用神念术？\n"NOR);

//       if( !me->query("zhuanbest",1))
//        return notify_fail("你没有资格使用这项技能！\n");

       if( me->query_condition("tianrenheyi"))
        return notify_fail("你的念力不足！\n");

       if( !me->query("4zhuan") && !me->query("5zhuan"))
        return notify_fail("你没有资格使用这项技能！\n");

       if( me->query("zhuanfinal/6") !=1 )
        return notify_fail("你没有资格使用这项技能！\n");

	if( userp(target) && target!=me && query_ip_name(target)==query_ip_name(me) )
	return notify_fail("你不能对自己的人用这个技术。\n");

        if ( me->is_busy() )
        return notify_fail("你现在正忙，无法使用神念术");


	msg = HIY "$N脸上红光时隐时现 天地二气交泰于身! \n";
	msg += HIY "$N像变了个人一样，气质有若神灵。\n";
	me->start_busy(2);

target->set_temp("apply/intelligence",100);
        if (target==me)
        me->apply_condition("tianrenheyi",3);
else    me->apply_condition("tianrenheyi",60);
		message_combatd(msg, me, target);
	return 1;
}
