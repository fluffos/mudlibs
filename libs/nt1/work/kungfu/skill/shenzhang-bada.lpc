// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// shenzhang-bada.c - 神掌八打
       
inherit SHAOLIN_SKILL;
        
string *action_msg = ({
        "$N一招「横云断峰」左掌佯攻，右掌蓄势击向$n的$l",
        "$N飞身上前，双掌同时击出，一招「三羊开泰」，将$n笼罩于掌风之中",
        "$N一招「跨虎登山」，左掌长驱直进，迅雷般拍向$n的$l",
        "$N一招「龙跃深渊」，后退了一步，随后身形往后一个倒纵，右掌凌空拍向$n的$l",
        "$N一招「雁落平沙」，身体半蹲，双掌一扫，两道劲风击向$n的下盘",
        "$N一个转身，一招「玄鸟划抄」，右掌连拍，掌风分三路击向$n",
        "$N纵身而上，一招「盘龙绕步」，左掌一圈，右掌随即直拍向$n的胸口",
        "$N身体旋转起来，一招「威镇八方」，幻出无数掌影，同时击向$n",
});

int valid_enable(string usage) { return usage == "strike" || usage == "parry"; } 
     
int valid_combine(string combo) { return combo == "wuxiang-zhi"; } 
      
int valid_learn(object me) 
{ 
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon")) 
                return notify_fail("练神掌八打必须空手。\n"); 
      
        if ((int)me->query_skill("force") < 300) 
                return notify_fail("你的内功火候不够，无法学神掌八打。\n"); 
     
        if ((int)me->query("max_neili") < 3000) 
                return notify_fail("你的内力太弱，无法练神掌八打。\n"); 
      
        if ((int)me->query_skill("strike", 1) < (int)me->query_skill("shenzhang-bada", 1))
                return notify_fail("你的基本指法水平有限，无法领会更高深的神掌八打。\n"); 
      
        return 1; 
} 
      
mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))], 
                "force": 320 + random(60), 
                "attack": 50 + random(10), 
                "dodge" : 50 + random(10), 
                "parry" : 50 + random(10), 
                "damage_type" : random(2)?"内伤":"瘀伤", 
        ]); 
}
      
int practice_skill(object me) 
{ 
        if (me->query_temp("weapon") || 
            me->query_temp("secondary_weapon")) 
                return notify_fail("你必须空手练习！\n"); 
      
        if ((int)me->query("qi") < 60) 
                return notify_fail("你的体力太低了。\n"); 
      
        if ((int)me->query("neili") < 60) 
                return notify_fail("你的内力不够练神掌八打。\n"); 
      
        me->receive_damage("qi", 50); 
        me->add("neili", -50); 
        return 1; 
} 
      
string perform_action_file(string action) 
{ 
        return __DIR__"shenzhang-bada/" + action; 
} 
