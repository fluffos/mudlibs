// fanyun-zhang.c 翻云掌

inherit SKILL;

mapping *action = ({
([      "action" : "$N一式「行云流水」，双掌一翻，一股劲力缓缓推向$n的$l",
	"force" : 180,
	"dodge" : 5,
	"parry" : 20,
	"damage": 15,
	"lvl" : 0,
	"skill_name" : "行云流水",
	"damage_type" : "瘀伤"
]),
([      "action" : "$N一式「披云戴月」，两掌一并，疾向$n的$l戳去",
	"force" : 220,
	"dodge" : 10,
	"parry" : 15,
	"damage": 25,
	"lvl" : 10,
	"skill_name" : "披云戴月",
	"damage_type" : "瘀伤"
]),
([      "action" : "$N使一式「翻云赴雨」，左掌微拂，右掌乍伸乍合，猛地插往$n的$l",
	"force" : 260,
	"dodge" : 15,
	"parry" : 20,
	"damage": 35,
	"lvl" : 20,
	"skill_name" : "翻云覆雨",
	"damage_type" : "瘀伤"
]),
([      "action" : "$N掌心隐隐发红，一式「排山倒海」，掌力如海水般向$n击去",
	"force" : 300,
	"dodge" : 20,
	"parry" : 30,
	"damage": 45,
	"lvl" : 30,
	"skill_name" : "排山倒海",
	"damage_type" : "瘀伤"
]),
([      "action" : "$N身形往上一纵，使出一式「乌云敝日」，双掌一摊，笔直地向$n的$l拍去",
	"force" : 340,
	"dodge" : 25,
	"parry" : 20,
	"damage": 55,
	"lvl" : 40,
	"skill_name" : "乌云敝日",
	"damage_type" : "瘀伤"
]),
([      "action" : "$N身形一变，使一式「重云深锁」，双掌带着萧刹的劲气，猛地击往$n的$l",
	"force" : 280,
	"dodge" : 25,
	"parry" : 25,
	"damage": 65,
	"lvl" : 50,
	"skill_name" : "重云深锁",
	"damage_type" : "瘀伤"
]),
([      "action" : "$N使一式「撕天排云」，左掌凝重，右掌轻盈，同时向$n的$l击去",
	"force" : 320,
	"dodge" : 30,
	"parry" : 30,
	"damage": 75,
	"lvl" : 60,
	"skill_name" : "撕天排云",
	"damage_type" : "瘀伤"
]),
([      "action" : "$N突地一招「云海波涛」，双掌挟着一阵风雷之势，猛地劈往$n的$l",
	"force" : 360,
	"dodge" : 30,
	"parry" : 35,
	"damage": 85,
       "lvl" : 70,
	"skill_name" : "云海波涛",
	"damage_type" : "瘀伤"
]),
([      "action" : "$N一式「变云无定」，双掌缦妙地一阵挥舞，不觉已击到$n的$l上",
	"force" : 300,
	"dodge" : 40,
	"parry" : 45,
	"damage": 95,
	"lvl" : 80,
	"skill_name" : "变云无定",
	"damage_type" : "瘀伤"
]),
([      "action" : "$N一式「殃云天降」，身形向上窜起丈余，双掌一高一低，看似简单，却令$n无法躲闪",
	"force" : 340,
	"dodge" : 45,
	"parry" : 50,
	"damage": 115,
	"lvl" : 90,
	"skill_name" : "殃云天降",
	"damage_type" : "瘀伤"
]),
([      "action" : "$N一式「云莱仙境」，身形凝立不动，两掌间绽出万道霞光，将$n紧紧罩住。",
	"force" : 340,
	"dodge" : 45,
	"parry" : 50,
	"damage": 120,
	"lvl" : 100,
	"skill_name" : "云莱仙境",
	"damage_type" : "瘀伤"
])
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry" || usage=="strike"; }


int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练翻云掌必须空手。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练翻云掌。\n");
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
	level   = (int) me->query_skill("fanyun-zhang",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("jing") < 100)
                return notify_fail("你的精力不够练此武功。\n");
        if ((int)me->query("qi") < 100)
                return notify_fail("你的体力不够练此武功。\n");
        if ((int)me->query("neili") < 100)
                return notify_fail("你的内力不够练此武功。\n");
        me->receive_damage("qi", 50);
        me->receive_damage("jing", 50);
        me->add("neili", -50);

	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"fanyun-zhang/" + action;
}
