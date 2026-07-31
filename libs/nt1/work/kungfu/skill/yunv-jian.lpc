// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// yunv-jian.c 玉女剑

inherit SKILL;

string *action_msg = ({
        "$N一招「雁行斜击」，身形斜飞，手中$w轻轻点向$n的$l",
        "$N长跃而起，「白虹经天」，$w猛然下刺",
        "$N使出「浪迹天涯」，挥剑直劈，威不可当",
        "$N使「花前月下」一招自上而下搏击，模拟冰轮横空、清光铺地的光景",
        "$N手中$w颤动，如鲜花招展来回挥削，只幌得$n眼花撩乱，浑不知从何攻来",
        "$N使出「清饮小酌」剑柄提起，剑尖下指，有如提壶斟酒，直挥$n的$l",
        "$N手中$w由内自外一刺，左手如斟茶壶，使出「扫雪烹茶」来",
        "$N左掌横摆胸前，右手中$w轻轻挥拂，却是一招「抚琴按萧」",
        "$N一招「松下对弈」，$w自右向左挥一个大弧，刺向$n的$l",
        "$N左手如拂五弦，竟以掌为剑攻向$n，却是一招「池边调鹤」",
        "$N一招「柳絮风飘」，$w轻灵地划出几个圆弧，向$n的$l挥去",
        "$N一招「小园艺菊」，手中$w迅疾向$n的下盘连点三点",
        "$N使出「西窗夜话」，手中$w中宫直入，攻向$n的$l",
        "$N脚下左高右低，一招「柳荫联句」，$w在空中化成一道光环，急攻$n",
        "$N手中$w由下而上卷起，犹如打起竹帘一般，却是「竹帘临池」",
        "$N做搭弓射箭状，一招「木兰射雁」，右手$w直刺$n的$l",
        "$N左手剑诀一领，右手$w平平刺向$n的$l，是一招「双蝶迷回」",
        "$N手中$w合身疾刺，一招「孤云出釉」，直指$n的$l",
        "$N一招「幽兰空谷」，$w看似随意地一挥，从$n不可思议的角度攻入",
        "$N使出「茶花满路」，一时间空中尽是$w的影子，令$n不知如何抵挡",
        "$N一招「陌路采桑」，$w连点数点，疾刺$n的$l",
        "$N突然盘蹲下来，一招「秋雨萧萧」，$w自下而上刺向$n",
        "$N错开脚步，手中$w突然从自己的肋下刺出，却是一招「琴心剑胆」",
        "$N犹如在水面滑行一般，一招「池塘秋夜」，平平地向$n的$l挥去",
        "$N一招「皓腕玉镯」，手中$w刺点$n的手腕",
        "$N一招「牡丹含泪」，$w绕出数个银圈，平平地向$n的$l卷去",
        "$N左脚轻点地面，身形往前一扑，一招「芍药蕴珠」，$w向$n的$l刺去",
        "$N一招「檐前飞燕」，身形跃起，手中$w扫向$n的$l",
        "$N脸现黯然之色，随意一招「蒹葭苍苍」，$w刺向$n的$l",
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry")
; }

int valid_learn(object me)
{
        if ((int)me->query_skill("yunv-xinfa", 1) < 15)
                return notify_fail("你的玉女心法火候不到，无法学习玉女剑法。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))],
                "damage": 120 + random(40),
                "attack": 60 + random(10),
                "dodge" : 60 + random(10),
                "parry" : 60 + random(10),
                "damage_type" : random(2)?"刺伤":"割伤",
        ]);
}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 70)
                return notify_fail("你的体力不够练玉女剑法。\n");
        if ((int)me->query("neili") < 70)
                return notify_fail("你的内力不足以练玉女剑法。\n");
        me->receive_damage("qi", 60);
        me->add("neili", -60);
        
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yunv-jian/" + action;
}

int query_effect_parry(object attacker, object me) 
{ 
        object weapon; 
        int lvl; 
        
        if (! objectp(weapon = me->query_temp("weapon")) || 
            (string)weapon->query("skill_type") != "sword") 
                return 0; 
        
        lvl = me->query_skill("yunv-jian", 1); 
        if (lvl < 90)  return 0; 
        if (lvl < 100) return 50; 
        if (lvl < 125) return 55; 
        if (lvl < 150) return 60; 
        if (lvl < 175) return 65; 
        if (lvl < 200) return 70; 
        if (lvl < 225) return 75; 
        if (lvl < 250) return 80; 
        if (lvl < 275) return 90; 
        if (lvl < 325) return 100; 
        if (lvl < 350) return 110; 
        return 120; 
} 
