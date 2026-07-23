// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
mapping *action = ({
        ([      "action":               
"$N使出一招「乌云蔽日」，身形一纵，双掌自上而下，拍向$n的$l",
                "dodge":                -100,
                "parry":                100,
                "force":                100,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N使出一招「云映晴空」，双掌一分，直切$n的$l",
                "dodge":                -100,
                "parry":                100,
                "force":                 70,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N使出云雾掌法中的「雾霭迷蒙」，掌掌不离$n的$l",
                "dodge":                -100,
                "parry":                100,
                "force":                50,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N双掌一错，一掌虚晃，使出「云雾山中」，对准$n的$l单掌斜劈",
                "dodge":                -100,
                "parry":                100,
                "force":                150,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N身形稳稳站定，双掌齐挥，使出「青山云海」，袭向$n$l",
                "dodge":                -100,
                "parry":                100,
                "force":                140,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N使出「旭日浮云」，急挥双掌，从空中当头向$n的$l出掌攻击",
                "dodge":                -200,
                "parry":                200,
                "force":                150,
                "damage_type":  "瘀伤"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("练云雾掌法必须空手。\n");
        return 1;
}

int valid_enable(string usage) { return usage=="unarmed"; }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 30 )
                return notify_fail("你的体力不够了，休息一下再练吧。\n");
        if( (int)me->query("neili") < 5 )
                return notify_fail("你的内力不够了，休息一下再练吧。\n");
        me->receive_damage("qi", 30);
        me->add("neili", -5);
        return 1;
}
int effective_level() { return 10;}
 
string *parry_msg = ({
        "$n使出一招「雾锁苍山」，贴身急进，将$N的$w牢牢锁住。\n",
        "$n掌势层层，一招「云开雾散」拍向$N拿着$w的手。\n",
        "$n使出「云海茫茫」，双掌一划，引偏了$N的$w。\n",
});

string *unarmed_parry_msg = ({
        "$n双掌一翻，一招「天高云淡」虚空拍出一掌，逼得$N撤招自保。\n",
        "$n施展出「白云浮玉」，轻描淡写的化解了$N的攻势。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int learn_bonus()
{
	return 0;
}
int practice_bonus()
{
	return 0;
}
int black_white_ness()
{
	return 0;
}

string perform_action_file(string action)
{
        return __DIR__"yunwu-strike/" + action;
}
