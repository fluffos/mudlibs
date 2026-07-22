// Rainbow-zhi.c 柔虹指
// Cracked by 凌惊雪 4-1-2003

#include <ansi.h>
inherit SKILL;

mapping *action1 = ({
        ([      "action": "$N左手一挥，一招「"+HIM"菊楼采月"NOR+"」右手点向$n$l。\n",
                "parry_msg": "$n左手一挥，一招「"+HIM"菊楼采月"NOR+"」幻出几朵菊影堪堪架住了来招。\n",
                "dodge":                -10,
                "parry":                10,
                "force":                20,
                "damage_type":  	"刺伤",
                "weapon":               "右手指风",
        ]),
        ([      "action": "$N使一招「"+HIM"雪桥翦梅"NOR+"」，身影忽前忽後，突然一转身左手往$n的$l点去。\n",
                "parry_msg": "$n使一招「"+HIM"雪桥翦梅"NOR+"」，但见梅花朵朵，将$N攻势逼回。\n",
                "dodge":                -10,
                "parry":                5,
                "force":                25,
                "damage_type":  	"刺伤",
                "weapon":               "左手食指",
        ]),
        ([      "action": "$N身法稍顿，左手一扬使出「"+HIM"柳亭簪花"NOR+"」往$n的$l点去。\n",
                "parry_msg": "$n身法稍顿，左手一扬使出「"+HIM"柳亭簪花"NOR+"」，数朵簪花残影架住了$N的$w。\n",
                "dodge":                -20,
                "parry":                -10,
                "force":                30,
                "damage_type":  "刺伤",
                "weapon":               "左手食指",
        ]),
        ([      "action": "只见$N纤腰一摆，陡然滑出数尺，右手顺著来势一招「"+HIM"桃坟扑蝶"NOR+"」往$n的$l点去。\n",
                "parry_msg": "只见$n腰身一摆，陡然滑出数尺，右手顺著来势一招「"+HIM"桃坟扑蝶"NOR+"」，只见一团团桃花升起，将$N$w架住。\n",
                "dodge":                -15,
                "parry":                -15,
                "force":                35,
                "damage_type":  "刺伤",
                "weapon":               "右手食指",
        ]),
});

mapping *action2 = ({
        ([      
        	"action": "$N左手一挥，一招「"+HIM"菊楼采月"NOR+"」右手凌空点向$n$l。\n",
        	"parry_msg": "$n左手一挥，一招「"+HIM"菊楼采月"NOR+"」幻出几朵菊影堪堪架住了来招。\n",
                "dodge":                -20,
                "parry":                -10,
                "force":                40,
                "damage_type":  	"刺伤",
                "weapon":               "右手指风",
        ]),
        ([      
        	"action": "$N使一招「"+HIM"雪桥翦梅"NOR+"」，身影忽前忽後，突然一转身左手遥指$n的$l！\n",
        	"parry_msg": "$n使一招「"+HIM"雪桥翦梅"NOR+"」，但见梅花朵朵，将$N攻势逼回。\n",
                "dodge":                -15,
                "parry":                0,
                "force":                50,
                "damage_type":  	"刺伤",
                "weapon":               "左手指风",
        ]),
        ([      
        	"action": "$N身法稍顿，左手一扬使出「"+HIM"柳亭簪花"NOR+"」，一道香风向$n的$l抚去。\n",
        	"parry_msg": "$n身法稍顿，左手一扬使出「"+HIM"柳亭簪花"NOR+"」，数朵簪花残影架住了$N的$w。\n",
                "dodge":                -20,
                "parry":                -10,
                "force":                60,
                "damage_type":  "刺伤",
                "weapon":               "指风",
        ]),
        ([      
        	"action": "只见$N腰身一摆，陡然滑出数尺，右手顺著来势一招「"+HIM"桃坟扑蝶"NOR+"」往$n的$l遥遥点去！\n",
        	"parry_msg": "只见$n腰身一摆，陡然滑出数尺，右手顺著来势一招「"+HIM"桃坟扑蝶"NOR+"」，只见一团团桃花升起，将$N$w架住。\n",
                "dodge":                -30,
                "parry":                -30,
                "force":                80,
                "damage_type":  "刺伤",
                "weapon":               "指风",
        ]),
});

int valid_learn(object me)
{
	int i = (int)me->query_skill("rainbow-zhi", 1);
	int j = (int)me->query_skill("brightjade-force", 1);
	if ( me->query("family/family_name") != "百花谷")
		return notify_fail("你不是百花谷门下，难以领会这门功夫的精髓。\n");
	if ( i >= j)
		return notify_fail("你的明玉神功不够高深，强学小心走火入魔。\n");
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练柔虹指必须空手。\n");
	return 1;
}

int valid_enable(string usage)
{
        return (usage=="unarmed") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
	if( me->query_level()<40 )
		return action1[random(sizeof(action1))];
	else	return action2[random(sizeof(action2))];	
}

int practice_skill(object me)
{
	int i = (int)me->query_skill("rainbow-zhi", 1);
	int j = (int)me->query_skill("brightjade-force", 1);
	if ( me->query("family/family_name") != "百花谷")
		return notify_fail("你不是百花谷门下，难以领会这门功夫的精髓。\n");
	if ( i >= j)
		return notify_fail("你的明玉神功不够高深，强学小心走火入魔。\n");
	if( (int)me->query("sen") < 30)
		return notify_fail("你的精神无法集中了，休息一下再练吧。\n");
	if( (int)me->query("kee") < 30 )
		return notify_fail("你现在手足酸软，休息一下再练吧。\n");
	if( (int)me->query("force") < 10 )
		return notify_fail("你的内力不够了。\n");

	me->receive_damage("sen", 30);
	me->add("force", -10);

	return 1;
}

string perform_action_file(string func)
{
return CLASS_D("baihuagu") + "/rainbow-zhi/" + func;
}

