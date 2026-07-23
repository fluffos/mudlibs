// fy-sword.c
inherit SKILL;

mapping *action = ({
        ([      "action":
"$N使出一招「风满长空」，手中的$w画了一道圆弧，向$n的$l刺来",
                "dodge":                30,
                "damage":               50,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N左手轻轻拍出一掌，右手中的$w使出一招「烈火腾云」，斩向$n的$l",
                "dodge":                10,
                "damage":               70,
                "damage_type":  "割伤"
        ]),
        ([      "action":
"$N使出一招「水到渠成」，身形婉如流水，手中$w从天而降，斩向$n的$l",
                "dodge":                50,
                "damage":               10,
                "damage_type":  "割伤"
        ]),
        ([      "action":
"$N使出一式的「雷震四方」对准$n的$l刺出一剑",
                "dodge":                20,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N将手中$w连晃几个虚招，一招「草深雾泽」向$n刺去",
                "dodge":                60,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N双手握剑，使出一招「天目昭辉」劈向$n的$l",
                "dodge":                100,
                "damage":               40,
                "damage_type":  "割伤"
        ]),
        ([      "action":
"$N手中剑轻轻一晃，$w化为一道电光，使出「地老天荒」刺向$n的$l",
                "dodge":                100,
                "damage":               100,
                "damage_type":  "刺伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_neili") < 50 )
                return notify_fail("你的内力不够，没有办法练大旗风云剑法。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 30
        ||      (int)me->query("neili") < 5 )
                return  notify_fail("你的内力或气不够，没有办法练习大旗风云剑法。\n"
);
        me->receive_damage("qi", 30);
        me->add("neili", -5);
        //write("你按著所学练了一遍大旗风云剑法。\n");
        return 1;
}

int effective_level() { return 9;}

string *parry_msg = ({
        "$n以功代守，$v直向$N刺去。$N吓的连退数步，撤回了攻势。\n",
        "$n使出一招「山高林密」，将全身躲在了$v形成的剑幕中。\n",
});

string *unarmed_parry_msg = ({
        "$n将手中的$v连续刺出，挡住$N的全部攻势。\n",
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
        return -10;
}
int practice_bonus()
{
        return 10;
}
int black_white_ness()
{
        return 30;
}
string perform_action_file(string action)
{
        return __DIR__"fy-sword/" + action;
}