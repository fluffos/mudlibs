//summon 召唤冰雪女神
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
                return notify_fail(HIW"「召唤冰雪女神」只能对战斗中的对手使用。\n"NOR);

        if( !me->query("zhuanbest",1))
        return notify_fail("你没有资格使用这项技能！\n");

	if((int)me->query("neili")< 4000)
	return notify_fail("你的法力太差了！\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("魔法不是用来对付弱小玩家的！\n");
	
	if((int)me->query_skill("magic-water",1)< 600)
	return notify_fail("你的水系魔法太差了！\n");
        spells = me->query_skill("spells");
        if(spells < 30 )
                return notify_fail("你的法术不够高！\n");

	if( !me->is_fighting() )
		return notify_fail("只有战斗中才能召唤冰雪女神！\n");
	
        if (present("bing nv",environment(me)))
		return notify_fail("只能如唤一个冰雪女神为你做战！\n");
        
        if ((int)me->query_condition("zdizi_busy"))  
        return notify_fail("召唤术可不能一天到晚用!\n");
	
	message_vision(HIW"$N"HIW"用手在天空划了一个五芒星，口中喃喃地念著咒文\n", me,target);
	message_vision(HIW"$N念到，宁静的深蓝之海！！\n", me,target);
	message_vision(HIW"$N念到，与天相交的那片汪洋 !\n", me,target);
	message_vision(HIW"$N念到，那动听的歌儿是为谁而唱!\n", me,target);
	message_vision(HIW"$N念到，美丽温柔的水之精灵啊 ! \n", me,target);
	message_vision(HIW"$N念到，我了解你的哀伤  ！\n", me,target);
	message_vision(HIW"$N念到，请展现您那曼妙的身姿 ！\n", me,target);
	message_vision(HIW"$N念到，伴着那洗净一切伤痛和污浊的慈悲之雨  ！\n", me,target);
	message_vision(HIW"$N念到，出现吧 温蒂妮!!! !!! \n", me,target);
 

	me->add("neili", -2000);
me->start_busy(3);
	seteuid(getuid());

soldier =new("/clone/magic/bingnv");
message_vision(HIW"$N"HIW"咒语过后,一名美丽的的冰之女神出现了！！\n", me,target);
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
