// 希夷剑法 
inherit SKILL;
#include <ansi.h>
mapping *action = ({
([	"action" : "$N一剑攻出，轻轻撩向$n。",
	"force" : 10,
	"dodge" : 10,
	"damage" : 10,
	"damage_type" : "刺伤"
]),
([	"action" : "$N剑柄反握，撞向$n。",
	"force" : 10,
	"dodge" : 10,
	"damage" : 10,
	"damage_type" : "瘀伤"
]),
});
int valid_enable(string usage) { return usage=="sword";}
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 1000)
		return notify_fail("你的内力不够。\n");
	if ( (int)me->query_skill("huashan-neigong", 1) < 120 )
		return notify_fail("你的华山内功火候太浅。\n");
	if ((int)me->query_skill("force", 1) < 120)
		return notify_fail("你的基本内功火候太浅。\n");
  if ( !me->query("huashan_newskills/jianzong") ||
       me->query("family/family_name")!="华山派" ) 
	  return notify_fail("这是华山剑宗的秘传绝学，你无法学习「希夷剑法」。\n");
	return 1;
}

int practice_skill(object me)
{
	object weapon;
	int min,qi=10,skxy,sk = pow(me->query("combat_exp")/100.0,1.0/3)*10;
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ( (int)me->query_skill("huashan-neigong", 1) < 120 )
		return notify_fail("你的华山内功火候太浅。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练希夷剑法。\n");
	if( (int)me->query("neili") < 50 )
    return notify_fail("你的内力不够了，休息一下再练吧。\n");
  if ( !me->query("huashan_newskills/jianzong") ||
       me->query("family/family_name")!="华山派" ) 
	  return notify_fail("这是华山剑宗的秘传绝学，你无法练习「希夷剑法」。\n");
	min=me->query_skill("yangwu-jian",1)-10;
	if (me->query_skill("xiyi-jian",1)<min)
	{
        me->add("neili", -15);
		qi+=20;
	}
	me->receive_damage("qi", qi);
	skxy=me->query_skill("xiyi-jian",1);
	if (!me->query_temp("hs/xiyi")&&skxy>1200&&me->query("huashan_newskills/jianzong"))
	{
		me->set_temp("hs/xiyi",1);
		if (skxy>sk*4/5)
		skxy=10*(skxy-1200)/(sk-1200);
		if (skxy>10) skxy=10;
		me->add_temp("apply/sword",skxy*me->query_skill("sword")/100);
		message_vision("$N练了一段希夷剑法，觉得对剑法的掌握更加纯熟了。\n",me);
	}
	return 1;
}
