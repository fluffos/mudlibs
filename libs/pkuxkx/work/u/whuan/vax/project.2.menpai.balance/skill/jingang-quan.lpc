// jingang-quan.c -大金刚拳

inherit SKILL;

mapping *action = ({
([	"action" : "$N盘膝而坐，二手合十，一式「莲花座」，双拳蓄势而发，击向$n的$l",
	"force" : 180,
        "dodge" : -5,
	"lvl" : 0,
	"skill_name" : "莲花座",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一式「烈火锥」，双掌轮流下击，拳势如焰，吡啪爆响",
	"force" : 200,
        "dodge" : 5,
	"damage": 0,
	"lvl" : 9,
	"skill_name" : "烈火锥",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N腾空飞起，一式「八方雨」，双手双腿齐出，令$n无可躲藏",
	"force" : 200,
        "dodge" : 10,
	"damage": 5,
	"lvl" : 19,
	"skill_name" : "八方雨",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N双掌虚含，掌缘下沉，一式「掌心雷」，缓缓向$n推出",
	"force" : 250,
        "dodge" : 5,
	"damage": 10,
	"lvl" : 39,
	"skill_name" : "掌心雷",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N一臂前伸，一臂后指，一式「五指山」，攻向$n的身前身后",
	"force" : 280,
        "dodge" : 5,
	"damage": 5,
	"lvl" : 49,
	"skill_name" : "五指山",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N一式「观音渡」，两手十指虚点$n的全身三十六道要穴",
	"force" : 300,
        "dodge" : 10,
	"damage": 10,
	"lvl" : 59,
	"skill_name" : "观音渡",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N两目内视，双手内笼，一式「天龙唱」，四面八方响起震人心魄的龙吟",
	"force" : 350,
        "dodge" : 5,
	"damage": 15,
	"lvl" : 79,
	"skill_name" : "天龙唱",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N似笑非笑，双拳无形无定，一式「如来笑」，骤然击向$n的前胸",
	"force" : 400,
        "dodge" : 10,
	"damage": 10,
	"lvl" : 109,
	"skill_name" : "如来笑",
        "damage_type" : "瘀伤"
])
});

int valid_enable(string usage) { return  usage=="cuff" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练大金刚拳必须空手。\n");
	if ((int)me->query_skill("tongzi-gong", 1) < 10)
		return notify_fail("你的混元一气功火候不够，无法学大金刚拳。\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力太弱，无法练大金刚拳。\n");
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
	level   = (int) me->query_skill("jingang-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练大金刚拳。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"jingang-quan/" + action;
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

string query_yinyang()
{
	return "纯阳";
}