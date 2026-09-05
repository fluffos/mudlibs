// riyue-jian 日月剑法

inherit SKILL;
mapping *action = ({
([	"action" : "$N一招「常娥笨月」，手中$w轻轻颤动，一剑剑连绵不绝地点向$n",
	"force" : 180,
	"dodge" : 20,
	"damage" : 30,
        "lvl" : 1,
	"skill_name" : "常娥笨月",
	"damage_type" : "刺伤"
]),
([	"action" : "$N突然向前一冲，右手$w使出一式「夸父逐日」,迅捷无比的刺向$n",
	"force" : 100,
	"dodge" : 15,
	"damage" : 40,
        "lvl" : 1,
	"skill_name" : "夸父逐日",
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「花前月下」，手中$w轻颤，化出重重剑影，平平地向$n刺去",
	"force" : 120,
	"dodge" : 15,
	"damage" : 50,
        "lvl" : 9,
	"skill_name" : "花前月下",
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「花好月圆」，手中$w化出的重重剑影合而为一，一气呵成地攻向$n",
	"force" : 130,
	"dodge" : 10,
	"damage" : 60,
        "lvl" : 29,
	"skill_name" : "花好月圆",
	"damage_type" : "刺伤"
]),
([	"action" : "$N使出「赤日炎炎」，$w划出无数的光圈，片片剑光撒向$n",
	"force" : 140,
	"dodge" : 5,
	"damage" : 70,
        "lvl" : 39,
	"skill_name" : "赤日炎炎",
	"damage_type" : "割伤"
]),
([	"action" : "$N左脚踏实，右脚虚点，一招「日新月异」，右手$w一挽剑花，左掌画了个圆弧，一齐逼向$n",
	"force" : 150,
	"dodge" : 5,
	"damage" : 80,
        "lvl" : 59,
	"skill_name" : "日新月异",
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「旭日东升」，手中$w一沉，紧接着突然上撩，刺向$n",
	"force" : 200,
	"dodge" : -5,
	"damage" : 90,
        "lvl" : 79,
	"skill_name" : "旭日东升",
	"damage_type" : "刺伤"
]),
([	"action" : "$N右脚微一点地，跃入半空，一招「浩劫残阳」，俯冲而下，剑尖直指$n",
	"force" : 200,
	"dodge" : -5,
	"damage" : 100,
        "lvl" : 99,
	"skill_name" : "浩劫残阳",
	"damage_type" : "刺伤"
])
});
int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }
int valid_combine(string combo) {return combo=="riyue-dao";}
int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("riyue-shengong", 1) < 20)
		return notify_fail("你的日月神功火候太浅。\n");
	return 1;
}
mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("riyue-jian",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
	object weapon;
	if ((string)me->query("family/family_name") != "日月神教")
		return notify_fail("你不是日月神教弟子，不能练日月剑法。\n");
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练日月剑法。\n");
	me->receive_damage("qi", 30);
	return 1;
}
string perform_action_file(string action)
{
	return __DIR__"riyue-jian/" + action;
}
