// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// huagu-mianzhang 化骨绵掌

#include <ansi.h>

inherit SKILL;

string *action_msg = ({
        "$N身形微晃，一招「长恨深入骨」，十指如戟，插向$n的双肩锁骨",
        "$N出手如风，十指微微抖动，一招「素手裂红裳」抓向$n的前胸",  
        "$N双手忽隐忽现，一招「长风吹落尘」，鬼魅般地抓向$n的肩头",  
        "$N左手当胸画弧，右手疾出，一招「明月映流沙」，猛地抓向$n的额头",
        "$N使一招「森然动四方」，激起漫天的劲风，撞向$n",
        "$N面无表情，双臂忽左忽右地疾挥，使出「黯黯侵骨寒」，十指忽伸忽缩，迅猛无比地袭向$n全身各处大穴",
        "$N使出「黄沙飘惊雨」，蓦然游身而上，绕着$n疾转数圈，$n正眼花缭乱间，\n$N已悄然停在$n身后，右手划出一道光圈，接着右手冲出光圈猛抓$n的后背",  
        "$N突然双手平举，$n一呆，正在猜测间，便见$N嗖的一下将双手收回胸前，接着一招「白骨无限寒」，五指如钩，直抓向$n的腰间",
        "$N使一招「灵蛇摆尾」，全身骤然一抖，把$n摔倒在地",
        "$N左掌内旋，一招「神龙现身」沾顾$n的手腕，同时展臂摇膀，横击$n的前胸",
        "$N右掌外翻，掌心向上，左掌内翻掌心反向上，一招「双龙绞尾」，抓住$n的手臂，互相绞力",
        "$N双掌交叉，使一招「双龙抢珠」，上搠$n的手臂，右脚前踢$n的右小腿",
        "$N立肘外旋内裹，向左滚推$n的手臂，右手握拳外旋直冲$n的面部，一招「虎踞龙盘」",
        "$N右脚虚点，左腿上搠$n的门面，同时右脚反踢$n的腰，「马踩游蛇」",
        "$N右手虚按$n背部，突然回身、摆步、拧腰、抡臂劈打，一记「龙起湖心」猛击$n的$l",
        "$N弧线跨步，一招「龙卧高山」，钩踢$n的裆部",
        "$N提膝击$n的腿膝，使一招「地动山摇」，出其不意使$n失去重心",
        "$N速出右拳沿$n右臂滚动，一招「直串龙潭」，边滚边向下直压$n的身体",
        "$N出右拳，左手由自己的右臂向前向上翻绕$n的右臂，一招「闪现雷鸣」",
        "$N速上右步，双手摆动迷惑$n，一招「水拍云崖」，右腿在手的掩护下横击$n的两肋",
        "$N凝神聚气，以意念转动脊椎，右手一记「龟蛇竟渡」，以不可抗拒之力击向$n的全身",
        "$N出右手与$n的手臂相触，突然翻掌握$n手腕，使出「倒索攀山」，向旁拉带$n",
});

int valid_enable(string usage) { return usage == "strike" ||  usage == "parry"; }  

int valid_combine(string combo) { return combo == "shenlong-bashi"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练化骨绵掌必须空手。\n");
        if (2 * (int)me->query_skill("shenlong-xinfa", 1) < (int)me->query_skill("shenlong-bashi", 1))
                return notify_fail("你的神龙心法火候不够，无法继续学化骨绵掌。\n");
        if ((int)me->query_skill("force", 1) < 50)
                return notify_fail("你的内功心法火候不够，练化骨绵掌会走火入魔。\n");
        if ((int)me->query("max_neili") < 300)
                return notify_fail("你的内力太弱，无法练化骨绵掌。\n");
        if ((int)me->query_skill("strike", 1) < (int)me->query_skill("huagu-mianzhang", 1))
                return notify_fail("你的基本掌法火候有限，无法领会更高深的化骨绵掌。\n");                
        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))], 
                "force" : 320 + random(120),
                "attack": 80 - random(10), 
                "dodge" : 80 - random(10), 
                "parry" : 80 - random(10), 
                "damage_type" : random(2)?"瘀伤":"内伤", 
        ]); 
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 80)
                return notify_fail("你的体力太低了。\n");
                
        if ((int)me->query("neili") < 80)
                return notify_fail("你的内力不够练化骨绵掌。\n");
 
        me->receive_damage("qi", 70);
        me->add("neili", -70);
        
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"huagu-mianzhang/" + action;
}

/*
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int amount;

        if ((int)me->query_skill("huagu-mianzhang") > 100)
        {
                if (random(damage_bonus) > (int)victim->query_skill("force") / 10
                &&  ! victim->query_temp("hgmz"))  
                {
                        victim->set_temp("hgmz", 1);
                        amount = 5 * damage_bonus/( 1 + victim->query_con()) + 1;
                        amount = amount / 100;
                        victim->add_temp("apply/str", -amount);
                        victim->start_call_out( (: call_other, __FILE__, "remove_effect", 
                                                victim, me, amount :), 
                                                (int)me->query_skill("huagu-mianzhang", 1) / 20);
                                                
                        return HIB "\n$N登时头晕目眩，立时便欲呕吐，喉间“呃呃呃”的不住作声。\n" NOR;
                }
        }
}

void remove_effect(object victim, object me, int amount)
{
        victim->delete_temp("hgmz");
        victim->add_temp("apply/str", amount);
        message_combatd(HIB"\n$N胸腹间气血翻涌，“哇”的一声，又是鲜血，又是清水，大口吐了出来。\n"NOR, victim);
        if( me )
                victim->receive_wound("qi", amount * 10 + random(amount * 10), me);
        else
                victim->receive_wound("qi", amount * 10 + random(amount * 10));
}
*/

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        int flvl;

        lvl  = me->query_skill("huagu-mianzhang", 1);
        flvl = me->query("jiali");
        if (lvl < 80 || flvl < 10 || ! damage_bonus)
                return;

        if (flvl * 2 + random(lvl) > victim->query_skill("force") &&
            victim->affect_by("huagu",
                              ([ "level" : flvl + random(flvl),
                                 "id"    : me->query("id"),
                                 "duration" : lvl / 50 + random(lvl / 20) ])))
        {
                return "“喀喇”一声响，$n大声惨叫，连退数步。\n";
        }
}

