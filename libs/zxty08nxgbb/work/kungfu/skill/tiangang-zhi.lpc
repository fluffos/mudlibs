// tiangang-zhi.c 天罡指穴法
// create by host dec,20
inherit SKILL;

mapping *action = ({
([  "action" : "$N左指划了个半圈，一式「浪起湖心」自下而上点向$n的丹田",
    "force" : 150,
    "dodge" : 5,
    "damage": 15,
    "lvl" : 0,
    "skill_name" : "浪起湖心",
    "damage_type" : "刺伤"
]),
([  "action" : "$N左右指双起，一招「瀑落清潭」，拂向$n阳关、风池、颈间三处穴门",
    "force" : 200,
    "dodge" : 10,
    "damage": 20,
    "lvl" : 5,
    "skill_name" : "瀑落清潭",
    "damage_type" : "刺伤"
]),
([  "action" : "$N晃身若蛇行，一式「龟蛇竞渡」，左指仿若无力般指向$n的$l",
    "force" : 250,
    "dodge" : 15,
    "damage": 25,
    "lvl" : 10,
    "skill_name" : "千夫所指",
    "damage_type" : "刺伤"
]),
([  "action" : "$N一式「倒索攀山」，右掌蓄式，右指幻出一缕指风，重重点向$n的$l",
    "force" : 300,
    "dodge" : -5,
    "damage": 30,
    "lvl" : 20,
    "skill_name" : "倒索攀山",
    "damage_type" : "刺伤"
]),
([  "action" : "$N一式「闪现雷鸣」，左指虚晃，右指风驰电掣般急急刺向$n的$l",
    "force" : 240,
    "dodge" : 15,
    "damage": 35,
    "lvl" : 30,
    "skill_name" : "闪现雷鸣",
    "damage_type" : "刺伤"
]),
([  "action" : "$N一式「地动山摇」，蓄集全身力气，双指排出一股气浪，击向$n",
    "force" : 280,
    "dodge" : -20,
    "damage": 40,
    "lvl" : 40,
    "skill_name" : "地动山摇",
    "damage_type" : "刺伤"
]),
([  "action" : "$N飞身而起，一式「水拍云崖」，右手划出一圈，拂向$n的$l",
    "force" : 320,
    "dodge" : 20,
    "damage": 45,
    "lvl" : 60,
    "skill_name" : "水拍云崖",
    "damage_type" : "刺伤"
]),
([  "action" : "$N凝神聚气，一式「泰山压顶」，双手幻出无数指风，从上而下罩$n",
    "force" : 380,
    "dodge" : 5,
    "damage": 50,
    "lvl" : 80,
    "skill_name" : "泰山压顶",
    "damage_type" : "刺伤"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }
int valid_combine(string combo) { return combo=="jinding-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("学习「天罡指穴法」必须空手。\n");
        if ((int)me->query_skill("linji-zhuang", 1) < 20)
            return notify_fail("你的「临济十二庄」火候不够，无法学习「天罡指穴法」。\n");
	if ((int)me->query("max_neili") < 100)
            return notify_fail("你的内力太弱，无法学习「天罡指穴法」。\n");
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
    level   = (int) me->query_skill("tiangang-zhi",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ( !me->query_skill("linji-zhuang",1) )
           return notify_fail("练「天罡指穴法」必须要有「临济十二庄」作底子。\n");

	if ((int)me->query("qi") < 30)
           return notify_fail("你的体力不够，休息一下再练吧。\n");

	if ((int)me->query("neili") < 20)
           return notify_fail("你的内力不够练「弹指神通」。\n");

        me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"tiangang-zhi/" + action;
}
