// pili-dan.c 霹雳弹
inherit SKILL;

mapping *action = ({
([      "action" : "$N手中$w脱手而出,使出一招「火龙飞腾」，打向$n的$l  ",
        "skill_name" : "火龙飞腾",
        "force" : 100,
        "dodge" : -5,
        "parry" : 5,
        "lvl" : 0,
        "damage" : 120,
        "damage_type" : "刺伤",
]),
([      "action" : "$N身体一侧，使一招「火树银花」，手中$w弹向$n的大腿  ",
        "skill_name" : "火树银花",
        "force" : 140,
        "dodge" : 5,
        "parry" : 5,
        "lvl" : 8,
        "damage" : 140,
        "damage_type" : "刺伤",
]),
([      "action" : "$N腾空而起，使出「霹雳天降」，手中$w飞快地射向$n的$l  ",
        "skill_name" : "霹雳天降",
        "force" : 180,
        "dodge" : 10,
        "parry" : 5,
        "lvl" : 16,
        "damage" : 160,
        "damage_type" : "刺伤",
]),
([      "action" : "$N使出一招「火如雨下」，$w如暴雨般扑向$n  ",
        "skill_name" : "火如雨下",
        "force" : 220,
        "dodge" : 5,
        "parry" : 5,
        "lvl" : 24,
        "damage" : 180,
        "damage_type" : "刺伤",
]),
});
int valid_enable(string usage) { return usage=="throwing" ; }
int valid_learn(object me)
{
        if (me->query("class")!="bonze" && (int)me->query_skill("pili-dan",1) >99 )
                return notify_fail("由于你不是佛门中人，心有俗念，不能领会佛门的高深武功。\n");
        if ((int)me->query_skill("linji-zhuang", 1) < 20)
                return notify_fail("你的临济十二庄火候不够，无法学霹雳弹。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练霹雳弹。\n");
        return 1;
}


int practice_skill(object me)
{       
        if (me->query("class")!="bonze" && (int)me->query_skill("pili-dan",1) >99 )
                return notify_fail("由于你不是佛门中人，心有俗念，不能领会佛门的高深武功。\n");
        if ((int)me->query("qi") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练霹雳弹。\n");
        me->receive_damage("qi", 25);
        me->add("neili", -5);
        return 1;
}


string perform_action_file(string action)
{
        return __DIR__"pili-dan/" + action;
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
        level   = (int) me->query_skill("pili-dan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
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

string query_yinyang()
{
	return "太阳";
}