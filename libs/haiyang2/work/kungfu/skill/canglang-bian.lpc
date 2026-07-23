// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>

inherit SKILL;

string *action_msg = ({
        HIR"$N跃起三丈，身在半空，招式陡变，“太古神龙”如惊涛骇浪，卷转电擎而落"NOR,
        YEL"$N鞭式一变，杀机四布，展开了天雷破有去无回的杀招“太古伏羲说八卦”"NOR,
        GRN"$N手中鞭影乍迸，卷起万重电光，“太古开天”轰然横扫。"NOR,
        HIC"$N惊叱一声，双手并举，寒光陡飞，霎时人鞭合一，凌空直向$n飞去"NOR,
        "$N伫立不动，挥动$w，使出一招「大海沉沙」，手中$w缓缓向$n的$l击去，去势虽不劲急，\n但鞭势沉滞，如同压了几千斤泥沙一般",
        "$N手持$w中央，一招「海天一线」，$w一端陡然一翻，点向$n前胸，劲风所至，将$n退路封住，\n另一端如灵蛇出洞，疾速卷向$n脚踝",
        "$N冷哼一声，急催内力，使出一招「巨浪排空」，鞭势加快，只见十数重鞭影如惊滔骇浪般向$n的$l疾卷而来",
        "$N缓缓转动手中$w，一式「万里无波」，手中$w去势奇慢，不带丝毫破空之声，\n但所过之处尘土飞扬，$w上所带劲风已刮得人扑面生疼",
        "$N身形游走不定，忽地使出一招「沧海一粟」，$w上风声大作，刹那间数十条鞭影从四面八方向$n周身要害击到",
        "$N狂啸一声，双目精光大盛，一招「怒海蓝涛」，鞭势展开，或横扫直击，或盘旋翻卷，倾刻间已将$n全身裹住",
});

int valid_enable(string usage) { return usage == "whip" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 50)
                return notify_fail("你的内力不够。\n");
                
        if ((int)me->query_skill("bibo-shengong", 1) < 120)
                return notify_fail("你的碧波神功火候太浅。\n");
        if ((int)me->query_skill("anying-fuxiang", 1) < 120)
                return notify_fail("你的暗影浮香火候太浅。\n");
        if ((int)me->query_skill("lanhua-shou", 1) < 120)
                return notify_fail("你的兰花拂穴手火候太浅。\n");
        if ((int)me->query_skill("luoying-shenjian", 1) < 120)
                return notify_fail("你的落英神剑火候太浅。\n");
        if ((int)me->query_skill("luoying-zhang", 1) < 120)
                return notify_fail("你的落英神剑掌火候太浅。\n");
        if ((int)me->query_skill("tanzhi-shentong", 1) < 120)
                return notify_fail("你的弹指神通火候太浅。\n");
        if ((int)me->query_skill("xuanfeng-leg", 1) < 120)
                return notify_fail("你的旋风扫叶腿火候太浅。\n");
        if ((int)me->query_skill("yuxiao-jian", 1) < 120)
                return notify_fail("你的玉箫剑法火候太浅。\n");
       if ((int)me->query_skill("count", 1) < 120)
                return notify_fail("你的阴阳八卦火候太浅。\n");
       if ((int)me->query_skill("qimen-wuxing", 1) < 120)
                return notify_fail("你的奇门五行火候太浅。\n");

        return 1; 
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))],
                "damage": 110 + random(310),
                "attack": 50 + random(30),
                "dodge" : 50 + random(30),
                "parry" : 50 + random(30),
                "force" : 150 + random(310),	
                "damage_type" : random(2)?"鞭伤":"刺伤", 
        ]);
}

int practice_skill(object me)
{
        object weapon, where;
        
        where = environment(me);
          if ((int)me->query_skill("anying-fuxiang", 1) < 120)
                return notify_fail("你的暗影浮香火候太浅。\n");
        if ((int)me->query_skill("lanhua-shou", 1) < 120)
                return notify_fail("你的兰花拂穴手火候太浅。\n");
        if ((int)me->query_skill("luoying-shenjian", 1) < 120)
                return notify_fail("你的落英神剑火候太浅。\n");
        if ((int)me->query_skill("luoying-zhang", 1) < 120)
                return notify_fail("你的落英神剑掌火候太浅。\n");
        if ((int)me->query_skill("tanzhi-shentong", 1) < 120)
                return notify_fail("你的弹指神通火候太浅。\n");
        if ((int)me->query_skill("xuanfeng-leg", 1) < 120)
                return notify_fail("你的旋风扫叶腿火候太浅。\n");
        if ((int)me->query_skill("yuxiao-jian", 1) < 120)
                return notify_fail("你的玉箫剑法火候太浅。\n");
       if ((int)me->query_skill("count", 1) < 120)
                return notify_fail("你的阴阳八卦火候太浅。\n");
       if ((int)me->query_skill("qimen-wuxing", 1) < 120)
                return notify_fail("你的奇门五行火候太浅。\n");      
              
        if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "whip")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 60)
                return notify_fail("你的体力不够练沧浪鞭法。\n");

        if ((int)me->query("neili") < 160)
                return notify_fail("你的内力不够练沧浪鞭法。\n");


        message_vision(HIC"$N面对海潮，徐徐挥鞭，使呼吸与海潮同步，渐渐感觉体内真气也如海潮澎湃一般无穷无尽。\n"NOR, me);
        me->add("neili", 30);
        me->recieve_damage("qi", 50);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"canglang-bian/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
       string msg;
       int j, k;
 int level;
       j = me->query_skill("yuxiao-jian", 1);
       k = me->query_skill("qimen-wuxing",1);
 level = (int) me->query_skill("bibo-shengong",1);
if (random(6)==0 && level>=300 && me->query_skill_mapped("force") == "bibo-shengong")
        {
if (victim->query("qi") > 600)
victim->add("qi",-250+random(200));
victim->add("eff_qi",-(50+random(200)));
                me->add("neili", -20);
if (!victim->is_busy()) victim->start_busy(1);
return HIR "$N施展开奇门五行,$n心神一乱,被打中$l。结果鲜血狂奔!!\n";
        }
	if( random(damage_bonus/2) > victim->query_str() ) {
		victim->receive_wound("qi", (damage_bonus - 10) / 2+30 );
		return HIB "$N徐徐挥鞭，使呼吸与海潮同步，，手中$w圈转如海潮澎湃一般无穷无尽圈向 $n全身! \n" NOR;
	}
}