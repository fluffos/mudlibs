inherit SKILL;

mapping *action = ({
([	"action" : "$N双手在胸前翻掌，由腹部向前向上推出，一招「通天炮」，一股劲风直逼&n",
	"force" : 100,
	"dodge" : 50,
	"skill_name" : "通天炮",
	"lvl" : 0,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N使一招「推山掌」，右手收置肋下，左手向外挥出，劈向$n的$l",
	"force" : 120,
	"dodge" : 48,
	"skill_name" : "推山掌",
	"lvl" : 8,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N由臂带手，在面前缓缓划过，使一招「旗门手」，挥向$n的$l",
	"force" : 140,
	"dodge" : 46,
	"skill_name" : "旗门手",
	"lvl" : 16,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N双手划弧，右手向上，左手向下，使一招「白鹤亮翅」，分击$n的面门和$l",
	"force" : 160,
	"dodge" : 44,
	"skill_name" : "白鹤亮翅",
	"lvl" : 24,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N一招「柔桥外膀」，左脚一个弓箭步，右手上举向外撇出，向$n的$l挥去",
	"force" : 180,
	"dodge" : 32,
	"skill_name" : "柔桥外膀",
	"lvl" : 32,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N左脚踏一个虚步，左手前推，右手后收,一招「开弓射雕」，向$n的$l锤去",
	"force" : 200,
	"dodge" : 40,
	"skill_name" : "开弓射雕",
	"lvl" : 40,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N左手变掌横于胸前，右拳由肘下穿出，一招「分金钟」，锤向$n的$l",
	"force" : 220,
	"dodge" : 8,
	"skill_name" : "分金钟",
	"lvl" : 48,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N左脚前踏半步，一招「双插莲花」，两手同时由下向$n的$l戳去",
	"force" : 240,
	"dodge" : 30,
	"skill_name" : "双插莲花",
	"lvl" : 56,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N招「霸王肘」，左脚一个弓箭步，右手上举向外撇出，向$n的$l挥去",
	"force" : 260,
	"dodge" : 35,
	"skill_name" : "霸王肘",
	"lvl" : 64,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N右手使一式招「一串钱」，扑身向$n的$l插去",
	"force" : 280,
	"dodge" : 40,
	"skill_name" : "一串钱",
	"lvl" : 70,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N左手虚按，右手使一招「掬心拳」，向$n的$l插去",
	"force" : 300,
	"dodge" : 45,
	"skill_name" : "掬心拳",
	"lvl" : 78,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N俯身向前，双手交叉成十字拳，一招「长离十旋斩」，向$n的$l锤去",
	"force" : 320,
	"dodge" : 50,
	"skill_name" : "长离十旋斩",
	"lvl" : 86,
        "damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练铁线拳必须空手。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练铁线拳。\n");
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
    level   = (int) me->query_skill("tiexian-quan",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 5, level/5)];

}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
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
	return __DIR__"tiexian-quan/" + action;
}