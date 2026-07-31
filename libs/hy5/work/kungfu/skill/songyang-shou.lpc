// songyang-shou.c  大嵩阳手

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N身躯微欠，中宫一掌缓缓拍出，光明正大，是此套手法的起首式「大嵩阳」",
        "force" : 150,
        "dodge" : 10,
        "damage" : 250,
        "damage_type" : "瘀伤",
        "lvl" : 0,
        "skill_name" : "大嵩阳"
]),
([      "action" : "$N忽拳忽掌，忽指忽抓，一式取自嵩山飞瀑的「天河水」，拍向$n的片刻间已变了十来种招数",
        "force" : 180,
        "dodge" : 5,
        "damage" : 250,
        "damage_type" : "内伤",
        "lvl" : 10,
        "skill_name" : "天河水"
]),
([      "action" : "$N大喝一声，使出一路大嵩阳手中的「铁梁道」，双手上下翻飞、大开大阖，连续击向$n",
        "force" : 240,
        "dodge" : 5,
        "damage" : 250,
        "damage_type" : "瘀伤",
        "lvl" : 30,
        "skill_name" : "铁梁道"
]),
([      "action" : "$N运劲于臂，大吼一声「万仞壑」，左掌拍出，右手成抓，同时袭到，两股巨力排山倒海般向$n压了过来",
        "force" : 440,
        "dodge" : 10,
        "damage" : 250,
        "damage_type" : "瘀伤",
        "lvl" : 50,
        "skill_name" : "万仞壑",
]),
([      "action" : "$N运起丹田之气猛喝一声，一式「观胜峰」，右掌挟带着狂风，向前斜推，掌势如劈山排云搬压向$n",
        "force" : 280,
        "dodge" : 15,
        "damage" : 250,
        "lvl" : 70,
        "skill_name" : "观胜峰",
         "damage_type" : "瘀伤"
]),
([      "action" : "$N双手忽而抓，忽而戳，忽而拳，忽而掌，连变数种，使一套「小铁梁」手法，左手一晃，右掌向$n的$l按去",
        "force" : 230,
        "dodge" : 5,
        "damage" : 250,
        "damage_type" : "内伤",
        "lvl" : 90,
        "skill_name" : "小铁梁"
]),
([      "action" : "$N气沉丹田，猛然怒喝一声，向前一个弓步，双掌合成「朝天闸」，带着风雷之声奋力击向$n",
        "force" : 300,
        "dodge" : -5,
        "damage" : 250,
        "damage_type" : "瘀伤",
        "lvl" : 110,
        "skill_name" : "朝天闸"
]),
([      "action" : "$N右腿向前弓步，一招「千丈渊」，左手化拳为掌，劲气十足，闪电般地由上向下劈$n",
        "force" : 340,
        "dodge" : 10,
        "damage" : 250,
        "damage_type" : "割伤",
        "weapon" : "掌缘",
        "lvl" : 130,
        "skill_name" : "千丈渊"
]),
});

int valid_enable(string usage) { return usage=="hand" ||  usage=="parry"; }

int valid_combine(string combo) { return combo=="hanbing-shenzhang"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练大嵩阳手必须空手。\n");
        if ((int)me->query_skill("songshan-qigong", 1) < 20)
                return notify_fail("你的嵩山气功火候不够，无法学大嵩阳手。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练大嵩阳手。\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int)me->query_skill("songyang-shou", 1);
        
        if (me->query_temp("ss_feiwu") == 2){
            return([      
                   "action": BLU "紧接着$N"BLU"右手一转一收，在$n"BLU"还没有反应过来时飞身欺前，腾出左手翻腕就是一式「震山掌」！"NOR,        
                   "force" : 550,
                   "dodge" : 40,
        "damage" : 550,
                   "damage_type" : "瘀伤",
                   ]);
            }
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
       
        if ((int)me->query("jing") < 50)
                return notify_fail("你的精力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练大嵩阳手。\n");
        me->receive_damage("jing", 30);
        me->receive_damage("neili", 5);
        if(me->query_skill("songyang-shou", 1) > 170)
                me->receive_damage("jing", 10);
        if(me->query_skill("songyang-shou", 1) > 190)
                me->receive_damage("neili", 5);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"songyang-shou/" + action;
}