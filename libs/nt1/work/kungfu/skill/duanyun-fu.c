// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// duanyun-fu.c 断云斧

inherit SKILL;

string *action_msg = ({
        "$N蓦地腾空跃起，双手紧握$w，对准$n的头顶，自上而下地砍了下去，只在半空中留下一团巨大的黑影",
        "$N突然发一声喊，冲前两步，手中$w由下而上反撩$n下三路，$n见到一道淡黄色的气影逼向自己，情知不妙，急忙招架",
        "$N忽然虎吼一声，闪身斜向左前方冲出一步，身体微晃，手中$w在空中划出一道淡影，急速横扫$n的右肩，气势迫人",
        "$N突然抽身向右滚倒，随即跳起，就在跳起的一瞬间，已单臂握着$w砸向$n的左肋，出手既快且狠",
        "$N双手横举$w，平扫$n前胸，招式未使老就已打住猝然变招，斧尖直撞$n的小腹，",
        "$N不急不缓地转身微蹲，$n见$N露出破绽，急忙抢攻，却突然发现$N的身体已转过来，手中$w正迅猛地扫向自己的下盘",
        "$N身形微动，就在同一时间自上中下左右砍出五斧，$n见五把$w从不同的方位砍向自己，一时间竟不知该如何招架",
        "$N前脚猛地往地上一顿，大地也微微一震，接着举起斧头在头顶急转数圈，$w就隐含风云之声平直而沉稳地袭向$n，\n"
        "$n无论向何处闪躲，总看见斧尖离自己不到一尺，不由大惊失色",
});

int valid_enable(string usage) { return usage == "axe" ||  usage == "parry"; }      

int valid_learn(object me)
{
        if ((int)me->query_skill("force", 1) < 20)
                return notify_fail("你的内功心法火候不够，无法学断云斧。\n");
        if ((int)me->query("max_neili") < 150)
                return notify_fail("你的内力太弱，无法练断云斧。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))], 
                "force": 260 + random(50), 
                "attack": 40 + random(10), 
                "dodge" : 40 + random(10), 
                "parry" : 40 + random(10), 
                "damage_type" : "砍伤", 
        ]); 
}

int practice_skill(object me)
{
        object weapon;
    
        if (!objectp(weapon = me->query_temp("weapon"))
        ||  (string)weapon->query("skill_type") != "axe")
                return notify_fail("你使用的武器不对。\n");    

        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力太低了。\n");
                
        if ((int)me->query("neili") < 50)
                return notify_fail("你的内力不够练断云斧。\n");
                
        me->receive_damage("qi", 40);
        me->add("neili", -40);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"duanyun-fu/" + action;
}


