inherit SKILL;

mapping *action = ({
([  "action" : "$N一式「蛙鸣三起」，以掌化爪，分袭$n的上中下三路要害",  
    "force" : 120,
    "dodge" : 5,
    "damage": 15,
    "lvl" : 0,
    "skill_name" : "蛙鸣三起",
    "damage_type" : "瘀伤"
]),
([  "action" : "$N左手虚晃，右手由前至后，反扣$n的肩井大穴",
    "force" : 130,
    "dodge" : 10,
    "damage": 20,
    "lvl" : 8,
    "skill_name" : "反手点穴",
    "damage_type" : "瘀伤"
]),
([  "action" : "$N使一式「前瞻后跳」，人似蛤蟆状，半蹲而立，忽得扑向$n",
    "force" : 150,
    "dodge" : 15,
    "damage": 20,
    "lvl" : 30,
    "skill_name" : "前瞻后跳",
    "damage_type" : "瘀伤"
]),
([  "action" : "$N使一式「分身无影」，四面八方出现无数掌影，一拳击向$n
的胸口",
    "force" : 220,
    "dodge" : 25,
    "damage": 35,
    "lvl" : 70,
    "skill_name" : "分身无影",
    "damage_type" : "内伤"
]),
([  "action" : "$N两手成爪像，全身咕噜作响，一式「无敌蛤蟆」，击向$n的$l",
    "force" : 270,
    "dodge" : 30,
    "damage": 40,
    "lvl" : 98,
    "skill_name" : "无敌蛤蟆",
    "damage_type" : "内伤"
])
});
int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }      
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
   return notify_fail("练蛤蟆拳必须空手。\n");
    if ((int)me->query_skill("hamagong", 1) < 20)
   return notify_fail("你的蛤蟆功火候不够，无法学蛤蟆拳。\n");
    if ((int)me->query("max_neili") < 100)
   return notify_fail("你的内力太弱，无法练蛤蟆拳手。\n");
    return 1;
}

string query_skill_name(int level)
{
    int i;
    for(i = sizeof(action)-1; i >= 0; i--)
    if(level >= action[i]["lvl"])
      return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
    int i, level;
    level = (int)me->query_skill("hamaquan", 1);
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
      return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
   return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 20)
   return notify_fail("你的内力不够练蛤蟆拳。\n");
    me->receive_damage("qi", 25);
    me->add("neili", -5);
    return 1;
}
string perform_action_file(string action)
{
	return __DIR__"hamaquan/" + action;
}

