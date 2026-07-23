// shenlong-bashi 神龙八式
#include <ansi.h>;
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([	"action" : "$N使一招"+(order[random(13)])+"「疏影横斜」"NOR"，左手轻轻一抹，向$n的$l拍去",
	"damage" : 120,
	"parry": 10,
	"force": 100,
        "damage_type" : "瘀伤",
	"skill_name" : "疏影横斜"
]),
([	"action" : "$N鼓气大喝，双掌使一招"+(order[random(13)])+"「五丁开山」"NOR"，推向$n的$l",
	"damage" : 130,
	"parry": 30,
	"damage_type" : "瘀伤",
	"skill_name" : "五丁开山"
]),
([	"action": "$N顺势使一招"+(order[random(13)])+"「风行草偃」"NOR"，移肩转身，左掌护面，右掌直击$n",
	"damage" : 140,
	"dodge": 80,
	"parry": 20,
	"force": 200,
	"damage_type": "瘀伤",
	"skill_name" : "风行草偃"
]),
([	"action": "$N退后几步，突然反手一掌，一招"+(order[random(13)])+"「神龙摆尾」"NOR"，无比怪异地击向$n",
	"damage" : 150,
	"dodge": 80,
	"parry": 20,
	"force": 250,
	"damage_type": "瘀伤",
	"skill_name" : "神龙摆尾"
]),
([	"action" : "$N使一式"+(order[random(13)])+"「风卷残云」"NOR"，全身飞速旋转，双掌一前一后，猛地拍向$n的胸口",
	"damage" : 150,
	"force" : 250,
        "dodge" : 10,
	"lvl" : 30,
        "damage_type" : "瘀伤",
	"skill_name" : "风卷残云"
]),
([	"action": "$N忽的使出"+(order[random(13)])+"「乾坤倒旋」"NOR"，以手支地，双腿翻飞踢向$n",
	"damage" : 160,
	"dodge": 20,
	"parry": 20,
	"force": 250,
	"damage_type": "瘀伤",
	"skill_name" : "乾坤倒旋"
]),
([	"action": "$N大吼一声，使出"+(order[random(13)])+"「同归于尽」"NOR"，不顾一切般扑向$n",
	"dodge": 25,
	"parry": 10,
	"damage" : 160,
	"force": 400,
	"damage_type": "内伤",
	"skill_name" : "同归于尽"
]),
([	"action": "$N深吸一口气，身体涨成球状，猛然流星赶月般直撞向$n",
	"dodge": 80,
	"damage" : 170,
	"parry": 10,
	"force": 400,
	"damage_type": "内伤",
	"skill_name" : "流星赶月"
]),
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }

