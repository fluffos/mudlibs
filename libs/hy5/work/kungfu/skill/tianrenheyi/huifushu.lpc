#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object obj;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() )
		return notify_fail(HIY"你要为谁使用恢复术？\n"NOR);

//       if( !me->query("zhuanbest",1))
//        return notify_fail("你没有资格使用这项技能！\n");

       if( me->query_condition("tianrenheyi"))
        return notify_fail("你的念力不足！\n");

       if( !me->query("4zhuan") && !me->query("5zhuan"))
        return notify_fail("你没有资格使用这项技能！\n");

       if( me->query("zhuanfinal/3") !=1 )
        return notify_fail("你没有资格使用这项技能！\n");

	if( userp(target) && target!=me && query_ip_name(target)==query_ip_name(me) )
	return notify_fail("你不能对自己的人用这个技术。\n");

        if ( me->is_busy() )
        return notify_fail("你现在正忙，无法使用恢复术");

	if((int)target->query("qi") > (int)target->query("max_qi")-(int)target->query("max_qi")/3)
	return notify_fail("目标现在不需要使用恢复术！\n");

	msg = HIY "$N放声长叹，霎那间，身上的伤在内力的作用下，好了很多!!\n";
	msg += HIY "$N吸取阴阳两气，聚精成力，顿觉气力倍增。\n";
	me->start_busy(2);

	if((int)target->query("qi") < (int)target->query("max_qi")+(int)target->query("max_qi")/3)
        {
        target->set("qi",target->query("max_qi")*2);
        target->set("eff_qi",target->query("max_qi")*2);
        }
        if (target==me)
        me->apply_condition("tianrenheyi",3);
else    me->apply_condition("tianrenheyi",6);
		message_combatd(msg, me, target);
	return 1;
}
