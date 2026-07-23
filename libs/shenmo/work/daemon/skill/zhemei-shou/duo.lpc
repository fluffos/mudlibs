// duo.c 空手入白刃
 
#include <ansi.h>
 
inherit F_SSERVER;
 
int perform(object me)
{
	string msg;
	object weapon, weapon2, target;
	int skill, dp, damage;

	me->clean_up_enemy();
	target = me->select_opponent();

	if( (int)me->query_temp("duo") )
		return notify_fail("你已经在夺敌人的兵刃了。\n");
	skill = me->query_skill("zhemei-shou",1);

	if( !(me->is_fighting() ))
		return notify_fail("空手入白刃只能对战斗中的对手使用。\n");
 
	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("你必须空手。\n");

	if (!objectp(weapon2 = target->query_temp("weapon")))
	   return notify_fail("对方没有兵刃，你不用担心。\n");

	if( skill < 50)
		return notify_fail("你的天山折梅手等级不够, 不能空手入白刃！\n");

        if (((int)me->query_skill("bahuang-gong", 1) < 50) &&
            ((int)me->query_skill("beiming-shengong", 1) < 50 ))
        return notify_fail(RED"你本门内功火候不够，使不出「空手夺白刃」。\n"NOR);

	if( me->query("neili") < 50 )
		return notify_fail("你的内力不够，无法空手入白刃！\n");
 
	msg = CYN "$N凝神闭息，打算施展空手入白刃的绝技. \n";
	message_combatd(msg, me);
     if( weapon2->query("ownmake"))
                return notify_fail("这个武器好像夺不下来！\n");
     if( weapon2->query("no_get") && weapon2->query("no_drop") )
                return notify_fail("这个武器好像夺不下来！\n");

	dp = target->query_skill("dodge",1);
	if( dp < 1 )
		dp = 1;
	if( random(skill) > random(dp) )
	{
		if(userp(me))
			me->add("neili",-50);
		msg = "$N使出空手入白刃的绝招, $n顿时觉得眼前一花，手腕一麻，手中兵刃脱手而出！\n" NOR;
		target->start_busy(2);
		weapon2->move(me);
		if (weapon2->query("ownmake")==1)
		{
			weapon2->move(target);
			msg += "那可是$n的随身家伙！$n手一伸将它捡回来。\n" NOR;
		}
		me->start_busy(2);
	}
	else
	{
		msg = "可是$n的看破了$N的企图，立刻采取守势，使$N没能夺下兵刃。\n"NOR;
		me->start_busy(2);
	}
	message_combatd(msg, me, target);
	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}
