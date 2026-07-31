// Cracked by chenzzz
// poshui-zhangfa
// 降魔杖法。

inherit SKILL;

mapping *action = ({
([      "action": "$N口中长啸一声，一招「报应不爽」手中$w长驱直入，迳刺$n$l",
	"force"  : 20,
	"attack" : 8,
	"dodge"  : 10,
	"parry"  : 15,
	"damage" : 9,
	"skill_name" : "报应不爽",
	"damage_type": "挫伤"
]),
([      "action": "$N手中$w一荡，使出「大限将至」，但见一道杖影隐隐约约，若有若无地向$n压下",
	"force"  : 30,
	"attack" : 10,
	"dodge"  : 15,
	"parry"  : 15,
	"damage" : 10,
	"skill_name" : "大限将至",
	"damage_type": "挫伤"
]),
([      "action": "只见$N手中$w疾横，斗地点出！这招「无法无天」轻灵飘逸，\n$n眼见杖风袭来，竟不知如何是好",
	"force"  : 50,
	"attack" : 14,
	"dodge"  : 10,
	"parry"  : 20,
	"damage" : 13,
		"skill_name" : "无法无天",
	"damage_type": "挫伤"
]),
([      "action": "$N大喝一声，手中$w向$n兜头击落，兵器未至，已将$n各处退路封死，好一招「在劫难逃」",
	"attack" : 21,
	"force"  : 70,
	"dodge"  : 15,
	"parry"  : 20,
	"damage" : 19,
	"skill_name" : "在劫难逃",
	"damage_type": "挫伤"
]),
([      "action": "$N倒提$w，轻轻一纵，一招「天网恢恢」从$n意想不到的地方刺出，$n顿时手足无措，狼狈万分",
	"force"  : 90,
	"attack" : 26,
	"dodge"  : 5,
	"parry"  : 20,
	"damage" : 21,
	"skill_name" : "天网恢恢",
	"damage_type": "挫伤"
]),
([      "action": "$N脸上突现煞气，举起手中$w，猛向$n$l击落，这招「再堕轮回」出手又快又狠",
	"force"  : 110,
	"attack" : 31,
	"dodge"  : 20,
	"parry"  : 20,
	"damage" : 21,
	"skill_name" : "再堕轮回",
	"damage_type": "挫伤"
]),
});

int valid_enable(string usage) { return usage=="staff" ||  usage=="parry"; }

int valid_learn(object me)
{
		object ob;

	if ((int)me->query("max_neili") < 2500)
		return notify_fail("你的内力不够。\n");

	if ((int)me->query_skill("force") < 200)
		return notify_fail("你的内功火候太浅。\n");

	if ((int)me->query_skill("staff", 1) < 120)
		return notify_fail("你的基本杖法火候太浅。\n");

	if( !(ob = me->query_temp("weapon")) || 
			(string)ob->query("skill_type") != "staff" )
		return notify_fail("你必须先找一根钢杖才能学降魔杖法。\n");

	if ((int)me->query_skill("staff", 1) < (int)me->query_skill("xiangmo-zhangfa", 1))
		return notify_fail("你的基本杖法水平有限，无法领会更高深的降魔杖法。\n");

	return 1;
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "staff")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query("qi") < 70)
		return notify_fail("你的体力不够练的降魔杖法。\n");

	if ((int)me->query("neili") < 80)
		return notify_fail("你的内力不够练降魔杖法。\n");

	me->receive_damage("qi", 60);
	me->add("neili", -70);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"xiangmo-zhangfa/" + action;
}

