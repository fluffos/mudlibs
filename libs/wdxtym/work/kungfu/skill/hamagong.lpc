// hamagong.c 蛤蟆功

#include <ansi.h>
inherit FORCE;

mapping *action = ({
([      "action" : "$N忽而倒竖，一手撑地，身子横挺，只以一掌向$n的$l拍出",
	"dodge"  : 0,
	"force"  : 310,
	"attack" : 103,
	"parry"  : 21,
	"damage" : 166,
	"lvl"    : 0,
	"damage_type": "震伤" 
]), 
([      "action" : "$N丝毫不动声色，双腿微曲，右掌平伸，左掌运起蛤蟆功的"
		   "劲力，呼的一声推向$n",
	"dodge"  : 0,
	"force"  : 332,
	"attack" : 112,
	"parry"  : 37,
	"damage" : 177,
	"lvl"    : 250,
	"damage_type": "震伤"
]), 
([      "action" : "$N闭眼逼住呼吸，过了片刻，猛跃而起，眼睛也不及睁开，双"
		   "掌便向$n的方向推了出去",
	"dodge"  : 0,
	"force"  : 360,
	"attack" : 122,
	"parry"  : 53,
	"damage" : 285,
	"lvl"    : 260,
	"damage_type": "震伤"
]),
([      "action" : "$N脚步摇摇幌幌，忽然双腿一弯、一登，口中阁的一声叫喝，"
		   "手掌向$n猛然推出",
	"dodge"  : 5,
	"force"  : 410,
	"attack" : 143,
	"parry"  : 67,
	"damage" : 291,
	"lvl"    : 270,
	"damage_type": "震伤"
]), 
});

int valid_enable(string usage, object me)
{ 
	return usage == "force" || usage == "unarmed" || usage == "parry";
}

int query_neili_improve(object me)
{
	int lvl;

	lvl = (int)me->query_skill("hamagong", 1);
	return lvl * lvl * 15 * 12 / 100 / 200;
}

int valid_learn(object me)
{
	if ( me->query("gender") == "无性" && me->query("hamagong", 1) > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的蛤蟆功。\n");

	if ((int)me->query_skill("force", 1) < 30)
		return notify_fail("你的基本内功火候不足，不能学蛤蟆功。\n");

	return ::valid_learn(me);
}

string query_skill_name(int level)
{
	int i = sizeof(action);

	while (i--)
		if(level > action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me)
{
	int i, level;
	
	level = (int) me->query_skill("hamagong", 1);
	if (random(5) == 1)
	{
		me->add("neili", -100);
		return ([
		"action": HIC "$N蹲低身子，两眼微闭，口中咕咕咕的叫了三声，双"
			  "掌向$n" HIC "缓缓推出！激得灰泥弥漫，尘土飞扬" NOR,
		"force"  : 738,
		"attack" : 152,
		"parry"  : 112,
		"dodge"  : 33,
		"damage" : 400,
		"damage_type": "瘀伤"]);
	}
	
	for (i = sizeof(action); i > 0; i--)
		if (level > action[i - 1]["lvl"])
			return action[NewRandom(i, 20, level / 5)];
}

 mixed hit_ob(object me, object victim, int damage_bonus)
{
	if (random(10) < 7)
	{
		victim->receive_wound("qi", damage_bonus / 6);
		return HIC "$n" HIC "硬承下$N" HIC "一掌，霎时全身一颤，经脉受震，喷出一口鲜血！"NOR"\n"HIR"打气血上限 -"+damage_bonus/6+"。"NOR"\n";
	}
} 

int practice_skill(object me)
{
	return notify_fail("蛤蟆功只能用学(learn)的来增加熟练度。\n");
}

string perform_action_file(string action)
{
	return __DIR__"hamagong/perform/" + action;
}
string exert_function_file(string action)
{
	return __DIR__"hamagong/exert/" + action;
}