//yingzhaogong.c【鹰爪功】
//not a main menpai skill(can be used by NPCs)

inherit SKILL;

mapping *action = ({
        ([      
        	"action": "只见$N耸身提气，全身骨骼一阵爆响！左手沉腰，右爪呼！地一声抓向$n的$l",
        	"parry_msg" : "只见$n耸身提气，全身骨骼一阵爆响！左手沉腰，右爪呼！地一声格开了$N的攻击。\n",
		"damage" : 30,
                "damage_type":  "抓伤"
        ]),
        ([      "action": "$N双腿连连踢出，身形亦节节拔高，半空中一个转折，双爪已向$n$l抓到",
        	"parry_msg" : "只见$n双腿连连踢出，呼！地一声格开了$N的攻击。\n",
		"damage" : 35,
                "damage_type":  "抓伤"
        ]),
        ([      "action": "$N左爪在$n眼前一划，右爪带风，由下而上往$n的$l狠命一抓",
        	"parry_msg" : "只见$n双腿连连踢出，呼！地一声格开了$N的攻击。\n",
		"damage" : 40,
                "damage_type":  "抓伤"
        ]),
        ([      "action": "$N单足点地，双臂一振使了个「鹰击长空」势不可挡地扑向$n",
        	"parry_msg" : "只见$n单足点地，双臂一振使了个「鹰击长空」，架开了$N的攻击。\n",
    		"damage" : 45,
                "damage_type":  "抓伤"
        ]),
        ([      "action": "只见$N连退几步，突然一个矮身贴地而飞，双爪刁钻异常地抓向$n$l",
        	"parry_msg" : "只见$n连退几步，突然一个矮身贴地而飞，将$N的$w架在一旁。\n",
   		"damage" : 50,
                "damage_type":  "抓伤"
        ]),
        ([      "action": "$N大喝一声，双爪青筋凸起，前后一抄，似乎要把$n撕得粉身碎骨而后快",
        	"parry_msg" : "$n大喝一声，双爪青筋凸起，前后一抄，将$N的$w拨在一旁。\n",
       		"damage" : 55,
                "damage_type":  "砸伤"
        ]),
        ([      "action": "$N往前一个轻纵，几乎与$n贴面而立，一声阴笑中右爪往$n的$l恶狠狠地一抓",
        	"parry_msg" : "$n往前一个轻纵，一声阴笑中右爪将$N的$w拨在一旁。\n",
       		"damage" : 60,
                "damage_type":  "抓伤"
        ]),
        ([      "action": "$N一个倒翻，背后就象长了眼睛似的，一爪又一爪延绵不绝地抓向$n的$l",
        	"parry_msg" : "$n一个倒翻，背后就象长了眼睛似的，一爪又一爪延绵不绝，$N的攻势顿时一滞。\n",
       		"damage" : 65,        
                "damage_type":  "抓伤"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon")
)
                return notify_fail("练鹰爪功必须空手。\n");
        return 1;
}

int valid_enable(string usage)
{
        return usage=="unarmed" || usage=="parry" ;
}

mapping query_action(object me, object weapon)
{
	int i;
     	mapping *m_actions;
     	i = me->query_skill("yingzhao-gong",1)/50;
     	if( i>8 )
     		i = 8;
     	if( random(10)==1 )		
     		return action[random(sizeof(action))];
     	else	return action[random(i)];
}

int practice_skill(object me)
{
	if( (int)me->query("sen") < 30)
		return notify_fail("你的精神无法集中了，休息一下再练吧。\n");
	if( (int)me->query("kee") < 30 )
		return notify_fail("你现在手足酸软，休息一下再练吧。\n");
	if( (int)me->query("force") < 10 )
		return notify_fail("你的内力不够了。\n");

	me->receive_damage("kee", 30);
	me->add("force", -10);

	return 1;
}

string query_parry_msg(object me,object target)
{
	mapping act;
	if( !me || !target )
		return 0;
	if( !me->query_temp("weapon") )
		return 0;
	act = query_action(me,me->query_temp("weapon"));
	return act["parry_msg"];
}