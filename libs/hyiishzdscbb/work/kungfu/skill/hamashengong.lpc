// hamagong.c 蛤蟆神功

#include <ansi.h>

inherit FORCE;

mapping *action = ({
([      "action": "$N忽而倒竖，一手撑地，身子横挺，只以一掌向$n的$l拍出",
        "dodge": 40,
        "force": 50,
        "damage" : 100,
        "lvl" : 0,	
        "damage_type": "瘀伤"
]),
([      "action": "$N双手在地上一撑，身子忽地拔起，一跃三尺，落在$n的面前，单掌向$p直劈而下",
        "weapon" : "掌缘",
        "dodge": 35,
        "force": 60,
        "damage" : 100,
        "lvl" : 0,
        "damage_type": "割伤"
]),
([      "action": "$N突然伸手在自己脸上猛抓一把，又反足在自己肾上狠踢一脚，一掌击出，中途方向必变，实不知将打何处",
        "dodge": 35,
        "force": 100,
        "lvl" : 20,
        "damage" : 100,
        "damage_type": "瘀伤"
]),
([      "action": "突然之间，$N俯身疾攻，上盘全然不守，微微侧头，一口唾沫往$n$l吐去",
        "weapon" : "唾液",
        "dodge": 80,
        "force": 180,
        "damage" : 100,
        "lvl" : 50,
        "damage_type": "刺伤"
]),
([      "action": "$N丝毫不动声色，双腿微曲，右掌平伸，左掌缓缓运起蛤蟆功的劲力，呼的一声推向$n",
        "dodge": 15,
        "force": 200,
        "lvl" : 80,
        "damage" : 200,
        "damage_type": "瘀伤"
]),
([      "action": "$N默念口诀运气经脉，只觉愈转愈是顺遂，当下一个翻身跃起，咕的一声叫喊，双掌对着$n拍出",
        "dodge": 10,
        "force": 250,
        "lvl" : 110,
        "damage" : 250,
        "damage_type": "瘀伤"
]),
([      "action": "但见$N双腿微曲，双掌会收，然后向$n一上一下，一放一收，斗然击出",
        "dodge": 20,
        "force": 300,
        "lvl" : 140,
        "damage" : 300,
        "damage_type": "瘀伤"
]),
([  "action": "$N闭眼逼住呼吸，过了片刻，猛跃而起，眼睛也不及睁开，双掌便向$n的方向推了出去",
        "dodge": 10,
        "force": 380,
        "lvl" : 170,
        "damage" : 380,
        "damage_type": "内伤"
]),
([  "action": "$N脚步摇摇幌幌的看上去马上就会跌倒，忽然双腿一弯、一登，口中阁的一声叫喝，手掌向$n猛然推出",
        "dodge": 15,
        "force": 400,
        "lvl" : 199,
        "damage" : 400,
        "damage_type": "瘀伤"
]),
});

int valid_enable(string usage) 
{ return usage == "force" || usage=="strike" || usage=="unarmed" || usage =="parry"; }

string query_skill_name(int level)
{
        int i = sizeof(action);

        while (i--)
                if(level > action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me)
{
        int i, level;
        
        level   = (int) me->query_skill("hamashengong",1);
        if (random(me->query_str()) > 30 && 
            random(level) > 120 &&
            me->query("max_neili") > 3000 &&
            me->query("neili") > 1300 ) {
                me->add("neili", -50);
                return ([
                "action": HIC "$N蹲低身子，两眼微闭，口中咕咕咕的叫了三声，双掌向$n缓缓推出！激得灰泥弥漫，尘土飞扬" NOR,
                "dodge" : 10,
                "force": 750,
                "damage_type": "瘀伤"]);
        }
        
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int valid_learn(object me)
{
    if ((int)me->query_skill("force", 1) < 200)
   return notify_fail("你的内功心法火候不够，无法学蛤蟆神功。\n");
    if ((int)me->query("neili") < 1500)
   return notify_fail("你的内力太弱，无法练蛤蟆神功。\n");
    return 1;
}

int practice_skill(object me)
{
      return notify_fail("蛤蟆神功不是随便什么地方都可以练习的。\n");
}


string exert_function_file(string func)
{
       return __DIR__"hamashengong/" + func;
}

string perform_action_file(string action)
{
        return __DIR__"hamashengong/" + action;
}
