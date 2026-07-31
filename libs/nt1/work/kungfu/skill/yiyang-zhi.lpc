// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// yiyang-zhi.c

#include <ansi.h>

inherit SKILL;

string *xue_name = ({ 
        "劳宫穴","膻中穴","曲池穴","关元穴","曲骨穴","中极穴","承浆穴","天突穴","百会穴",
        "幽门穴","章门穴","大横穴","紫宫穴","冷渊穴","天井穴","极泉穴","清灵穴","至阳穴",
}); 

string *action_msg = ({
        "$N身形向后飘出，左掌护胸，右手食指向前遥遥一挥，正是一招「鲁阳返日」",
        "$N一式「无声无色」，施施然向前踏上半步，稍一侧身，右手拇指无声无息地点向$n的$l",
        "$N面带微笑，左手食指若有若无、右手食指劲气逼人向着$n交叉点出，一式「双树枯荣」深得禅机",
        "$N“嚯”地冲到$n的跟前，左手无名指一反一复连点两下，旋即退开，正是一式「阴阳交错」",
        "$N身形陡然向上拔起，双手急点数下，一式「烈日骄阳」已将$n的全身要穴罩在指风之下",
        "$N吸气凝神，右手握住左腕，左手凭空出指，“哧”的一声指力破空点向$n，好一招「丹凤朝阳」！",
        "$N一式「非假非空」，双手低垂缩在袖中，小拇指轻出，$n正迟疑时，突觉两道凌厉劲气破空而至",
        "$N脚下不丁不八站好，右手食指三曲三伸，指上劲力四溢，是一式「三阳开泰」遥点$n的$l",
});

int valid_enable(string usage) { return usage == "finger" || usage == "parry"; }

int valid_learn(object me)
{
        if (me->query("gender") == "女性" && me->query_str() < 27)
                return notify_fail("你由于先天体质所限，无法修习一阳指。\n");
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练一阳指必须空手。\n");
        if ((int)me->query_skill("kurong-changong", 1) < 80) 
                return notify_fail("你的枯荣禅功火候不够，无法学一阳指。\n");
        if ((int)me->query("max_neili") < 500)
                return notify_fail("你的内力太弱，无法练一阳指。\n");
        if ((int)me->query_skill("finger", 1) <80)
                return notify_fail("你的基本指法火候不够，无法学一阳指。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))],
                "force" : 320 + random(120),
                "attack": 70 + random(10),
                "dodge" : 70 + random(10),
                "parry" : 70 + random(10),
                "damage_type" : "刺伤",
        ]);        
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 80)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 80)
                return notify_fail("你的内力不够练一阳指。\n");
        me->receive_damage("qi", 70);
        me->add("neili", -70);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yiyang-zhi/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        string name, weapon;
        mixed result;
        name = xue_name[random(sizeof(xue_name))];
    
        if (random(me->query_skill("yiyang-zhi", 1)) > 80
        &&  me->query("neili") > 200)
        {
                if (! random(2))
                {
                        result = ([ "damage" : damage_bonus / 2 ]);
                        me->add("neili", -50);
                        victim->set("neili", 0);
                        result += ([ "msg" : CYN "紧接着$N食指一曲一弹,一道指力破空而出,正点中$n的" RED + name + 
                                             CYN "，真气立时涣散！\n" NOR ]);
                        return result;
                } else
                if (! random(2) == 1)
                {
                        result = ([ "damage" : damage_bonus ]);
                        me->add("neili", -30);  
                        result += ([ "msg" : CYN "紧接着$N食指一曲一弹,一道指力破空而出,正点中$n的" RED + name +
                                             CYN "，$n深受重伤！\n" NOR ]);
                }
        }
}

int query_effect_parry(object attacker, object me)
{
        int lvl;

        if (objectp(me->query_temp("weapon")))
                return 0;

        lvl = me->query_skill("yiyang-zhi", 1);
        if (lvl < 80)  return 0;
        if (lvl < 200) return 50;
        if (lvl < 280) return 80;
        if (lvl < 350) return 100;
        return 120;
}
