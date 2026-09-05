// taiji-zhao.c 太极爪

inherit SKILL;

mapping *action = ({
([      "action" : "$N使一招「犀牛望月」，双手骤然一分，飘忽不定的按向$n的$l",
       "force" : 100,
	"dodge" : 30,
   "skill_name" : "犀牛望月",
        "damage_type" : "抓伤"
]),
([      "action" : "$N左手虚点，右手忽左忽右使一招「杯弓蛇影」，向$n的$l插去",
        "force" : 160,
	"dodge" : 25,
        "skill_name" : "杯弓蛇影",
        "damage_type" : "抓伤"
]),
([      "action" : "$N双手回缩,又突然前递一招「云开雾散」密不透风的打向$n的$l",
        "force" : 250,
	"dodge" : 20,
        "skill_name" : "云开雾散",
        "damage_type" : "抓伤"
]),
([      "action" : "$N左手虚晃，身形一变,右爪一记「掩耳盗铃」击向$n的肋部",
        "force" : 300,
	"dodge" : 15,
       "skill_name" : "掩耳盗铃",
        "damage_type" : "抓伤"
]),
([      "action" : "$N一招「鹤立鸡群」，身形一拔,右爪左右连晃数下,击向$n的$l",
        "force" : 340,
	"dodge" : 10,
        "skill_name" : "鹤立鸡群",
        "damage_type" : "抓伤"
])
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }
int valid_combine(string combo) { return combo=="taiji-quan"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
 return notify_fail("练太极爪必须空手。\n");
	if ((int)me->query_skill("taiji-shengong", 1) < 20)
               return notify_fail("你的太极神功火候不够，无法学太极爪。\n");
	if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练太极爪。\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 100)
		return notify_fail("你的体力太低了。\n");
      if ((int)me->query("neili") < 100)
               return notify_fail("你的内力不够练太极爪。\n");
        me->receive_damage("qi", 30);
        me->add("neili", -25);
	return 1;
}

string perform_action_file(string action)
{
        return __DIR__"taiji-claw/" + action;
}

string *parry_msg = ({
        "只听见「锵」一声，被$p格开了。\n",
        "结果「当」地一声被$p挡开了。\n",
        "但是被$n用手中$v架开。\n",
        "但是$n身子一侧，用手中$v格开。\n",
});

string *unarmed_parry_msg = ({
        "但是$n身子一侧，用左手轻轻一推$N的$w，$N的$w一下就偏了出去。\n",
	"$n左手轻轻推出，拍向$N的$w，然后身体向右一侧，顺势后拉，$N就象打在一团棉絮中，对$n毫无伤害。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
