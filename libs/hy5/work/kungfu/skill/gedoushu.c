#include <ansi.h>
inherit SKILL;

mapping *action = ({
([  "action" : 		"$N挥拳攻击$n的$l",
    "damage": 100,
    "lvl" : 0,
    "skill_name" : "蛙鸣三起",
    "damage_type" : "瘀伤"
]),
([  "action" : "$N往$n的$l一抓",
    "dodge" : 10,
    "damage": 100,
    "lvl" : 0,
    "skill_name" : "反手点穴",
    "damage_type":	"抓伤",
]),
([  "action" : "$N往$n的$l狠狠地踢了一脚",
    "dodge" : 15,
    "damage": 20,
    "lvl" : 0,
    "skill_name" : "前瞻后跳",
		"damage_type":	"瘀伤",
]),
([  "action" : "$N提起拳头往$n的$l捶去",
    "dodge" : 25,
    "damage": 80,
    "lvl" : 0,
    "skill_name" : "分身无影",
    "damage_type":	"瘀伤",
]),
([  "action" : "$N对准$n的$l用力挥出一拳",
    "dodge" : 30,
    "damage": 100,
    "lvl" : 0,
    "skill_name" : "无敌蛤蟆",
    "damage_type":	"瘀伤",
])
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }      
int valid_learn(object me)
{
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
    level = (int)me->query_skill("gedoushu", 1);
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
      return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    return 1;
}
string perform_action_file(string action)
{
	return __DIR__"gedoushu/" + action;
}