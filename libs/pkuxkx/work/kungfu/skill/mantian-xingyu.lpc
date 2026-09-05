// mantian-xingyu
//by hubo

inherit SKILL;
mapping *action = ({
([      "action" : "$N喊一声：“看镖”，拧腰回身，右手一扬，一只飞镖应声而出，带着
嗤嗤声响飞向$N。",
        "force" : 40,
        "dodge" : 5,
        "damage": 15,
        "lvl" : 0,
//        "weapon":"金花",
        "skill_name" : "回头望月",
        "damage_type" : "刺伤"
]),
([      "action" : "$N手中抓一把飞镖，用「漫天飞雨」的手法散出，各个击向$n的全
身各处要穴。",
        "force" : 50,
        "dodge" : 10,
        "damage": 20,
        "lvl" : 8,
//        "weapon":"金花",
        "skill_name" : "漫天飞雨",
        "damage_type" : "刺伤"
]),
([      "action" : "$N假装不敌，边退边把手伸向镖囊，回身发出，喊道：去死吧！！",
        "force" : 60,
        "dodge" : 15,
        "damage": 20,
        "lvl" : 60,
//      "weapon":"金花",
        "skill_name" : "暗渡陈仓",
        "damage_type" : "刺伤"
]),
([      "action" : "$N突然停住，全身上下，每个部位都射出无数只飞镖，吓得$n目瞪口呆！",
        "force" : 100,
        "dodge" : 20,
        "damage": 30,
        "lvl" : 100,
//        "weapon":"金花",
        "skill_name" : "日月辉映",
        "damage_type" : "刺伤"
]),
});
int valid_enable(string usage) { return usage=="throwing" || usage=="parry"; }
int valid_learn(object me)
{

        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练天女散花。\n");
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
        level   = (int) me->query_skill("mantian-xingyu",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练漫天星雨。\n");
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
        return __DIR__"mantian-xingyu/" + action;
}        

