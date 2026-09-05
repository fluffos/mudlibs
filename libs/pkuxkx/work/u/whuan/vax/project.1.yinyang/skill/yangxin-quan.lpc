// nutrifux.c

inherit SKILL;

mapping *action = ({
	([	"action":		"$N使出一招「上叠手」，右掌一翻，左掌虚进击向$n的$l",
		"dodge":		-10,
		"parry":		-10,
		"force":		200,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N使出一招「下叠手」，左掌一晃，右掌上翻顺势击向$n的$l",
		"dodge":		-10,
		"parry":		-10,
		"force":		170,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N使出「拊腕穿肘」，踏上两步$n身前，一个肘□撞向$n的$l",
		"dodge":		-30,
		"parry":		20,
		"force":		150,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N上半身一仰一挺，使出「仰平退」，双掌平推击向$n$l",
		"dodge":		-50,
		"parry":		30,
		"force":		200,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N左掌护住身前，一个打跌右掌一招「斜钩进步」拍向$n$l",
		"dodge":		-20,
		"parry":		-10,
		"force":		210,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N双掌绕了几个圈转，使出「中堂匝」，掌影飘飘拍向$n$l",
		"dodge":		-30,
		"parry":		-10,
		"force":		220,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N「嘿」地一声，单腿跨回，一招「平虚吊步」双掌齐出直攻$n$l",
		"parry":		-40,
		"force":		200,
		"damage_type":	"瘀伤"
	]),
});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练养心拳必须空手。\n");
         if( (int)me->query("shaqi") > 50 )
		return notify_fail("你的杀气太重，无法练养心拳。\n");
	return 1;
}

int valid_enable(string usage) { return usage=="cuff"; }

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 30 )
		return notify_fail("你的体力不够了，休息一下再练吧。\n");
        if( (int)me->query("neili") < 5 )
		return notify_fail("你的内力不够了，休息一下再练吧。\n");
        me->receive_damage("qi", 30);
        me->add("neili", -5);
	return 1;
}

string query_yinyang()
{
	return "太阳";
}