// sanhua-judingzhang.c -三花聚顶掌法

inherit SKILL;
#include <ansi.h>

mapping *action = ({
([	"action" : "$N"HIR"合掌交叠，双掌变幻吞吐，缓缓推向"NOR"$n"HIR"的$l"NOR,
	"force" : 280,
        "dodge" : 15,
        "parry" : 20,
	"damage": 10,
	"lvl" : 0,
	"skill_name" : "金玉满堂",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N"HIW"五指绽开，仿佛捧起一朵莲花，疾向"NOR"$n"HIW"的$l拍去"NOR,
	"force" : 460,
        "dodge" : 20,
        "parry" : 15,
	"damage": 20,
	"lvl" : 40,
	"skill_name" : "天门开阖",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N"HIC"左掌虚托，右掌乍伸乍合，瞬间左掌变掌为指，右手反成了虚招，猛地刺往"NOR"$n"HIC"的$l"NOR,
	"force" : 340,
        "dodge" : 15,
        "parry" : 20,
	"damage": 30,
	"lvl" : 60,
	"skill_name" : "宠辱若惊",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N"HIY"双掌乱飞，幻化无形，三朵莲花呈品字形向"NOR"$n"HIY"飘去"NOR,
	"force" : 420,
        "dodge" : 30,
        "parry" : 30,
	"damage": 40,
	"lvl" : 80,
	"skill_name" : "万物自宾",
        "damage_type" : "瘀伤"
])
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_combine(string combo) { return combo=="kongming-quan"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练三花聚顶掌法必须空手。\n");
    if ((int)me->query_skill("sanhua-judingzhang",1)<100)
        return notify_fail("一百级以内三花聚顶掌法，只有通过学习。\n");
	if (me->query("family/family_name")!="全真派")
		return notify_fail("你已叛出师门，就不要再练习三花聚顶掌法了。\n");
    if ((int)me->query_skill("xiantian-gong", 1) < 200)
		return notify_fail("你的先天功火候不够，无法学三花聚顶掌法。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练三花聚顶掌法。\n");
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
	level   = (int) me->query_skill("sanhua-judingzhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练散花掌。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

string *parry_msg = ({
        "只听见「锵」一声，被$p格开了。\n",
        "结果「当」地一声被$p挡开了。\n",
        "但是被$n用手中$v架开。\n",
        "但是$n身子一侧，用手中$v格开。\n",
});

string *unarmed_parry_msg = ({
        "但是被$p格开了。\n",
        "结果被$p挡开了。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
string perform_action_file(string action)
{
    return __DIR__"sanhua-judingzhang/" + action;
}
