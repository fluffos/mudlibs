// jinding-mianzhang.c -金顶绵掌

inherit SKILL;

mapping *action = ({
([	"action" : "$N向$n遥遥一鞠，一式「三阳开泰」，双掌大开大阖，挡开$n的进击",
	"force" : 180,
        "dodge" : 5,
	"damage_type" : "瘀伤",
	"lvl" : 0,
	"skill_name" : "三阳开泰"
]),
([	"action" : "紧跟着$N面含微笑，一式「五气呈祥」，双掌云缠雾绕，同时攻向$n全身各处",
	"force" : 220,
        "dodge" : 5,
        "damage_type" : "瘀伤",
	"lvl" : 10,
	"skill_name" : "五气呈祥"
]),
([	"action" : "$N划身错步，一式「逆流捧沙」，双掌内拢外托，攻向$n的$l",
	"force" : 270,
        "dodge" : 5,
        "damage_type" : "劈伤",
	"lvl" : 20,
	"skill_name" : "逆流捧沙"
]),
([	"action" : "紧跟着$N使一式「罡风推云」，双手化掌，一前一后向前猛推，击向$n的$l",
	"force" : 300,
        "dodge" : -5,
        "damage_type" : "瘀伤",
	"lvl" : 30,
	"skill_name" : "罡风推云"
]),
([	"action" : "$N使一式「狂风卷地」，全身飞速旋转，双掌一前一后，猛地拍向$n的胸口",
	"force" : 320,
        "dodge" : 10,
        "damage_type" : "瘀伤",
	"lvl" : 40,
	"skill_name" : "狂风卷地"
]),
([	"action" : "$N一式「雷洞霹雳」，双掌以迅雷不及掩耳之势，劈向你的两额太阳穴",
	"force" : 340,
        "dodge" : -5,
        "damage_type" : "瘀伤",
	"lvl" : 60,
	"skill_name" : "雷洞霹雳"
]),
([	"action" : "$N向上高高跃起，一式「高山流水」，居高临下，掌力笼罩$n的全身",
	"force" : 380,
        "dodge" : 0,
        "damage_type" : "瘀伤",
	"lvl" : 90,
	"skill_name" : "高山流水"
]),
([	"action" : "$N使一式「摘星换斗」，劲气弥漫，双掌如轮，一环环向$n的$l斫去",
	"force" : 400,
        "dodge" : 10,
        "damage_type" : "劈伤",
	"lvl" : 120,
	"skill_name" : "摘星换斗"
]),
([	"action" : "$N一式「梵心降魔」，双掌似让非让，似顶非顶，气浪如急流般使你陷身其中",
	"force" : 460,
        "dodge" : -10,
        "damage_type" : "瘀伤",
	"lvl" : 150,
	"skill_name" : "梵心降魔"
]),
([	"action" : "$N怒叱一声，一式「金顶佛光」，闪步上引，挥掌疾拍你的顶心死穴",
	"force" : 520,
        "dodge" : 10,
        "damage_type" : "瘀伤",
	"lvl" : 180,
	"skill_name" : "金顶佛光"
])
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练金顶绵掌掌必须空手。\n");
	if ((int)me->query_skill("linji-zhuang", 1) < 20)
		return notify_fail("你的临济十二庄火候不够，无法学习金顶绵掌。\n");
	if ((int)me->query("max_neili") < 150)
		return notify_fail("你的内力太弱，无法练般若掌。\n");
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
	level = (int)me->query_skill("jinding-mianzhang", 1);
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("你的精力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练金顶绵掌。\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}
