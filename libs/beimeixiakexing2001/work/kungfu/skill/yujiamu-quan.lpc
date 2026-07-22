//Cracked by Roath
// yujia-muquan 金刚瑜珈母拳
// qfy, chage, paoshou Sept 26, 1996
// Ryu, 11/14/96.

inherit SKILL;

mapping *action = ({
([      "action" : "$N单拳「灌顶」，迳直向$n的天灵盖劈下",
        "force" : 140,
        "dodge" : 5,
        "lvl" : 0,
        "skill_name" : "灌顶",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N双手摆「解苦」式，握拳侧置于身，眼望右上方，忽的跃起口中暴喝，一拳捣向$n的$l",
	"force" : 170,
        "dodge" : 5,
	"lvl" : 8,
	"skill_name" : "解苦",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N收脸「颦眉」，左手虚掩，右拳穿出，拳势如焰吡啪爆响地击往$n$l",
	"force" : 200,
        "dodge" : 5,
	"damage": 10,
	"lvl" : 16,
	"skill_name" : "颦眉",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N吟无主咒，一式「嗔恚」，收拳出拐，磕向$n的$l",
        "force" : 240,
        "dodge" : 15,
        "damage": 10,
        "lvl" : 24,
        "skill_name" : "嗔恚",
        "damage_type" : "内伤"
]),
([	"action" : "$N作「静寂」式，低伏在地，猛然翻身跳起，双手双脚齐出，将$n笼罩在拳风下",
	"force" : 280,
        "dodge" : 15,
	"damage": 10,
	"lvl" : 32,
	"skill_name" : "静寂",
        "damage_type" : "内伤"
]),
([      "action" : "$N左臂微抬，心念「妙音」，握拳如钩，击向$n的$l",
        "force" : 320,
        "dodge" : 15,
        "damage": 10,
        "lvl" : 40,
        "skill_name" : "妙音",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N脚踏空行步，使出一招「明心」，绕到$n身侧，双拳张开，插向$n的$l",
        "force" : 320,
        "dodge" : 15,
        "damage": 10,
        "lvl" : 48,
        "skill_name" : "明心",
        "damage_type" : "内伤"
]),
([	"action" : "$N双拳置于身后，微笑中后退两步，趁$n迟疑间豁然冲上，一招「制胜」双拳贯向$n两耳",
	"force" : 360,
        "dodge" : 5,
	"damage": 20,
	"lvl" : 56,
	"skill_name" : "制胜",
        "damage_type" : "瘀伤"
])
});

int valid_enable(string usage) { return  usage=="cuff" || usage=="parry"; }

int valid_combine(string combo) { return combo=="dashou-yin"; } 

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练金刚瑜珈母拳法必须空手。\n");
	if ((int)me->query_skill("longxiang-banruo", 1) < 10
	&& (int)me->query_skill("xiaowuxiang", 1) < 10){
		return notify_fail("你的内功修为火候不够，无法学金刚瑜珈母拳法。\n");
	}
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练金刚瑜珈母拳法。\n");
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
	level   = (int) me->query_skill("yujiamu-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("你的精力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练金刚瑜珈母拳法。\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"yujia-muquan/" + action;
}
