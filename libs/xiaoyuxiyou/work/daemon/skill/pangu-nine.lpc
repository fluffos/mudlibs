// Pangu-nine.c 盘古九式
// Cracked by 凌惊雪 5-12-2003

inherit SKILL;

mapping *action = ({
([      "action" : "只见$N一个斜跨，使个「将军上马」，手中$w带出一道寒气，由下而上疾挑$n$l",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//1
([      "action" : "只见$N一个斜跨，使个「将军上马」，手中$w带出一道寒气，由下而上疾挑$n$l",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//2
([      "action" : "$N使出一招「唐兵留客」，手中$w回收，右掌引内力直刺$n的$l",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//3
([      "action" : "$N左手化出一个圆圈，右手中的$w一招「力劈华山」向$n的$l挥去！",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//4
([      "action" : "$N手中$w自左而右地划了一个大弧,平平刺向$n的$l,正是「威镇四方」",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//5
([      "action" : "$N一弹手中的$w，一招「神勇无敌」，手中的$w向$n的$l雷霆般地砸下",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//6
([      "action" : "$N暴喝一声，腾空飞起，以泰山压顶之式扑下，手中的$w带着轰轰雷声一招「千钧一发」击向$n的$l",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//7
([      "action" : "$N手中的$w一转，一招「百战百胜」从四面八方盖向$n的$l",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//8
([      "action" : "$N一抖手中的$w，一招「横扫千军」幻出一片刀光剑影，虚虚实实的挥向$n的$l",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//9
([      "action" : "$N使出一招「气盖山河」，$w狂舞，一道内劲如排山倒海般攻向$n",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//10
([      "action" : "$N使出一招「开天辟地」，手中$w有如神助，一道内劲如排山倒海般攻向$n",
        "dodge" : -80,
        "parry" : -80,
        "damage" : 160,
        "force" : 160,
        "damage_type" : "刺伤",
]),
});

int valid_enable(string usage) 
	{ 
		return (usage == "spear") || (usage == "mace") || (usage == "parry"); 
	}

int valid_learn(object me)
{
        if (me->query("chushi/chushi_jjf") != "yes" )
                return notify_fail("你没有领悟「盘古九式」的窍门。\n");
        if ((int)me->query("max_force") < 1000)
                return notify_fail("你的内力太弱，无法练「盘古九式」。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
	int i = me->query_temp("pfm-pangu");
	if( !me->query_temp("pfm-pangu") ) {
        return action[random(sizeof(action))];
	}
	else
	{
	return action[i];
	}
}

int practice_skill(object me)
{
        if (me->query("chushi/chushi_jjf") != "yes" )
                return notify_fail("你没有领悟「盘古九式」的窍门。\n");
        if ((int)me->query("kee") < 60)
                return notify_fail("你的体力不够练「盘古九式」。\n");
        if ((int)me->query("force") < 50)
                return notify_fail("你的内力不够练「盘古九式」。\n");
        me->receive_damage("kee", 50);
        return 1;
}
string perform_action_file(string func)
{
return CLASS_D("chushi") + "/pangu-nine/" + func;
}
