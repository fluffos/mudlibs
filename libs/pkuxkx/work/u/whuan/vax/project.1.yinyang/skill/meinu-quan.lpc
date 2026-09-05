// meinu-quan -美女拳法
// create bye dingdang
inherit SKILL;
mapping *action = ({
([	"action" : "$N双手合拳向上抬击，一招“麻姑拜寿”，击向$n的头部",
	"force" : 200,
        "dodge" : 5,
	"damage_type" : "瘀伤",
	"lvl" : 0,
	"skill_name" : "麻姑拜寿"
]),
([	"action" : "$N右手挥左，左手送右，作个掷梭织布之状，一招“天孙织锦”，击向$n的前胸",
	"force" : 220,
        "dodge" : 5,
        "damage_type" : "瘀伤",
	"lvl" : 10,
	"skill_name" : "天孙织锦"
]),
([	"action" : "$N举手作提铛斟酒之状，一式“文君当炉”，戳向$n的肩部",
	"force" : 240,
        "dodge" : 5,
        "damage_type" : "劈伤",
	"lvl" : 20,
	"skill_name" : "文君当炉"
]),
([	"action" : "$N腰一弯，手一长，一招“貂婵拜月”，斩向$n的颈部",
	"force" : 260,
        "dodge" : -5,
        "damage_type" : "瘀伤",
	"lvl" : 30,
	"skill_name" : "貂婵拜月"
]),
([	"action" : "$N一招“西施捧心”，左拳打出，击向$n的前胸",
	"force" : 280,
        "dodge" : 10,
        "damage_type" : "瘀伤",
	"lvl" : 40,
	"skill_name" : "西施捧心"
]),
([	"action" : "$N左手斜举，右手五指弹起，作个弹琵琶的姿势，五指弹向$n的腰部，正是一式“昭君出塞”",
	"force" : 300,
        "dodge" : 5,
        "damage_type" : "瘀伤",
	"lvl" : 50,
	"skill_name" : "昭君出塞"
]),
([	"action" : "$N身子微晃，跌跌撞撞，一式“贵妃醉酒”，向右斜过去，肩头撞向$n",                       
	"force" : 320,
        "dodge" : 20,
        "damage_type" : "瘀伤",
	"lvl" : 60,
	"skill_name" : "贵妃醉酒"
]),
([	"action" : "$N身子前扑，一招“则天垂帘”，双掌以垂帘式斜削将下来，削向$n",
	"force" : 350,
        "dodge" : 10,
        "damage_type" : "瘀伤",
	"lvl" : 70,
	"skill_name" : "则天垂帘"
]),
([	"action" : "$N悄退数步，一招“古墓幽居”，右手支颐，长叹一声，脸现寂寥之意，左手轻轻挥向$n",
	"force" :400,
	"dodge" :20,
	"damage_type" : "瘀伤",
	"lvl" :100,
	"skill_name" : "古墓幽居"
])
});
int valid_enable(string usage) { return usage=="cuff" ||  usage=="parry"; }
//int valid_combine(string combo) { return combo=="qianmie-shou"; }
int valid_learn(object me)
{       
       	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练美女拳法必须空手。\n");
	if(me->query("gender")!="女性"&&(int)me->query_skill("meinu-quan",1)>100)
                return notify_fail("你不是女性，对「美女拳法」柔和的拳法不能好好地掌握。\n");
	if ((int)me->query_skill("changhen-xinfa", 1) < 10)
		return notify_fail("你的长恨心法火候不够，无法学美女拳法。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练美女拳法。\n");
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
	level = (int)me->query_skill("meinu-quan", 1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{	if(me->query("gender")!="女性"&&(int)me->query_skill("meinu-quan",1)>100)
                return notify_fail("你不是女性，对「美女拳法」柔和的拳法不能好好地掌握。\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练美女拳法。\n");
	me->receive_damage("qi", 25);
	me->add("neili", -5);
	return 1;
}

string query_yinyang()
{
	return "太阴";
}