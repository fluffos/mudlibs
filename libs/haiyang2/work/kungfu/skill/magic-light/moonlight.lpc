#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object obj;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() )
		return notify_fail(HIY"你要为谁使用月光术？\n"NOR);

       if( !me->query("zhuanbest",1))
        return notify_fail("你没有资格使用这项技能！\n");

	if((int)me->query("neili")< 600)
	return notify_fail("你的法力太差了！\n");

        if ( me->is_busy() )
        return notify_fail("你现在正忙，无法使用月光术");
        if( !me->query("zhuanbest",1))
        return notify_fail("你没有资格使用这项技能！\n");
	if((int)me->query("neili")< 1000)
	return notify_fail("你的法力太差了！\n");
	if((int)me->query_skill("magic-light",1)< 250)
	return notify_fail("你的光明魔法太差了！\n");

	if((int)target->query("qi") > (int)target->query("max_qi")-(int)target->query("max_qi")/3)
	return notify_fail("目标现在不需要使用月光术！\n");

	msg = HIY "$N念动咒语 慈爱万能的主，由您所有的力量，赐与我重生吧！！。\n";
	msg += HIY "$N念动咒语 念动咒语 信光明者，得永生!!！。\n";
	msg += HIW "$n的身上，布慢了圣之月光，身上的伤轻了不少!\。\n";
	me->add("neili",-500);
	me->start_busy(2);

	if((int)target->query("qi") < (int)target->query("max_qi")+(int)target->query("max_qi")/3)
        {
        target->add("qi",target->query("eff_qi")/3);
        target->add("eff_qi",target->query("eff_qi")/3);
if (target->query("qi") > target->query("max_qi")+1000)
target->set("qi",target->query("max_qi")+1000);
if (target->query("eff_qi") > target->query("max_qi"))
target->set("eff_qi",target->query("max_qi"));
        }
	if((int)target->query("jing") < (int)target->query("max_jing")+(int)target->query("max_jing")/3)
        {
        target->add("jing",target->query("eff_jing")/3);
        target->add("eff_jing",target->query("eff_jing")/3);
if (target->query("jing") > target->query("max_jing")+1000)
target->set("jing",target->query("max_jing")+1000);
if (target->query("eff_jing") > target->query("max_jing"))
target->set("eff_jing",target->query("max_jing"));

         }
		message_combatd(msg, me, target);
	return 1;
}
