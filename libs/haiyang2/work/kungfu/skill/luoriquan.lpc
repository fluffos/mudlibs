// TIE@FY3
inherit SKILL;
mapping *action = ({
        ([      "action":               
"$N飘然有出尘之意，一招「穿花露滴衣」回拍$n的$l！",
                "damage":               60,
                "dodge":                40,
                "parry":                40,
                "damage_type":  "瘀伤"
        ]), 
        ([      "action":               
"$N长啸连连，使一招「暮色千山入」，双手闪电般击向$n的$l！",
                "damage":               60,
                "dodge":                20,
                "parry":                60,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N一招「因风离海上」，身行飘渺如云烟，忽地向$n的$l一拂！",
                "damage":               80,
                "dodge":                10,
                "parry":                40,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N双手合击，一招「月涌大江流」猛然击向$n的$l！",
                "damage":               200,
                "dodge":                -110,
                "parry":                -40,
                
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N陡然回身一转，一招「白云回望合」向$n$l虚空拍出一掌！",
                "damage":               110,
                "dodge":                100,
                "parry":                200,
               
                "damage_type":  "瘀伤"
        ]),

});

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
	return notify_fail("练落日拳必须空手。\n");
        return 1;
}

int valid_enable(string usage)
{
        return (usage=="unarmed") || (usage=="parry");
}
mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
         if( (int)me->query("jing") < 30 )
                return 
notify_fail("你的体力不够练这门拳法，还是先休息休息吧。\n");
        me->receive_damage("jing", 30);
        return 1;
}
int effective_level() { return 15;}
 
string *parry_msg = ({
        "$n冉冉腾空而起，早以一招「江鸣夜雨悬」令$N所有招式都落在空处。\n",
	
});

string *unarmed_parry_msg = ({
"$n冉冉腾空而起，早以一招「江鸣夜雨悬」令$N所有招式都落在空处。\n",
	
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
	return 30;
}
int practice_bonus()
{
	return -30;
}
int black_white_ness()
{
	return 320;
}


string perform_action_file(string action)
{
        return __DIR__"luoriquan/" + action;
}

