//Cracked by Kafei
//qinnashou.c  擒拿手
// arthurgu 1999/10

#include <ansi.h>
inherit SKILL;
//inherit F_CLEAN_UP;

// This function selects a random target for offensive spells/functions.
object offensive_target(object me)
{
	int sz;
	object *enemy;

	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	sz = sizeof(enemy);
	if( sz > 4 ) sz = 4;

	if( sz > 0 ) return enemy[random(sz)];
	else return 0;
}
string* buwei = ({
        "右手肘部",
        "手腕",
        "左手关节",
        "颈部",
        "肩部关节",
        "背心要穴",
        "膝关节",
        "命门"
});

mapping *action = ({
([      "action": "$N双眉一扬，双拳微微一顿，然后飞快的抓向$n的" + buwei[random(8)] + "",
        "dodge": 30,
        "force": 280,
        "damage": 180,
        "lvl" : 0,
        "damage_type" : "内伤"
]),
([      "action" : "$N施出擒拿绝技，一错身抓向$n的" + buwei[random(8)] + "",
        "force" : 300,
        "parry" : 5,
        "damage": 180,
        "lvl" : 10,
        "damage_type" : "内伤"
]),
([      "action": "$N闪开$n的攻击，一把抓向$n的" + buwei[random(8)] + "",
        "force" : 280,
        "parry" : 5,
        "damage": 280,
        "lvl" : 20,
        "damage_type" : "内伤"
]),
});

int valid_enable(string usage) { return  usage=="hand" || usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练擒拿手手必须空手。\n");
        return 1;
}


mapping query_action(object me, object weapon)
{
        int i, level;
        object victim;
        string bw;
        
        if( !victim && me->is_fighting() ) victim = offensive_target(me);
        level   = (int) me->query_skill("qinnashou",1);
        
        bw = buwei[random(sizeof(buwei))];
if (me && victim)
{
        if ((int) me->query_skill("qinnashou",1) > random(50) && level > random(240) && me->query("neili") > 300
        && random(me->query("combat_exp")) > victim->query("combat_exp")/2 && random(2)==0
         && me->query_skill_mapped("parry") == "qinnashou"
         && me->query_skill_mapped("hand") == "qinnashou"
         && !me->is_busy()
         && !victim->is_busy()
         && !me->query_temp("weapon")) {
                me->add("neili", -50);
                message_vision(HIC"$N用擒拿技斗然间抓住了$n的"+bw+"!\n"NOR,me,victim);
                message_vision(GRN"$N退避不及，被$n擒拿住"+bw+",行动不免迟缓下来。\n"NOR,victim,me);
                victim->start_busy(1 + random(level/50));
        }
}
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if (me->query_skill("qinnashou",1) < 99)
           return notify_fail("此项技能只能大于一百级时能学习。\n");

        if ((int)me->query("jing") < 100)
                return notify_fail("你的精力不够练此武功。\n");
        if ((int)me->query("qi") < 100)
                return notify_fail("你的体力不够练此武功。\n");
        if ((int)me->query("neili") < 100)
                return notify_fail("你的内力不够练此武功。\n");
        me->receive_damage("qi", 50);
        me->receive_damage("jing", 50);
        me->add("neili", -50);
        return 1;
}

