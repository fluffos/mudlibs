//anranxiaohun-zhang.c 黯然消魂掌
// By Kayin @ CuteRabbit Studio 99-4-16 16:22 new
// By Xuanyuan
/*
    黄药师回了数掌，只觉那三人冲过来的势头便似潮水一般，一个浪头方过，第
二个更高的浪头又扑了过来，心想：“这少年的掌力一掌强似一掌，确是武林中的
奇才！”
*/

inherit SKILL;
#include <ansi.h>
mapping *action = ({
([	"action" : "$N一招「杞人忧天」抬头向天，浑若不见，呼的一掌向自己头顶空空拍出，手掌斜下，掌力化成弧形，四散落下拍向$n的$l。",
	"dodge": 20,
	"parry": 15,
	"force": 480,
	"damage": 100,
	"lvl" : 0,
	"skill_name" : "杞人忧天",
	"damage_type" : "内伤"
]),
([	"action" : "$N一招「无中生有」手臂下垂，绝无半点防御姿式，突然间手足齐动，左掌右袖、双足头锤、连得胸背腰腹尽皆有招式发出撞向$n.",
	"dodge": 10,
	"parry": 30,
	"force": 560,
	"damage": 80,
	"lvl" : 10,
	"skill_name" : "无中生有",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一招「拖泥带水」右手云袖飘动，宛若流水，左掌却重滞之极，便似带着几千斤泥沙一般，左右齐攻$n。",
	"dodge": 10,
	"parry": 5,
	"force": 540,
	"damage": 120,
	"lvl" : 20,
	"skill_name" : "拖泥带水",
	"damage_type" : "内伤"
]),

([	"action" : "$N一招「力不从心」含胸收腹，头缓缓低下，脚步沉重的迈向$n,单掌软绵绵的拍向$n的$l。",
	"dodge": 0,
	"parry": 10,
	"force": 520,
	"damage": 90,
	"lvl" : 30,
	"skill_name" : "力不从心",
    "damage_type" : "瘀伤"
]),
([	"action" : "$N一招「行尸走肉」踢出一脚。这一脚发出时恍恍惚惚，隐隐约约，若有若无的踢向$n",
	"dodge": 5,
	"parry": 25,
	"force": 640,
	"damage": 125,
	"lvl" : 40,
	"skill_name" : "行尸走肉",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N单掌平托，一招「庸人自扰」没精打采的拍向$n的$l.",
	"dodge": 10,
	"parry": 20,
	"force": 560,
	"damage": 80,
	"lvl" : 50,
	"skill_name" : "庸人自扰",
            "damage_type" : "瘀伤"
]),
([	"action" : "$N一招「倒行逆施」突然纵起丈余，头下脚上，倒过身子，一掌拍向$n的$l",
	"dodge": 20,
	"parry": 15,
	"force": 480,
	"damage": 25,
	"lvl" : 60,
	"skill_name" : "倒行逆施",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一招「心惊肉跳」凝目远眺，脚下虚浮，胸前门户洞开，全身姿式与武学中各项大忌无不吻合。",
	"dodge": 10,
	"parry": 15,
	"force": 600,
	"damage": 120,
	"lvl" : 70,
	"skill_name" : "心惊肉跳",
           "damage_type" : "内伤"
]),
([	"action" : "$N一招「废寝忘食」脚下虚浮，有如几天不吃不睡后的脚步朗舱的袭到$n的身旁，左掌右袖攻向$n的$l。",
	"dodge": 30,
	"parry": 5,
	"force": 620,
	"damage": 130,
	"lvl" : 80,
	"skill_name" : "废寝忘食",
           "damage_type" : "瘀伤"
]),
([	"action" : "$N一招「徘徊空谷」左攻右打，虚虚实实的攻向$n的$l。",
	"dodge": 10,
	"parry": 15,
	"force": 610,
	"damage": 100,
	"lvl" : 90,
	"skill_name" : "徘徊空谷",
           "damage_type" : "瘀伤"
]),
([	"action" : "$N一招「饮恨吞声」左手做饮酒状，右袖斜斜挥向$n的$l。",
	"dodge": 20,
	"parry": 0,
	"force": 520,
	"damage": 130,
	"lvl" : 100,
	"skill_name" : "饮恨吞声",
           "damage_type" : "瘀伤"
]),
([	"action" : "$N一招「六神不安」身如陀螺急转，展开轻功围着$n快速游走，忽然飞身而起，拍向$n的$l。",
	"dodge": 40,
	"parry": 5,
	"force": 650,
	"damage": 120,
	"lvl" : 110,
	"skill_name" : "六神不安",
           "damage_type" : "内伤"
]),
([	"action" : "$N一招「穷途末路」闪身到$n身旁，左掌举到胸前平推而出，接着右袖斜斜拍向$n的$l。",
	"dodge": 10,
	"parry": 35,
	"force": 620,
	"damage": 100,
	"lvl" : 120,
	"skill_name" : "穷途末路",
           "damage_type" : "瘀伤"
]),
([	"action" : "$N一招「呆若木鸡」双目直直的盯着$n，身体动也不动一下的飞向$n",
	"dodge": 30,
	"parry": 5,
	"force": 650,
	"damage": 90,
	"lvl" : 130,
	"skill_name" : "呆若木鸡",
           "damage_type" : "内伤"
]),
([	"action" : "$N低头冥想，一招「若有所失」左掌向外平平推向$n的$l。",
	"dodge": 20,
	"parry": 15,
	"force": 650,
	"damage": 90,
	"lvl" : 140,
	"skill_name" : "若有所失",
           "damage_type" : "瘀伤"
]),
([	"action" : "$N一招「四通八达」单掌晃出千万掌影将$n笼罩在掌力之下。",
	"dodge": 20,
	"parry": 10,
	"force": 650,
	"damage": 125,
	"lvl" : 150,
	"skill_name" : "四通八达",
           "damage_type" : "内伤"
]),
([	"action" : "$N错步上前，一招「鹿死谁手」招招抢先，以快打慢，一个转身已经转到了$n的身后，运指如风点向$n的大椎穴。",
	"dodge": 30,
	"parry": 25,
	"force": 650,
	"damage": 130,
	"lvl" : 160,
	"skill_name" : "鹿死谁手",
           "damage_type" : "点穴"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_learn(object me)
{
	if(!me->query("married_times")) 
		return notify_fail("你还没有所爱的人，不能领会其中的精要！\n");
	if (me->query("gender") != "男性") 
                return notify_fail("你体会不到男人思念一个人的心情。\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练黯然消魂掌必须空手。\n");
	if ((int)me->query("max_neili") < 2000)
		return notify_fail("你的内力太弱，无法练黯然消魂掌。\n");
	if ((int)me->query_str()< 40)
		return notify_fail("你的臂力太弱，无法练黯然消魂掌。\n");	
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level, jiali;
	object victim;
	victim = me->select_opponent();
	level = (int) me->query_skill("xiaohun-zhang",1);
	jiali=me->query("jiali");
	if (jiali < 50)
	jiali = 50;

	if (victim->query("neili") > 0
		&& random(me->query_skill("xiaohun-zhang",1))> 150
		&& me->query("neili") > 0
		&& me->query("jiali") > 0) {
		message_vision(BLU "\n$n只觉$N掌力的势头便似潮水一般，一个浪头方过，第二个更高的浪头又扑了过来。\n" NOR, me, victim);
		victim->add("neili", -jiali*3/2);
	}

	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 50, level)];
}

int practice_skill(object me)
{
	if ( me->query_skill("xiaohun-zhang", 1) > 80 && !environment(me)->query("insea"))
		return notify_fail("你必须借助外物的帮助方可继续修练黯然消魂掌。\n");
	if ((int)me->query("jingli") < 200)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 100)
		return notify_fail("你的内力不够练黯然消魂掌。\n");
	me->receive_damage("jingli", 50);
	me->add("neili", -50);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"xiaohun-zhang/" + action;
}
