// tianshan-zhang.c, based on dagou-bang.c
// by yucao

inherit SKILL;

mapping *action = ({
([	"action": "$N使出一招「冰河开冻」，手中$w大开大阖扫向$n的$l",
	"dodge": -3,
	"force": 200,
	"damage": 100,
	"damage_type": "挫伤"
]),
([	"action": "$N手中$w阵阵风响，一招「山风凛冽」向$n的$l攻去",
	"dodge": -5,
	"force": 220,
	"damage": 145,
	"damage_type": "挫伤"
]),
([	"action": "$N举起$w，居高临下使一招「天山雪崩」砸向$n的$l",
	"dodge": 2,
	"force": 250,
	"damage": 180,
	"damage_type": "挫伤"
]),
([	"action": "$N一招「峰回路转」，$w左右迂回向$n的$l点去",
	"dodge": 5,
	"force": 330,
	"damage": 250,
	"damage_type": "挫伤"
]),
});

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 80)
		return notify_fail("你的内力不够。\n");
	return 1;
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练天山杖法。\n");
	me->receive_damage("qi", 25);
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
        return __DIR__"tianshan-zhang/" + action;
}

string query_yinyang()
{
	return "太阴";
}