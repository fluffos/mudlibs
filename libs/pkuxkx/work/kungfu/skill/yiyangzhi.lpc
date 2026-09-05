// yiyang-zhi 一阳指
// Made by ysg (1997.10.19)

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action" : "$N侧身抬臂，右手食指划圈，缓缓推出，一式「普渡众生」摁向$n的$l",
	"force"  : 260,
        "dodge"  : 5,
	"parry"  : 10,
	"damage" : 100,
	"lvl" : 0,
	"skill_name" : "普渡众生",
	"damage_type" : "刺伤"
]),
([	"action" : "$N一式「童子拜佛」，双手合十，一股锐利无俦的内力，凌虚向$n的$l涌去",
	"force"  : 240,
	"dodge" : 30,
	"parry"  : 20,
	"damage" : 140,
	"lvl" : 45,
	"skill_name" : "童子拜佛",
        "damage_type" : "内伤"
]),
([	"action" : "$N一式「无我无相」，左手食指指尖向天，指端射出一缕罡气，穿过$n的$l",
	"force"  : 220,
        "dodge"  : 35,
	"parry"  : 35,
	"damage" : 325,
	"lvl" : 65,
	"skill_name" : "无我无相",
        "damage_type" : "刺伤"
]),
([	"action" : "$N满眼慈悲，一式「四大皆空」，右手食指对着对着$n的眉心遥遥摁去，$n不知\n"
			"为何，只觉万般皆空，竟然忘了躲开。",
	"force"  : 300,
        "dodge"  : 40,
	"parry"  : 40,
	"damage" : 320,
	"lvl" : 82,
	"skill_name" : "四大皆空",
        "damage_type" : "刺伤"
])
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练一阳指必须空手。\n");
         if ((int)me->query("max_neili") < 300)
		return notify_fail("你的内力太弱，无法练一阳指。\n");
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
         level = (int) me->query_skill("yiyangzhi", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
        return action[0];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 100)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("你的内力不够练一阳指。\n");
	me->receive_damage("qi", 90);
	me->add("neili", -30);
	return 1;
}

string perform_action_file(string action)
{
return __DIR__"yiyangzhi/" + action;
}