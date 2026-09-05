//xuanguan.c // from yihun.c 移魂大法

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target)
{
       if( me->query("family/family_name")!="古墓派" || !me->query("family/topone") ) 
		return notify_fail("你不是古墓派大弟子，没有得到真传，无法使用「冲破玄关」。\n");
		
	if( (int)me->query_skill("jiuyin-shengong",1) <300 )
        return notify_fail("你现在并没有处于定身中。\n");
		
    if( (int)me->query_temp("mark/xuanguan") >time() -10 )
        return notify_fail("你刚刚用过绝技。\n");

    if( (int)me->query("neili",1) < 50 )
        return notify_fail("你的内力不到 50，不能使用冲破玄关解除自己的定身。\n");

    if( target->is_busy() )
        return notify_fail("你的移魂大法还在" + target->name() + "身上发挥着效力，放胆攻击吧！\n");

    message_vision(HIY"$N抬头看天，想起了遥远的大漠，凝目北望，但见北斗七星煜煜生光，猛地心念一动，\n"
					+"依照北斗七星的旋转将体内穴位倒转一遍，定身之术立即解除。\n" NOR, me, target );

    me->add("neili", -50);
    if(random(me->query("combat_exp")+me->query_skill("force")*900)>target->query("combat_exp")/3 )
    {
        tell_object(target, HIR "你恍恍忽忽，乱蹦乱舞，不知道自己在做什么。\n" NOR);
        message_vision(HIG "$N旋即使一个移魂大法，只见$n渐渐咧开嘴，傻笑起来。\n\n"\n" NOR, me, target);
        target->start_busy(8+random(6));
    }
	me->set_temp("mark/xuanguan",time())
    return 1;
}
