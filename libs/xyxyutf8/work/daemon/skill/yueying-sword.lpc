// Yueying-sword.c 月影神剑
// Cracked by 凌惊雪 5-20-2003

inherit SKILL;

mapping *action = ({
([      "action" : "$N使一招「星倚轩窗」，手中$w化为一道疾光刺向$n的$l",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//1
([      "action" : "$N使一招「星倚轩窗」，手中$w化为一道疾光刺向$n的$l",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//2
([      "action" : "只见$N几个急转，使出「云翔天际」，一声娇喝中剑光冲天而起，扫向$n的$l",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//3
([      "action" :"$N淡淡一笑，一式「风舞长袖」舞出无数幻影，$n只觉得阵阵幽香四面袭来，却不知该如何闪躲",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//4
([      "action" : "$N手中$w轻轻一抖，一式「煮酒传觥」幻出一遍寒光罩向$n。$n只觉得连呼吸都被冻住了",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//5
([      "action" :"$n只觉得一缕冷香掠过，$N已悄然间飘至$n身后，剑心直指$n的后胸，正是一式「轻歌揽月」",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//6
([      "action" : "$N一式「醉伴纤柳」，神色娴雅，一道澄如秋水、寒似玄冰的剑光直指$n破绽所在",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
});


int valid_enable(string usage) 
	{ 
		return (usage == "sword") || (usage == "parry"); 
	}

int valid_learn(object me)
{
        if (me->query("chushi/chushi_moon") != "yes" )
                return notify_fail("你没有领悟「月影神剑」的窍门。\n");
        if ((int)me->query("max_force") < 1000)
                return notify_fail("你的内力太弱，无法练「月影神剑」。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
	int i = me->query_temp("pfm-yueying");
	if( !me->query_temp("pfm-yueying") ) {
        return action[random(sizeof(action))];
	}
	else
	{
	return action[i];
	}
}

int practice_skill(object me)
{
        if (me->query("chushi/chushi_moon") != "yes" )
                return notify_fail("你没有领悟「月影神剑」的窍门。\n");
        if ((int)me->query("kee") < 60)
                return notify_fail("你的体力不够练「月影神剑」。\n");
        if ((int)me->query("force") < 50)
                return notify_fail("你的内力不够练「月影神剑」。\n");
        me->receive_damage("kee", 50);
        return 1;
}
string perform_action_file(string func)
{
return CLASS_D("chushi") + "/yueying-sword/" + func;
}
