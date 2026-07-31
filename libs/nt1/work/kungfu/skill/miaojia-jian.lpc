// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>

inherit SKILL;

string *action_msg = ({
        "$N面露微笑，一招「苏秦背剑」，手中$w一抖，剑光暴长，洒向$n的$l",
        "$N一招「下步劈山」，身形突闪，剑招陡变，手中$w从后部斜刺向$n的$l",
        "$N暴退数尺，一招「抱剑归山」，低首抚剑，随后手中$w骤然穿上，刺向$n的$l",
        "$N身形一晃，疾掠而上，使一招「丹凤朝阳」，手中$w龙吟一声，对准$n连递数剑",
        "$N身形一展，施展出「随形腿弄花葬剑」，如影相随，手中$w疾往$n的$l刺去",
        "$N一招「阴阳扇折枝开合」，侧过身子，手中$w疾往斜上挑起，直指$n的$l",
        "$N微微一个转身，一招「空剑抚琴挥鞭」，手中$w却已自肋下穿出，罩向$n的$l",
        "$N神色微变，一招「翻云手剑指澜关」，剑招顿时变得凌厉无比，手中$w闪电般射向$n",
        "$N缓缓低首，接着一招「洗剑怀中抱月」，手中$w中宫直进，迅捷无比地往$n刺去",
        "$N纵步上走，单腿猛的踢向$n腰间，$n正要抽身回防，只见刹那间剑光一闪，$N\n"
        "一招「迎门腿反劈华山」，$w已经反劈而下",
        "$N矮身侧步，一招「返腕翼德闯帐」，手中$w反手疾挑而出，“唰”的一声往$n刺去",
        "$N一招「黄龙转身吐须」，蓦地疾退一步，又冲前三步，手中$w化为一道凌厉的弧光\n"
        "往$n的$l刺去",
        "$N一招「上步云边摘月」，纵身跃起，不见踪影，接着却又从半空中穿下，双手紧紧握着\n"
        "$w，声势逼人地刺向$n的$l",
        "$N一招「提撩剑白鹤舒翅」，手中$w“嗤”的一声斜刺向天空，随即向下“唰唰”两\n"
        "下，划出一个叉字，往$n的$l刺去",
        "$N左腿微抬，一招「冲天掌苏秦背剑」，左手虚击，右手$w猛的自下方挑起，激起数\n"
        "股劲风反挑$n的$l",
});

string main_skill() { return "daojian-guizhen"; }

int valid_enable(string usage) {return usage == "sword" || usage == "parry";}

int valid_learn(object me)
{

        if ((int)me->query_skill("daojian-guizhen", 1))
                return notify_fail("你已经将苗家剑法和胡家刀法二者合一了。\n");

        if ((int)me->query("max_neili") < 1300)
                return notify_fail("你的内力不够。\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("你的内功火候太浅。\n");

        if ((int)me->query_skill("sword", 1) < 120)
                return notify_fail("你的基本剑法火候不够，无法学习苗家剑法。\n");

        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("miaojia-jian", 1))
                return notify_fail("你的基本剑法水平有限，无法领会更高深的苗家剑法。\n");

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

        if ((int)me->query_skill("daojian-guizhen", 1))
                return notify_fail("你已经将苗家剑法和胡家刀法二者合一了。\n");

        if ( ! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if ((int)me->query("qi") < 70)
                return notify_fail("你的体力目前没有办法练习苗家剑法。\n");

        if ((int)me->query("neili") < 70)
                return notify_fail("你的内力不够，无法练习苗家剑法。\n");
        
        me->add("qi", -60);
        me->add("neili", -60);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"miaojia-jian/" + action;
}
