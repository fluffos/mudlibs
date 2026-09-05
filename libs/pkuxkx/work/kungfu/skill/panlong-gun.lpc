// panlong-gun.c 太祖盘龙棍
// Modified by Venus Oct.1997
// Zine 2013
inherit SKILL;
#include <ansi.h>

string *dodge_msg = ({
    "$n右脚轻轻一点跃开躲过了$N的攻击。\n",
    "$n向旁边扑出，顺势一滚，闪到一边。\n",
    "$n斜里冲前一步，棍尖一点，$N这一招落到空处。\n",
    "$n忽然直身飞入半空，很久也不见人影，半响后竟闪到了$N的背后。\n",
    "$n突然一个急转身，$N的这一招滑到了一边。\n",
});

mapping *action2 = ({
([  "action" : HIY"$N斜里冲前一步，一招『进步短刺』，手中$w"+HIY+"刺向$n的$l"NOR,
    "damage": 385,
    "dodge" : 55,
    "damage_type" : "挫伤"
]),
([  "action" : HIY"$N忽然直身飞入半空，很久也不见人影，$n正搜寻间，$N已
飞身扑下，『毒蛇出洞』，$w"+HIY+"攻向$n的$l"NOR,
    "damage": 440,
    "dodge" : 50,
    "damage_type" : "挫伤"
]),
([  "action" : HIY"$N原地一个后滚翻，却在落地的一刹那，身体向$n平飞过
去，手中$w"+HIY+"指向$n的$l，好一招『野马跳涧』"NOR,
    "damage": 385,
    "dodge" : 66,
    "damage_type" : "挫伤"
]),
([  "action" : HIY"$N突然一个急转身，一式『罗汉撞钟』，$w"+HIY+"横扫一圈后挟着猛烈的劲道打向$n的$l"NOR,
    "damage": 495,
    "dodge" : 82,
    "damage_type" : "挫伤"
]),
([  "action" : HIY"$N向前扑出，顺势一滚，接着翻身跳起使一招『箭舌通天』，手里$w"+HIY+"斜向上击
向$n的$l"NOR,
    "damage": 440,
    "dodge" : 72,
    "damage_type" : "挫伤"
]),
([  "action" : HIY"$N手里$w"+HIY+"高举，一招『力劈华山』向$n的$l劈去"NOR,
    "damage": 380,
    "dodge" : 72,
    "damage_type" : "挫伤"
])
});  //给朝廷封王的招式奖励，加上颜色，每招威力上浮10%,Zine Nov 5 2010

mapping *action = ({
([  "action" : "$N斜里冲前一步，一招『进步短刺』，手中$w刺向$n的$l",
    "damage": 350,
    "dodge" : 50,
    "damage_type" : "挫伤"
]),
([  "action" : "$N忽然直身飞入半空，很久也不见人影，$n正搜寻间，$N已
飞身扑下，『毒蛇出洞』，$w攻向$n的$l",
    "damage": 400,
    "dodge" : 45,
    "damage_type" : "挫伤"
]),
([  "action" : "$N原地一个后滚翻，却在落地的一刹那，身体向$n平飞过
去，手中$w指向$n的$l，好一招『野马跳涧』",
    "damage": 350,
    "dodge" : 60,
    "damage_type" : "挫伤"
]),
([  "action" : "$N突然一个急转身，一式『罗汉撞钟』，$w横扫一圈后挟着猛烈的劲道打向$n的$l",
    "damage": 450,
    "dodge" : 75,
    "damage_type" : "挫伤"
]),
([  "action" : "$N向前扑出，顺势一滚，接着翻身跳起使一招『箭舌通天』，手里$w斜向上击
向$n的$l",
    "damage": 400,
    "dodge" : 65,
    "damage_type" : "挫伤"
]),
([  "action" : "$N手里$w高举，一招『力劈华山』向$n的$l劈去",
    "damage": 340,
    "dodge" : 50,
    "damage_type" : "挫伤"
])
});

int valid_enable(string usage){return usage=="staff" || usage=="parry" || usage == "dodge"; }

int valid_learn(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("max_neili") < 100)
   return notify_fail("你的内力太弱，无法练习太祖盘龙棍。\n");
    return 1;
}

mapping query_action(object me, object weapon)
{
    if (me->query("chaoting/wang")||me->query("chaoting/jiawang"))
    {
        return action2[random(sizeof(action2))];
    }
    else
    {
        return action[random(sizeof(action))];
    }
}

string query_dodge_msg(string limb)
{
    return dodge_msg[random(sizeof(dodge_msg))];
}

string perform_action_file(string action)
{
        return __DIR__"panlong-gun/" + action;
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("你使用的武器不对。\n");

    if ((int)me->query("qi") < 30)
   return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 20)
   return notify_fail("你的内力不够练太祖盘龙棍。\n");
    me->receive_damage("qi", 20);
    return 1;
}


