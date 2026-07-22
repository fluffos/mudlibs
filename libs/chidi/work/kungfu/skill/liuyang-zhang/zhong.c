// zhong.c 种生死符
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
    object obj;
    string msg;

    if( !target ) target = offensive_target(me);
    if( !target || !target->is_character() )
        return notify_fail("生死符只能种在对手身上。\n");

    if (me->query("gender")!="女性" || me->query("family/family_name")!="灵鹫宫" || (string)me->query_skill_mapped("force")!="bahuang-gong")
        return notify_fail("只有灵鹫宫的弟子才会种生死符。\n");

    if( (int)me->query_skill("liuyang-zhang", 1) < 1000 )
        return notify_fail("你的天山六阳掌不够娴熟，不能种生死符。\n");
	if( environment(me)->query("no_fight") )
		return notify_fail("这里不准战斗。\n");
        if(userp(target) && target->query("age") < 18)
		return notify_fail("放过这个无知小儿吧！\n");
    if (!objectp(obj=present("jiudai", me)))
        return notify_fail("你身上没有酒袋，不能化水为冰。\n");
    if( !obj->query("liquid/remaining") )
        return notify_fail( obj->name() + "是空的。\n" );

	obj->add("liquid/remaining", -1);

    msg = CYN "$N化水为冰，凝于掌中，轻飘飘地拍向$n。\n";
    me->start_busy(1);
    if( random( (int)me->query_skill("liuyang-zhang",1))
          > random(target->query_skill("dodge") ) )
	{
        msg += CYN " 结果$p被$P攻了个正着！\n" NOR;
        target->receive_damage("qi",(int)me->query_skill("bahuang-gong",1),me);
        target->receive_wound("qi",15 + random(10),me);
        target->receive_wound("jing", 10, me);
        target->apply_condition("ss_poison", me->query_skill("liuyang-zhang",1)/100 + 1 +
        target->query_condition("ss_poison"));
        me->start_busy(random(4));
    }
	else
	{
        msg += "可是$p急忙闪在一旁，躲了开去。\n" NOR;
        me->start_busy(4);
    }
    message_vision(msg, me, target);
    target->start_busy(1 + random(2));
    if( !target->is_killing(me) )
        target->kill_ob(me);
    destruct(obj);
    return 1;
}
