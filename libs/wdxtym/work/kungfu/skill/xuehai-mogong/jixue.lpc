// jixue.c 血海魔功祭血大法

#include <ansi.h>

inherit F_SSERVER;

void remove_effect(object me, int amount);

string query_name() { return "祭血"ZJBR"大法"; }
string *pfm_type() { return ({ "force", }); }

int exert(object me, object target)
{  
	object weapon = me->query_temp("weapon");
	string msg;
	int skill;

	if ((int)me->query_temp("jixue"))
		return notify_fail("你已经运起祭血大法了。\n");
	
if ((int)me->query_temp("jixue-zheng"))
		return notify_fail("你已经运起祭血大法了。\n");
	
	if ((int)me->query("neili") < 300)
		return notify_fail("你的真气不够！\n");

	if ((int)me->query_skill("force") < 150)
		return notify_fail("你的血海魔功的修为不够，不能使用祭血大法！\n");

	msg = HIR "$N" HIR "使出血海魔功「祭血大法」，刹时间脸色变得"
	      "血红，"HIR "$N" HIR "忽地咬破舌尖，喷出一口鲜血！"NOR"\n";

	skill = (int)me->query_skill("xuehai-mogong", 1);

	
	
	if (me->query("qi") > me->query("max_qi") / 2 )
	{
		if (!me->query_temp("weapon")==0 && weapon->query("magic/skill/xuehai-mogong"))
	{
		me->add_temp("apply/damage",skill*2);
		me->add_temp("apply/unarmed_damage",skill*2);
		me->set_temp("jixue-zheng", 1);
		me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill :), 2 + skill/50);
		me->add("neili", -500);
		me->receive_damage("qi", me->query("max_qi") / 2);
		msg = HIR "$N" HIR "使用鲜血，激发红水晶的力量，使大法的力量更上一层楼。"NOR"\n";
		message_combatd(msg, me);
	return 1;
	} 
		me->add_temp("apply/damage", skill);
		me->add_temp("apply/unarmed_damage", skill);
		me->set_temp("jixue", 1);
		me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill :), 2 + skill/50);
		me->add("neili", -250);
		me->receive_damage("qi", me->query("max_qi") / 3);
	} else
		msg = HIR "$N" HIR "发现自己气力不济，没能提起祭血大法。"NOR"\n";

	message_combatd(msg, me);
	return 1;
}

void remove_effect(object me, int amount)
{
	object weapon = me->query_temp("weapon");
	int skill = (int)me->query_skill("xuehai-mogong", 1);
	if ((int)me->query_temp("jixue-zheng") && (weapon->query("magic/skill/xuehai-mogong")))
	{
		me->add_temp("apply/damage", -skill *2);
		me->add_temp("apply/unarmed_damage", -skill*2);
		me->delete_temp("jixue-zheng");
		tell_object(me, "红水晶的力量逐渐减弱，你无法继续维持大法。\n");
	}
	
	
	if ((int)me->query_temp("jixue"))
	{
		me->add_temp("apply/damage", -amount);
		me->add_temp("apply/unarmed_damage", -amount);
		me->delete_temp("jixue");
		tell_object(me, "你的祭血大法运行完毕，将内力收回丹田。\n");
	}
}
