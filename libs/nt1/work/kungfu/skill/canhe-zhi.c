// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// canhe-zhi.c 参合指

inherit SKILL;

#include <ansi.h>

string *xue_name = ({ 
        "劳宫穴","膻中穴","曲池穴","关元穴","曲骨穴","中极穴","承浆穴","天突穴","百会穴",
        "幽门穴","章门穴","大横穴","紫宫穴","冷渊穴","天井穴","极泉穴","清灵穴","至阳穴",
});

string *action_msg = ({
        "$N劲风激荡，双指错落搭置，一招「目不识丁」凶狠地向$n的$l插去",
        "$N大吼一声，十指上下分飞，一招「画龙点睛」，双指直取$n的$l",
        "$N十指互错，虚幻虚实，一招「扑朔迷离」，前后左右，瞬息间向$n攻出了六招",
        "$N身行腾空而起，一招「受宠若惊」，来势奇快，向$n的$l猛插下去",
        "$N身行一闪，若有若无捱到$n身前，一招「滔滔不绝」，插向$n的$l",
        "$N一招「退避三舍」，右手一拳击出，左掌化指，一掌一指凌空击向$n的$l",
        "$N双掌化指，指中带掌，双手齐推，一招「卧薪尝胆」，一股排山倒海的内力，直扑$n$l",
        "$N突然身行急转，一招「相煎何急」，十指飞舞，霎时之间将$n四面八方都裹住了",
        "$N默运神元神功，将内力聚于手指，平平淡淡毫无花俏地点向$n的膻中穴，已到反璞归真的境界",
        "$N凌空虚点数指，数道指风合成一股剑气，直攻向$n,剑气之凌厉不在六脉神剑之下",
});

string *xue2_name = ({
        MAG "$N默运神元神功，将内力聚于手指，平平淡淡毫无花俏地点向$n的膻中穴" NOR,
        YEL "$N两掌竖合，掌心微虚，如莲花之开放，接着双手食指轻轻一弹，两股指风同时袭向$n" NOR,
        WHT "$N凌空虚点数指，数道指风合成一股剑气，直向$n攻去"NOR,
        RED "$N缓缓举手，五指先是箕张，再缓缓拢指合拳，霎时生出气凝河岳般的剑气狂扬" NOR,
        HIR "$N指风犀利，似一道无形剑气，将$n笼罩于内，$n只觉胸口一痛，全身真气狂泻而出" NOR
});
        
int valid_combine(string combo)  
{
        /*
         object me = this_player();
         mapping myfam = (mapping)me->query("family");
         if (myfam["master_name"] == "慕容博")
         */
        return combo == "qixing-quan";
}

int valid_enable(string usage) { return usage == "finger" || usage == "parry"; }


int valid_learn(object me)
{
        if ((int)me->query("int") < 30)
                return notify_fail("你的悟性这么差劲，就不要强求了。\n");
        if ((int)me->query("dex") < 30)
                return notify_fail("你的身法太差了，无法学习参合指。\n");
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练参合指必须空手。\n");
        if ((int)me->query_skill("shenyuan-gong", 1) < 15)
                return notify_fail("你的神元功火候不够，无法学参合指。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练参合指。\n");
        if ((int)me->query_skill("finger", 1) < (int)me->query_skill("canhe-zhi", 1))
                return notify_fail("你的基本指法水平有限，无法领会更高深的参合指。\n");                
        return 1;
}

mapping query_action(object me, object weapon)
{        
        string name;   
        int i, level;
        level   = (int) me->query_skill("canhe-zhi", 1);
        name = xue2_name[random(sizeof(xue2_name))];

        if (random(level) >= 300)
        {
                return ([
                        "action": "" + name + "" NOR,
                        "damage_type": "刺伤",
                        "attack": 200,
                        "dodge" : 100,
                        "parry" : 100,
                        "force" : 500,
                ]);
        } else 
        {
                return ([
                        "action": action_msg[random(sizeof(action_msg))],
                        "force" : 330 + random(60),
                        "attack": 70 + random(10),
                        "dodge" : 70 + random(10),
                        "parry" : 70 + random(10),
                        "damage_type" : "刺伤",
                ]);
        }
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 80)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 80)
                return notify_fail("你的内力不够练参合指。\n");
        me->receive_damage("qi", 70);
        me->add("neili", -70);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"canhe-zhi/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        string name, weapon;
        name = xue_name[random(sizeof(xue_name))];
    
        if (victim->is_busy() || damage_bonus < 100) return 0;
        
        if (! objectp(weapon = me->query_temp("weapon"))) 
        {
                if ((me->query("neili") > 200) && random(me->query_skill("canhe-zhi", 1)) > 60)
                {
                        victim->start_busy(2);
                        me->add("neili",-30);
                        if (victim->query("neili") <= (damage_bonus / 2 + 30))
                                victim->set("neili", 0);
                        else
                                victim->add("neili", - damage_bonus / 2 + 30);
                                
                        return HIW "$N默运神元神功，指风轻飘飘地点向$n，一股内劲无声无息的绕向$n周身大穴！\n"
                               HIW "$n只觉全身一麻，已被一招点中「" HIR + name + HIW "」！\n" NOR;
                } 
        }
}

int difficult_level() 
{
        return 400;
}
