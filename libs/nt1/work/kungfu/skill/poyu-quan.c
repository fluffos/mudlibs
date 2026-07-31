// by sinb
// poyu-quan.c 劈石破玉拳

inherit SKILL;
#include <ansi.h>

mapping *action_msg = ({
        "$N施展「起手式」，身子微躬、右拳左掌合着一揖，突然随势向前疾探，打向$n$l",
        "$N左掌虚抚使出「石破天惊」，右拳“嗖”地一声从掌风中猛穿出来，击向$n的$l",
        "$N气沉丹田，身向前俯，双掌「铁闩横门」，带着隐隐风雷之声缓缓地推向$n",
        "$N腾空飞起，一式「千斤坠地」，对着$n雷霆般地猛捣数拳，拳风猛烈重如山",
        "忽然$n转到$N身后，$N一式「傍花拂柳」，守中带攻的背对反手一拳迅捷回击",
        "$N闪电般一招「金刚挚尾」，急冲到$n身前，抓向膻中大穴，欲将$n提起丢掷",
        "$N双拳连捣，使出「封闭手」，带动重重拳影，翻山蹈海般地盖向$n周身上下",
        "$N拳势如雷似电，一式「粉石碎玉」，荡起虎虎拳风，力拔千钧的笔直捣往$n$l",
});

int valid_enable(string usage) { return  usage == "cuff" || usage == "parry"; }

int valid_combine(string combo) { return combo == "hunyuan-zhang"; }


int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练劈石破玉拳必须空手。\n");
        if ((int)me->query_skill("zixia-shengong", 1) < 20)
                return notify_fail("你的紫霞功火候不够，无法学劈石破玉拳。\n");
        if ((int)me->query("max_neili") < 50)
                return notify_fail("你的内力太弱，无法练劈石破玉拳。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))], 
                "force": 300 + random(30), 
                "attack": 60 + random(10), 
                "dodge" : 60 + random(10), 
                "parry" : 60 + random(10), 
                "damage_type" : random(2)?"瘀伤":"内伤", 
        ]); 
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 70)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 70)
                return notify_fail("你的内力不够练劈石破玉拳。\n");
        me->receive_damage("qi", 60);
        me->add("neili", -60);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"poyu-quan/" + action;
}

