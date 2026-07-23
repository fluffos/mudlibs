// jiuyin-shenzhua.c 九阴神爪

#include <ansi.h>
inherit SKILL;
mapping *action = ({
([ "action" : BLU"$N势若疯虎，形若邪魔，双爪如钢抓铁钩，左手手腕翻处，右手疾伸，五根手指抓向$n$l"NOR,
   "force" : 150,
   "damage" : 30,
   "dodge" : 5,
   "lvl" : 0,
   "damage_type" : "抓伤"
]),
([ "action" : BLU"突然人影闪动，$N迫到$n身后，袖中伸出手，五根手指向$n$l插了下去"NOR,
   "force" : 200,
   "weapon" : "五指",
   "damage" : 50,
   "dodge" : 10,
   "lvl" : 10,
   "damage_type" : "刺伤"
]),
([ "action" : BLU"$N手臂关节喀喇一响，手臂斗然长了半尺，一掌按在$n$l，五指即要插进"NOR,
   "force" : 250,
   "weapon" : "手指",
   "damage" : 60,
   "dodge" : 5,
   "lvl" : 20,
   "damage_type" : "刺伤"
]),
([ "action" : BLU"$N双手微张，十根尖尖的指甲映出灰白光忙，突然翻腕出爪，五指猛地插落"NOR,
   "force" : 300,
   "weapon" : "手爪",
   "damage" : 70,
   "dodge" : 5,
   "lvl" : 30,
   "damage_type" : "刺伤"
]),
([ "action" : BLU"$N左手突然在$n眼前上围下钩，左旋右转，连变了七八般，蓦地里右手一伸，五根手指直插$n$l"NOR,
   "force" : 350,
   "weapon" : "五根手指",
   "damage" : 80,
   "dodge" : 5,
   "lvl" : 40,
   "damage_type" : "刺伤"
]),
([  "action" : BLU "$N左爪虚晃，右爪蓄力，一招" HIR "「勾魂夺魄」" BLU "直插向$n的$l" NOR,
    "force" : 400,
    "dodge" : 10,
    "damage": 130,
    "lvl"   : 100,
    "skill_name" : "勾魂夺魄" ,
        "damage_type" : "抓伤"
]),
([  "action" : BLU "$N双手连环成爪，爪爪钩向$n，" HIR "「九子连环」" BLU "已向$n的$l抓出" NOR,
    "force" : 420,
    "dodge" : 20,
    "damage": 145,
    "lvl"   : 120,
    "skill_name" : "九子连环" ,
        "damage_type" : "抓伤"
]),
([  "action" : BLU "$N身形围$n一转，使出" HIR "「天罗地网」" BLU "，$n的$l已完全笼罩在爪影下" NOR,
    "force" : 440,
    "dodge" : 30,
    "damage": 155,
    "lvl"   : 140,
    "skill_name" : "天罗地网" ,
        "damage_type" : "抓伤"
]),
([  "action" : BLU "$N使一招" HIR "「风卷残云」" BLU "，双爪幻出满天爪影抓向$n全身" NOR,
    "force" : 520,
    "dodge" : 40,
    "damage": 170,
    "lvl"   : 160,
    "skill_name" : "风卷残云" ,
        "damage_type" : "抓伤"
]),
([  "action" : BLU "$N吐气扬声，一招" HIR "「唯我独尊」" BLU "双爪奋力向$n天灵戳下" NOR,
    "force" : 620,
    "dodge" : 50,
    "damage": 210,
    "lvl"   : 180,
    "skill_name" : "唯我独尊" ,
    "damage_type" : "抓伤"
]),
});

int valid_enable(string usage)
{ 
     return usage=="claw" || usage=="parry" ;
}

int valid_learn(object me)
{
       if (!me->query("jiuyin/full"))
               return notify_fail("你现在不能学习九阴神爪。\n");
       if ((int)me->query_skill("jiuyin-baiguzhua", 1) > 1)
               return notify_fail("你学了九阴白骨抓，无法学习九阴神爪。\n");
       if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
               return notify_fail("练九阴神爪必须空手。\n");
       if ((int)me->query_skill("jiuyin-zhengong", 1) < 100)
               return notify_fail("你的九阴真功火候不够，无法练九阴神爪。\n");
       if ((int)me->query_skill("daode-jing", 1) < 100)
               return notify_fail("你的道德经火候不够，无法练九阴神爪。\n");
       if ((int)me->query_skill("claw", 1) < 41)
               return notify_fail("你的基本爪功火候不够，无法学习。\n");
       if ((int)me->query("max_neili") < 1000)
               return notify_fail("你的内力太弱，无法练九阴神爪。\n");
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
	int i, j, level, lev1, lev2;
	level = (int) me->query_skill("jiuyin-shenzhua",1);
	lev1 = (int) me->query_skill("jiuyin-zhengong", 1);
	lev2 = (int) me->query_skill("jiuyin-shenfa", 1);
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			j = NewRandom(i, 20, level/5);
	if ((int)me->query_skill("daode-jing", 1) > 199 && random(level) > 180
	 && me->query_skill("jiuyin-zhengong") > 100 )
		return ([
			"action" : action[j]["action"] + RED"\n$N所使的似乎是江湖中驰名的阴毒功夫九阴白骨爪，但是招数光明正大，威力强极！"NOR,
			"force" : action[j]["force"] + random(lev1)/2,
			"dodge" : random(lev2),
			"damage" : action[j]["damage"] + random(lev1) / 2,
			"lvl" : action[j]["lvl"],
			"skill_name" : action[j]["skill_name"],
			"damage_type" : action[j]["damage_type"],
			]);
	else
		return action[j];
}

int practice_skill(object me)
{
       if( (int)me->query_skill("jiuyin-shenzhua", 1 ) < 150 )
               return notify_fail("你现在不能练习九阴神爪。\n");
       if ((int)me->query("jing") < 40)
               return notify_fail("你的体力太低了。\n");
       if ((int)me->query("neili") < 50)
               return notify_fail("你的内力不够练九阴神爪。\n");
       me->receive_damage("jing", 30);
       me->add("neili", -10 - random((int)me->query_skill("jiuyin-shenzhua", 1 )/10+1));
       return 1;
}

string perform_action_file(string action)
{
        return __DIR__"jiuyin-shenzhua/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
if (me->query_skill_mapped("force") != "jiuyin-zhengong")
return 0;

	if (!me->query("jiuyin/full")) return 0;
if( damage_bonus < 70 ) return 0;
	if( damage_bonus > 100 )
		victim->receive_wound("qi", damage_bonus / 3 );
	else
		victim->receive_wound("qi", damage_bonus / 2);

	return HIR "你听到「喀啦」一声轻响，竟似是骨碎的声音！\n" NOR;
}
