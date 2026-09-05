// fengyun-shou.c -风云手

// 2003/3/17 notme add perform
inherit SKILL;

mapping *action = ({
([	"action" : "$N一式「风满长空」，以掌化爪，五指如钩，直逼$n的膻中要穴",
	"force" : 120,
        "dodge" : 20,
	"damage": 15,
        "lvl" : 0,
        "skill_name" : "风满长空",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N左手虚晃，一式「烈火腾云」，右手上下直击，反扣$n的肩井大穴",
	"force" : 130,
        "dodge" : 40,
	"damage": 20,
        "lvl" : 9,
        "skill_name" : "烈火腾云",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N使一式「草深雾泽」，掌指齐出，拍拿并施，拿向$n的三路要害",
	"force" : 150,
        "dodge" : 50,
	"damage": 20,
        "lvl" : 19,
        "skill_name" : "草深雾泽",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N左手鹰抓，右手蛇举，一式「天目昭辉」疾扣$n的中节大脉",
	"force" : 180,
        "dodge" : 40,
	"damage": 10,
        "lvl" : 29,
        "skill_name" : "天目昭辉",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N使一式「雷震四方」，四面八方出现无数掌影，一爪突出，抓向$n的胸口",
	"force" : 220,
        "dodge" : 45,
	"damage": 25,
        "lvl" : 49,
        "skill_name" : "雷震四方",
        "damage_type" : "内伤"
]),
([	"action" : "$N两手环扣，全身关节啪啪作响，一式「水到渠成」，击向$n的$l",
	"force" : 270,
        "dodge" : 40,
	"damage": 10,
        "lvl" : 59,
        "skill_name" : "水到渠成",
        "damage_type" : "内伤"
]),
([	"action" : "$N一式「山高林密」，十指齐伸，遮天蔽日般地笼罩$n的全身要穴",
	"force" : 330,
        "dodge" : 45,
	"damage": 15,
        "lvl" : 79,
        "skill_name" : "山高林密",
        "damage_type" : "内伤"
]),
([	"action" : "$N岳立霆峙，一式「地老天荒」，在一阵暴雷声中，双手同时拍中$n的七道死穴",
	"force" : 400,
        "dodge" : 40,
	"damage": 20,
        "lvl" : 99,
        "skill_name" : "地老天荒",
        "damage_type" : "内伤"
])
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }

int valid_combine(string combo) { return combo=="yingzhua-gong"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练风云手必须空手。\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
		return notify_fail("你的混元一气功火候不够，无法学风云手。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练风云手。\n");
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
	level   = (int) me->query_skill("fengyun-shou",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练风云手。\n");
	me->receive_damage("qi", 25);
	me->add("neili", -5);
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
return __DIR__"fengyun-shou/" + action;
 }

string query_yinyang()
{
	return "少阳";
}