// Demon-blade.c 万魔之刃
// Cracked by 凌惊雪 5-20-2003

inherit SKILL;

mapping *action = ({
([      "action" : "$N使出万魔之刃中的起手式“万魔初醒”，手中的$w划出一溜光芒斩向$n的$l",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "砍伤",
]),
//1
([      "action" : "$N使出万魔之刃中的起手式“万魔初醒”，手中的$w划出一溜光芒斩向$n的$l",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "砍伤",
]),
//2
([      "action" : "$N刀锋忽转，手中的$w一招“魔光乍现”，闪电般劈向$n的$l",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "劈伤",
]),
//3
([      "action" : "$N手一抖，一招“魔焰万丈”手中的$w幻成一片刀花，散向$n的$l",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "戳伤",
]),
//4
([      "action" : "$N的双脚点地，刀背贴身，一招“万刃天魔”全身转出一团刀光滚向$n",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 50,
        "damage_type" : "刺伤",
]),
//5
([      "action" : "$N身影晃动，刀锋忽左忽右，一招“独尊地魔”，手中的$w，从中路突然砍至$n的$l",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 50,
        "damage_type" : "砍伤",
]),
//6
([      "action" : "$N刀刃向上，一招“如意人魔”，从一个$n意想不到的角度撩向$n的$l",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 50,
        "damage_type" : "砍伤",
]),
//7
([      "action" : "$N你手中的$w左右横划，一招“万魔归宗”，来来回回地狂扫向$n的$l",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 60,
        "damage_type" : "砍伤",
]),
//8
([      "action" : "$N使出万魔之刃的收手式“十万神魔”，手中的$w迅捷无比地砍向$n的$l",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 70,
        "damage_type" : "砍伤",
]),
});


int valid_enable(string usage) 
	{ 
		return (usage == "blade") || (usage == "parry"); 
	}

int valid_learn(object me)
{
        if (me->query("chushi/chushi_wdd") != "yes" )
                return notify_fail("你没有领悟「万魔之刃」的窍门。\n");
        if ((int)me->query("max_force") < 1000)
                return notify_fail("你的内力太弱，无法练「万魔之刃」。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
	int i = me->query_temp("pfm-demon");
	if( !me->query_temp("pfm-demon") ) {
        return action[random(sizeof(action))];
	}
	else
	{
	return action[i];
	}
}

int practice_skill(object me)
{
        if (me->query("chushi/chushi_wdd") != "yes" )
                return notify_fail("你没有领悟「万魔之刃」的窍门。\n");
        if ((int)me->query("kee") < 60)
                return notify_fail("你的体力不够练「万魔之刃」。\n");
        if ((int)me->query("force") < 50)
                return notify_fail("你的内力不够练「万魔之刃」。\n");
        me->receive_damage("kee", 50);
        return 1;
}
string perform_action_file(string func)
{
return CLASS_D("chushi") + "/demon-blade/" + func;
}
