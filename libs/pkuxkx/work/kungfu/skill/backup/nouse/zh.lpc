// feihua-shou.c -飞花摘叶手
inherit SKILL;
mapping *action = ({
([      "action" : "$N一招「回头望月」拧腰回身，右手一扬，一朵金花应声而出，带着
嗤嗤声响飞向$N。",
        "force" : 40,
        "dodge" : 5,
        "damage": 15,
        "lvl" : 0,
//        "weapon":"金花",
        "skill_name" : "回头望月",
        "damage_type" : "刺伤"
]),
([      "action" : "$N手中扣上几朵金花，用「漫天飞雨」的手法散出，各个击向$n的全
身各处要穴。",
        "force" : 50,
        "dodge" : 10,
        "damage": 20,
        "lvl" : 8,
//        "weapon":"金花",
        "skill_name" : "漫天飞雨",
        "damage_type" : "刺伤"
]),
([      "action" : "$N欺身向前，双掌拍向$n诱敌，一式「暗渡陈仓」，虚晃一招，接着
口中：“呸！”的一声吐出一朵金花射向$n。",
        "force" : 60,
        "dodge" : 15,
        "damage": 20,
        "lvl" : 60,
//      "weapon":"金花",
        "skill_name" : "暗渡陈仓",
        "damage_type" : "刺伤"
]),
([      "action" : "$N左手弹出一朵金花，袭向$n,待到劲道稍弱时，一招「日月辉映」,
右手电射出另一朵金花正中前者，结果前面的金花力道大增，迅猛无伦地射向$n，令$n大吃
一惊。",
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
int valid_combine(string combo) { return combo=="yingzhua-gong"; }
int valid_learn(object me)
{
      
        if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
                return notify_fail("你的九阳神功火候不够，无法学飞叶摘花手。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练飞叶摘花手。\n");
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
        level   = (int) me->query_skill("feihua-shou",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练飞叶摘花手。\n");
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
