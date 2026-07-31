// Xiangsi-sword.c 弹指相思剑
// Cracked by 凌惊雪 5-20-2003

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N使一招「情投意合」，手中$w如一条银蛇般刺向$n的$l",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//1
([      "action" : "$N使一招「情投意合」，手中$w如一条银蛇般刺向$n的$l",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//2
([      "action" : "$N使出弹指相思剑中的「朝朝暮暮」，剑光霍霍斩向$n的$l",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//3
([      "action" : "$N一招「痴心情长」，身形陡然滑出数尺，手中$w斩向$n的$l",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//4
([      "action" : "$N手中$w中宫直进，一式「生生世世」对准$n的$l刺出一剑",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//5
([      "action" : "$N纵身一跃，手中$w一招「此恨绵绵」对准$n的$l斜斜刺出一剑",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//6
([      "action" : "$N的$w凭空一指，一招「魂萦梦牵」刺向$n的$l",
        "dodge" : -50,
        "parry" : -50,
        "damage" : 100,
        "damage_type" : "刺伤",
]),
//7
([      "action" : "$N手中$w向外一分，使一招「往事如烟」反手对准$n$l一剑刺去",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//8
([      "action" : "$N横剑上前，身形一转手中$w使一招「黯然消魂」画出一道光弧刺向$n的$l",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//9
([      "action" : "$N使出「千里婵娟」，一时间空中尽是$w的影子，令$n不知如何抵挡",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//10
([      "action" : HIW"$N一招「弹指相思」，左手一弹指，右手$w"HIW"看似随意地一挥，从$n不可思议的角度攻入"NOR,
        "dodge" : -80,
        "parry" : -80,
        "damage" : 150,
        "force" : 80,
        "damage_type" : "刺伤",
]),
([      "action" : HIB"
$N面色凄然，神色十分激动，眼中泪珠滚动，手中$w"HIB"疾舞不停，全身都已笼罩
在迫人的剑气中，$n不由骇然，只见$N身形微变，无数道剑气已逼向$n的$l"NOR,
        "dodge" : -80,
        "parry" : -80,
        "damage" : 120,
        "force" : 60,
        "damage_type" : "刺伤",
]),
});


int valid_enable(string usage) 
	{ 
		return (usage == "sword") || (usage == "parry"); 
	}

int valid_learn(object me)
{
        if (me->query("chushi/chushi_pansidong") != "yes" )
                return notify_fail("你没有领悟「弹指相思剑」的窍门。\n");
        if ((int)me->query("max_force") < 1000)
                return notify_fail("你的内力太弱，无法练「弹指相思剑」。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
	int i = me->query_temp("pfm-tanzhi");
	if( !me->query_temp("pfm-tanzhi") ) {
        return action[random(sizeof(action))];
	}
	else
	{
	return action[i];
	}
}

int practice_skill(object me)
{
        if (me->query("chushi/chushi_pansidong") != "yes" )
                return notify_fail("你没有领悟「弹指相思剑」的窍门。\n");
        if ((int)me->query("kee") < 60)
                return notify_fail("你的体力不够练「弹指相思剑」。\n");
        if ((int)me->query("force") < 50)
                return notify_fail("你的内力不够练「弹指相思剑」。\n");
        me->receive_damage("kee", 50);
        return 1;
}
string perform_action_file(string func)
{
return CLASS_D("chushi") + "/xiangsi-sword/" + func;
}
