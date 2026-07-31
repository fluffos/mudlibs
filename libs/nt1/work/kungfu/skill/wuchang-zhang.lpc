// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// wuchang-zhang.c 无常杖法

inherit SHAOLIN_SKILL;

string *action_msg = ({
        "$N微一躬身，一招「庸人自扰」，$w带着刺耳的吱吱声，擦地扫向$n的脚踝",
        "$N一招「想入非非」，右手托住杖端，左掌居中一击，令其凭惯性倒向$n的肩头",
        "$N一招「六神不安」，举起$w乒乒乓乓地满地乱敲，让$n左闪右避，狼狈不堪",
        "$N一招「面无人色」，举起$w，呆呆地盯了一会，突然猛地一杖打向$n的$l",
        "$N将$w顶住自己的胸膛，一端指向$n，一招「心惊肉跳」，大声叫喊着冲向$n",
        "$N一招「行尸走肉」，全身僵直，蹦跳着持杖前行，冷不防举杖拦腰向$n劈去",
        "$N面带戚色，一招「饮恨吞声」，趁$n说话间，一杖向$n张大的嘴巴捅了过去",
        "$N一招「力不从心」，假意将$w摔落地上，待$n行来，一脚勾起，击向$n的$l",
        "$N伏地装死，一招「穷途没路」，一个翻滚，身下$w往横里打出，挥向$n的裆部",
        "$N一招「呆若木鸡」，身不动，脚不移，$w却直飞半空，不偏不倚地砸向$n的$l",
        "$N高举$w，一招「人鬼殊途」，身形如鬼魅般飘出，对准$n的天灵盖一杖打下",
        "$N一招「我入地狱」，单腿独立，$w舞成千百根相似，根根砸向$n全身各处要害",
});

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 500)
                return notify_fail("你的内力不够。\n");

        if ((int)me->query_skill("force") < 80)
                return notify_fail("你的内功火候太浅。\n");

        if ((int)me->query_skill("staff", 1) < (int)(int)me->query_skill("wuchang-zhang", 1))
                return notify_fail("你的基本杖法水平有限，无法领会更高深的无常杖法。\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([ 
                "action": action_msg[random(sizeof(action_msg))], 
                "damage": 90 + random(30), 
                "attack": 40 + random(10),
                "dodge" : 40 + random(10),
                "parry" : 40 + random(10),
                "damage_type": "挫伤", 
        ]);
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "staff")
                return notify_fail("你使用的武器不对。\n");
        if (me->query_str() < 20)
                return notify_fail("你的臂力不够练无常杖法。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的精力不够练无常杖法。\n");
        if ((int)me->query("neili") < 50)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("qianye-shou", 1) < 100)
                return notify_fail("你的如来千叶手修为还不够。\n");

        me->receive_damage("qi", 40);
        me->add("neili", -40);
        return 1;
}

void skill_improved(object me)
{
        if( (int)me->query_skill("zui-gun", 1) >= 200
        &&  (int)me->query_skill("wuchang-zhang", 1) >= 200
        &&  !me->query("sl_gifts/zg") ) {
                me->add("dex", 1);
                me->set("sl_gifts/zg", 1);
                tell_object(me, "你的醉棍和无常杖学有所成，提高了你的身法。\n");
        }
}

string perform_action_file(string action)
{
        return __DIR__"wuchang-zhang/" + action;
}
