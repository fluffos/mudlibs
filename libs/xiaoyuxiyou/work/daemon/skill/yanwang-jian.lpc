// Yanwang-jian.c 阎王追魂剑
// Cracked by 凌惊雪 5-19-2003

inherit SKILL;

mapping *action = ({
([      "action" : "$N手中$w一抖，「三阴转幽」使将出来，剑招奇变横生，$n瞧得心惊神眩",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//1
([      "action" : "$N手中$w一抖，「三阴转幽」使将出来，剑招奇变横生，$n瞧得心惊神眩",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//2
([      "action" :"$N手中$w如云雾变化，正是一招「幻影三变」，极尽诡奇之能事，动向无定，不可捉摸",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//3
([      "action" :"$N舞动$w，一招「飞暴流天」,突然一个疾冲，$w挟着闪闪剑光刺向$n的$l",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//4
([      "action" : "$N手中$w自左而右地划了一个大弧,平平刺向$n的$l,正是「修罗初现」",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//5
([      "action" :"$N身形一展，使出「阎王索命」，$w陡发铮然之音，无数光环乱转，霎时之间已将$n裹在一团剑光之中",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//6
([      "action" : "$N暴喝一声，腾空飞起，以泰山压顶之式扑下，$w带着雷霆霹雳一招「怒涛穿石」击向$n的$l",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//7
([      "action" :"$N手上$w慢慢点出，突然间在空中一颤，一招「血海修罗」,剑刃暗发嗡嗡之声，带着漫天血影，顷刻间竟然已绕到了$n背后",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
});


int valid_enable(string usage) 
	{ 
		return (usage == "sword") || (usage == "parry"); 
	}

int valid_learn(object me)
{
        if (me->query("chushi/chushi_hell") != "yes" )
                return notify_fail("你没有领悟「阎王追魂剑」的窍门。\n");
        if ((int)me->query("max_force") < 1000)
                return notify_fail("你的内力太弱，无法练「阎王追魂剑」。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
	int i = me->query_temp("pfm-yanwang");
	if( !me->query_temp("pfm-yanwang") ) {
        return action[random(sizeof(action))];
	}
	else
	{
	return action[i];
	}
}

int practice_skill(object me)
{
        if (me->query("chushi/chushi_hell") != "yes" )
                return notify_fail("你没有领悟「阎王追魂剑」的窍门。\n");
        if ((int)me->query("kee") < 60)
                return notify_fail("你的体力不够练「阎王追魂剑」。\n");
        if ((int)me->query("force") < 50)
                return notify_fail("你的内力不够练「阎王追魂剑」。\n");
        me->receive_damage("kee", 50);
        return 1;
}
string perform_action_file(string func)
{
return CLASS_D("chushi") + "/yanwang-jian/" + func;
}
