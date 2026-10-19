// qingyi-jian.c 情义剑

inherit SKILL;

mapping *action = ({
([      "action":"$N使一式「大悲式」，手中$w嗡嗡微振，幻成一条疾光刺向$n的$l",
	"force" : 120,
	"dodge" : -10,
	"damage": 15,
	"lvl" : 0,
	"skill_name" : "大悲式",
	"damage_type":  "刺伤"
]),
([      "action":"$N错步上前，使出「大欢式」，剑意若有若无，$w淡淡地向$n的$l挥去",
	"force" : 140,
	"dodge" : -10,
	"damage": 20,
	"lvl" : 10,
	"skill_name" : "大欢式",
	"damage_type":  "割伤"
]),
([      "action":"$N一式「大离式」，纵身飘开数尺，运发剑气，手中$w遥摇指向$n的$l",
	"force" : 160,
	"dodge" : 5,
	"damage" : 25,
	"lvl" : 20,
	"skill_name" : "大离式",
	"damage_type":  "割伤"
]),
([      "action":"$N纵身向前跃起，一式「大合式」，剑光如轮疾转，霍霍斩向$n的$l",
	"force" : 180,
	"dodge" : 10,
	"damage": 35,
	"lvl" : 30,
	"skill_name" : "大合式",
	"damage_type":  "割伤"
]),
([      "action":"$N手中$w中宫直进，一式「大喜式」，带着丝丝剑气对准$n的$l刺出一剑",
	"force" : 220,
	"dodge" : 15,
	"damage": 40,
	"lvl" : 40,
	"skill_name" : "大喜式",
	"damage_type":  "刺伤"
]),
([      "action":"$N手中$w斜指苍天，剑芒吞吐，一式「大怒式」，对准$n的$l斜斜击出",
	"force" : 260,
	"dodge" : 5,
	"damage": 45,
	"lvl" : 50,
	"skill_name" : "大怒式",
	"damage_type":  "刺伤"
]),
([      "action":"$N左指凌空虚点，右手$w带出丈许雪亮剑芒，一式「大哀式」刺向$n的$l",
	"force" : 320,
	"dodge" : 5,
	"damage": 55,
	"lvl" : 60,
	"skill_name" : "大哀式",
	"damage_type":  "刺伤"
]),
([      "action":"$N一式「大乐式」，$w嗡嗡作响，如疾电般射向$n的胸口",
	"force" : 380,
	"dodge" : 5,
	"damage": 60,
	"lvl" : 70,
	"skill_name" : "大乐式",
	"damage_type":  "刺伤"
]),
([      "action":"$N一式「心剑」，$w陡然化为纵横交错的剑网，铺天盖地向$n盖下去",
	"force" : 420,
	"dodge" : 5,
	"damage": 60,
	"lvl" : 80,
	"skill_name" : "心剑",
	"damage_type":  "刺伤"
]),

});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }


int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
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
	level   = (int) me->query_skill("qingyi-jian",1);
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
	return __DIR__"qingyi-jian/" + action;
}
