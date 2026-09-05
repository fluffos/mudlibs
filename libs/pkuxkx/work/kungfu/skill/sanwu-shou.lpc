// 三无三不手,神雕李莫愁用的
//  zine
inherit SKILL;
#include <ansi.h>
mapping *action = ({
([      "action" : "$N这一招“无孔不入”，乃是向敌人周身百骸进攻，虽是一招，其实千头万绪，一招之中包含了数十招，竟是同时点$n全身各处大穴",
        "force" : 200,
        "dodge" : -5,
        "parry" : 10,
        "lvl" : 0,
        "skills_name" : "无孔不入",
        "damage_type" : "抓伤"
]),
([      "action" : "$N跟着一招“无所不至”。这一招点的$n周身诸处偏门穴道",
        "force" : 240,
        "dodge" : 0,
        "parry" : -5,
        "lvl" : 10,
        "skills_name" : "无所不至",
        "damage_type" : "抓伤"
]),
([      "action" : "$N“三无三不手”的第三手“无所不为”立即使出。这一招不再点穴，专打$n眼睛、咽喉、小腹、下阴等人身诸般柔软之处",
        "force" : 280,
        "dodge" : 10,
        "parry" : 10,
        "lvl" : 20,
        "skills_name" : "无所不为",
        "damage_type" : "震伤"
]),
});


mapping *action2 = ({
([      "action" : HIW"$N"+HIW+"这一招“无孔不入”，乃是向敌人周身百骸进攻，虽是一招，其实千头万绪，一招之中包含了数十招，竟是同时点$n"+HIW+"全身各处大穴"NOR,
        "force" : 250,
        "dodge" : 25,
        "parry" : 20,
        "lvl" : 0,
        "skills_name" : "无孔不入",
        "damage_type" : "抓伤"
]),
([      "action" : HIW"$N"+HIW+"跟着一招“无所不至”。这一招点的$n"+HIW+"周身诸处偏门穴道"NOR,
        "force" : 280,
        "dodge" : 30,
        "parry" : 15,
        "lvl" : 30,
        "skills_name" : "无所不至",
        "damage_type" : "抓伤"
]),
([      "action" : HIW"$N"+HIW+"“三无三不手”的第三手“无所不为”立即使出。这一招不再点穴，专打$n"+HIW+"眼睛、咽喉、小腹、下阴等人身诸般柔软之处"NOR,
        "force" : 295,
        "dodge" : 15,
        "parry" : 35,
        "lvl" : 60,
        "skills_name" : "无所不为",
        "damage_type" : "震伤"
]),
});

mapping *action3 = ({
([      "action" : CYN"$N"+CYN+"这一招“无孔不入”，乃是向敌人周身百骸进攻，虽是一招，其实千头万绪，一招之中包含了数十招，竟是同时点$n"+CYN+"全身各处大穴"NOR,
        "force" : 300,
        "dodge" : 80,
        "parry" : 10,
        "lvl" : 0,
        "skills_name" : "无孔不入",
        "damage_type" : "抓伤"
]),
([      "action" : CYN"$N"+CYN+"跟着一招“无所不至”。这一招点的$n"+CYN+"周身诸处偏门穴道"NOR,
        "force" : 340,
        "dodge" : 50,
        "parry" : 25,
        "lvl" : 30,
        "skills_name" : "无所不至",
        "damage_type" : "抓伤"
]),
([      "action" : CYN"$N"+CYN+"“三无三不手”的第三手“无所不为”立即使出。这一招不再点穴，专打$n"+CYN+"眼睛、咽喉、小腹、下阴等人身诸般柔软之处"NOR,
        "force" : 280,
        "dodge" : 90,
        "parry" : 50,
        "lvl" : 60,
        "skills_name" : "无所不为",
        "damage_type" : "震伤"
]),
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }

int valid_combine(string combo) { return combo=="chilian-shenzhang"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练三无三不手必须空手。\n");
        if ((int)me->query_skill("yunu-xinfa", 1) < 50)
                return notify_fail("你的玉女心法火候不够，不能学三无三不手。\n");
        if ((int)me->query_skill("force", 1) < 50)
                return notify_fail("你的基本内功火候不够，不能学三无三不手。\n");
        if ((int)me->query("neili") < 1000)
                return notify_fail("你的内力太弱，练不了三无三不手。\n");
        me->add("neili",-20);
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
        level   = (int) me->query_skill("sanwu-shou",1);
        if (level>500)
        return action3[random(sizeof(action3))];
        if (level>200)
        return action2[random(sizeof(action2))];
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
        
}

int practice_skill(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练三无三不手必须空手。\n");
        if ((int)me->query_skill("yunu-xinfa", 1) < 50)
                return notify_fail("你的玉女心法火候不够，不能学三无三不手。\n");
        if ((int)me->query_skill("force", 1) < 50)
                return notify_fail("你的基本内功火候不够，不能学三无三不手。\n");
        if ((int)me->query("neili") < 1000)
                return notify_fail("你的内力太弱，练不了三无三不手。\n");
        if ((int)me->query("qi") < 600)
                return notify_fail("你的体力太弱，练不了三无三不手。\n");
        me->add("neili",-20);
        me->receive_damage("qi", 10);
        return 1;
}
 

string perform_action_file(string action)
{
        return __DIR__"sanwu-shou/" + action;
}
