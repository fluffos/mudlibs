// 综合搏击 Zine 巫师专用

#include <ansi.h>

inherit FORCE;

string check() { return "force"; }

mapping *action = ({
([      "action": "$N劲由心生，双腿以不可思议的角度像$n踢出",
        "dodge": 15000,
        "parry": 20000,
        "force": 30000,
        "lvl" : 0,
        "damage": 20000,
        "damage_type": "内伤"
]),
([      "action":"$N猛喝一声，双掌切向$n颈部",
        "parry": 15000,
        "force": 38000,
        "lvl" : 0,
        "damage": 30000,
        "damage_type": "内伤"
]),
([      "action":"$N蹲下身子，又猛然跃起，一个膝撞砸向$n",
        "dodge": 25000,
        "force": 40000,
        "lvl" : 0,
        "damage": 40000,
        "damage_type": "内伤"
]),
([      "action":"$N飞身跃起，一个头槌撞向$n",
        "dodge": 35000,
        "force": 45000,
        "lvl" : 0,
        "damage": 30060,
        "damage_type": "瘀伤"
]),
([      "action":"$N一记直拳毫不讲理地砸向$n",
        "dodge": 20000,
        "force": 50000,
        "lvl" : 0,
        "damage": 40000,
        "damage_type": "瘀伤"
]),
([      "action":"$N一记手刀砍向$n太阳穴",
        "dodge": 10000,
        "force": 55000,
        "lvl" : 0,
        "damage": 50000,
        "damage_type": "内伤"
]),
});



mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
       
}
int valid_enable(string usage)
{
        return usage=="throwing" || usage=="parry" || usage=="force" || usage=="strike" || usage=="hand" || usage=="dodge" || usage=="dagger" ||usage=="sword"|| usage=="blade"|| usage=="staff";
}

int valid_learn(object me)
{
        
        if ( !wizardp(me))
                return notify_fail("只有巫师能用这个技能。\n");
}

int practice_skill(object me)
{
        return notify_fail("只有巫师能用这个技能。\n");
}
string exert_function_file(string func)
{
        return __DIR__"boxing/" + func;
}
string perform_action_file(string action)
{
        return __DIR__"boxing/" + action;
}

string *parry_msg = ({
	"$n将手一挥，格开了$N的$w。\n",
        "只听见「锵」一声，被$p格开了。\n",
        
});