// lingxiao-nayun-shou.c
// created : nerd Mar/3/1997

inherit SKILL;

mapping *action = ({
    ([   "action"  :"$N使出一招「稳若盘石」，左掌直立，右掌穿出击向$n的$l",
         "lian"    :"$N使出一招「稳若盘石」，左掌直立，右掌向前击出。",
         "zhaoshi" : "「稳若盘石」",
         "sen"   : 6,
         "parry" : 20,
         "dodge" : 15,
         "jibie" : 0,
         "wound" : 10,    
         "damage": 155,
         "damage_type":  "瘀伤"
    ]),
    ([   "action"  :"$N一招「势若山岳」，左掌化虚为实击向$n的$l",
         "lian"    :"$N一招「势若山岳」，左掌虚虚实实击出。",
         "zhaoshi" : "「势若山岳」",
         "damage" : 240,
         "wound"  : 15, 
         "sen"    : 8,
         "parry"  : 20,
         "dodge"  : 20,
         "jibie"  : 5,   
         "damage_type":  "瘀伤"
    ]),
    ([   "action"  :"$N前脚剔出，右手随后一招「屹若战阵」拍向$n的$l",
         "lian"    :"$N前脚剔出，右手随后一招「屹若战阵」。",
         "zhaoshi" : "「屹若战阵」",
         "sen"   : 10,
         "jibie" : 15,
         "parry" : 30,
         "dodge" : 20,
         "damage": 170,
         "damage_type":  "瘀伤"
    ]),
    ([   "action": "$N双掌一错，使出「翼若搏鹫」，身形飞起，对准$n的$l连续拍出",
         "lian"  :"$N双掌一错，使出「翼若搏鹫」，身形飞起数尺。",
         "zhaoshi" : "「翼若搏鹫」",
         "damage":  140,
         "wound" :  15, 
         "sen"  :  8,
         "parry" : 30,
         "dodge" : 20,
         "jibie":    20,
         "damage_type":  "瘀伤"
    ]),
    ([   "action": "$N左掌上扬，右掌推出，一招「婉若藏龙」击向$n$l",
         "lian"  : "$N左掌上扬，右掌推出，一招「婉若藏龙」快速拍出。",
         "zhaoshi" : "「婉若藏龙」",
         "sen"  : 6,
         "jibie": 30,
         "parry" : 10,
         "dodge" : 40,
         "damage": 160,
         "damage_type":  "瘀伤"
    ]),
    ([   "action":"$N使出「迸若流落」，化出数道身形同时击向$n的$l",
         "lian" :"$N使出「迸若流落」，化出数道身形同时击出。",
         "zhaoshi" : "「迸若流落」",
         "sen"   : 8,
         "jibie" : 40,
         "damage": 150,
         "wound" : 20, 
         "parry" : 10,
         "dodge" : 25,
         "damage_type":  "瘀伤"
    ]),
    ([   "action": "$N吐气扬声，一招「围若狩猎」，箭步上前，拍向$n的$l",
         "lian" : "$N吐气扬声，一招「围若狩猎」，一个箭步向前拍出。",
         "zhaoshi" : "「围若狩猎」",
         "sen"    : 8,
         "jibie"  : 50,
         "parry"  : 20,
         "dodge"  : 30,
         "wound"  :15, 
         "damage" : 270,
         "damage_type":  "瘀伤"
    ]),
});

string * parry_msg = ({
    "$n一招「舞若翻袖」，双掌翻舞，$N眼前一花，失去了$n的踪影。\n",
    "$n两手握拳，一招「颓若寝兽」，格开了$N的一击。\n",
    "但见$n一招「齐若友朋」，跟上一步，化开了$N的攻势。\n",
});
    

  
string query_parry_msg(object weapon)
{
    return parry_msg[random(sizeof(parry_msg))];
}

int valid_learn(object me)
{

	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练这门武功必须空手。\n");
	return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed" || usage=="parry" || usage=="hand";
}
int valid_combine(string combo) { return combo=="panheng-zhang"; }

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("jing") < 30)
		return notify_fail("你的精神无法集中了，休息一下再练吧。\n");
	if( (int)me->query("qi") < 30 )
		return notify_fail("你现在手足酸软，休息一下再练吧。\n");
	if( (int)me->query("neili") < 10 )
		return notify_fail("你的内力不够了。\n");

	me->receive_damage("qi", 30);
	me->add("neili", -10);

	return 1;
}

string perform_action_file(string func)
{
	return __DIR__"lingxiao-shou/"+func;
}


