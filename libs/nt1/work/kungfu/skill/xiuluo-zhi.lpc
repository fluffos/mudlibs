// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

inherit SHAOLIN_SKILL;
        
string *action_msg = ({
        "$N左手一个虚晃，右指跟进，一招「割肉饲鹰」，右指击向$n的$l",
        "$N揉身而上，随后身形一矮，一式「投身饿虎」,试图拿住$n的周身大穴",
        "$N面露凶光，一式「斫头谢天」,手指直击向$n的百汇大穴",
        "$N摒指如刀，一招「折骨出髓」,双指划出一条刀路砍向$n的腰部",
        "$N忽然左腾右纵，双指连点，一招「挑身千灯」，一时间无数道劲气同时击向$n",
        "$N提起身形，一招「挖眼布施」,居高临下，以讯雷不及掩耳的速度功向$n",
        "$N双指分左右两路，一招「剥皮书经」，分别点向$n两处大穴，令$n措不及防",
        "$N一招「剜心决志」，一指对准自己，随后就地一个翻滚，右手食指戳向$n的$l",
        "$N一招「刺血满地」，双手十指连弹，一时间无数道劲气如潮水般涌向$n，令$n无从躲闪",
});

int valid_enable(string usage) { return usage == "finger" || usage == "parry"; } 
      
int valid_learn(object me) 
{ 
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon")) 
                return notify_fail("练修罗指必须空手。\n"); 
      
        if ((int)me->query_skill("force") < 200) 
                return notify_fail("你的内功火候不够，无法学修罗指。\n"); 
     
        if ((int)me->query("max_neili") < 800) 
                return notify_fail("你的内力太弱，无法练修罗指。\n"); 
      
        if ((int)me->query_skill("finger", 1) < (int)me->query_skill("xiuluo-zhi", 1))
                return notify_fail("你的基本指法水平有限，无法领会更高深的修罗指。\n"); 
      
        return 1; 
} 
      
mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))],
                "force" : 260 + random(60),
                "attack": 40 + random(10),
                "dodge" : 40 + random(10),
                "parry" : 40 + random(10),
                "damage_type" : "刺伤",
        ]);        
}
      
int practice_skill(object me) 
{ 
        if (me->query_temp("weapon") || 
            me->query_temp("secondary_weapon")) 
                return notify_fail("你必须空手练习！\n"); 
      
        if ((int)me->query("qi") < 50) 
                return notify_fail("你的体力太低了。\n"); 
      
        if ((int)me->query("neili") < 50) 
                return notify_fail("你的内力不够练修罗指。\n"); 
      
        me->receive_damage("qi", 40); 
        me->add("neili", -40); 
        return 1; 
} 
      
string perform_action_file(string action) 
{ 
        return __DIR__"xiuluo-zhi/" + action; 
} 


