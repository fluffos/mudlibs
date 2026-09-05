// xiezi 判官笔法－写字
// by bing

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	string *titles = ({
		HIY "秃笔翁到此一游" NOR,
		HIC "梅庄旅游纪念  － 秃笔翁书" NOR,
		HIR "我是一口小小小小猪" NOR,
		HIG "我是" NOR + HIR "大色狼！" NOR,
	});
	string msg,arg;
	object weapon;

	if( !target ) target = offensive_target(me);
	
	if( !target || !target->is_character() )
		return notify_fail("你要在谁脸上写字？\n");
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("id") != "panguan bi")
        if (!objectp(weapon = me->query_temp("secondary_weapon"))
        || (string)weapon->query("id") != "panguan bi")
	        return notify_fail("你又没拿判官笔，怎么写字？刻吗？\n");


	if( me->query_skill("panguan-bifa",1) < 100 ) 
		return notify_fail("你的判官笔法等级不够，没法在人家脸上写字。\n");
	
	if ((int)me->query("neili") < 100 )
		return notify_fail("你的内力不够，使不出这一招。\n");
	
	msg = HIR "$N手中的判官笔忽然向着$n的脸直戳过来！\n";

	if( ((int)random(me->query("combat_exp")*3/2)) > (int)target->query("combat_exp") )
	{
		msg += "$N在$n脸上连涂几下，然后向后一跃，看着$n的脸哈哈大笑。\n"NOR;
		message_vision(msg, me, target);
		if (!arg)
		{
			target->set("title",titles[random(sizeof(titles))] );
		}
		else {	target->set("title",arg);	}

	}else {
		msg += HIG "但是$n轻轻一躲，逃过了这一劫。\n"NOR;
		message_vision(msg, me, target);
		}
	
	me->add("neili", -100);

	return 1;
}
