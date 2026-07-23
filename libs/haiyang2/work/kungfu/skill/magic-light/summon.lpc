// summon 召唤天使
#include <ansi.h>
inherit F_SSERVER;
#define MAX_GUARD 15
int perform(object me, object target)
{
	object soldier;
	int	spells;
	string 	msg;
	object	env;
	object	*inv;
	int	i,exp;
	if( !target ) target = offensive_target(me);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail(HIY"「召唤天使」只能对战斗中的对手使用。\n"NOR);

        if( !me->query("zhuanbest",1))
        return notify_fail("你没有资格使用这项技能！\n");

	if((int)me->query("neili")< 4000)
	return notify_fail("你的法力太差了！\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("魔法不是用来对付弱小玩家的！\n");
	
	if((int)me->query_skill("magic-light",1)< 650)
	return notify_fail("你的光明魔法太差了！\n");
        spells = me->query_skill("spells");
        if(spells < 30 )
                return notify_fail("你的法术不够高！\n");

	if( !me->is_fighting() )
		return notify_fail("只有战斗中才能召唤召唤天使！\n");
	
        if (present("light angel",environment(me)))
		return notify_fail("只能如唤一个召唤天使为你做战！\n");
        
        if ((int)me->query_condition("zdizi_busy"))  
        return notify_fail("召唤术可不能一天到晚用!\n");
	
	message_vision(HIY"$N"HIY"用手在天空划了一个五芒星，口中喃喃地念著咒文\n", me,target);
	message_vision(HIY"$N"HIY"念到，炽天使，智天使，座天使，主天使，力天使! \n", me,target);
	message_vision(HIY"$N"HIY"念到，能天使，权天使，大天使，天使，三阶九天使啊!\n", me,target);
	message_vision(HIY"$N"HIY"念到，天罚之时已经到来，请赐给我面前的敌人永久的毁灭吧！！！！！！\n", me,target);
	message_vision(HIY"$N"HIY"念到，摇荡于久远与无限之间所有心之根源啊! \n", me,target);
	message_vision(HIY"$N"HIY"念到，所有存在于此的光明之火炎啊！\n", me,target);
	message_vision(HIY"$N"HIY"念到，请将沉睡于我灵魂深处的这个力量！\n", me,target);
	message_vision(HIY"$N"HIY"念到，从无限召唤到此助我一臂之力吧！！！ ！\n", me,target);
	message_vision(HIY"$N"HIY"念到，出现吧，军天使 米迦勒 !!! \n", me,target);
 

	me->add("neili", -2500);
me->start_busy(3);
	seteuid(getuid());

soldier =new("/clone/magic/lightman");
message_vision(HIY"$N"HIY"咒语过后,军天使 米迦勒 !!!出现了！！\n", me,target);
	soldier->move(environment(me));
if (userp(me))
{
	soldier->set("combat_exp",me->query("combat_exp"));
exp = (int)me->query("combat_exp");
	soldier->set("qi",me->query("max_qi"));
	soldier->set("eff_qi",me->query("max_qi"));
	soldier->set("max_qi",me->query("max_qi"));
	soldier->set("jing",me->query("max_qi"));
	soldier->set("eff_jing",me->query("max_qi"));
	soldier->set("max_jing",me->query("max_qi"));
	soldier->set("neili",me->query("max_neili"));
	soldier->set("max_neili",me->query("max_neili"));
}
        soldier->invocation(me, (exp));
	soldier->set("possessed", me);
	return 1;
}
