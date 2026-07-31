// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// sanyin-zhua.c -三阴蜈蚣爪

#include <ansi.h>

inherit SKILL;

string *action_msg = ({
        "$N阴阴地笑了笑，伸手虚击$n的面门，趁$n全力招架之际，一转身，反手抓向$n的$l",
        "$N突然倒下装死，就在$n疑惑不定之间，猛然跃起，双手抓向$n的$l，$n大惊之下，不知所措",
        "$N扑地而倒，宛若一条蜈蚣，在地上快速爬了几步，绕到$n身后，一爪抓下",
        "尖叫声中，$N脸上隐隐泛出绿色，一显即逝，右爪猛地探向$n的$l",
        "$N轻轻的对着$n脸上吹了一口气，$n瞬间方寸大乱，$N借机连向$n胸前抓了数下",
        "$N绕着$n快速的转了几圈，暴喝一声，掌爪互逆，几道冷风从指端射出，袭向$n",
        "$N身影忽前忽後，身形飘忽不定，突然一转身左手往$n的$l拢去",
        "$N使出一招「抽髓手」，十指泛出隐隐的蓝色光芒，搭住$n身躯，有如附骨之蛆",
});
int valid_enable(string usage) { return usage == "claw" || usage == "parry"; }

int valid_combine(string combo) { return combo == "chousui-zhang"; }

int valid_learn(object me)
{
        
        int  nb,  nh;
        nb = (int)me->query_skill("poison", 1);
        nh = (int)me->query_skill("sanyin-zhua", 1);

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练三阴蜈蚣爪必须空手。\n");
                
        if ((int)me->query_skill("huagong-dafa", 1) < 10)
                return notify_fail("你的化功大法火候不够，无法学三阴蜈蚣爪。\n");
                
        if ( nb < 100 && nb <= nh )
                return notify_fail("你的毒技修为不够，无法提高三阴蜈蚣爪。\n");

        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练三阴蜈蚣爪。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))], 
                "force": 210 + random(60), 
                "attack": 50 - random(10), 
                "dodge" : 50 - random(10), 
                "parry" : 50 - random(10), 
                "damage_type" : random(2)?"瘀伤":"抓伤", 
        ]); 
}

int practice_skill(object me)
{
        int  nb,  nh; 
        nb = (int)me->query_skill("poison", 1); 
        nh = (int)me->query_skill("sanyin-zhua", 1); 

        if (nb < 100 && nb <= nh) 
                return notify_fail("你的毒技修为不够，无法提高三阴蜈蚣爪。\n"); 

        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力太低了。\n");
                
        if ((int)me->query("neili") < 50)
                return notify_fail("你的内力不够练三阴蜈蚣爪。\n");
                
        me->receive_damage("qi", 40);
        me->add("neili", -40);
        
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;
        int flvl;

        lvl  = me->query_skill("sanyin-zhua", 1);
        flvl = me->query("jiali");

        if (flvl * 2 + random(lvl) > victim->query_skill("force") &&
            victim->affect_by("xx_poison",
                              ([ "level" : flvl + random(flvl),
                                 "id"    : me->query("id"),
                                 "duration" : lvl / 100 + random(lvl / 10) ])))
        {
                return HIW "$n" HIW "只感一阵极寒从心底升起，看来是中了$N" HIW "抓上的剧毒。\n" NOR;
        }
}

string perform_action_file(string action)
{
        return __DIR__"sanyin-zhua/" + action;
}


