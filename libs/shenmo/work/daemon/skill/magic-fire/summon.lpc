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
                return notify_fail(RED"「召唤火龙」只能对战斗中的对手使用。\n"NOR);

        if( !me->query("zhuanbest",1))
        return notify_fail("你没有资格使用这项技能！\n");

	if((int)me->query("neili")< 4000)
	return notify_fail("你的法力太差了！\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("魔法不是用来对付弱小玩家的！\n");
	
	if((int)me->query_skill("magic-fire",1)< 600)
	return notify_fail("你的火系魔法太差了！\n");
        spells = me->query_skill("spells");
        if(spells < 30 )
                return notify_fail("你的法术不够高！\n");

	if( !me->is_fighting() )
		return notify_fail("只有战斗中才能召唤火龙！\n");
	
        if (present("shenghuo long",environment(me)))
		return notify_fail("只能如唤一头火龙为你做战！\n");
        
        if ((int)me->query_condition("zdizi_busy"))  
        return notify_fail("召唤术可不能一天到晚用!\n");
	
	message_vision(HIM"$N"HIM"用手在天空划了一个五芒星，口中喃喃地念著咒文\n", me,target);
	message_vision(HIM"$N念到，伟大的火之精灵王啊，听从我的号令，现出你真实的力量吧！！\n", me,target);
	message_vision(HIM"$N念到，终年沸腾的灼热之海!\n", me,target);
	message_vision(HIM"$N念到，那连磐石也能融化的烈焰之洋!\n", me,target);
	message_vision(HIM"$N念到，远高于萨拉曼达的精灵啊! \n", me,target);
	message_vision(HIM"$N念到，世上所有火焰的主人啊 ！\n", me,target);
	message_vision(HIM"$N念到，请展现您雄壮的身姿吧 ！\n", me,target);
	message_vision(HIM"$N念到，伴着那灼天之火 ！\n", me,target);
	message_vision(HIM"$N念到，出现吧，伊弗利特!!! \n", me,target);
 

	me->add("neili", -2000);
me->start_busy(3);
	seteuid(getuid());

soldier =new("/clone/magic/huolong");
message_vision(HIR"$N"HIR"咒语过后,一条巨大的火龙出现了！！\n", me,target);
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
