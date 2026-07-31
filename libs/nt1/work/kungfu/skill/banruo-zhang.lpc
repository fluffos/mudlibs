// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// banruo-zhang.c 般若掌

#include <ansi.h>

inherit SHAOLIN_SKILL;

string *action_msg = ({
        "$N前腿踢出，后腿脚尖点地，一式「横空出世」，二掌直出，攻向$n的上中下三路",
        "$N左掌划一半圆，一式「长虹贯日」，右掌斜穿而出，疾拍$n的胸前大穴",
        "$N使一式「云断秦岭」，右掌上引，左掌由后而上一个甩劈，斩向$n的$l",
        "$N左掌护胸，右拳凝劲后发，一式「铁索拦江」，缓缓推向$n的$l",
        "$N使一式「狂风卷地」，全身飞速旋转，双掌一前一后，猛地拍向$n的胸口",
        "$N合掌抱球，猛吸一口气，一式「怀中抱月」，双掌疾推向$n的肩头",
        "$N向上高高跃起，一式「高山流水」，居高临下，掌力笼罩$n的全身",
        "$N使一式「摘星换斗」，劲气弥漫，双掌如轮，一环环向$n的$l斫去",
        "$N两掌上下护胸，一式「翻江搅海」，骤然化为满天掌雨，攻向$n",
        "$N一式「金刚伏魔」，双手合十，对着$n微微一揖，全身内劲如巨浪般汹涌而出",
});

int valid_enable(string usage) { return usage == "strike" ||  usage == "parry"; }

int valid_combine(string combo) { return combo == "yizhi-chan"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练般若掌必须空手。\n");

        if ((int)me->query_skill("force") < 30)
                return notify_fail("你的内功火候不够，无法练般若掌。\n");

        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练般若掌。\n");

        if ((int)me->query_skill("strike", 1) < (int)me->query_skill("banruo-zhang", 1))
                return notify_fail("你的基本掌法火候水平有限，无法领会更高深的般若功。\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        string *msg = ({
                "喝道：“吃我一掌！”",
                "双手合什，说道：“阿弥陀佛！”",
                "说道：“罪过罪过！”这四字一出口，忽地",
                "",
        });

        level = (int)me->query_skill("banruo-zhang", 1);
        if (me->query_temp("sl_perform/san"))
        {
                i = me->query_skill("force") + level;
                return([      
                        "action": HIW"$N"+ msg[random(sizeof(msg))] +"双掌自外向里转了个圆圈，缓缓向$n推了过来。\n"
                                        "$P掌力未到，$n已感胸口呼吸不畅，顷刻之间，$N的掌力如怒潮般汹涌而至！"NOR,         
                        "force" : i + random(i),
                        "dodge" : 100,
                        "parry" : 100,
                        "attack": 200,
                        "damage_type" : "瘀伤", ]);
        }
        return ([
                "action": action_msg[random(sizeof(action_msg))], 
                "force": 320 + random(120), 
                "attack": 50 + random(10), 
                "dodge" : 50 + random(10), 
                "parry" : 50 + random(10), 
                "damage_type" : random(2)?"内伤":"瘀伤", 
        ]); 
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 60)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 60)
                return notify_fail("你的内力不够练般若掌。\n");

        if( (int)me->query_skill("nianhua-zhi", 1) < 150 )
                return notify_fail("你的拈花指修为还不够。\n");

        me->receive_damage("qi", 50);
        me->add("neili", -50);
        return 1;
}

void skill_improved(object me)
{
        int level = (int)me->query_skill("banruo-zhang", 1);

        if (level >= 180
        &&  (int)me->query_skill("yizhi-chan", 1) >= 180
        &&  ! me->query("sl_gifts/yzc") ) {
                me->add("con", 1);
                me->set("sl_gifts/yzc", 1);
                tell_object(me, "\n你的一指禅和般若掌学有所成，提高了你的根骨。\n");
        }

        if( !(level % 10) && level >= (int)me->query_skill("force", 1) ) {
                me->improve_skill("force", (level - 5), 1);
                tell_object(me, "\n你在般若掌方面的造诣增进了你的基本内功修为。\n");
        }

        /*
        if( !(level % 10) && level >= (int)me->query_skill("hunyuan-yiqi", 1) ) {
                me->improve_skill("hunyuan-yiqi", (level - 5)/2, 1);
                tell_object(me, "\n你在般若掌方面的造诣增进了你的混元一气功修为。\n");
        }              
        */
}

string perform_action_file(string action)
{
        return __DIR__"banruo-zhang/" + action;
}

