// jinding-mianzhang.c -金顶绵掌
// create bye cuer
inherit SKILL;
mapping *action = ({
([	"action" : "$N一式「三阳开泰」，单足点地，身形飘动，突然一足踢出，两手左右夹击，攻向$n",
	"force" : 200,
        "dodge" : 5,
	"damage_type" : "瘀伤",
	"lvl" : 0,
	"skill_name" : "三阳开泰"
]),
([	"action" : "$N一式「五气呈祥」，左掌划一半圆，护住胸口，右掌似丝毫不着力对$n连拍五掌",
	"force" : 220,
        "dodge" : 5,
        "damage_type" : "瘀伤",
	"lvl" : 9,
	"skill_name" : "五气呈祥"
]),
([	"action" : "$N左右两掌绵绵不绝的向前推出，一阵阵阴柔掌风袭向$n的前胸，正是一式「罡风推云」",
	"force" : 240,
        "dodge" : 5,
        "damage_type" : "劈伤",
	"lvl" : 19,
	"skill_name" : "罡风推云"
]),
([	"action" : "$N后脚一点，身形前滑，一式「逆流捧沙」，并掌向$n的前胸推去",
	"force" : 260,
        "dodge" : -5,
        "damage": 5,
        "damage_type" : "瘀伤",
	"lvl" : 29,
	"skill_name" : "逆流捧沙"
]),
([	"action" : "$N娇喝一声，使一式「雷洞霹雳」，全身飞速旋转，双掌一前一后，全力拍向$n的胸口",
	"force" : 280,
        "dodge" : 5,
        "damage_type" : "瘀伤",
	"lvl" : 39,
	"skill_name" : "雷洞霹雳"
]),
([	"action" : "$N微一运气，一式「金顶佛光」，跃向空中，双手拍出绵绵掌影，飘向$n",
	"force" : 300,
        "dodge" : 5,
        "damage_type" : "瘀伤",
	"lvl" : 49,
	"skill_name" : "金顶佛光"
]),
([	"action" : "$N一脸肃容，双眼观鼻，两手合什，一招「梵心降魔」，两手翻转向$n慢慢推出",                       
	"force" : 300,
        "dodge" : 5,
        "damage": 5,
        "damage_type" : "瘀伤",
	"lvl" : 69,
	"skill_name" : "梵心降魔"
]),
([	"action" : "$N使一式「法尊八荒」，飘入半空，双掌划着圆圈，漫天掌影笼罩了$n的全身",
	"force" : 400,
        "dodge" : 10,
        "damage": 10,
        "damage_type" : "瘀伤",
	"lvl" : 109,
	"skill_name" : "法尊八荒"
])
});
int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }
int valid_combine(string combo) { return combo=="tiangang-zhi"; }
int valid_learn(object me)
{       
        if (me->query("class")!="bonze" && (int)me->query_skill("jinding-mianzhang",1) >99 )
                return notify_fail("由于你不是佛门中人，心有俗念，不能领悟金顶绵掌的精妙之处。\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练金顶绵掌必须空手。\n");
	if ((int)me->query_skill("linji-zhuang", 1) < 10)
		return notify_fail("你的临济十二庄火候不够，无法学金顶绵掌。\n");
	if ((int)me->query("max_neili") < 20)
		return notify_fail("你的内力太弱，无法练金顶绵掌。\n");
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
	level = (int)me->query_skill("jinding-mianzhang", 1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
	if (me->query("class")!="bonze" && (int)me->query_skill("jinding-mianzhang",1) >99 )
                return notify_fail("由于你不是佛门中人，心有俗念，不能练高深的佛门武功。\n");
        if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练金顶绵掌。\n");
	me->receive_damage("qi", 25);
	me->add("neili", -5);
	return 1;
}
