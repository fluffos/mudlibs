// Seven-star.c 北斗七星剑
// Cracked by 凌惊雪 5-17-2003

inherit SKILL;

mapping *action = ({
([      "action" : "$N使出一招「天枢剔斗」，剑光闪烁不定，若有若无地刺向$n$l",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//1
([      "action" : "$N使出一招「天枢剔斗」，剑光闪烁不定，若有若无地刺向$n$l",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//2
([      "action" : "$N脚下踏了个七星步，一招「天璇射月」手中$w势若飞瀑向$n拦腰一斩",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "劈伤",
]),
//3
([      "action" : "$N轻轻一跃，使了个「天机开展」，却在转身之际对准$n$l斜斜挥出一剑",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//4
([      "action" : "$N神态悠闲，手中$w凭空一指，一招「天权银河」轻妙地划向$n的$l",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//5
([      "action" : "$N手中$w向外一分，使一招「玉衡百里」反手对准$n$l一剑刺去",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//6
([      "action" : "$N身形转个不停，突然一招「开阳星流」使出，手中$w划出一道银弧，径刺$n$l",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//7
([      "action" : "$N手中$w连续划出几个光环，一阵吸力带得$n向前踏出一步，\n$N左手一式「耀光焘天下」已刺向$n的$l",
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
        if (me->query("chushi/chushi_wzg") != "yes" )
                return notify_fail("你没有领悟「北斗七星剑」的窍门。\n");
        if ((int)me->query("max_force") < 1000)
                return notify_fail("你的内力太弱，无法练「北斗七星剑」。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
	int i = me->query_temp("pfm-star");
	if( !me->query_temp("pfm-star") ) {
        return action[random(sizeof(action))];
	}
	else
	{
	return action[i];
	}
}

int practice_skill(object me)
{
        if (me->query("chushi/chushi_wzg") != "yes" )
                return notify_fail("你没有领悟「北斗七星剑」的窍门。\n");
        if ((int)me->query("kee") < 60)
                return notify_fail("你的体力不够练「北斗七星剑」。\n");
        if ((int)me->query("force") < 50)
                return notify_fail("你的内力不够练「北斗七星剑」。\n");
        me->receive_damage("kee", 50);
        return 1;
}
string perform_action_file(string func)
{
return CLASS_D("chushi") + "/seven-star/" + func;
}
