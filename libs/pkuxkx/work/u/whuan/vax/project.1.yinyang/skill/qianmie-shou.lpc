inherit SKILL;
mapping *action = ({
([      "action" : "$N一招「万树梨花开」，右手一扬，无数$w脱手而出，无声无响
地飞向$N。",
        "force" : 50,
        "dodge" : 5,
        "damage": 30,
        "lvl" : 0,
//        "weapon":"玉蜂针",
        "skill_name" : "万树梨花开",
        "damage_type" : "刺伤"
]),
([      "action" : "$N抓出一把$w，一记「心有千千节」,只见空中冲出无数黑线，击向$n的全
身各处要穴。",
        "force" : 100,
        "dodge" : 10,
        "damage": 50,
        "lvl" : 8,
//        "weapon":"玉蜂针",
        "skill_name" : "心有千千节",
        "damage_type" : "刺伤"
]),
([      "action" : "$N欺身向前，左手微向后扬，右手伸出，一招「烟村四五家」，数根$w以五种劲道射向$n。",
        "force" : 200,
        "dodge" : 15,
        "damage": 70,
        "lvl" : 60,
//      "weapon":"玉蜂针",
        "skill_name" : "烟村四五家",
        "damage_type" : "刺伤"
]),
([      "action" : "$N右手五指微挥，一招「流白小提诗」，十数根$w成一条直线，射向$n。",
        "force" : 300,
        "dodge" : 20,
        "damage": 90,
        "lvl" : 100,
//        "weapon":"玉蜂针",
        "skill_name" : "流白小提诗",
        "damage_type" : "刺伤"
]),
([      "action" : "$N右手猛洒，只见无数$w如泼墨，如瀑布，漫天盖地地卷向$n,好一招「泼墨大写意」。",
        "force" : 500,
        "dodge" : 20,
        "damage": 120,
        "lvl" : 100,
//        "weapon":"玉蜂针",
        "skill_name" : "泼墨大写意",
        "damage_type" : "刺伤"
]),
});
int valid_enable(string usage) { return usage=="throwing" || usage=="parry"; }
int valid_combine(string combo) { return combo=="meinu-quan"; }
int valid_learn(object me)
{
      
        if ((int)me->query_skill("changhen-xinfa", 1) < 20)
                return notify_fail("你的长恨心法火候不够，无法学千灭手。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练千灭手。\n");
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
        level   = (int) me->query_skill("qianmie-shou",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练千灭手。\n");
        me->receive_damage("qi", 25);
        me->add("neili", -5);
        return 1;
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
        
string perform_action_file(string action)
{
          return __DIR__"qianmie-shou/" + action;
}

string query_yinyang()
{
	return "太阴";
}
