// invocation.c
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
                return notify_fail(HIB"「召唤恶魔」只能对战斗中的对手使用。\n"NOR);

        if( !me->query("zhuanbest",1))
        return notify_fail("你没有资格使用这项技能！\n");

	if((int)me->query("neili")< 4000)
	return notify_fail("你的法力太差了！\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("魔法不是用来对付弱小玩家的！\n");
	
	if((int)me->query_skill("magic-dark",1)< 650)
	return notify_fail("你的黑暗魔法太差了！\n");
        spells = me->query_skill("spells");
        if(spells < 30 )
                return notify_fail("你的法术不够高！\n");

	if( !me->is_fighting() )
		return notify_fail("只有战斗中才能召唤恶魔！\n");
	
        if (present("dark angel",environment(me)))
		return notify_fail("只能如唤一个恶魔为你做战！\n");
        
        if ((int)me->query_condition("zdizi_busy"))  
        return notify_fail("召唤术可不能一天到晚用!\n");
	
	message_vision(HIB"$N"HIB"用手在天空划了一个五芒星，口中喃喃地念著咒文\n", me,target);
	message_vision(HIB"$N"HIB"念到，唤地的五芒，召唤水的五芒，召唤火的五芒，召唤风的五芒! \n", me,target);
	message_vision(HIB"$N"HIB"念到，伟大的王神啊，在我周围照耀五芒星的光芒吧!\n", me,target);
	message_vision(HIB"$N"HIB"念到，从上天的五芒中赐予我力量吧！！！\n", me,target);
	message_vision(HIB"$N"HIB"念到，统御四界的黑暗之王啊! \n", me,target);
	message_vision(HIB"$N"HIB"念到，世上所有黑暗的主人啊 ！\n", me,target);
	message_vision(HIB"$N"HIB"念到，请展现您雄壮的身姿吧 ！\n", me,target);
	message_vision(HIB"$N"HIB"念到，伴着那巨大的黑洞 ！\n", me,target);
	message_vision(HIB"$N"HIB"念到，出现吧，坠天使 路西法!!! \n", me,target);
 

	me->add("neili", -2500);
me->start_busy(3);
	seteuid(getuid());

soldier =new("/clone/magic/darkman");
message_vision(HIB"$N"HIB"咒语过后,暗黑天使路西法出现了！！\n", me,target);
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
