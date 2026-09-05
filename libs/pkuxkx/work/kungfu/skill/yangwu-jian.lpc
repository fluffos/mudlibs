// 养吾剑法
inherit SKILL;
#include <ansi.h>
mapping *action = ({
([	"action" : "$N平平无奇一剑递出，攻向$n。",
	"force" : 10,
	"dodge" : 10,
	"damage" : 10,
	"damage_type" : "刺伤"
]),
([	"action" : "$N剑锋向下，挥向$n。",
	"force" : 10,
	"dodge" : 10,
	"damage" : 10,
	"damage_type" : "刺伤"
]),
});
int valid_enable(string usage) { return usage=="sword";}
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int valid_learn(object me)
{
	if ( (int)me->query("max_neili") < 1000 )
		return notify_fail("你的内力不够。\n");
	if ( (int)me->query_skill("zixia-shengong", 1) < 120 )
		return notify_fail("你的紫霞神功火候太浅。\n");
	if ( (int)me->query_skill("force", 1) < 120 )
		return notify_fail("你的基本内功火候太浅。\n");
  if ( !me->query("huashan_newskills/qizong") ||
       me->query("family/family_name")!="华山派" ) 
	  return notify_fail("这是华山气宗的秘传绝学，你无法学习「养吾剑法」。\n");
	return 1;
}

int practice_skill(object me)
{
	object weapon;
	int sklvl = pow(me->query("combat_exp")/100.0,1.0/3)*10,min,qi=10;
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ( (int)me->query_skill("zixia-shengong", 1) < 120 )
		return notify_fail("你的紫霞神功火候太浅。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练养吾剑法。\n");
	if( (int)me->query("neili") < 50 )
    return notify_fail("你的内力不够了，休息一下再练吧。\n");
  if ( !me->query("huashan_newskills/qizong") ||
       me->query("family/family_name")!="华山派" ) 
	  return notify_fail("这是华山气宗的秘传绝学，你无法练习「养吾剑法」。\n");
	min=sklvl-20;
	if (me->query_skill("yangwu-jian",1)<min)
	{
        me->add("neili", -15);
		qi+=20;
	}
	me->receive_damage("qi", qi);
	return 1;
}

string perform_action_file(string action)
{
               return __DIR__"yangwu-jian/" + action;
}
