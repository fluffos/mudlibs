// liuh-ken.c

inherit SKILL;

mapping *action = ({
        ([      "action":               "$N使一招「烽火连三月」，对准$n的$l轻飘飘的推去",
                "dodge":                -50,
                "parry":                20,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               "$N扬起右掌，左掌一晃，一招「会当凌绝顶」便往$n的$l拍去",
                "dodge":                -20,
                "parry":                10,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               "$N右掌虚晃，表情凝重，左掌一招「断魔式」往$n的$l击出",
                "dodge":                -100,
                "parry":                -80,
                "force":                 -60,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               "$N左掌微收，右掌一转使出一招「明月出天山」，抓向$n的$l",
                "dodge":                -50,
                "parry":                -30,
                "force":                100,
                "damage_type":  "抓伤"
        ]),
        ([      "action":               "$N倏地一个转身，双掌一挑「云卷云舒」直冲$n$l",
                "dodge":                -10,
                "parry":                -60,
                "force":                110,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               "$N左掌一沉，右掌飘飘，面含杀机的使出「辟魔式」砍向$n$l",
                "dodge":                -110,
                "parry":                -50,
                "force":                150,
                "damage_type":  "挫伤"
        ]),
        ([      "action":               "$N右掌在$n$l划过，随后一招「沧海横流」左掌已告临体",
                "parry":                -50,
                "force":                60,
                "damage_type":  "淤伤"
        ]),
        ([      "action":               "$N左手虚晃，右掌平推，一招「月涌大江流」击向$n$l",
                "dodge":                -20,
                "parry":                -50,
                "force":                150,
                "damage_type":  "挫伤"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("练魔魔掌法必须空手。\n");
        return 1;
}

int valid_enable(string usage)
{
        return usage=="strike" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30 )
                return notify_fail("你的体力不够了，休息一下再练吧。\n");
        me->receive_damage("kee", 30);
        return 1;
}
int effective_level() { return 10;}

string *parry_msg = ({
        "$n一招「苍茫云海间」，右掌轻拂$N的面门，逼得$N中途撤回手中的$w。\n",
        "$n右掌虚幌，左掌「摘星扫月」，逼得$N后退三步。\n",
        "$n以守为攻，一招「斜倚小楼独自愁」，轻拍$N握$w的手腕。\n",
        "$n一招「捧日降魔」，轻轻一托$N握$w的手，引偏了$N的$w。\n",
});

string *unarmed_parry_msg = ({
        "$n一招「推山式」，逼得$N中途撤招。\n",
        "$n脚走阴阳，一招「黄河入海」，攻$N之必救。\n",
        "$n左掌压下，右掌一招「辟魔式」，将$N封于尺外。\n",
        "$n双掌齐出，使出一招「沧海横流」，$N的功势入泥牛入海，消失得无影无踪。\n",

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
        return 10;
}
int practice_bonus()
{
        return 10;
}
int black_white_ness()
{
        return 30;
}
