// pudu-zhang.c 普渡杖法

inherit SKILL;

mapping *action = ({
([
	"action":"$N使一招「黄牛转角」，手中$w自下而上，沉猛无比地向$n的小腹挑去。",
	"lvl" : 0,
	"skill_name" : "黄牛转角",
	"damage_type":"挫伤"
]),
([
	"action":"$N快步跨出，一招「野马追风」，左手平托$w，右掌猛推杖端，顶向$n的胸口。",
	"lvl" : 9,
	"skill_name" : "野马追风",
	"damage_type":"挫伤"
]),
([
	"action":"$N高举$w，一招「猛虎跳涧」，全身跃起，手中$w搂头盖顶地向$n击去。",
	"lvl" : 18,
	"skill_name" : "猛虎跳涧",
	"damage_type":"挫伤"
]),
([
	"action":"$N一招「狮子摇头」，双手持杖如橹，对准$n猛地一搅，如同平地刮起一阵旋风。",
	"lvl" : 27,
	"skill_name" : "狮子摇头",
	"damage_type":"挫伤"
]),
([
	"action":"$N横持$w，一招「苍龙摆尾」，杖端化出无数个圆圈，凝滞沉重，把$n缠在其中。",
	"lvl" : 36,
	"skill_name" : "苍龙摆尾",
	"damage_type":"挫伤"
]),
([
	"action":"$N全身滚倒，$w盘地横飞，突出一招「大蟒翻身」，杖影把$n裹了起来",
	"lvl" : 45,
	"skill_name" : "大蟒翻身",
	"damage_type":"挫伤"
]),
([
	"action":"$N双手和十，躬身一招「胡僧托钵」，$w自肘弯飞出，拦腰向$n撞去。",
	"lvl" : 53,
	"skill_name" : "胡僧托钵",
	"damage_type":"挫伤"
]),
([
	"action":"$N一招「慈航普渡」，$w如飞龙般自掌中跃出，直向$n的胸口穿入。",
	"lvl" : 60,
	"skill_name" : "慈航普渡",
	"damage_type":"挫伤"
]),
});

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("yijin-jing", 1) < 20)
		return notify_fail("你的易筋经内功火候太浅。\n");
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
        int i, level, j;
	level   = (int) me->query_skill("pudu-zhang",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action": action[j]["action"],
				"damage_type": action[j]["damage_type"],
				"lvl": action[j]["lvl"],
				"force": 100 + random(250),
				"dodge": random(20)-10,
				"damage": 40 + random(60),
				"parry": random(10),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("pudu-zhang", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 30 || me->query("neili") < 10)
		return notify_fail("你的体力不够练普渡杖法。\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}
