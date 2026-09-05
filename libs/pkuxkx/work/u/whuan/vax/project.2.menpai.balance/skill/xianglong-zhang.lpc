// xianglong-zhang.c

inherit SKILL;

#include <ansi.h>
mapping *action = ({
        ([      "action": "$N双掌平平提到胸前，神色沉重的缓缓施出「亢龙有悔」推向$n的$l",
         "dodge": -10,
         "parry": 10,
         "force": 500,
         "damage_type": "瘀伤"
         ]),
        ([      "action": "$N突然身形飞起，双掌居高临下一招「飞龙在天」拍向$n的$l",
         "dodge": -8,
         "parry": -20,
         "force": 280,
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N右掌一招「见龙在田」，迅捷无比地劈向$n的$l",
         "dodge": -6,
         "parry": -10,
         "force": 220,
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N双掌施出一招「鸿渐于陆」，隐隐带着风声拍向$n的$l",
         "dodge": -4,
         "parry": -10,
         "force": 260,
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N左掌聚成拳状，右掌一招「潜龙勿用」缓缓推向$n的$l",
         "dodge": -2,
         "parry": 10,
         "force": 300,
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N施出一招「利涉大川」，右掌插腰，左掌劈向$n的$l",
         "dodge": 0,
         "parry": 20,
         "force": 350,
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N使出「突如其来」，右掌从不可能的角度向$n的$l推出",
         "dodge": 5,
         "parry": 10,
         "force": 300,
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N大吼一声，双掌使出「震惊百里」，不顾一切般击向$n",
         "dodge": -10,
         "parry": -10,
         "force": 400,
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N使出「或跃在渊」，向$n的$l连拍数掌",
         "dodge": 5,
         "parry": -20,
         "force": 330,
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N身形滑动，双掌使一招「双龙取水」一前一后按向$n的$l",
         "dodge": 10,
         "parry": 20,
         "force": 260,
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N使出「鱼跃于渊」，身形飞起，双掌并在一起向$n的$l劈下",
         "dodge": 15,
         "parry": 30,
         "force": 350,
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N双掌立起，使出「时乘六龙」向$n连砍六下",
         "dodge": 2,
         "parry": 20,
         "force": 370,
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N使出「密云不雨」，左掌封住$n的退路，右掌斜斜地劈向$l",
         "dodge": -1,
         "parry": 20,
         "force": 320,
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N使出「损则有孚」，双掌软绵绵地拍向$n的$l",
         "dodge": -2,
         "parry": 10,
         "force": 350,
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N脚下一转，突然欺到$n身前，一招「龙战于野」拍向$n的$l",
         "dodge": 5,
         "parry": 40,
         "force": 330,
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N门户大开，一招「履霜冰至」向$n的$l劈去",
         "dodge": -25,
         "parry": 1,
         "force": 320,
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N使出「羝羊触蕃」，双掌由下往上击向$n的$l",
         "dodge": -1,
         "parry": 40,
         "force": 300,
         "damage_type": "瘀伤"
         ]),
        ([  "action": "$N左掌护胸，右掌使一招「神龙摆尾」上下晃动着击向$n的$l",
         "dodge": 12,
         "parry": 40,
         "force": 320,
         "damage_type": "瘀伤"
         ]),
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }
int valid_combine(string combo) { return combo=="shexing-shou"; }

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练降龙十八掌必须空手。\n");
    if ((int)me->query_skill("huntian-qigong", 1) < 20)
        return notify_fail("你的混天气功火候不够，无法练降龙十八掌。\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力太弱，无法练降龙十八掌。\n");
    return 1;
}

mapping query_action(object me, object weapon)
{
	// dewolf : enhance xiang long 18 zhang
	if ( me->query_skill_mapped("force") == "huntian-qigong" )
	{
		// 受伤时候自动pfm
		if ( me->query("eff_qi")*3/2 < me->query("max_qi") && random(me->query_skill("force")) > 250 && me->query("neili") > 1500 && me->query("jiali") > 200 )
		{
			return ([
			"action": CYN"$N大步迈出，左手一划，右掌呼的一声，便向$n击去，正是一招「亢龙有悔」，力自掌生，猛不可当"NOR,
			"dodge": -10,
			"parry": 25,
			"force": 650,
			"damage": 120,
			"damage_type": "瘀伤" ]);
		}
		else if ( me->query("eff_qi")*3/2 < me->query("max_qi") &&  random(me->query_skill("strike")) > 280 && random(me->query_skill("force")) > 200 && me->query("neili") > 1000 && me->query("jiali") > 150 )
		{
			me->add("neili", -50);
			return ([
			"action": HIY"$N一招「亢龙有悔」，平推出去。初推出去看似轻描淡写，但一遇阻力，刹时之间连加"+ chinese_number(y) +"道後劲，一道强似一道，重重叠叠，直至无坚不摧，无强不破"NOR,
			"dodge": -20+random(20),
			"parry": 25+random(20),
			"force": 650+random(150),
			"damage": 120+random(50),
			"damage_type": random(2)?"内伤":"瘀伤" ]);
		}
		else if ( me->query("eff_qi")*3/2 < me->query("max_qi") &&  random(me->query_skill("strike")) > 210 && random(me->query_skill("force")) > 150 && me->query("neili") > 500 && me->query("jiali") > 100 )
		{
			me->add("neili", -30);
			return ([
			"action": YEL"$N踏上两步，呼的一声，一招「亢龙有悔」当胸击去。这一掌"+ chinese_number(x) +"分发，"+ chinese_number(10-x) +"分收，劲道去而复回，实是非同小可"NOR,
			"dodge": -20+random(100),
			"parry": 25+random(100),
			"force": 650+random(50),
			"damage": 120+random(20),
			"damage_type": random(2)?"内伤":"瘀伤" ]);
		}
	}
	
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 40)
        return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 10)
        return notify_fail("你的内力不够练降龙十八掌。\n");
    me->receive_damage("qi", 30);
    me->add("neili", -5);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"xianglong-zhang/" + action;
}

string *parry_msg = ({
        "只听见「锵」一声，被$p格开了。\n",
        "结果「当」地一声被$p挡开了。\n",
        "但是被$n用手中$v架开。\n",
        "但是$n身子一侧，用手中$v格开。\n",
        });

string *unarmed_parry_msg = ({
        "但是被$p格开了。\n",
        "结果被$p挡开了。\n",
        });

string query_parry_msg(object weapon)
{
    if( weapon )
        return parry_msg[random(sizeof(parry_msg))];
    else
        return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

string query_yinyang()
{
	return "太阳";
}