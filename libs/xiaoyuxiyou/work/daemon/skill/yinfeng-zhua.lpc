// yinfeng-zhua.c, 【阴风爪】
// created 9-5-97 pickle
//menpai skill(can be used by some yaomo NPCs)
//lestat modi for dtxy
//  霉气扑鼻，千疮百孔，残缺不全，摇摇欲坠
#include <ansi.h>
inherit SKILL;

mapping *action = ({
  ([
	"name"  : "「霉气扑鼻」",
    	"action": "$n只觉隐隐传来一阵霉气，正奇怪间，$N的左爪已到$l。\n",
	"force" : 20,
	"dodge" : -10,
	"parry" : -10,
	"damage_type" :	"抓伤",
  ]),
  ([
	"name"  : "「千疮百孔」",
    	"action": "$N笨拙无比地伸爪向$n的$l抓去。这招看似千疮百孔，破绽无数，但等$n招架时，却被逼得手忙脚乱，叫苦不迭。\n",
	"force" : 25,
	"dodge" : -10,
	"parry" : -10,
	"damage_type" :	"抓伤",
  ]),
  ([
	"name"  : "「残缺不全」",
    	"action": "$N左爪不动，右爪迅捷无比地向$n连施五抓。当$n全神贯注地对付这五抓时，$N的右爪已神不知鬼不觉地到了$n的$l。\n",
    	"force" : 30,
	"dodge" : 10,
	"parry" : -30,
	"damage_type" :	"抓伤",
  ]),
  ([
	"name"  : "「摇摇欲坠」",
    	"action": "$N突然间跃起数尺，居高临下向$n抓来。$n虽然看出$N胸腹间空门大开，却被这「摇摇欲坠」的凌厉攻势逼得回手自救。\n",
	"force" : 70,
	"dodge" : -10,
    	"parry" : -20,
	"damage_type" :	"抓伤",
  ]),
});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练阴风爪必须空手。\n");
    	return 1;
}

int valid_enable(string usage) { return usage=="unarmed";}

mapping query_action(object me, object weapon)
{
	int i;
	if( !me )
		return 0;
	i = me->query_skill("yinfeng-zhua")/100+1;
	if( i>4 )
		i = 4;	
	return action[random(i)];
}

int practice_skill(object me)
{
	if( (int)me->query("sen") < 40)
		return notify_fail("你的精神无法集中了，休息一下再练吧。\n");
	if( (int)me->query("kee") < 40 )
		return notify_fail("你现在手足酸软，休息一下再练吧。\n");
	if( (int)me->query("force") < 10 )
		return notify_fail("你的内力不够了。\n");
        me->receive_damage("kee", 5);
	me->add("force", -5);
	return 1;
}

string perform_action_file(string func)
{
	return CLASS_D("wdd") + "/yinfeng-zhua/" + func;
}
