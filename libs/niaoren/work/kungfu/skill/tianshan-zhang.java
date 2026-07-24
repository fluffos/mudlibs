// tianshan-zhang.c 天山杖法, based on dagou-bang.c
// modified by Venus Oct.1997
// by yucao

inherit SKILL;

mapping *action = ({
([      "action": "$N使出一招「冰河開凍」，手中$w大開大闔掃向$n的$l",
    "dodge": -3,
    "damage": 40,
    "damage_type": "挫傷"
]),
([      "action": "$N手中$w陣陣風響，一招「山風凜冽」向$n的$l攻去",
    "dodge": -5,
    "damage": 45,
    "damage_type": "挫傷"
]),
([      "action": "$N舉起$w，居高臨下使一招「天山雪崩」砸向$n的$l",
    "dodge": -10,
    "damage": 60,
    "damage_type": "挫傷"
]),
([      "action": "$N一招「峰回路轉」，$w左右迂回向$n的$l點去",
    "dodge": -5,
    "damage": 50,
    "damage_type": "挫傷"
]),
});

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry")
; }

int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 80)
   return notify_fail("你的內力不夠。\n");
    return 1;
}

int practice_skill(object me)
{
    object weapon;

    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "staff")
   return notify_fail("你使用的武器不對。\n");
    if ((int)me->query("qi") < 50)
   return notify_fail("你的體力不夠練天山杖法。\n");
    me->receive_damage("qi", 25);
    return 1;
}

