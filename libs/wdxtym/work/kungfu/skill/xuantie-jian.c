inherit SKILL;

string  *msg = ({
"$N当胸平平刺出一剑，看似毫无变化，却有轰轰之声，$n只觉一股大力由$w剑身直逼周身",
"$N凌空跃起，身随$w起，借助下行之势向下猛劈一剑，将$n周身笼于剑气之下",
"$N轻叹一声，随手横劈一剑，缓缓指向$n，当真平淡中蕴涵所有变化，无招胜有招",
"$N迅疾挑出一剑，此剑之快，匪夷所思，$n惊恐之际一染、已然无法分辨剑路来去",
"$N提$w顺刺，逆击，横削，倒劈，无不是剑法的入门，当真返朴归真，已不存任何破绽",
"$N仰首长啸，令风云变幻，旋及$w剑气弥漫于$n周身各处，$n但觉身处惊涛骇浪之中", 
"$N祭起手中$w，左手捏成剑诀，咄喝一声，空中满是剑影，宛若千道银链，在$n身边游动",
"$N连出十余剑，一时迅疾如流星划空，一时凝重迟缓，招招无迹可寻，平淡至极又匪思至极", 
"$N手中$w剑势如虹，无可当锋，$n惊怖中更觉剑力有如海潮一般，一波一浪阵阵涌来，绵延不绝",
"$N手中$w向前挑出，看似无甚劲力，启知剑势将老，内力却如海潮一般汹涌，向$n袭去",
"$N远远挥出一剑，$n不料气劲如此之强，防范一疏，一股大力劈头而来",
"$N深吸一口气，手中$w挟带风声，平平淡淡的挥向$n。风声越来越响，竟如同暴风之中一般",
"$N一凝神，$w居然发出淡淡的一层暗青色光芒，如狂风怒潮一边，向$n卷去",
});

string  *super_msg = ({
"$N随手挥出一剑，去势极缓却隐隐含着“隆隆”的风雷之声，已经达到剑道的至高境界",
"$N手中$w交左手，右手凌空指向$n，$p忽觉凌厉剑气迎面而来，原来$N已入无剑胜有剑的境界",
"$N抬手一剑，急如飞虹闪电却无丝毫声息，寂静以极，已窥剑法之巅",
"$N一剑刺到，泛起淡淡海蓝，无声无息，内力却是极强",
"$N每出一剑都和周围事物相应合，招式毫无征兆随意而创，剑之所达意之所向",
"$N心中竟无半点波澜，纯以意运剑，长剑每挥一剑，便涌出一股气劲，好似要去吞没对手",
"$N突然之间招数全无，只是极平常的一刺，却已经意在剑前。招式越是平平威力却是越大",
"$N剑气如风，含劲而无式，举手投足之间内劲浑厚，剑法已然反璞归真而无招自胜",
});


mapping *action = ({
([      "action": "$N手中的$w荡出，就如大江东去，势不可挡",
	"force" : 250,
	"attack": 70,
	"dodge" : 30,
	"damage": 13,
	"parry" : 70,
	"lvl"   : 0,
	"damage_type": "割伤"
]),
([      "action": "$N踏上一步，手中$w舞出一道剑光劈向$n的$l",
	"force" : 310,
	"attack": 80,
	"dodge" : 33,
	"parry" : 79,
	"damage": 24,
	"lvl"   : 40,
	"damage_type": "割伤"
]),
([      "action": "$N手中$w一抖，一剑刺出，攻向$n的$l，没有半点花巧",
	"force" : 330,
	"attack": 90,
	"dodge" : 41,
	"parry" : 85,
	"damage": 35,
	"lvl"   : 80,
	"damage_type": "割伤"
]),
([      "action": "$N手中$w微微颤动，忽然刺出，一道剑光射向$n的$l",
	"force" : 360,
	"attack": 95,
	"dodge" : 45,
	"parry" : 92,
	"damage": 39,
	"lvl"   : 120,
	"damage_type": "刺伤"
]),
([      "action": "$N横过$w，蓦然横扫$n，气势如宏",
	"force" : 380,
	"attack": 97,
	"dodge" : 47,
	"parry" : 99,
	"damage": 48,
	"lvl"   : 160,
	"damage_type": "割伤"
]),
([      "action": "$N手中的$w连削带刺，夹带着一阵旋风掠过$n全身",
	"force" : 400,
	"attack": 100,
	"dodge" : 50,
	"parry" : 100,
	"damage": 50,
	"lvl"   : 200,
	"damage_type": "刺伤"
])
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query_skill("force") < 200)
		return notify_fail("你的内功火候不到，无法学习玄铁剑法。\n");

	if (me->query("max_neili") < 2000)
		return notify_fail("你的内力太差，无法学习玄铁剑法。\n");

	if (me->query_str() < 45)
		return notify_fail("你现在膂力太差，无法学习玄铁剑法。\n");

	if (me->query_skill("force", 1) < me->query_skill("xuantie-jian", 1))
		return notify_fail("你的内功底子还不够，无法领会更高深的玄铁剑法。\n");

	if (me->query_skill("sword", 1) < me->query_skill("xuantie-jian", 1))
		return notify_fail("你的基本剑法水平有限，无法领会更高深的玄铁剑法。\n");

	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int) me->query_skill("xuantie-jian", 1);


	if( level > 250 )
		return ([
			"action": HIC+replace_string(replace_string(msg[random(sizeof(msg))], "$w", "$w"), "$w", "$w"HIC)+NOR,
			"dodge": random(100),
			"parry": random(100),
			"force": 350 + random(250),
			"damage": 200 + random(130),
			"damage_type": "割伤",
		]);


	for (i = sizeof(action); i > 0; i--)
		if (level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) || 
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query("qi") < 80)
		return notify_fail("你的体力不够练玄铁剑法。\n");

	if ((int)me->query("neili") < 80)
		return notify_fail("你的内力不够练玄铁剑法。\n");

	me->receive_damage("qi", 65);
	me->add("neili", -70);

	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	object weapon;
	
	if (random(10) < 7)
	{
			victim->receive_wound("qi", damage_bonus / 6, me);
		return HIR "$n" HIR "登时连退了五六步，脸如金纸！"NOR"\n"HIR"打气血上限 -"+damage_bonus/6+"。"NOR"\n";
	}
}

string perform_action_file(string action)
{
	return __DIR__"xuantie-jian/" + action;
}
