// Huoyan-dao.c 火焰刀
// Cracked by 凌惊雪 5-12-2003

inherit SKILL;

mapping *action = ({
([      "action" : "$N使出一招「钻木取火」，飞身急转，双掌向前平平拍向$n",
        "dodge" : -30,
        "parry" : -30,
        "damage" : 90,
        "damage_type" : "内伤",
]),
([      "action" : "$N使出一招「祝融怀焰」，手掌如刀，斜斜劈向$n的$l",
        "dodge" : -30,
        "parry" : -30,
        "damage" : 100,
        "damage_type" : "内伤",
]),
([      "action" : "$N使出一招「风火无边」，双掌一拍，一道内力自掌中攻向$n的$l",
        "dodge" : -30,
        "parry" : -30,
        "damage" : 110,
        "damage_type" : "内伤",
]),
([      "action" : "$N使出一招「六道轮回」，双手合十，当头劈向$n",
        "dodge" : -30,
        "parry" : -30,
        "damage" : 120,
        "damage_type" : "内伤",
]),
([      "action" : "$N使出一招「双龙吐焰」，双掌一错，两道内力交叉攻向$n的$l",
        "dodge" : -30,
        "parry" : -30,
        "damage" : 130,
        "damage_type" : "内伤",
]),
([      "action" : "$N使出一招「刀山火海」，双掌向下斜拍，顿时万千道内力从四面八方攻向$n",
        "dodge" : -30,
        "parry" : -30,
        "damage" : 140,
        "damage_type" : "内伤",
]),
([      "action" : "$N使出一招「白佛光度」，左臂回收，右掌引内力直刺$n的$l",
        "dodge" : -30,
        "parry" : -30,
        "damage" : 150,
        "damage_type" : "内伤",
]),
([      "action" : "$N使出一招「火内莲花」，双掌微并，两臂前伸，一道内劲如排山倒海般攻向$n",
        "dodge" : -30,
        "parry" : -30,
        "damage" : 200,
        "damage_type" : "内伤",
]),
});

int valid_enable(string usage) 
	{ 
		return (usage == "unarmed") || (usage == "parry"); 
	}

int valid_learn(object me)
{
        if ((int)me->query_skill("bolomiduo", 1) < 100)
                return notify_fail("你的婆萝蜜多心经火候不够，无法学「火焰刀」。\n");
        if ((int)me->query("max_force") < 1000)
                return notify_fail("你的内力太弱，无法练「火焰刀」。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
	int i = me->query("HYD");
	if( !me->query("HYD") ) {
        return action[random(sizeof(action))];
	}
	else
	{
	return action[i];
	}
}

int practice_skill(object me)
{
        if ((int)me->query("kee") < 60)
                return notify_fail("你的体力不够练「火焰刀」。\n");
        if ((int)me->query("force") < 50)
                return notify_fail("你的内力不够练「火焰刀」。\n");
        me->receive_damage("kee", 50);
        return 1;
}
string perform_action_file(string func)
{
return CLASS_D("sanxian") + "/huoyan-dao/" + func;
}
