// liancheng-jian.c 连城剑法

inherit SKILL;

mapping *action = ({
([	"action":"$N使一式「孤鸿海上来」，手中$w嗡嗡微振，幻成一条疾光刺向$n的$l",
	"force" : 120,
        "dodge" : 10,
	"damage": 350,
	"lvl" : 0,
	"skill_name" : "孤鸿海上来",
	"damage_type":	"割伤"
]),
([	"action":"$N错步上前，使出「池潢不敢顾」，手中$w划出一道剑光劈向$n的$l",
	"force" : 140,
            "dodge" : 50,
	"damage": 300,
	"lvl" : 9,
	"skill_name" : "池潢不敢顾",
	"damage_type":	"割伤"
]),
([	"action":"$N手中$w一抖，一招「落日照大旗」，斜斜一剑反腕撩出，攻向$n的$l",
	"force" : 160,
           "dodge" : 50,
	"damage": 350,
	"lvl" : 18,
	"skill_name" : "落日照大旗",
	"damage_type":	"割伤"
]),
([	"action":"$N手中剑锵啷啷长吟一声，一式「马鸣风萧萧」，一道剑光飞向$n的$l",
	"force" : 180,
            "dodge" : 50,
	"damage": 300,
	"lvl" : 32,
	"skill_name" : "马鸣风萧萧",
	"damage_type":	"刺伤"
]),
([	"action":"$N一式「落日阳关路」，手中$w舞出无数剑花，使$n难断虚实，无可躲避",
	"force" : 220,
            "dodge" : 50,
	"damage": 340,
	"lvl" : 50,
	"skill_name" : "落日阳关路",
	"damage_type":	"刺伤"
]),
([	"action":"$N手中$w斜指苍天，剑芒吞吐，一式「羌笛怨杨柳」，对准$n的$l斜斜击出",
	"force" : 260,
            "dodge" : 50,
	"damage": 320,
	"lvl" : 70,
	"skill_name" : "羌笛怨杨柳",
	"damage_type":	"刺伤"
]),
([	"action":"$N一式「春风度玉门」，手腕急抖，挥洒出万点金光，刺向$n的$l",
	"force" : 320,
            "dodge" : 50,
	"damage": 360,
	"lvl" : 80,
	"skill_name" : "春风度玉门",
	"damage_type":	"刺伤"
]),
([	"action":"$N一式「遥挂在前川」，$w飞斩盘旋，如疾电般射向$n的胸口",
	"force" : 380,
            "dodge" : 50,
	"damage": 380,
	"lvl" : 90,
	"skill_name" : "遥挂在前川",
	"damage_type":	"刺伤"
]),
([	"action":"$N一式「飞流三千尺」，$w突然从天而降，一片金光围掠$n全身",
	"force" : 400,
            "dodge" : 50,
	"damage": 400,
	"lvl" : 100,
	"skill_name" : "飞流三千尺",
	"damage_type":	"刺伤"
])
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me) { return 1; }

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
	level   = (int) me->query_skill("liancheng-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 350)
		return notify_fail("你的体力不够练连城剑法。\n");
	if ((int)me->query("jing") < 300)
		return notify_fail("你的精力不够练连城剑法。\n");
	me->receive_damage("qi", 300);
	me->receive_damage("jing", 100);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"liancheng-jian/" + action;
}
