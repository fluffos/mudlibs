// wuluo-zhang.c 五罗轻烟掌

inherit SKILL;

mapping *action = ({
([  "action" : "$N屏息静气，手起一掌「轻烟袅袅」，轻轻柔柔地拍向$n",
    "force"  : 130,
    "dodge"  : 20,
	"damage" : 0,
    "lvl"    : 0,
	"skill_name" : "轻烟袅袅",
	"damage_type" : "瘀伤"
]),
([  "action" : "$N轻轻浅笑，绕到$n身后，左手做势温柔轻拥$n腰间。$n蹙
眉急躲，$N右手一招「烟雾缭绕」，无声无息向$n的$l拍到",
    "force"  : 150,
    "dodge"  : 20,
	"damage" : 30,
    "lvl"    : 20,
	"skill_name" : "烟雾缭绕",
	"damage_type" : "内伤"
]),
([  "action" : "$N一招「烟海云涛」，双掌幻化出一片掌影，如一阵轻烟，
将$n细细密密地笼罩于内",
    "force"  : 150,
    "dodge"  : 30,
	"damage" : 45,
    "lvl"    : 40,
	"skill_name" : "烟海云涛",
	"damage_type" : "瘀伤"
]),

([  "action" : "$N返身越出圈外，回首一招「云烟渺渺」，远远地向$n的$l
轻轻拍出两掌，掌风刮到，陡然变盛直让$n呼不出气来",
    "force"  : 200,
    "dodge"  : 25,
	"damage" : 55,
    "lvl"    : 60,
	"skill_name" : "云烟渺渺",
    "damage_type" : "瘀伤"
]),
([  "action" : "$N左掌从右掌内围翻出，轻飘飘地向$n拍去，看到$n起手招
架，右掌却自胸口疾速圈出，一招「烟雾弥漫」，赶超左掌，拍向$n的$l",
    "force"  : 250,
    "dodge"  : 70,
	"damage" : 10,
    "lvl"    : 80,
	"skill_name" : "烟雾弥漫",
    "damage_type" : "瘀伤"
]),
([  "action" : "$N双掌齐推，振起一阵劲风，一招「烟消云散」在一丈开外
击向$n",
    "force"  : 300,
    "dodge"  : 20,
	"damage" : 90,
    "lvl"    : 100,
	"skill_name" : "烟消云散",
    "damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_combine(string combo) { return combo=="jinyu-quan"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练五罗轻烟掌必须空手。\n");
	if ((int)me->query_skill("kurong-changong",1) < 20)
		return notify_fail("你的枯荣禅功太弱，无法练五罗轻烟掌。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练五罗轻烟掌。\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
    level = (int) me->query_skill("wuluo-zhang",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练五罗轻烟掌。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}