int valid_combine(string combo) { return combo=="huagu-mianzhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练神龙八式必须空手。\n");
	if ((int)me->query_skill("shenlong-xinfa", 1) < 25)
		return notify_fail("你的神龙心法火候不够，无法学神龙八式.\n");
	if ((int)me->query_skill("force", 1) < 25)
		return notify_fail("你的基本内功火候不够，无法学神龙八式。\n");
	if ((int)me->query("max_neili") < 150)
		return notify_fail("你的内力太弱，无法练神龙八式。\n");
	if (4*(int)me->query_skill("shenlong-xinfa",1) <(int)me->query_skill("shenlong-bashi",1))
		return notify_fail("你的神龙心法火候不够，无法继续学神龙八式。\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        object target;

        level   = (int) me->query_skill("shenlong-bashi",1);
        target = me->select_opponent();
        weapon = me->query_temp("weapon");

	if (me->query("gender") == "男性")
{
	if( random(4)==1 && random(level) > 250)
	{
		return ([
		"action" : HIR"$n抓住$N的后颈，一把提起。$N左手慢慢反转，在$n左腋底搔了一把，\n"
		   "$n身子软了下来，$N左手拿住$n腋下，右手慢慢回转，抓住$n领口，缓缓\n"
		   "举起$n的身子，过了自己头顶，向外摔出"NOR,
		"force" : 550+random(200),
		"dodge" : 350,
		"damage": 550+random(200),
	"skill_name" : "子胥举鼎",
	"damage_type" : "瘀伤" ]);
	}
 else	if( random(4)==1 && random(level) > 200)
	{
		return ([
		"action" : HIM"$N俯伏地上，$n伸右足踏住$N的后腰，$N双腿一缩，似欲跪拜，\n"
		   "右臂却慢慢横掠而出，突然间一个筋斗，向$n的胯下钻去，只一作势\n"
		   "左手已抓住$n右脚足踝，右手向$n小腹击去"NOR,
        	"force" : 500,
        	"dodge" : 100,
        	"parry" : 200,
        	"damage": 500,
	"skill_name" : "鲁达拔柳",
	"damage_type" : "瘀伤"]);
	}
 else	if( random(4)==1 && random(level) > 150)
	{
		return ([
               "action" : HIY"$N双臂反在背后，突然双手十指弯起，各成半球之形，身子向后一撞\n"
		   "十指便抓向$n的胸部，$n向后一缩，$N突然一个倒翻筋斗，身子跃起\n"
		   "双腿一分，已跨在$n肩头，同时双手按指压住$n太阳穴，食指按眉，中指按眼"NOR,
        	"force" : 450,
        	"dodge" : 100,
        	"parry" : 200,
        	"damage": 450,
	"skill_name" : "狄青降龙",
	"damage_type" : "瘀伤"
]);
	}
}
	if (me->query("gender") == "女性")
{
	if( random(4)==1 && random(level) > 250)
	{
		return ([
		"action" : HIW"$N身子微曲，纤腰轻扭，左足反踢，向$n的小腹踢去，$n后缩相避，\n"
		   "$N顺势反过身来，左手搂住$n头颈，右手握剑对准$n后心，一剑刺去"NOR,
		"force" : 550+random(200),
		"dodge" : 350,
		"damage": 550+random(200),
	"skill_name" : "贵妃回眸",
	"damage_type" : "瘀伤" ]);
	}
 else	if( random(4)==1 && random(level) > 200)
	{
		return ([
                 "action" : HIC"$N翻身卧倒，$n伸出右足踏住$N的后腰，$N的脑袋向着她自己的胸口钻落，\n"
		   "顺势在地下一个筋斗，在$n的胯下钻过，右手握剑刺入$n的后心"NOR,
		"force" : 500,
        	"dodge" : 100,
        	"parry" : 200,
        	"damage": 500,
	"skill_name" : "小怜横陈",
	"damage_type" : "瘀伤"]);
	}
 else	if( random(4)==1 && random(level) > 150)
	{
		return ([
               "action" : HIG"$N右足向前轻踢，顺势一勾，腿上的剑疾向$n的咽喉刺去"NOR,
        	"force" : 450,
        	"dodge" : 100,
        	"parry" : 200,
        	"damage": 450,
	"skill_name" : "飞燕回翔",
		"damage_type" : "瘀伤"
]);
	}
}
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];

}
 
int practice_skill(object me)
{
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("你的内力不够练神龙八式。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
    return __DIR__"shenlong-bashi/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        int flvl;
	int level, jiali, time,level2,damage,damage2;
	object weapon;
object target;

        level = (int) me->query_skill("shenlong-xinfa",1);
        level2= (int) me->query_skill("shenlong-xinfa",1);

damage2= (int) victim->query("neili",1)/8;
if (damage2>= 3800) damage2 = 3800;
	
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "shenlong-xinfa")
{
	victim->apply_condition("snake_poison",15);
	victim->apply_condition("chanchu_poison",15);
	victim->apply_condition("ill_fashao",10);
	victim->apply_condition("ill_kesou",10);
	victim->apply_condition("ill_shanghan",10);
	victim->apply_condition("ill_zhongshu",10);
	victim->apply_condition("ill_dongshang",10);
 victim->apply_condition("xuanming_poison",10);
if (!victim->is_busy()) victim->start_busy(2);	
 return HIR "$N高声狂叫：战无不胜，攻无不克，无坚不摧，无敌不破！$n头一晕,鲜血喷出!\n";
}

 

}