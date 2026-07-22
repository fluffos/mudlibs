// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// lieyan-dao.c 烈焰刀

inherit SKILL;

string *action_msg = ({
        "$N一招「黑龙现身」，$w有如一条黑龙在$n的周身旋游，勿快勿慢，变化若神",
        "$N一招「万水千山」，左右腿一前一后，$w乱披风势向$n的$l斩去",
        "$N纵身跃落，一招「横扫千里」，$w带着疾风呼的一声便向$n横扫过去",
        "$N一招「左右开弓」，$w大开大阖，左右并进，左一刀，右一刀向$n的两肩砍落",
        "$N手中$w自上而下，一招「百丈飞瀑」，刀光流泻，如一片雪白瀑布砍向$n的头部",
        "$N挥舞$w，使出一招「直摧万马」，上劈下撩，左挡右开，如千军万马般罩向$n",
        "$N带得刀风劲疾，一招「怪蟒翻身」，一个猛转身，连刀带人往$n的$l的劈去",
        "$N向前一个弓步，一招「上步劈山」，$w直直的劈出，一片流光般的刀影向$n的全身罩去",
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("shenghuo-shengong", 1) < 20)
                return notify_fail("你的圣火神功火候太浅。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))],
                "damage": 120 + random(30),
                "attack": 60 - random(10),
                "dodge" : 60 - random(10),
                "parry" : 60 - random(10),
                "damage_type" : "割伤",
        ]);
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够练烈焰刀。\n");
        if ((int)me->query("neili") < 50)
                return notify_fail("你的内力不够练烈焰刀。\n");
        me->receive_damage("qi", 40);
        me->add("neili", -40);
        return 1;
}

