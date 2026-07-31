//
// huanhua-jian.c 浣花剑法
//
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "只见白芒一闪,$N使出一招「长虹贯日」，手中$w一抖，直刺$n的$l  ",
        "skill_name" : "长虹贯日",
        "force" : 100,
        "dodge" : -10,
        "lvl" : 0,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
([      "action" : "$N使出一式「旭日飞升」，剑光在长空中划起半道弧型，剑芒向$n的$l飞贯而来  ",
        "skill_name" : "旭日飞升",
        "force" : 140,
        "dodge" : 5,
        "lvl" : 8,
        "damage" : 50,
        "damage_type" : "刺伤",
]),
([      "action" : "$N使出一招「飞星刺月」，纵身跃入半空，$w如流星般劈向$n的$l  ",
        "skill_name" : "飞星刺月",
        "force" : 180,
        "dodge" : -10,
        "lvl" : 16,
        "damage" : 60,
        "damage_type" : "割伤",
]),
([      "action" : "$N使出「一星抛月」，$w的剑光舞得如圆月，忽然一剑刺向$n的$l  ",
        "skill_name" : "一星抛月",
        "force" : 220,
        "dodge" : 10,
        "lvl" : 24,
        "damage" : 70,
        "damage_type" : "刺伤",
]),
([      "action" : "$N使出一招「天际长江」，全身劲气贯于$w中，剑气直指$n的$l  ",
        "skill_name" : "天际长江",
        "force" : 250,
        "dodge" : 10,
        "lvl" : 32,
        "damage" : 80,
        "damage_type" : "刺伤",
]),
([      "action" : "$N使出一式「紫气万象」，一排剑光如白影般向$n的$l扫去  ",
        "skill_name" : "紫气万象",
        "force" : 280,
        "dodge" : 15,
        "lvl" : 40,
        "damage" : 90,
        "damage_type" : "割伤",
]),
([      "action" : "$N使出一招「花雨点点」，手中$w一抖,$n只觉得漫天剑光扑面而来  ",
        "skill_name" : "花雨点点",
        "force" : 300,
        "dodge" : 20,
        "lvl" : 48,
        "damage" : 100,
        "damage_type" : "割伤",
]),
([      "action" : "$N飞身一跃，居高临下使出「漫天花雨」，顿时剑尖如雨刺向$n的$l  ",
        "skill_name" : "漫天花雨",
        "force" : 320,
        "dodge" : 25,
        "lvl" : 56,
        "damage" : 110,
        "damage_type" : "刺伤",
]),
([      "action" : "$N猛然跃起,使出一招「花落无凭」，在半空中向$n徐徐劈去一剑  ",
        "skill_name" : "花落无凭",
        "force" : 340,
        "dodge" : 20,
        "lvl" : 66,
        "damage" : 120,
        "damage_type" : "刺伤",
]),
([      "action" : "$N使出一式「梅花三弄」，$w舞出三朵剑花,正在$n茫然的时候,剑花中心一道剑光向$n的$l扫去  ",
        "skill_name" : "梅花三弄",
        "force" : 360,
        "dodge" : 25,
        "lvl" : 84,
        "damage" : 130,
        "damage_type" : "割伤",
]),
([      "action" : "$N纵身轻轻跃起，一式「满天星斗」，剑光如水，一泻千里，洒向$n全身",
        "skill_name" : "满天星斗",
        "force" : 380,
        "dodge" : 20,
        "lvl" : 92,
        "damage" : 140,
        "damage_type" : "割伤",
]),
([      "action" : "$N轻抬$w，一招「移花接玉」，竟把$n的全部攻击力转向了$n  ",
        "skill_name" : "移花接玉",
        "force" : 400,
        "dodge" : 25,
        "lvl" : 100,
        "damage" : 150,
        "damage_type" : "刺伤",
]),
([      "action" : HIY "$N剑尖斜指，一式「生亦何欢，死亦何患」,手中$w藉着真力一吐，铺天剑光向$n飞去。"NOR,
        "skill_name" : "生亦何欢，死亦何患",
        "force" : 400,
        "dodge" : 25,
        "lvl" : 100,
        "damage" : 180,
        "damage_type" : "刺伤",
]),
});


int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
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
	level   = (int) me->query_skill("huanhua-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
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
	return __DIR__"huanhua-jian/" + action;
}
