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
                return notify_fail(HIC"「召唤天魔神」只能对战斗中的对手使用。\n"NOR);

        if( !me->query("zhuanbest",1))
        return notify_fail("你没有资格使用这项技能！\n");

	if((int)me->query("neili")< 4000)
	return notify_fail("你的法力太差了！\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("魔法不是用来对付弱小玩家的！\n");
	
	if((int)me->query_skill("magic-ice",1)< 600)
	return notify_fail("你的气系魔法太差了！\n");
        spells = me->query_skill("spells");
        if(spells < 30 )
                return notify_fail("你的法术不够高！\n");

	if( !me->is_fighting() )
		return notify_fail("只有战斗中才能召唤天魔神！\n");
	
        if (present("tian moshen",environment(me)))
		return notify_fail("只能如唤一位天魔神为你做战！\n");
        
        if ((int)me->query_condition("zdizi_busy"))  
        return notify_fail("召唤术可不能一天到晚用!\n");
	
	message_vision(HIC"$N"HIC"用手在天空划了一个五芒星，口中喃喃地念著咒文\n", me,target);
	message_vision(HIC"$N念到，眩目的霹雳，将击碎一切愚蠢的阻挡……\n", me,target);
	message_vision(HIC"$N念到，破空而去的光之长矛，将刺穿无边的黑暗……\n", me,target);
	message_vision(HIC"$N念到，沙拉斯，大气和大地的精灵，都按古老契约来履行义务吧！！！！ \n", me,target);
	message_vision(HIC"$N念到，充斥于天地之间的精灵呦，根据古老的契约，展现你们的力量吧！！！！！\n", me,target);
	message_vision(HIC"$N念到，请展现您雄壮的身姿吧 ！\n", me,target);
	message_vision(HIC"$N念到，伴着那满天落雷 ！\n", me,target);
	message_vision(HIC"$N念到，出现吧，沙拉斯!!! \n", me,target);
 

	me->add("neili", -2000);
me->start_busy(3);
	seteuid(getuid());

soldier =new("/clone/magic/iceman");
message_vision(HIC"$N"HIC"咒语过后,一条个巨大的天魔神出现了！！\n", me,target);
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
