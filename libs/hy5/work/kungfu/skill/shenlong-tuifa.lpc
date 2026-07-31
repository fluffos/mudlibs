// shenlong-tuifa.c 神龙腿法
// by aug   99.9.10

inherit SKILL;
#include <ansi.h>

mapping *action = ({
([      "action" : "$N双脚并步，一式「星罗棋布」，连环踢向$n",
        "force" : 80,
        "dodge" : 10,
        "parry" : 10,
        "lvl" : 0,
        "skill_name" : "星罗棋布",
        "damage_type" : "内伤"
]),
([      "action" : "$N脚踩七星，以奇门步法，从不可思议的角度踢出一腿，好一招「倒踩七星」",
        "force" : 120,
        "dodge" : 15,
        "parry" : 10,
        "lvl" : 20,
        "skill_name" : "倒踩七星",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N使一招「神龙摆尾」，右脚前跨，左腿反踢身后的$n，大大出乎$n意料",
        "force" : 165,
        "dodge" : -5,
        "parry" : -5,
        "lvl" : 40,
        "skill_name" : "神龙摆尾",
        "damage_type" : "内伤"
]),
([      "action" : "$N一式「蛇行无踪」，双腿摇摆不定，诡异的缠向$n",
        "force" : 200,
        "dodge" : 10,
        "parry" : 23,
        "lvl" : 60,
        "skill_name" : "蛇行无踪",
        "damage_type" : "内伤"
]),
([      "action" : "$N飞身而起，双腿在空中盘旋踢出，一式「旋风无敌」袭向$n的胸膛",
        "force" : 250,
        "dodge" : 10,
        "parry" : 15,
        "lvl" : 80,
        "skill_name" : "旋风无敌",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N一转身，反身飞起，以旋风之势向$n踢出十多腿，快的连腿影都看不清，正是一招「无影身腿」",
        "force" : 290,
        "dodge" : 20,
        "parry" : 25,
        "lvl" : 100,
        "skill_name" : "无影身腿",
        "damage_type" : "内伤"
]),
([      "action" : "$N右脚向前一步，左膝提起，右腿连环提出八腿，速度虽然不快，可所含内力惊人，正是「神龙八腿」",
        "force" : 330,
        "dodge" : 10,
        "parry" : 15,
        "lvl" : 150,
        "skill_name" : "神龙八腿",
        "damage_type" : "内伤"
]),
([      "action" : "$N左腿支地，右腿夹带着风雷之声缓缓踢出，正是天下最刚猛的腿法「开碑裂石」，一腿既出，非死即伤",
        "force" : 360,
        "dodge" : -15,
        "parry" : -15,
        "lvl" : 200,
        "skill_name" : "开碑裂石",
        "damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return usage == "leg" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("shenlong-xinfa", 1) < 10)
                return notify_fail("你的神龙心法火候太浅，无法学习神龙腿法。\n");
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

	level =  me->query_skill("shenlong-tuifa",1);
	
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("jing") < 25)
                return notify_fail("你的体力不够练神龙腿法。\n");
	if ((int)me->query("neili") < 8)
                return notify_fail("你的内力不够练神龙腿法。\n");
        me->receive_damage("jing", 25);
        me->add("neili", -8);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"shenlong-tuifa/" + action;
}
