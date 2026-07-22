// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
mapping *action = ({
	([	"action":		"$N手中的$w迎风一晃，刀锋带出裂锦般的声音，万马奔腾般地砍向$n的$l",
		"force":		400,
                "damage":               200,
                "dodge" : 10,
                "lvl" : 0,
                "skill_name" : "日本无敌",
    		"damage_type":	"割伤"
	]),
	([	"action":		"$N手中的$w迎风狂舞，象暴风中的滚沙，裹向$n的$l",
                "damage":               200,
		"force":		300,
                "dodge" : 30,
                "lvl" : 20,
                "skill_name" : "东亚共荣",
		"damage_type":	"割伤"
	]),
	([	"action":		"$N手中的$w象狂风中的流云，忽聚忽散地砍向$n的$l",
		"force":		100,
                "damage":               200,
                "dodge" : 50,
                "lvl" : 40,
                "skill_name" : "中日亲善",
                "damage_type":	"割伤"
	]),
	([	"action":		"$N晃动手中的$w，刀光忽隐忽现，象秋风中的落叶，一刀连一刀地散向$n的$l",
		"force":		100,
                "damage":               200,
                "dodge" : 60,
                "lvl" : 80,
                "skill_name" : "天皇万岁",
                "damage_type":	"割伤"
	]),
	([	"action":		"$N聚起全身的功力，手中的$w象刺骨寒风般割向$n",
		"force":		200,
		"damage":		200,
                "dodge" : 70,
                "lvl" : 100,
                "skill_name" : "武士不败",
                "damage_type":	"割伤"
	]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; } 

int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 300)
    return notify_fail("你的内力不够。\n");
    if ((int)me->query_skill("force", 1) < 60)
    return notify_fail("你的内功心法火候太浅。\n");
    if ((int)me->query_skill("dodge", 1) < 60)
    return notify_fail("你的轻功火候太浅。\n");
    if ((int)me->query_dex() < 25)
    return notify_fail("你的身法还不够灵活。\n");
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
    level   = (int) me->query_skill("wind-blade",1);
    for(i = sizeof(action); i > 0; i--)
   if(level > action[i-1]["lvl"])
      return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    object weapon;

    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
    return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("qi") < 30)
    return notify_fail("你的体力不够练刀法。\n");
    me->receive_damage("qi", 25);
    return 1;
}

string perform_action_file(string action)
{
    return __DIR__"wind-blade/" + action;
}
