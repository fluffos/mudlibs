//tianmo-zhang.c 天魔掌法
//By haiyan

inherit SKILL; 

mapping *action =({
([      "action":"$N左脚一收，身体向左倾斜，右手使出一招「天魔伏法」，一掌拍向$n的$l。",
        "force" :40,
        "parry" :5,
        "dodge" :5,
        "damage":18,
        "lvl"   :0,
        "skill_name" :"天魔伏法",
        "damage_type":"瘀伤"
]),
([      "action":"$N一提真气，身子急拔，使出一招「分身化影」，幻出数个身影，拍向$n全身的各处要穴。",
        "force" :60,
        "parry" :10,
        "dodge" :10,
        "damage":20,
        "lvl"   :50,
        "skill_name" :"分身化影",
        "damage_type":"瘀伤"
]),
([      "action":"$N左跨一步，右跨一步，瞬间来到$n的面前，一招「魔天穹刹」，双掌内蕴真力，按向$n。",
        "force" :80,
        "parry" :20,
        "dodge" :20,
        "damage":32,
        "lvl"   :80,
        "skill_name" :"魔天穹刹",
        "damage_type":"瘀伤"
]),
([      "action":"$N使一招「柳阴路曲」，上身前躬，双掌各划了个半圆，齐齐拍向$n的$l。",
        "force" :100,
        "parry" :30,
        "dodge" :30,
        "damage":46,
        "lvl"   :100,
        "skill_name" :"柳阴路曲",
        "damage_type":"瘀伤"
]),
([      "action":"$N使出一招「枯木生华」，左手拍向右掌，牵动全身，向$n飞身扑击。",
        "force" :120,
        "parry" :30,
        "dodge" :40,
        "damage":60,
        "lvl"   :120,
        "skill_name" :"枯木生华",
        "damage_type":"瘀伤"
]),
([      "action":"$N纤腰一摆，陡然滑出数尺，右手顺势一招「魔影重重」往$n的$l拍去。",
        "force" :150,
        "parry" :40,
        "dodge" :50,
        "damage":75,
        "lvl"   :150,
        "skill_name" :"魔影重重",
        "damage_type":"内伤"
]),
([      "action":"$N使出「虚敲实应」，右掌上引，左掌由后而上，形成一股气流冲向$n",
        "force" :180,
        "parry" :50,
        "dodge" :60,
        "damage":100,
        "lvl"   :180,
        "skill_name" :"虚敲实应",
        "damage_type":"内伤"
]),
});

int valid_enable(string usage) { return usage == "strike" || usage == "parry"; }

int valid_learn(object me)
{
     if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
         return notify_fail("练天魔掌法必须空手。\n");

     if ((int)me->query_skill("riyue-xinfa", 1) < 100)
         return notify_fail("你的内功心法火候太浅，不能学天魔掌法。\n");

     if ((int)me->query_skill("strike", 1) < 80)
         return notify_fail("你的基本掌法火候不够。\n");

     if ((int)me->query("max_neili") < 300)
         return notify_fail("你的内力太低，无法学天魔掌法。\n");

     if ((int)me->query_skill("strike", 1) < (int)me->query_skill("tianmo-zhang", 1))
         return notify_fail("你的基本掌法水平有限，无法领会更高深的天魔掌法。\n");

     return 1;
}

string query_skill_name(int level)
{
     int i;
     for(i = sizeof(action)-1; i >= 0; i--)
     if(level >= action[i]["lvl"])
            return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
     int i, level;
     level = (int) me->query_skill("tianmo-zhang", 1);
     for(i = sizeof(action); i > 0; i--)
         if(level > action[i-1]["lvl"])
              return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
     if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
         return notify_fail("练天魔掌法必须空手。\n");

     if ((int)me->query("qi") < 80)
            return notify_fail("你的体力不够练天魔掌法。\n");

     if ((int)me->query("neili") < 70)
            return notify_fail("你的内力不够练天魔掌法。\n");

     me->receive_damage("qi", 65);
     me->add("neili", -55);
     return 1;
}

string perform_action_file(string action)
{
     return __DIR__"tianmo-zhang/" + action;
}

