//【摧心掌】 
//menpai skill
//lestat 修改于2001 for大雪山
#include <ansi.h>
inherit SKILL;

mapping *action = ({
        ([      "action": "只见$N凝神运气，左手护胸，右手掌心呈暗红，带着一股腥热之气拍向$n$l",
        	"parry_msg" : "$n凝神运气，左手护胸，右手掌心呈暗红，“喀”的一声架住了$N的$w。\n",
                "dodge":  -5,
                "parry":  -5,
	    	"force":  20,
	    	"damage" : 10,
                "damage_type":  "瘀伤"
        ]),
        ([      "action": "$N脚下连换几个方位，双掌一错，右手突然暴涨数尺往$n$l一搭一推",
        	"parry_msg" : "$n脚下连换几个方位，双掌一错，右手突然暴涨数尺，将$N的$w推向一旁。\n",
                "dodge":  -5,
                "parry":  -5,
	    	"force": 30,
		"damage" : 15,
                "damage_type":  "瘀伤"
        ]),
        ([      "action": "$N身形一滚，一脚凌空踢出，并不攻敌。左掌却在这一带之下从意想不到的角度拍上了$n的$l",
        	"parry_msg" : "$n身形一滚，一脚凌空踢出，并不攻敌。左掌却在这一带之下从意想不到的角度拍上了$N的$w。\n",
                "dodge":                -10,
                "parry":                -10,
	    	"force":		30,
	    	"damage" : 15,
                "damage_type":  "瘀伤"
        ]),
        ([      "action": "$N嘿嘿一笑，双掌在空气中划得嗤嗤着响！劲气纵横中突然飞出一掌，悄无声息地拍向$n$l",
        	"parry_msg" : "$n嘿嘿一笑，双掌在空气中划得嗤嗤着响！劲气纵横中突然飞出一掌，悄无声息地将$w格在一旁。\n",
                "dodge":                -15,
                "parry":                -15,
	    	"force":		30,
	    	"damage" : 20,
                "damage_type":  "瘀伤"
        ]),
        ([      "action": "$N轻轻一纵，与$n错身而过。便在这时，$N的手臂就象没长骨头似的往外一曲，快若闪电地击上了$n$l",
        	"parry_msg" : "$n轻轻一纵，与$N错身而过。便在这时，$p的手臂就象没长骨头似的往外一曲，快若闪电地格开了$N的$w。\n",
                "dodge":                -15,
                "parry":                -15,
	    	"force":		40,
	    	"damage" : 25,
                "damage_type":  "瘀伤"
        ]),
        ([      "action": "$N接连几个急转，身形如陀螺般向$n滚去，转一圈击一掌，掌掌不离$n的$l",
        	"parry_msg" : "$n接连几个急转，身形如陀螺般向$N滚去，转一圈击一掌，将$N的$w震了开来。\n",
                "dodge":                -20,
                "parry":                -20,
	    	"force":		50,
	    	"damage" : 30,
                "damage_type":  "瘀伤"
        ]),
        ([      "action": "只听$N一声清啸，身形如流水，掌势若浮云，暗光流转中延绵不绝地拍向$n周身要害",
        	"parry_msg" : "只听$n一声清啸，身形如流水，掌势若浮云，暗光流转中将$N的攻势化作无形。\n",
                "dodge":                -25,
                "parry":                -25,
	    	"force":		60,
	    	"damage" : 35,
                "damage_type":  "瘀伤"
        ]),
        ([      "action": "$N往后一纵，就势使了扫堂腿，双掌却借机反卷而上，长驱直入地击向$n$l",
        	"parry_msg" : "$n往后一纵，就势使了扫堂腿，双掌却借机反卷而上，“喀”的格开了$n的$w。\n",
                "dodge":                -30,
                "parry":                -25,
	    	"force":		60,
	    	"damage" : 40,
                "damage_type":  "瘀伤"
        ]),
});

int valid_learn(object me)
{
	if( (string)me->query_skill_mapped("force")!= "ningxie-force")
     return notify_fail("摧心掌必须配合冰谷凝血功才能练。\n");
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练摧心掌必须空手。\n");
	return 1;
}

int valid_enable(string usage)
{
        return usage=="unarmed" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        int i;
        if( !intp(i = me->query_temp("cuixin_per")) )
        {
        	i = me->query_skill("cuixin-zhang",1)/50;
     		if( i>8 )
     			i = 8;
     		if( random(10)==1 )		
     			return action[random(sizeof(action))];
     		else	return action[random(i)];
	}
        else 
        {
		if( i>7 )	
			i = 7; 
        	return action[i];
        }
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

string perform_action_file(string func)
{
return CLASS_D("xueshan") + "/cuixin-zhang/"+func;
}

