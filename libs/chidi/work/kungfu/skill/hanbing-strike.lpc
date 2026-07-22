// hanbing-strike.c   烈焰寒冰掌
// by jacki(97.7.24)
// Modified by Venus Oct.1997

inherit SKILL;

mapping *action = ({
([  "action": "$N双掌一错，一招「风起云涌」，狂风般扫向$n的$l",
    "dodge": 30,
    "force": 200,
//      "poison": 80,
    "damage_type": "瘀伤"
]),
([  "action": "$N一招「风雪满天」，身形突然旋转起来扑向$n，双掌拍向$n的$l", 
    "dodge": 40,
    "force": 240,
//      "poison": 60,
    "damage_type": "瘀伤"
]),
([  "action": "$N将寒毒运至左手，一招「万里雪飘」，迅疾无比地抓向$n的$l",   
    "dodge": 50,
    "force": 280,
//      "poison": 100,
    "damage_type": "瘀伤"
]),
([  "action": "$N后退一步，突然一招「千里冰封」，掌挟奇寒之气拍向$n的$l",   
    "dodge": 60,
    "force": 300,
//      "poison": 80
    "damage_type": "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }   

mapping query_action(object me)
{
    if (random(me->query_skill("unarmed",1)) > 60 &&
   me->query_skill("force",1) > 50 &&
   me->query("neili") > 100 ) {
   me->add("neili", -100);
   return ([
   "action": "$N奋起全身之力，一招「烈焰寒冰」，凌厉无比地击向$n",
   "force": 350,
   "damage_type": "瘀伤"]);
    }
    return action[random(sizeof(action))];
}

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
   return notify_fail("练烈焰寒冰掌必须空手。\n");
    if ((int)me->query_skill("xuantian-force", 1) < 20)
   return notify_fail("你的玄天气功火候不够，无法练烈焰寒冰掌。\n")
;
    if ((int)me->query("max_neili") < 60)
   return notify_fail("你的内力太弱，无法练寒冰掌");
    return 1;
}


int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
   return notify_fail("你的体力太低了，先休息一下吧。\n");
    if ((int)me->query("neili") < 8)
   return notify_fail("你的内力不够练寒冰掌。\n");
    if (me->query_skill("hanbing-strike", 1) < 50)
   me->receive_damage("qi", 20);
    else
   me->receive_damage("qi", 30);
    me->add("neili", -5);
    return 1;
}

