// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

inherit SKILL;

string *action_msg = ({
        "$N使一招「春江潮水」，双手划了个半圈，按向$n的$l",
        "$N使一招「海上明月」，左手轻轻一挥，劈向$n的$l",
        "$N右手掌心向外，由右向左，使一招「滟滟随波」，向$n的$l打去",
        "$N使一招「江流宛转」，分击$n的胸口和$l",
        "$N使一招「月照花林」，左右掌同时击出，空中突然左右掌方向互变",
        "$N左手不住晃动，右掌一招「空中流霜」，向$n的$l打去",
        "$N左手变掌为啄，右掌立掌如刀，一招「汀上白沙」，劈向$n的$l",
        "$N左脚退后半步，右掌使一招「江天一色」，横挥向$n",
        "$N一招「皎皎孤月」，左掌先发而后至，右掌后发而先至",
        "$N双掌缩入袖中，双袖飞起扫向$n的$l，却是一招「长江流水」",
        "$N左手虚按，右手划道弧线使一招「白云悠悠」，向$n的$l插去",
        "$N双手变掌做拳，向前向后划弧，一招「青枫浦上」击向$n的$l",
        "$N左手虚划，右手变掌为钩一记「楼月蜚回」击向$n的$l",
        "$N施出「玉户帘中」，右掌向外挥出，左掌同时攻向$n",
        "$N由臂带手，在面前缓缓划过，使一招「鸿雁长飞」，挥向$n的$l",
        "$N负身就地，右掌使一招「鱼龙潜跃」，自下而上向$n的$l击去",
        "$N右手由钩变掌，双手掌心向上，右掌向前推出一招「月华流照」",
        "$N右掌不住向外扫出，是一式「闲潭落花」，左掌旋转着向$n攻去",
        "$N右手经腹前经左肋向前撇出，使一招「江水流春」，向$n的$l锤去",
        "$N使一招「斜月沉沉」，左掌连划三个大圈，右掌从圈中穿出击向$n",
        "$N左手向上划弧拦出，右手使出「碣石潇湘」，不离$n头顶方寸之间",
});

int valid_enable(string usage)
{
        return usage == "strike" || usage == "parry" ;
}

int valid_combine(string combo)
{
        return combo == "qixing-shou";
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练昊天掌必须空手。\n");

        if ((int)me->query("max_neili") < 800)
                return notify_fail("你的内力修为太差，无法学昊天掌。\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("你的内功火候不够，无法学昊天掌。\n");

        if ((int)me->query_skill("strike", 1) < 80)
                return notify_fail("你的基本掌法水平有限，无法学昊天掌。\n");

        if ((int)me->query_skill("strike", 1) < (int)me->query_skill("haotian-zhang", 1))
                return notify_fail("你的基本掌法水平有限，无法领会更高深的昊天掌。\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))], 
                "force": 300 + random(30), 
                "attack": 50 + random(10), 
                "dodge" : 50 + random(10), 
                "parry" : 50 + random(10), 
                "damage_type" : random(2)?"瘀伤":"内伤", 
        ]); 
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 60)
                return notify_fail("你的体力太低了。\n");

        if ((int)me->query("neili") < 60)
                return notify_fail("你的内力不够练昊天掌。\n");

        me->receive_damage("qi", 50);
        me->add("neili", -50);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"haotian-zhang/" + action;
}
