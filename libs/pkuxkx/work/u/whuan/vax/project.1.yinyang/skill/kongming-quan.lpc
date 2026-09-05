// xiaoyao-quan.c
//made by hacky
inherit SKILL;

mapping *action = ({
([	"action" : "$N盘膝而坐，二手合十，一式「童子拜观音」，双拳蓄势而发，击向$n的$l",
	"force" : 170,
        "dodge" : -5,
	"lvl" : 10,
        "damage" : 50,
	"skill_name" : "童子拜观音",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N左脚塌实,一式「浮云去来」，两手扣环，拢成圈状,猛攻向$n的$1",
	"force" : 200,
        "dodge" : 5,
	"damage": 45,
	"lvl" : 10,
	"skill_name" : "浮云去来",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N腾空飞起，一式「漫天飞雪」，双手双腿齐出，令$n无可躲藏",
	"force" : 230,
        "dodge" : 15,
	"damage": 70,
	"lvl" : 20,
	"skill_name" : "漫天飞雪",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N纵身飘开数丈,右手蓄势,一着[清风问莲],攻向$n的$1",
	"force" : 270,
        "dodge" : 5,
	"damage": 60,
	"lvl" : 30,
	"skill_name" : "清风问莲",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N一臂前伸，一臂后指，一式「露草拂霜」，攻向$n的身前身后",
	"force" : 320,
        "dodge" : 10,
	"damage": 65,
	"lvl" : 40,
	"skill_name" : "露草拂霜",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N回身拧腰,一式「碧海连天」，右手自上而下划出一个大圆,向$n的$1攻去",
	"force" : 380,
        "dodge" : 25,
	"damage": 90,
	"lvl" : 48,
	"skill_name" : "碧海连天",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N左手虚晃，步履飘飘，一式「江上飞花」，不经意间向$n的$1掠去.",
	"force" : 450,
        "dodge" : 15,
	"damage": 95,
	"lvl" : 54,
	"skill_name" : "江上飞花",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N虚步提腰，双拳无形无定，一式「落花拈叶」，骤然击向$n的前胸",
	"force" : 530,
        "dodge" : 20,
	"damage": 100,
	"lvl" : 60,
	"skill_name" : "落花拈叶",
        "damage_type" : "瘀伤"
])
});

int valid_enable(string usage) { return  usage=="cuff" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练空明拳法必须空手。\n");
	if ((int)me->query_skill("xiantian-gong", 1) < 10)
		return notify_fail("你的先天功火候不够，无法学空明拳法。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练空明拳法。\n");
        if ((int)me->query_skill("xiantian-gong", 1) < (int)me->query_skill("kongming-quan", 1) - 10 && (int)me->query_skill("xiantian-gong", 1) < 180)
		return notify_fail("你的先天功火候不够，无法掌握空明拳法的奥秘。\n");
        if ((int)me->query_skill("yangxin-quan", 1) < 40 )
                return notify_fail("你的养心拳等级不够,无法领会空明拳. \n");
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
	level   = (int) me->query_skill("kongming-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练空明拳法。\n");
        if ((int)me->query_skill("xiantian-gong", 1) < (int)me->query_skill("kongming-quan", 1) - 10 && (int)me->query_skill("xiantian-gong", 1) < 180)
		return notify_fail("你的先天功火候不够，无法掌握空明拳法的奥秘。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
        return __DIR__"kongming-quan/" + action;
}

string *parry_msg = ({
        "$n一抖$v，手中的$v化作一条长虹，磕开了$N的$w。\n",
        "$n挥舞$v，手中的$v化做漫天雪影，荡开了$N的$w。\n",
        "$n手中的$v一抖，向$N的手腕削去。\n",
        "$n将手中的$v舞得密不透风，封住了$N的攻势。\n",
        "$n反手挥出$v，整个人消失在一团光芒之中。\n",
});

string *unarmed_parry_msg = ({
        "$n猛击$N的面门，逼得$N中途撤回$w。\n",
        "$n以守为攻，猛击$N的手腕。\n",
        "$n左手轻轻一托$N$w，引偏了$N$w。\n",
        "$n脚走阴阳，攻$N之必救。\n",
        "$n左拳击下，右拳自保，将$N封于尺外。\n",
        "$n双拳齐出，$N的功势入泥牛入海，消失得无影无踪。\n",
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
	return "太阳";
}