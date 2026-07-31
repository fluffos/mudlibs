// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// quanzhen-jian.c 全真剑法

#include <ansi.h>

inherit SKILL;

string *action_msg = ({
        "$N晃动$w，踏奇门，走偏锋，剑尖颤了几颤，一招巧妙无比的「分花拂柳」，似左实右，已点在$n$l",
        "$N使一招「琴心三叠」，身形向上飘起，手中$w虚虚实实幻出三点寒光射向$n$l",
        "$N身形绕$n一转，猛然一式「罡风扫叶」，将$w舞出满天剑影，挟着劲风向$n扫去",
        "$N仰天长笑，身形飘然而起，在半空中身子一旋，一式「狂歌痛饮」手中$w狂风般地击向$n的$l",
        "$N左手捏着剑诀，右足踏开一招“定阳针”向上斜刺，$w锵然跃出倏的化作几点星光射向$n的$l",
        "$N向前迈去一大步，使出「探海屠龙」，手中$w舞成一个光球，迅若奔雷击向$n的$l",
        "$N运力一抖$w，一时「马蹴落花」，$w幻出点点剑花，飘然刺向$n的$l",
        "$N手中$w一指，纵起丈余，一时「横行漠北」，$w雷霆般射向$n的$l",
        "$N大喝一声，一招「白虹经天」，$w闪电般划出一道大圆弧劈向$n的$l",
        "$N身形向上飘起，突然一转身，头下脚上，手握$w，一招「絮坠无声」，无声无息地攻向$n的$l",
        "$N手中$w一抖，一招「照破万缘」，$w逼出耀眼光芒，奋力击向$n",
        "$N忽然身形高高跃起，使出「浪迹天涯」，$w幻出漫天花瓣，迅如雷霆射向$n的$l",
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry" ; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 200)
                return notify_fail("你的内力不够，不能修习全真剑法 。\n");
                
        if ((int)me->query_skill("sword",1) < 40)
                return notify_fail("你的基本剑法不够，不能修习全真剑法。\n");
        /*                
        if ((int)me->query_skill("xiantian-gong", 1) < 40)
                return notify_fail("你的先天功火候太浅，不能修习全真剑法 。\n");
                
        if (me->query_skill_mapped("force") != "xiantian-gong")
                return notify_fail("你修习别派内功，不能修习全真剑法 。 \n");
        */                
        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))],
                "damage": 120 + random(40),
                "attack": 70 + random(10),
                "dodge" : 70 + random(10),
                "parry" : 70 + random(10),
                "damage_type" : random(2)?"刺伤":"割伤",
        ]);
}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon"))
        ||  (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
                
        if ((int)me->query("qi") < 80)
                return notify_fail("你的体力不够练全真剑法。\n");
                
        if ((int)me->query("neili") < 80)
                return notify_fail("你的内力不够练全真剑法。\n");
                
        me->receive_damage("qi", 70);
        me->add("neili", -70);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"quanzhen-jian/" + action;
}

