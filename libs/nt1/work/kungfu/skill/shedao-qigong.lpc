// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// shedao-qigong  蛇岛奇功

inherit SKILL;

string *action_msg = ({
        "$N使一招「仙鹤梳翎」手中$w一提，插向$n的$l",
        "$N使出「灵蛇出洞」，身形微弓，手中$w倏的向$n的$l戳去",
        "$N身子微曲，左足反踢，乘势转身，使一招「贵妃回眸」，右手$w已戳向$n$l",
        "$N使一式「飞燕回翔」，背对着$n，右足一勾，顺势在$w上一点，$w陡然向自己咽喉疾射，\n"
        "接着$N身子往下一缩，$w掠过其咽喉，急奔$n急射而来",
        "$N忽的在地上一个筋斗，使一招「小怜横陈」，从$n胯下钻过，手中$w直击$n",
        "$N大吼一声，使一招「子胥举鼎」，反手擒拿$n极泉要穴，欲将$n摔倒在地",
        "$N双腿一缩，似欲跪拜，一招「鲁达拨柳」左手抓向$n右脚足踝，右手$w直击$n小腹",
        "$N突然一个倒翻筋斗，一招「狄青降龙」，双腿一分，跨在肩头，双掌直击$n",
});

int valid_enable(string usage) { return usage == "sword"|| usage == "staff"|| usage == "parry"; }

int valid_learn(object me)
{
        object weapon;

        if (objectp(weapon = me->query_temp("weapon")))
        if ((string)weapon->query("skill_type") != "staff" 
        &&  (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
                
        if ((int)me->query_skill("shenlong-xinfa", 1) < 30)
                return notify_fail("你的神龙心法火候不够，无法学蛇岛奇功.\n");
                
        if ((int)me->query_skill("force", 1) < 30)
                return notify_fail("你的基本内功火候不够，无法学蛇岛奇功。\n");
                
        if ((int)me->query_skill("shenlong-bashi", 1) < 30)
                return notify_fail("你的神龙八式火候不够，无法学蛇岛奇功。\n");
                
        if ((int)me->query_skill("shenlong-xinfa", 1) < (int)me->query_skill("shedao-qigong", 1))
                return notify_fail("你的神龙心法火候不够，无法继续学蛇岛奇功。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))],
                "damage": 120 + random(50),
                "attack": 70 + random(10),
                "dodge" : 70 + random(10),
                "parry" : 70 + random(10),
                "damage_type" : random(2)?"刺伤":"挫伤",
        ]);
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 80)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 80)
                return notify_fail("你的内力不够练蛇岛奇功。\n");
        me->receive_damage("qi", 70);
        me->add("neili", -70);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"shedao-qigong/" + action;
}

int query_effect_parry(object attacker, object me)
{
        int lvl;

        if (! objectp(me->query_temp("weapon")))
                return 0;

        lvl = me->query_skill("shedao-qigong", 1);
        if (lvl < 80)  return 0;
        if (lvl < 200) return 50;
        if (lvl < 280) return 80;
        if (lvl < 350) return 100;
        return 120;
}



