// liuxing-dao.c 流星赶月镖


inherit SKILL;

mapping *action = ({
([      "action" : "$N手中$w激射而出,使出一招「银星如雨」，打向$n的$l  ",
        "skill_name" : "银星如雨",
        "force" : 100,
        "dodge" : -5,
        "parry" : 5,
        "lvl" : 0,
        "damage" : 120,
        "damage_type" : "刺伤",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :)

]),
([      "action" : "$N身体微侧，使一招「飞星若线」，手中$w飞向$n的大腿  ",
        "skill_name" : "飞星若线",
        "force" : 140,
        "dodge" : 5,
        "parry" : 5,
        "lvl" : 8,
        "damage" : 140,
        "damage_type" : "刺伤",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :)
]),
([      "action" : "$N飞身而起，运足全身内力，使出「陨星似铁」，$w似有千钧之力地打向$n的$l  ",
        "skill_name" : "霹雳天降",
        "force" : 180,
        "dodge" : 10,
        "parry" : 5,
        "lvl" : 16,
        "damage" : 160,
        "damage_type" : "刺伤",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :)
]),
([      "action" : "$N使出一招「流星赶月」，$w如暴雨般迅雷不及掩耳地扑向$n  ",
        "skill_name" : "流星赶月",
        "force" : 220,
        "dodge" : 5,
        "parry" : 5,
        "lvl" : 24,
        "damage" : 180,
        "damage_type" : "刺伤",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :)
]),
});

int valid_enable(string usage) { return (usage == "throwing") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 400)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("biyun-xinfa", 1) < 80)
		return notify_fail("你的碧云心法火候太浅。\n");
	if ((int)me->query_skill("biye-wu", 1) < 30)
		return notify_fail("你的碧叶随风舞火候太浅。\n");
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
	level   = (int) me->query_skill("liuxing-dao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "throwing")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够，练不了流星赶月镖。\n");
	me->receive_damage("qi", 30);
	return 1;
}

