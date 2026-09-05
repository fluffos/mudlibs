// liao.c  一阳指的特殊招式－疗伤
// Made by ysg (1997.10.22)

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	int level;
	
	level = me->query_skill("yiyang-zhi", 1);

	if( !target ) target = offensive_target(me);
	
	if( target == me ) 
		return notify_fail("使用一阳指不能给自己疗伤。\n");
	if( !target || !target->is_character() )
		return notify_fail("你要给谁疗伤？\n");
	if( target->is_fighting() || me->is_fighting() )
		return notify_fail("在战斗中疗伤，你想找死啊？\n");
	if( level < 40 ) return notify_fail("你的一阳指等级不够，还不到能够疗伤的境界。\n");
	
	if( (int)me->query("max_neili") < 350 
	|| (int)me->query("neili") < 200 )
		return notify_fail("你的内力不够，不能用一阳指疗伤。\n");

	tell_room(environment(me),
	HIY"只见"+(string)me->query("name")+"深深的吸了一口气，脸色顿时变得紫红，伸出右手食指，运指如飞，\n"
	"沿着"+(string)target->query("name")+"的任、都二脉一路点将下来，只见"
	+(string)target->query("name")+"“哇”的吐出一口鲜血，脸色看起来好多了。\n"NOR,({me,target}));

	tell_object(me,HIY"你盘膝坐下，调匀了气息，使出一阳指的独门功夫，开始疗伤。\n"NOR);
	me->add("neili", -200);
	me->receive_damage("qi", 100);
	me->receive_damage("jing", 100);
	me->receive_wound("jing", 80, "替人疗伤耗尽精血");
	me->receive_wound("qi", 80, "替人疗伤耗尽精血");
	me->start_busy(3);
	target->set("eff_qi", (int)target->query("max_qi"));
	target->set("eff_jing", (int)target->query("max_jing"));
	return 1;
}
