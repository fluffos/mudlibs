// quanzhen-jian.c 全真剑法

inherit SKILL;

mapping *action = ({
([      "action":"$N使一式「"+HIC+"探海屠龙"+NOR+"」，手中$w由左至右横扫向向$n的$l",
	"force" : 30,
	"attack": 10,
	"dodge" : 10,
	"damage": 13,
	"lvl" : 0,
	"skill_name" : HIC"探海屠龙"NOR,
	"damage_type":  "割伤"
]),
([      "action":"$N踏上一步，「"+HIG+"罡风扫叶"+NOR+"」，手中$w盘旋飞舞出一道剑光劈向$n的$l",
	"force" : 40,
	"attack": 15,
	"dodge" : 20,
	"damage": 14,
	"lvl" : 9,
	"skill_name" : HIG"罡风扫叶"NOR,
	"damage_type":  "割伤"
]),
([      "action":"$N手中$w一抖，一招「"+HIB+"顺水推舟"+NOR+"」，斜斜一剑反腕撩出，攻向$n的$l",
	"force" : 50,
	"attack": 20,
	"dodge" : 25,
	"damage": 15,
	"lvl" : 18,
	"skill_name" : HIB"顺水推舟"NOR,
	"damage_type":  "割伤"
]),
([      "action":"$N手中$w连绕数个大圈，一式「"+HIY+"星弛电闪"+NOR+"」，一道剑光飞向$n的$l",
	"force" : 80,
	"attack": 25,
	"dodge" : 30,
	"damage": 25,
	"lvl" : 27,
	"skill_name" : HIY"星弛电闪"NOR,
	"damage_type":  "刺伤"
]),
([      "action":"$N一式「"+HIM+"白鹤亮翅"+NOR+"」，左手伸展，右手$w挥向$n的$l",
	"force" : 100,
	"attack": 30,
	"dodge" : 35,
	"damage": 28,
	"lvl" : 36,
	"skill_name" : HIM"白鹤亮翅"NOR,
	"damage_type":  "割伤"
]),
([      "action":"$N手中$w斜指苍天，一式「"+YEL+"横行漠北"+NOR+"」，对准$n的$l斜斜击出",
	"force" : 120,
	"attack": 33,
	"dodge" : 45,
	"damage": 30,
	"lvl" : 44,
	"skill_name" : YEL"横行漠北"NOR,
	"damage_type":  "刺伤"
]),
([      "action":"$N一式「"+MAG+"马蹴落花"+NOR+"」，手腕急抖，挥洒出万点金光，刺向$n的$l",
	"force" : 140,
	"attack": 36,
	"dodge" : 42,
	"damage": 42,
	"lvl" : 52,
	"skill_name" : MAG"马蹴落花"NOR,
	"damage_type":  "刺伤"
]),
([      "action":"$N一式「"+HIG+"九品莲台"+NOR+"」，$w飞斩盘旋，如疾电般射向$n的胸口",
	"force" : 160,
	"attack": 40,
	"dodge" : 55,
	"damage": 45,
	"lvl" : 60,
	"skill_name" : HIG"九品莲台"NOR,
	"damage_type":  "刺伤"
]),
([      "action":"$N使一式「"+HIR+"荆轲刺秦"+NOR+"」，手中$w合身疾刺$n的胸口，威不可当",
	"force" : 180,
	"attack": 45,
	"dodge" : 55,
	"damage": 56,
	"lvl" : 70,
	"skill_name" : HIR"荆轲刺秦"NOR,
	"damage_type":  "刺伤"
]),
([      "action":"$N手中$w划出一道长长的弧线，刺向$n的$l，却是一招「"+BLU+"箫史乘龙"+NOR+"」",
	"force" : 200,
	"attack": 50,
	"dodge" : 58,
	"damage": 57,
	"lvl" : 80,
	"skill_name" : BLU"箫史乘龙"NOR,
	"damage_type":  "刺伤"
]),
([      "action":"$N回剑自守，使一式「"+WHT+"深藏若虚"+NOR+"」，蓦地手中$w向$n击出",
	"force" : 230,
	"attack": 55,
	"dodge" : 65,
	"damage": 68,
	"lvl" : 90,
	"skill_name" : WHT"深藏若虚"NOR,
	"damage_type":  "刺伤"
]),
([      "action":"$N左足踢起，一式「"+CYN+"魁星踢斗"+NOR+"」，$w从不可思议的角度刺向$n",
	"force" : 240,
	"attack": 57,
	"dodge" : 62,
	"damage": 70,
	"lvl" : 114,
	"skill_name" : CYN"魁星踢斗"NOR,
	"damage_type":  "刺伤"
]),
([      "action":"$N一式「"+HIY+"紫电穿云"+NOR+"」，$w突然从天而降，一片金光围掠$n全身",
	"force" : 270,
	"attack": 60,
	"dodge" : 66,
	"damage": 75,
	"lvl" : 129,
	"skill_name" : HIY"紫电穿云"NOR,
	"damage_type":  "刺伤"
])
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query_skill("force") < 30)
		return notify_fail("你的内功火候不到，无法学习全真剑法。\n");

	if (me->query("neili") < 200)
		return notify_fail("你的内力太差，无法学习全真剑法。\n");

	if (me->query_skill("sword", 1) < me->query_skill("quanzhen-jian", 1))
		return notify_fail("你的基本剑法水平有限，无法领会更高深的全真剑法。\n");

	return 1;
}

string query_skill_name(int level)
{
	int i;
	for (i = sizeof(action) - 1; i >= 0; i--)
		if (level >= action[i]["lvl"])
			return action[i]["skill_name"];
}
//等级提升，是否学会新的招式
string query_skill_up(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
	 {
		if(level == action[i]["lvl"])
		 {
		     return action[i]["skill_name"];
		 }
	 }
	  return "no";
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int) me->query_skill("quanzhen-jian",1);
	for (i = sizeof(action); i > 0; i--)
		if (level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
	object weapon;

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query("qi") < 60)
		return notify_fail("你的体力不够练全真剑法。\n");

	if ((int)me->query("neili") < 60)
		return notify_fail("你的内力不够练全真剑法。\n");

	me->receive_damage("qi", 55);
	me->add("neili", -53);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"quanzhen-jian/" + action;
}
